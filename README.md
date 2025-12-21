# 🎮 SS004 - Tetris Game

Dự án game Tetris được phát triển bằng C++ với giao diện console, hỗ trợ đa nền tảng (macOS, Linux, Windows).

## 📋 Mục lục

- [Giới thiệu](#giới-thiệu)
- [Tính năng](#tính-năng)
- [Yêu cầu hệ thống](#yêu-cầu-hệ-thống)
- [Cài đặt và Biên dịch](#cài-đặt-và-biên-dịch)
- [Cách chạy](#cách-chạy)
- [Điều khiển](#điều-khiển)
- [Cấu trúc dự án](#cấu-trúc-dự-án)
- [Kiến trúc và Công nghệ](#kiến-trúc-và-công-nghệ)
- [Tính năng đã triển khai](#tính-năng-đã-triển-khai)
- [Tính năng đang phát triển](#tính-năng-đang-phát-triển)
- [Troubleshooting](#troubleshooting)
- [Đóng góp](#đóng-góp)
- [Tài liệu tham khảo](#tài-liệu-tham-khảo)

## 🎯 Giới thiệu

**SS004 - Tetris Game** là một dự án game Tetris cổ điển được phát triển bằng ngôn ngữ lập trình C++, chạy trên giao diện console/terminal. Dự án được thiết kế với mục tiêu áp dụng các nguyên lý lập trình hướng đối tượng (OOP), đặc biệt là tính đa hình (polymorphism) và kế thừa (inheritance) trong việc quản lý các khối Tetrominoes.

### Mục tiêu dự án

Dự án nhằm mục đích:
- **Thực hành OOP**: Áp dụng các khái niệm class, inheritance, polymorphism trong C++
- **Xây dựng game console**: Phát triển một game hoàn chỉnh với giao diện text-based
- **Cross-platform development**: Hỗ trợ đa nền tảng (macOS, Linux, Windows)
- **Tối ưu hóa hiệu năng**: Xử lý input không đồng bộ và tối ưu vòng lặp game

### Đặc điểm kỹ thuật

- **Ngôn ngữ**: C++11 trở lên
- **Kiến trúc**: Object-Oriented Programming với base class `Blocks` và các derived classes
- **Design Pattern**: Factory Pattern để tạo các loại block khác nhau
- **Input Handling**: Non-blocking keyboard input sử dụng POSIX APIs (macOS/Linux) và Windows APIs
- **Game Loop**: Vòng lặp game được tối ưu với timing chính xác và phản hồi input nhanh

### Tính năng nổi bật

Game hỗ trợ đầy đủ 7 loại khối Tetrominoes chuẩn (I, O, T, S, Z, J, L) với khả năng xoay và di chuyển. Mỗi loại khối được triển khai như một class riêng biệt kế thừa từ class `Blocks` cơ sở, cho phép mỗi khối có logic xoay riêng phù hợp với đặc tính của nó (ví dụ: I-block có 2 trạng thái xoay, O-block không xoay, các block khác có 4 trạng thái).

> 📖 Để biết thêm về cách chơi và chiến lược, xem file [INTRODUCE.md](./INTRODUCE.md)

## ✨ Tính năng

### Đã triển khai
- ✅ 7 loại khối Tetrominoes (I, O, T, S, Z, J, L)
- ✅ Di chuyển khối trái/phải
- ✅ Khối tự động rơi xuống với tốc độ tăng dần
- ✅ Kiểm tra va chạm và biên
- ✅ Vẽ board game với khung viền
- ✅ Hỗ trợ đa nền tảng (macOS, Linux, Windows)
- ✅ Input không đồng bộ (non-blocking input) với tối ưu phản hồi
- ✅ **Xoay khối** (phím `w` hoặc `r`) - sử dụng polymorphism
- ✅ **Xóa hàng khi đầy** - tự động xóa và rơi các khối phía trên
- ✅ **Hệ thống Level** - tăng level mỗi 5 dòng xóa
- ✅ **Tăng tốc độ** - tốc độ rơi tăng dần theo level
- ✅ **Hard Drop** (phím `s`) - rơi nhanh xuống vị trí thấp nhất
- ✅ **Game Over detection** - phát hiện khi board đầy
- ✅ **Màn hình Game Over** - hiển thị level và tổng số dòng đã xóa
- ✅ **Object-Oriented Design** - sử dụng polymorphism với class Blocks

### Đang phát triển
- 🔄 Hiển thị khối tiếp theo (Next Piece)
- 🔄 Hệ thống điểm số chi tiết
- 🔄 Lưu điểm cao nhất (High Score)
- 🔄 Animation khi xóa hàng
- 🔄 Màu sắc cho các khối

## 💻 Yêu cầu hệ thống

### Hệ điều hành
- macOS 10.12 trở lên
- Linux (hầu hết các distribution)
- Windows (cần chỉnh sửa code để sử dụng `conio.h` hoặc thư viện tương đương)

### Công cụ phát triển
- **Compiler**: GCC 4.8+ hoặc Clang 3.3+ (hỗ trợ C++11)
- **Make** (tùy chọn, để sử dụng Makefile)

## 🔧 Cài đặt và Biên dịch

### Cách 1: Biên dịch trực tiếp

**Cho macOS/Linux:**
```bash
# Di chuyển vào thư mục dự án
cd SS004-Tetris-Game

# Biên dịch
g++ -o tetris main-macos.cpp -std=c++11

# Hoặc với Clang
clang++ -o tetris main-macos.cpp -std=c++11
```

**Cho Windows:**
```bash
# Biên dịch với MinGW hoặc MSVC
g++ -o tetris.exe main.cpp -std=c++11

# Hoặc với MSVC
cl main.cpp /EHsc /Fe:tetris.exe
```

### Cách 2: Sử dụng Makefile (nếu có)

```bash
make
```

### Cách 3: Biên dịch với các tùy chọn tối ưu

```bash
g++ -o tetris main.cpp -std=c++11 -O2 -Wall
```

**Giải thích các flag:**
- `-std=c++11`: Sử dụng chuẩn C++11
- `-O2`: Tối ưu hóa code
- `-Wall`: Hiển thị tất cả cảnh báo

## 🚀 Cách chạy

Sau khi biên dịch thành công, chạy game bằng lệnh:

```bash
./tetris
```

**Lưu ý:** Game cần chạy trong terminal/console để hoạt động đúng. Không chạy trong IDE terminal nếu IDE không hỗ trợ input không đồng bộ.

## 🎮 Điều khiển

| Phím | Hành động |
|------|-----------|
| `a` | Di chuyển khối sang trái |
| `d` | Di chuyển khối sang phải |
| `x` | Rơi xuống 1 ô (soft drop) |
| `s` | Rơi nhanh xuống vị trí thấp nhất (hard drop) |
| `w` hoặc `r` | Xoay khối (90 độ theo chiều kim đồng hồ) |
| `q` | Thoát game |

> 💡 **Mẹo**: Sử dụng `s` để rơi nhanh và `w`/`r` để xoay khối vào vị trí tối ưu!

## 📁 Cấu trúc dự án

```
SS004-Tetris-Game/
├── main.cpp              # File source code cho Windows
├── main-macos.cpp        # File source code cho macOS/Linux
├── Blocks.h              # Header file chứa class Blocks và các derived classes
├── blocks.h              # Alias cho Blocks.h (tương thích)
├── README.md            # File này - hướng dẫn kỹ thuật
├── INTRODUCE.md         # Hướng dẫn chơi game và chiến lược
├── DOCUMENTATION.tex     # Tài liệu kỹ thuật LaTeX
├── DOCUMENTATION.md      # Tài liệu kỹ thuật Markdown
├── TECHNICAL_DOCUMENTATION.tex  # Tài liệu kỹ thuật chi tiết (LaTeX)
├── TECHNICAL_DOCUMENTATION.md   # Tài liệu kỹ thuật chi tiết (Markdown)
└── tetris               # File executable (sau khi biên dịch)
```

## 🏗️ Kiến trúc và Công nghệ

### Cấu trúc code

#### 1. **Biến toàn cục**
```cpp
char board[H][W]              // Board game 20x15
int x, y                      // Vị trí hiện tại của khối
Blocks* currentBlock          // Con trỏ đến block hiện tại (polymorphism)
int level                     // Level hiện tại
int totalLines                // Tổng số dòng đã xóa
int fallDelay                 // Tốc độ rơi hiện tại (ms)
```

#### 2. **Hàm chính**

**Input & Control:**
- `kbhit()`: Kiểm tra xem có phím được nhấn không (non-blocking)
- `getch()`: Lấy ký tự từ bàn phím (không cần Enter)

**Game Logic:**
- `canMove(dx, dy)`: Kiểm tra khối có thể di chuyển không
- `block2Board()`: Vẽ khối lên board
- `boardDelBlock()`: Xóa khối khỏi board
- `initBoard()`: Khởi tạo board với khung viền
- `removeLine()`: Xóa hàng đầy và trả về số dòng đã xóa
- `updateSpeed(linesRemoved)`: Cập nhật level và tốc độ rơi
- `canRotateBlock()`: Kiểm tra có thể xoay block không
- `rotateBlock()`: Xoay block sử dụng polymorphism
- `hardDrop()`: Rơi nhanh block xuống vị trí thấp nhất
- `isGameOver()`: Kiểm tra điều kiện game over
- `drawGameOver()`: Hiển thị màn hình game over

**Rendering:**
- `draw()`: Vẽ board ra màn hình với thông tin level, lines, delay

#### 3. **Object-Oriented Design**

Game sử dụng **polymorphism** với class `Blocks`:

```cpp
// Base class
class Blocks {
    virtual void rotate() = 0;  // Pure virtual - mỗi block xoay khác nhau
    virtual bool canRotate() const;
    char getCell(int i, int j) const;
};

// Derived classes
class IBlock : public Blocks { ... };  // 2 trạng thái xoay
class OBlock : public Blocks { ... };  // Không xoay
class TBlock : public Blocks { ... };  // 4 trạng thái xoay
// ... và các block khác
```

**Factory Pattern:**
- `createBlock(int type)`: Tạo instance của block type tương ứng

#### 4. **Cross-platform Support**

**macOS/Linux (`main-macos.cpp`):**
- `<termios.h>`: Điều khiển terminal
- `<unistd.h>`: POSIX system calls
- `<fcntl.h>`: File control
- `<thread>` và `<chrono>`: Sleep và timing

**Windows (`main.cpp`):**
- `<conio.h>`: Console I/O (`_kbhit()`, `_getch()`)
- `<windows.h>`: Windows API (`Sleep()`)

### Các khối Tetrominoes

Game hỗ trợ 7 loại khối chuẩn của Tetris:

1. **I-Block**: Khối thẳng (4 ô)
2. **O-Block**: Khối vuông (2x2)
3. **T-Block**: Khối chữ T
4. **S-Block**: Khối chữ S
5. **Z-Block**: Khối chữ Z
6. **J-Block**: Khối chữ J
7. **L-Block**: Khối chữ L

## 📝 Tính năng đã triển khai

### ✅ Hoàn thành

1. **Hệ thống Board**
   - Board 20x15 với khung viền
   - Vẽ và cập nhật board real-time
   - Hiển thị level, tổng số dòng, và tốc độ rơi

2. **Hệ thống Khối (Polymorphism)**
   - 7 loại khối Tetrominoes (I, O, T, S, Z, J, L)
   - Sử dụng class `Blocks` với virtual methods
   - Mỗi block có logic xoay riêng (I-block: 2 trạng thái, O-block: không xoay, các block khác: 4 trạng thái)
   - Factory pattern để tạo block: `createBlock(int type)`
   - Khối tự động rơi xuống với tốc độ tăng dần

3. **Di chuyển và Xoay**
   - Di chuyển trái/phải (`a`/`d`)
   - Soft drop (`x`) - rơi xuống 1 ô
   - Hard drop (`s`) - rơi nhanh xuống vị trí thấp nhất
   - Xoay khối (`w`/`r`) - sử dụng polymorphism
   - Kiểm tra va chạm với biên và khối khác
   - Kiểm tra va chạm khi xoay

4. **Hệ thống Level và Tốc độ**
   - Level tăng mỗi 5 dòng xóa (`LINES_PER_LEVEL = 5`)
   - Tốc độ rơi ban đầu: 1000ms (`BASE_DELAY`)
   - Tốc độ rơi giảm 40ms mỗi level (`SPEED_STEP`)
   - Tốc độ tối thiểu: 100ms (`MIN_DELAY`)

5. **Xóa Hàng**
   - Tự động phát hiện hàng đầy
   - Xóa hàng và rơi các khối phía trên xuống
   - Cập nhật level và tốc độ sau khi xóa

6. **Game Over**
   - Phát hiện khi block mới không thể spawn
   - Phát hiện khi board đầy đến hàng đầu tiên
   - Hiển thị màn hình game over với level và tổng số dòng
   - Đợi người dùng nhấn phím trước khi thoát

7. **Input System**
   - Non-blocking keyboard input
   - Tối ưu phản hồi: kiểm tra input mỗi 50ms (`INPUT_CHECK_INTERVAL`)
   - Cross-platform support (macOS/Linux/Windows)

8. **Rendering**
   - Clear screen và vẽ lại board
   - Hiển thị khối đang rơi
   - Hiển thị thông tin game (level, lines, delay)

## 🔨 Tính năng đang phát triển

### 🔄 Cần hoàn thiện

1. **Hệ thống điểm số chi tiết**
   - Tính điểm dựa trên số dòng xóa (1 line = 100, 2 lines = 300, 3 lines = 500, 4 lines = 800)
   - Bonus điểm cho hard drop
   - Hiển thị điểm trên màn hình
   - Lưu điểm cao nhất (High Score)

2. **Cải thiện UI/UX**
   - Hiển thị Next Piece (khối tiếp theo)
   - Màu sắc cho các khối (ANSI colors hoặc Windows colors)
   - Animation khi xóa hàng
   - Hiển thị điểm số chi tiết

3. **Tính năng nâng cao**
   - Wall kick khi xoay (nếu block không thể xoay ở vị trí hiện tại, thử di chuyển sang trái/phải)
   - Hold piece (giữ khối để dùng sau)
   - Ghost piece (hiển thị vị trí block sẽ rơi đến)
   - Sound effects
   - Pause game

4. **Tối ưu hóa**
   - Tối ưu rendering performance
   - Giảm memory usage
   - Cải thiện input handling

## 🐛 Troubleshooting

### Lỗi: "conio.h: No such file or directory"
**Giải pháp**: Code đã được cập nhật để không sử dụng `conio.h`. Nếu vẫn gặp lỗi, đảm bảo bạn đang sử dụng phiên bản mới nhất của `main.cpp`.

### Game không phản hồi khi nhấn phím
**Nguyên nhân**: Terminal không hỗ trợ non-blocking input.
**Giải pháp**: 
- Chạy game trong terminal thật (Terminal.app trên macOS, Terminal trên Linux)
- Không chạy trong IDE terminal

### Màn hình không clear khi vẽ
**Giải pháp**: Đảm bảo terminal hỗ trợ ANSI escape codes hoặc lệnh `clear`.

### Compile error trên Windows
**Giải pháp**: 
- Sử dụng MinGW hoặc MSVC với thư viện tương đương
- Hoặc sử dụng WSL (Windows Subsystem for Linux)

## 🤝 Đóng góp

Mọi đóng góp đều được chào đón! Để đóng góp:

1. Fork dự án
2. Tạo branch mới (`git checkout -b feature/AmazingFeature`)
3. Commit thay đổi (`git commit -m 'Add some AmazingFeature'`)
4. Push lên branch (`git push origin feature/AmazingFeature`)
5. Mở Pull Request

### Các tính năng cần đóng góp

- [x] Hoàn thiện hàm `removeLine()` ✅
- [x] Tính năng xoay khối với polymorphism ✅
- [x] Thêm Game Over screen ✅
- [x] Hệ thống level và tăng tốc độ ✅
- [ ] Thêm hệ thống điểm số chi tiết
- [ ] Cải thiện UI/UX (màu sắc, animation)
- [ ] Hiển thị Next Piece
- [ ] Thêm âm thanh
- [ ] Wall kick khi xoay
- [ ] Hold piece
- [ ] Ghost piece
- [ ] Tối ưu hóa performance

## 📚 Tài liệu tham khảo

- [Tetris Guideline](http://tetris.wiki/Tetris_Guideline) - Tiêu chuẩn chính thức của Tetris
- [C++ Reference](https://en.cppreference.com/) - Tài liệu C++
- [POSIX Terminal Interface](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/termios.h.html)

## 📄 License

Dự án này được phát triển cho mục đích giáo dục.

## 👥 Tác giả

**SS004 Legend Team**

- Phiên bản: SS004
- Năm: 2025

---

## 📖 Tài liệu bổ sung

Để biết thêm về:
- **Cách chơi và chiến lược**: Xem [INTRODUCE.md](./INTRODUCE.md)
- **Cấu trúc code**: Xem comments trong `main-macos.cpp` hoặc `main.cpp`
- **Tài liệu kỹ thuật chi tiết**: Xem [TECHNICAL_DOCUMENTATION.md](./TECHNICAL_DOCUMENTATION.md) hoặc [TECHNICAL_DOCUMENTATION.tex](./TECHNICAL_DOCUMENTATION.tex)
- **Tài liệu dự án đầy đủ**: Xem [DOCUMENTATION.md](./DOCUMENTATION.md) hoặc [DOCUMENTATION.tex](./DOCUMENTATION.tex)
- **Kiến trúc OOP**: Xem file [Blocks.h](./Blocks.h) để hiểu về polymorphism và design pattern

---

*"Tetris không chỉ là một trò chơi, mà là một nghệ thuật của sự sắp xếp và chiến lược!"* 🎮
