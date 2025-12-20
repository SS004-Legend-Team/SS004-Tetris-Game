# TÀI LIỆU KỸ THUẬT - TRÒ CHƠI TETRIS

## 1. TỔNG QUAN

### 1.1. Mô tả
Tetris là trò chơi puzzle cổ điển, người chơi điều khiển các khối hình (tetromino) rơi xuống và sắp xếp chúng để tạo thành các dòng hoàn chỉnh. Khi một dòng được lấp đầy, nó sẽ bị xóa và người chơi được điểm. Tốc độ rơi tăng dần theo level.

### 1.2. Công nghệ sử dụng
- **Ngôn ngữ**: C++
- **Paradigm**: Hướng đối tượng (OOP) với tính đa hình (Polymorphism)
- **Platform**: 
  - Windows: `main.cpp` (sử dụng `conio.h`, `windows.h`)
  - macOS/Linux: `main-macos.cpp` (sử dụng `termios.h`, `unistd.h`)

### 1.3. Cấu trúc file
```
SS004-Tetris-Game/
├── blocks.h          # Định nghĩa các class Blocks và derived classes
├── main.cpp          # Code chính cho Windows
├── main-macos.cpp    # Code chính cho macOS/Linux
└── TECHNICAL_DOCUMENTATION.md  # Tài liệu này
```

---

## 2. KIẾN TRÚC HỆ THỐNG

### 2.1. Kiến trúc tổng quan

```
┌─────────────────────────────────────────────────────────┐
│                    GAME ENGINE                          │
├─────────────────────────────────────────────────────────┤
│                                                           │
│  ┌──────────────┐    ┌──────────────┐    ┌──────────┐  │
│  │  Xử lý       │    │  Điều khiển │    │  Hiển    │  │
│  │  Input       │───▶│  Logic Game │───▶│  thị     │  │
│  └──────────────┘    └──────────────┘    └──────────┘  │
│         │                    │                  │        │
│         │                    │                  │        │
│         ▼                    ▼                  ▼        │
│  ┌──────────────┐    ┌──────────────┐    ┌──────────┐  │
│  │  Sự kiện     │    │  Quản lý     │    │  Xuất    │  │
│  │  Bàn phím    │    │  Khối        │    │  Màn hình│  │
│  └──────────────┘    └──────────────┘    └──────────┘  │
│                                                           │
└─────────────────────────────────────────────────────────┘
         │                    │                  │
         ▼                    ▼                  ▼
┌──────────────┐    ┌──────────────┐    ┌──────────┐
│  Blocks.h    │    │  Bàn chơi   │    │  Màn hình │
│  (OOP)       │    │  (Mảng 2D)  │    │  Console  │
└──────────────┘    └──────────────┘    └──────────┘
```

### 2.2. Mô hình hướng đối tượng

Hệ thống sử dụng **Design Pattern: Factory Pattern** và **Polymorphism**:

- **Base Class**: `Blocks` (abstract class)
- **Derived Classes**: `IBlock`, `OBlock`, `TBlock`, `SBlock`, `ZBlock`, `JBlock`, `LBlock`
- **Factory Function**: `createBlock(int type)`

---

## 3. CẤU TRÚC DỮ LIỆU

### 3.1. Game Board
```cpp
char board[H][W];  // H = 20, W = 15
```
- Mảng 2 chiều biểu diễn trạng thái bàn chơi
- `' '` = ô trống
- `'I'`, `'O'`, `'T'`, `'S'`, `'Z'`, `'J'`, `'L'` = các loại block

### 3.2. Block Shape
```cpp
char shape[4][4];  // Mỗi block được biểu diễn trong ma trận 4x4
```
- Mỗi block chiếm tối đa 4x4 ô
- Chỉ một phần của ma trận chứa block thực tế

### 3.3. Game State Variables
```cpp
int level = 1;              // Level hiện tại
int totalLines = 0;          // Tổng số dòng đã xóa
int fallDelay = BASE_DELAY;  // Thời gian delay giữa các lần rơi (ms)
int x, y;                    // Vị trí block hiện tại trên board
Blocks* currentBlock;         // Con trỏ đến block đang rơi
```

### 3.4. Constants
```cpp
#define H 20                  // Chiều cao board
#define W 15                  // Chiều rộng board
#define MIN_DELAY 100         // Delay tối thiểu (ms)
#define BASE_DELAY 1000       // Delay cơ bản (ms)
#define SPEED_STEP 40         // Bước tăng tốc mỗi level
#define LINES_PER_LEVEL 5     // Số dòng cần xóa để lên level
```

---

## 4. CÁC MODULE CHÍNH

### 4.1. Module Blocks (blocks.h)

#### 4.1.1. Class Blocks (Base Class)
```cpp
class Blocks {
protected:
    char shape[4][4];
    int rotationState;
public:
    virtual ~Blocks();
    char getCell(int i, int j) const;
    virtual void rotate() = 0;  // Pure virtual - đa hình
    virtual bool canRotate() const;
};
```

**Trách nhiệm**:
- Định nghĩa interface chung cho tất cả các block
- Cung cấp phương thức truy cập shape
- Định nghĩa virtual method `rotate()` để các class con override

#### 4.1.2. Derived Classes

| Class | Số trạng thái xoay | Mô tả |
|-------|-------------------|-------|
| `IBlock` | 2 | Block thẳng (dọc/ngang) |
| `OBlock` | 0 | Block vuông (không xoay) |
| `TBlock` | 4 | Block hình chữ T |
| `SBlock` | 2 | Block hình chữ S |
| `ZBlock` | 2 | Block hình chữ Z |
| `JBlock` | 4 | Block hình chữ J |
| `LBlock` | 4 | Block hình chữ L |

**Ví dụ cấu trúc IBlock**:
```
Trạng thái 0 (dọc):      Trạng thái 1 (ngang):
    [ ]                      [ ][ ][ ][ ]
    [I]                      [I][I][I][I]
    [I]                      [ ]
    [I]                      [ ]
    [I]
```

### 4.2. Module Game Logic

#### 4.2.1. Di chuyển và va chạm
```cpp
bool canMove(int dx, int dy)
```
- Kiểm tra block có thể di chuyển theo hướng (dx, dy) không
- Kiểm tra biên và va chạm với các block đã đặt

#### 4.2.2. Xoay block
```cpp
bool canRotateBlock()
void rotateBlock()
```
- `canRotateBlock()`: Kiểm tra vị trí sau khi xoay có hợp lệ không
- `rotateBlock()`: Sử dụng **polymorphism** - gọi `currentBlock->rotate()`
- Mỗi loại block tự xử lý logic xoay riêng

#### 4.2.3. Xóa dòng
```cpp
int removeLine()
```
- Quét từ dưới lên để tìm dòng đầy
- Xóa dòng và dịch chuyển các dòng phía trên xuống
- Trả về số dòng đã xóa

#### 4.2.4. Cập nhật tốc độ
```cpp
void updateSpeed(int linesRemoved)
```
- Cộng dồn `totalLines`
- Tính `level = totalLines / LINES_PER_LEVEL + 1`
- Giảm `fallDelay = BASE_DELAY - (level - 1) * SPEED_STEP`
- Giới hạn `fallDelay >= MIN_DELAY`

### 4.3. Module Rendering

#### 4.3.1. Vẽ board
```cpp
void draw()
```
- Xóa màn hình (`system("cls")` hoặc `system("clear")`)
- Vẽ border và board
- Hiển thị thông tin: Level, Lines, Delay

#### 4.3.2. Quản lý block trên board
```cpp
void block2Board()    // Vẽ block lên board
void boardDelBlock()  // Xóa block khỏi board (để di chuyển)
```

### 4.4. Module Input Handling

#### 4.4.1. Windows (main.cpp)
- Sử dụng `conio.h`: `kbhit()`, `getch()`
- `Sleep()` từ `windows.h`

#### 4.4.2. macOS/Linux (main-macos.cpp)
- Tự implement `kbhit()` và `getch()` bằng `termios.h`
- Sử dụng `this_thread::sleep_for()` từ C++11

**Bảng điều khiển**:
| Phím | Chức năng |
|------|-----------|
| `a` | Di chuyển trái |
| `d` | Di chuyển phải |
| `x` | Rơi nhanh |
| `w` hoặc `r` | Xoay block |
| `q` | Thoát game |

---

## 5. SƠ ĐỒ KHỐI (FLOWCHART)

### 5.1. Sơ đồ tổng quan - Vòng lặp Game

```
                    ┌─────────────┐
                    │   BẮT ĐẦU   │
                    └──────┬──────┘
                           │
                           ▼
                    ┌─────────────┐
                    │ Khởi tạo    │
                    │ - Random    │
                    │ - Tạo block │
                    │ - Khởi tạo  │
                    │   bàn chơi  │
                    └──────┬──────┘
                           │
                    ┌──────▼──────┐
                    │ VÒNG LẶP    │◄────┐
                    │   GAME      │     │
                    └──────┬──────┘     │
                           │            │
                           ▼            │
              ┌──────────────────────┐  │
              │  Xóa block khỏi      │  │
              │  bàn chơi (để di    │  │
              │  chuyển)            │  │
              └──────┬───────────────┘  │
                     │                  │
                     ▼                  │
         ┌───────────────────────┐     │
         │   Kiểm tra bàn phím?  │     │
         └───┬───────────────┬───┘     │
             │               │         │
          Có │               │Không    │
             │               │         │
             ▼               ▼         │
    ┌──────────────┐  ┌──────────────┐ │
    │ Xử lý Input: │  │              │ │
    │ - Di chuyển  │  │              │ │
    │ - Xoay       │  │              │ │
    │ - Thoát      │  │              │ │
    └──────┬───────┘  └──────┬───────┘ │
           │                 │         │
           └────────┬────────┘         │
                    │                  │
                    ▼                  │
         ┌───────────────────────┐     │
         │  Có thể rơi xuống?    │     │
         └───┬───────────────┬───┘     │
             │               │         │
          Có │               │Không    │
             │               │         │
             ▼               ▼         │
    ┌──────────────┐  ┌──────────────┐ │
    │  Di chuyển   │  │ Block đã     │ │
    │  xuống       │  │ chạm đáy:   │ │
    │              │  │ - Khóa block│ │
    │              │  │ - Kiểm tra  │ │
    │              │  │   dòng      │ │
    │              │  │ - Xóa dòng │ │
    │              │  │   đầy      │ │
    │              │  │ - Cập nhật │ │
    │              │  │   tốc độ   │ │
    │              │  │ - Block mới │ │
    └──────┬───────┘  └──────┬───────┘ │
           │                 │         │
           └────────┬────────┘         │
                    │                  │
                    ▼                  │
         ┌───────────────────────┐     │
         │  Vẽ block lên bàn    │     │
         │  chơi                │     │
         └──────┬────────────────┘     │
                │                      │
                ▼                      │
         ┌───────────────────────┐     │
         │  Hiển thị màn hình   │     │
         │  (Render)            │     │
         └──────┬────────────────┘     │
                │                      │
                ▼                      │
         ┌───────────────────────┐     │
         │  Tạm dừng             │     │
         │  (fallDelay ms)       │     │
         └──────┬────────────────┘     │
                │                      │
                └──────────────────────┘
```

### 5.2. Sơ đồ xử lý xoay block (Đa hình)

```
                    ┌─────────────┐
                    │ Người chơi  │
                    │ nhấn 'w'    │
                    │ hoặc 'r'    │
                    └──────┬──────┘
                           │
                           ▼
                    ┌─────────────┐
                    │rotateBlock()│
                    └──────┬──────┘
                           │
                           ▼
         ┌─────────────────────────────┐
         │ currentBlock tồn tại?       │
         │ canRotate()?                │
         └───┬─────────────────────┬───┘
             │                     │
          Không│                   │Có
             │                     │
             ▼                     ▼
    ┌──────────────┐      ┌──────────────┐
    │   Thoát      │      │canRotateBlock│
    │              │      │() - Kiểm tra │
    │              │      │vị trí sau   │
    │              │      │xoay hợp lệ?  │
    └──────────────┘      └──────┬───────┘
                                 │
                                 ▼
                    ┌─────────────────────┐
                    │  Vị trí hợp lệ?     │
                    └───┬─────────────┬───┘
                        │             │
                     Không│           │Có
                        │             │
                        ▼             ▼
               ┌──────────────┐  ┌──────────────┐
               │   Thoát      │  │ ĐA HÌNH:    │
               │              │  │ currentBlock│
               │              │  │ ->rotate()  │
               │              │  │             │
               │              │  │ Mỗi loại    │
               │              │  │ block có    │
               │              │  │ logic xoay  │
               │              │  │ riêng       │
               └──────────────┘  └──────────────┘
```

### 5.3. Sơ đồ xóa dòng

```
                    ┌─────────────┐
                    │removeLine() │
                    └──────┬──────┘
                           │
                           ▼
                    ┌─────────────┐
                    │ Vòng lặp từ │
                    │ dưới lên    │
                    │ (i = H-2    │
                    │  đến 1)     │
                    └──────┬──────┘
                           │
                           ▼
                    ┌─────────────┐
                    │ Dòng i đầy? │
                    └───┬─────┬───┘
                        │     │
                     Có │     │Không
                        │     │
                        ▼     ▼
              ┌──────────────┐  │
              │ removed++   │  │
              │              │  │
              │ Dịch chuyển  │  │
              │ tất cả dòng  │  │
              │ phía trên    │  │
              │ xuống 1      │  │
              │              │  │
              │ Xóa dòng     │  │
              │ trên cùng    │  │
              │              │  │
              │ i++ (kiểm    │  │
              │ tra lại dòng │  │
              │ i)           │  │
              └──────┬───────┘  │
                     │          │
                     └──────┬───┘
                            │
                            ▼
                    ┌─────────────┐
                    │ Trả về số   │
                    │ dòng đã xóa │
                    │ (removed)   │
                    └─────────────┘
```

---

## 6. SƠ ĐỒ CLASS (CLASS DIAGRAM)

```
                    ┌─────────────────────┐
                    │      Blocks         │
                    │  (Abstract Class)    │
                    ├─────────────────────┤
                    │ - shape[4][4]       │
                    │ - rotationState     │
                    ├─────────────────────┤
                    │ + getCell()         │
                    │ + rotate() = 0      │◄─── Virtual
                    │ + canRotate()       │
                    └──────────┬──────────┘
                               │
                ┌──────────────┼──────────────┐
                │              │              │
                ▼              ▼              ▼
        ┌───────────┐  ┌───────────┐  ┌───────────┐
        │  IBlock   │  │  OBlock   │  │  TBlock   │
        ├───────────┤  ├───────────┤  ├───────────┤
        │ +rotate() │  │ +rotate() │  │ +rotate() │
        │ (2 states)│  │ (no rot)  │  │ (4 states)│
        └───────────┘  └───────────┘  └───────────┘
                │              │              │
                └──────────────┼──────────────┘
                               │
                ┌──────────────┼──────────────┐
                │              │              │
                ▼              ▼              ▼
        ┌───────────┐  ┌───────────┐  ┌───────────┐
        │  SBlock    │  │  ZBlock    │  │  JBlock   │
        ├───────────┤  ├───────────┤  ├───────────┤
        │ +rotate() │  │ +rotate() │  │ +rotate() │
        │ (2 states)│  │ (2 states)│  │ (4 states)│
        └───────────┘  └───────────┘  └───────────┘
                               │
                               ▼
                        ┌───────────┐
                        │  LBlock   │
                        ├───────────┤
                        │ +rotate() │
                        │ (4 states)│
                        └───────────┘

                    ┌─────────────────────┐
                    │   createBlock()     │
                    │  (Factory Function)  │
                    ├─────────────────────┤
                    │ + createBlock(type) │
                    │   Returns Blocks*  │
                    └─────────────────────┘
```

---

## 7. THUẬT TOÁN CHÍNH

### 7.1. Thuật toán xoay block (Rotation Algorithm)

**Cho các block xoay 90 độ (T, S, Z, J, L)**:
```
Ma trận xoay 90° theo chiều kim đồng hồ:
new[i][j] = old[3-j][i]

Ví dụ với ma trận 4x4:
[0][0] [0][1] [0][2] [0][3]      [3][0] [2][0] [1][0] [0][0]
[1][0] [1][1] [1][2] [1][3]  →   [3][1] [2][1] [1][1] [0][1]
[2][0] [2][1] [2][2] [2][3]      [3][2] [2][2] [1][2] [0][2]
[3][0] [3][1] [3][2] [3][3]      [3][3] [2][3] [1][3] [0][3]
```

**Cho IBlock (đặc biệt)**:
- Chỉ có 2 trạng thái: dọc ↔ ngang
- Logic riêng: xóa và vẽ lại shape

### 7.2. Thuật toán kiểm tra va chạm

```cpp
bool canMove(int dx, int dy) {
    for mỗi ô (i, j) trong shape[4][4]:
        if shape[i][j] != ' ':
            xt = x + j + dx
            yt = y + i + dy
            if (xt < 1 || xt >= W-1 || yt >= H-1):
                return false  // Vượt biên
            if (board[yt][xt] != ' '):
                return false  // Va chạm với block khác
    return true
}
```

### 7.3. Thuật toán xóa dòng

```cpp
int removeLine() {
    removed = 0
    for i từ H-2 xuống 1:
        if dòng i đầy:
            removed++
            // Dịch chuyển tất cả dòng phía trên xuống
            for r từ i xuống 2:
                board[r] = board[r-1]
            // Xóa dòng trên cùng
            board[1] = ' ' (toàn bộ)
            i++  // Kiểm tra lại dòng i (vì đã dịch xuống)
    return removed
}
```

### 7.4. Thuật toán cập nhật tốc độ

```cpp
void updateSpeed(int linesRemoved) {
    totalLines += linesRemoved
    level = totalLines / LINES_PER_LEVEL + 1
    fallDelay = BASE_DELAY - (level - 1) * SPEED_STEP
    if (fallDelay < MIN_DELAY):
        fallDelay = MIN_DELAY
}
```

**Ví dụ**:
- Level 1: `fallDelay = 1000ms`
- Level 2: `fallDelay = 960ms` (sau 5 dòng)
- Level 3: `fallDelay = 920ms` (sau 10 dòng)
- ...
- Level 24: `fallDelay = 100ms` (tối đa)

---

## 8. TÍNH NĂNG ĐẶC BIỆT

### 8.1. Polymorphism (Đa hình)

**Ưu điểm**:
- Mỗi loại block tự quản lý logic xoay riêng
- Dễ mở rộng: thêm block mới chỉ cần tạo class mới
- Code sạch, dễ bảo trì

**Ví dụ sử dụng**:
```cpp
Blocks* block = createBlock(2);  // Tạo TBlock
block->rotate();  // Gọi rotate() của TBlock, không phải Blocks
```

### 8.2. Factory Pattern

Hàm `createBlock()` đóng vai trò Factory:
- Tạo object dựa trên type
- Ẩn chi tiết khởi tạo
- Dễ thêm block mới

### 8.3. Cross-platform Support

- **Windows**: `main.cpp` với `conio.h`
- **macOS/Linux**: `main-macos.cpp` với `termios.h`
- Cùng logic game, chỉ khác input/output

---

## 9. ĐIỂM MẠNH VÀ HẠN CHẾ

### 9.1. Điểm mạnh
✅ Sử dụng OOP với polymorphism  
✅ Code được tổ chức rõ ràng (tách file)  
✅ Hỗ trợ đa nền tảng  
✅ Dễ mở rộng (thêm block mới)  
✅ Logic game hoàn chỉnh (di chuyển, xoay, xóa dòng, tăng tốc)  

### 9.2. Hạn chế và cải tiến có thể
⚠️ Chưa có hệ thống điểm số  
⚠️ Chưa có preview block tiếp theo  
⚠️ Chưa có hold block  
⚠️ Chưa có game over detection  
⚠️ Chưa có high score  
⚠️ Chưa có âm thanh  

---

## 10. HƯỚNG DẪN BIÊN DỊCH VÀ CHẠY

### 10.1. Windows
```bash
g++ main.cpp -o tetris.exe
./tetris.exe
```

### 10.2. macOS/Linux
```bash
g++ main-macos.cpp -o tetris -std=c++11
./tetris
```

### 10.3. Yêu cầu
- Compiler hỗ trợ C++11 trở lên
- Windows: cần `conio.h` và `windows.h`
- macOS/Linux: cần `termios.h` và `unistd.h`

---

## 11. KẾT LUẬN

Trò chơi Tetris này được xây dựng với:
- **Kiến trúc OOP** sử dụng polymorphism
- **Design Pattern**: Factory Pattern
- **Cấu trúc code** rõ ràng, dễ bảo trì
- **Cross-platform** support

Code minh họa tốt các khái niệm:
- Inheritance (Kế thừa)
- Polymorphism (Đa hình)
- Virtual functions
- Factory Pattern
- Memory management (new/delete)

---

**Tác giả**: SS004-Tetris-Game Team  
**Ngày**: 2024  
**Phiên bản**: 1.0

