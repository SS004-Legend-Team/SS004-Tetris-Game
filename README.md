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

Đây là một phiên bản Tetris cổ điển được triển khai bằng C++ thuần, chạy trên terminal/console. Game sử dụng các thư viện POSIX để xử lý input không đồng bộ và tương thích với nhiều hệ điều hành.

> 📖 Để biết thêm về cách chơi và chiến lược, xem file [INTRODUCE.md](./INTRODUCE.md)

## ✨ Tính năng

### Đã triển khai
- ✅ 7 loại khối Tetrominoes (I, O, T, S, Z, J, L)
- ✅ Di chuyển khối trái/phải
- ✅ Khối tự động rơi xuống
- ✅ Kiểm tra va chạm và biên
- ✅ Vẽ board game với khung viền
- ✅ Hỗ trợ đa nền tảng (macOS, Linux)
- ✅ Input không đồng bộ (non-blocking input)

### Đang phát triển
- 🔄 Xóa hàng khi đầy (hiện tại đang TODO)
- 🔄 Xoay khối
- 🔄 Hệ thống điểm số
- 🔄 Cấp độ và tăng tốc độ
- 🔄 Game Over detection
- 🔄 Hiển thị khối tiếp theo (Next Piece)
- 🔄 Lưu điểm cao nhất

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

```bash
# Di chuyển vào thư mục dự án
cd SS004-Tetris-Game

# Biên dịch
g++ -o tetris main.cpp -std=c++11

# Hoặc với Clang
clang++ -o tetris main.cpp -std=c++11
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
| `s` | Rơi nhanh (hard drop) |
| `q` | Thoát game |

> ⚠️ **Lưu ý**: Hiện tại chưa có tính năng xoay khối. Tính năng này đang được phát triển.

## 📁 Cấu trúc dự án

```
SS004-Tetris-Game/
├── main.cpp              # File source code chính
├── main-window.cpp       # File source code cho phiên bản GUI (nếu có)
├── README.md            # File này - hướng dẫn kỹ thuật
├── INTRODUCE.md         # Hướng dẫn chơi game và chiến lược
└── tetris               # File executable (sau khi biên dịch)
```

## 🏗️ Kiến trúc và Công nghệ

### Cấu trúc code

#### 1. **Biến toàn cục**
```cpp
char board[H][W]     // Board game 20x15
int x, y             // Vị trí hiện tại của khối
int b                // Chỉ số khối hiện tại
char blocks[][4][4]  // Mảng chứa các khối Tetrominoes
```

#### 2. **Hàm chính**

- `kbhit()`: Kiểm tra xem có phím được nhấn không (non-blocking)
- `getch()`: Lấy ký tự từ bàn phím (không cần Enter)
- `canMove(dx, dy)`: Kiểm tra khối có thể di chuyển không
- `block2Board()`: Vẽ khối lên board
- `boardDelBlock()`: Xóa khối khỏi board
- `initBoard()`: Khởi tạo board với khung viền
- `draw()`: Vẽ board ra màn hình
- `removeLine()`: Xóa hàng đầy (đang TODO)

#### 3. **Cross-platform Support**

Code sử dụng các thư viện POSIX để đảm bảo tương thích:
- `<termios.h>`: Điều khiển terminal
- `<unistd.h>`: POSIX system calls
- `<fcntl.h>`: File control

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

2. **Hệ thống Khối**
   - 7 loại khối Tetrominoes
   - Khối tự động rơi xuống
   - Random khối mới

3. **Di chuyển**
   - Di chuyển trái/phải
   - Kiểm tra va chạm với biên và khối khác
   - Hard drop (rơi nhanh)

4. **Input System**
   - Non-blocking keyboard input
   - Cross-platform support (macOS/Linux)

5. **Rendering**
   - Clear screen và vẽ lại board
   - Hiển thị khối đang rơi

## 🔨 Tính năng đang phát triển

### 🔄 Cần hoàn thiện

1. **Xóa hàng** (`removeLine()`)
   - Phát hiện hàng đầy
   - Xóa hàng và rơi các khối phía trên xuống
   - Animation khi xóa hàng

2. **Xoay khối**
   - Implement rotation logic
   - Kiểm tra va chạm khi xoay
   - Wall kick (nếu cần)

3. **Hệ thống điểm số**
   - Tính điểm khi xóa hàng
   - Hiển thị điểm trên màn hình
   - Lưu điểm cao nhất

4. **Game Over**
   - Phát hiện khi board đầy
   - Hiển thị màn hình Game Over
   - Option chơi lại

5. **Cải thiện UI**
   - Hiển thị Next Piece
   - Hiển thị điểm số, cấp độ
   - Hiển thị số hàng đã xóa

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

- [ ] Hoàn thiện hàm `removeLine()`
- [ ] Cải thiện UI/UX (đổi giao diện viền và khối)
- [ ] Tính năng xoay khối
- [ ] Thêm hệ thống điểm số
- [ ] Thêm Game Over screen
- [ ] Thêm âm thanh
- [ ] Thêm màu sắc cho các khối
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
- **Cấu trúc code**: Xem comments trong `main.cpp`

---

*"Tetris không chỉ là một trò chơi, mà là một nghệ thuật của sự sắp xếp và chiến lược!"* 🎮
