#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <string>
#include "blocks.h"

using namespace std;
#define H 20
#define W 15
#define MIN_DELAY 100
#define BASE_DELAY 1000
#define SPEED_STEP 40
#define LINES_PER_LEVEL 5
#define CELL_EMPTY "  "
#define CELL_BLOCK "[]"
#define INPUT_CHECK_INTERVAL 10

char board[H][W] = {};

int level = 1;
int totalLines = 0;
int fallDelay = BASE_DELAY;

int x, y;

// Con trỏ đến block hiện tại
Blocks* currentBlock = nullptr;
bool canMove(int dx, int dy) {
  if (!currentBlock) return false;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (currentBlock->getCell(i, j) != ' ') {
        int xt = x + j + dx;
        int yt = y + i + dy;
        if (xt < 1 || xt >= W - 1 || yt >= H - 1)
          return false;
        if (board[yt][xt] != ' ')
          return false;
      }
  return true;
}
void block2Board() {
  if (!currentBlock) return;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (currentBlock->getCell(i, j) != ' ')
        board[y + i][x + j] = currentBlock->getCell(i, j);
}
void boardDelBlock() {
  if (!currentBlock) return;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (currentBlock->getCell(i, j) != ' ')
        board[y + i][x + j] = ' ';
}
void initBoard() {
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      board[i][j] = ' ';
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void draw() {
  gotoxy(0, 0);

  const int playW = W - 2;
  const int playH = H - 1;

  // Top border
  cout << "+" << std::string(playW * 2 + 2, '-') << "+\n";

  for (int i = 0; i < playH; i++) {
    cout << "|+";
    for (int j = 1; j <= W - 2; j++) {
      if (board[i][j] == ' ')
        cout << CELL_EMPTY;
      else
        cout << CELL_BLOCK;
    }
    cout << "+|\n";
  }

  // Bottom border
  cout << "+" << std::string(playW * 2 + 2, '-') << "+\n";

  cout << "Level: " << level
       << " | Lines: " << totalLines
       << " | Delay: " << fallDelay << "ms\n";
}

/**
 * Xóa line
 * @return số line đã xóa
 */
int removeLine();

/**
 * Cập nhật tốc độ block rơi sau khi xóa line
 * @param linesRemoved số line đã xóa
 */
void updateSpeed(int linesRemoved);

/**
 * Kiểm tra có thể xoay block hiện tại không
 */
bool canRotateBlock();

/**
 * Xoay block sử dụng polymorphism
 */
void rotateBlock();

/**
 * Tạo block mới dựa trên type
 */
Blocks* createBlock(int type);

/**
 * Rơi nhanh block xuống vị trí thấp nhất có thể
 */
void hardDrop();

/**
 * Kiểm tra xem game có kết thúc không (block chạm đường trên)
 */
bool isGameOver();

/**
 * Hiển thị màn hình Game Over
 */
void drawGameOver();

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Thiết lập trạng thái ẩn
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

int main() {
    hideCursor();
  srand(time(0));
  x = 5;
  y = 0;
  currentBlock = createBlock(rand() % 7);
  initBoard();

  int elapsedTime = 0;  // Thời gian đã trôi qua trong chu kỳ hiện tại

  while (1) {
    boardDelBlock();

    // Kiểm tra input liên tục với delay ngắn để phản hồi nhanh
    int remainingTime = fallDelay - elapsedTime;
    int sleepTime = (remainingTime > INPUT_CHECK_INTERVAL) ? INPUT_CHECK_INTERVAL : (remainingTime > 0 ? remainingTime : 0);

    if (kbhit()) {
      char c = getch();
      if (c == 'a' && canMove(-1, 0)) {
        x--;
      }
      if (c == 'd' && canMove(1, 0)) {
        x++;
      }
      if (c == 'x' && canMove(0, 1)) {
        y++;
      }
      if (c == 's') {  // Rơi nhanh (hard drop)
        hardDrop();
      }
      if (c == 'w' || c == 'r') {  // Thêm phím xoay
        rotateBlock();
      }
      if (c == 'q')
        break;

      // Vẽ lại sau khi xử lý input
      block2Board();
      draw();
    }

    // Cập nhật thời gian đã trôi qua
    elapsedTime += sleepTime;
    Sleep(sleepTime);

    // Chỉ cho block rơi xuống khi đã hết thời gian fallDelay
    if (elapsedTime >= fallDelay) {
      elapsedTime = 0;  // Reset thời gian cho chu kỳ mới

      boardDelBlock();  // Đảm bảo xóa block trước khi kiểm tra
      if (canMove(0, 1))
        y++;
      else {
        block2Board();
        const int linesRemoved = removeLine();
        updateSpeed(linesRemoved);
        x = 5;
        y = 0;
        delete currentBlock;  // Giải phóng block cũ
        currentBlock = createBlock(rand() % 7);

        // Kiểm tra Game Over sau khi tạo block mới
        if (isGameOver()) {
          block2Board();
          draw();
          drawGameOver();
          break;
        }
      }
      block2Board();
      draw();
    }
  }
  delete currentBlock;  // Giải phóng trước khi kết thúc
  return 0;
}

int removeLine() {
    int removed = 0;

    for (int i = H - 2; i > 0; i--) {
        bool full = true;

        for (int j = 1; j < W - 1; j++) {
            if (board[i][j] == ' ') {
                full = false;
                break;
            }
        }

        if (full) {
            removed++;

            for (int r = i; r > 1; r--) {
                for (int c = 1; c < W - 1; c++) {
                    board[r][c] = board[r - 1][c];
                }
            }

            for (int c = 1; c < W - 1; c++) {
                board[1][c] = ' ';
            }

            i++;
        }
    }

    return removed;
}

void updateSpeed(int linesRemoved) {
    // Cộng dồn tổng số dòng đã xóa từ đầu game
    totalLines += linesRemoved;

    // Tính level hiện tại
    // Ví dụ:
    // 0–4 dòng  -> level 1
    // 5–9 dòng  -> level 2
    // 10–14 dòng -> level 3
    level = totalLines / LINES_PER_LEVEL + 1;

    // Giảm delay để tăng tốc
    fallDelay = BASE_DELAY - (level - 1) * SPEED_STEP;

    // Giới hạn tốc độ tối đa
    if (fallDelay < MIN_DELAY) {
        fallDelay = MIN_DELAY;
    }
}
// Kiểm tra có thể xoay block hiện tại không
bool canRotateBlock() {
    if (!currentBlock) return false;

    // Tạo một bản sao tạm để kiểm tra
    char temp[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            temp[i][j] = currentBlock->getCell(i, j);

    // Xoay tạm thời
    char rotated[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            rotated[i][j] = temp[3 - j][i];

    // Kiểm tra vị trí sau khi xoay
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (rotated[i][j] != ' ') {
                int xt = x + j;
                int yt = y + i;

                if (xt < 1 || xt >= W - 1 || yt < 1 || yt >= H - 1)
                    return false;
                if (board[yt][xt] != ' ')
                    return false;
            }
    return true;
}

// Xoay block sử dụng polymorphism
void rotateBlock() {
    if (!currentBlock || !currentBlock->canRotate()) return;

    if (canRotateBlock()) {
        // Sử dụng virtual method để xoay - đa hình
        currentBlock->rotate();
    }
}

// Rơi nhanh block xuống vị trí thấp nhất có thể
void hardDrop() {
    if (!currentBlock) return;

    boardDelBlock();  // Xóa block khỏi board trước khi tính toán

    // Tìm vị trí thấp nhất mà block có thể rơi đến
    while (canMove(0, 1)) {
        y++;
    }

    // Block đã ở vị trí thấp nhất, khóa block ngay lập tức
    block2Board();
    const int linesRemoved = removeLine();
    updateSpeed(linesRemoved);
    x = 5;
    y = 0;
    delete currentBlock;
    currentBlock = createBlock(rand() % 7);

    // Kiểm tra Game Over sau khi tạo block mới
    if (isGameOver()) {
        block2Board();
        draw();
        drawGameOver();
    }
}

// Kiểm tra xem game có kết thúc không (block chạm đường trên)
bool isGameOver() {
    if (!currentBlock) return false;

    // Block mới được tạo ở y = 0
    // Kiểm tra xem block có chạm vào block đã có trên board không
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (currentBlock->getCell(i, j) != ' ') {
                int xt = x + j;
                int yt = y + i;  // y = 0, nên yt = i (0, 1, 2, 3)

                // Kiểm tra biên ngang
                if (xt < 1 || xt >= W - 1) continue;

                // Nếu block có phần ở hàng chơi (yt >= 1) và chạm vào block đã có
                if (yt >= 1 && yt < H - 1) {
                    if (board[yt][xt] != ' ') {
                        return true;  // Chạm vào block đã có
                    }
                }

                // Nếu block ở hàng đầu tiên (yt = 1) và board đã có block ở đó
                // thì block mới không thể xuất hiện -> game over
                if (yt == 1 && board[1][xt] != ' ') {
                    return true;
                }
            }
        }
    }

    // Kiểm tra thêm: nếu block không thể di chuyển xuống ngay từ đầu
    // (tức là board đã đầy đến hàng đầu tiên)
    if (y == 0 && !canMove(0, 1)) {
        // Kiểm tra xem có block nào ở hàng đầu tiên (y = 1) không
        for (int j = 1; j < W - 1; j++) {
            if (board[1][j] != ' ') {
                return true;  // Board đã đầy đến hàng đầu tiên
            }
        }
    }

    return false;
}

// Hiển thị màn hình Game Over
void drawGameOver() {
    system("cls");

    const int playW = W - 2;
    const int playH = H - 1;

    // Vẽ board với block cuối cùng
    cout << "+" << std::string(playW * 2 + 2, '-') << "+\n";

    for (int i = 0; i < playH; i++) {
        cout << "|+";
        for (int j = 1; j <= W - 2; j++) {
            if (board[i][j] == ' ')
                cout << CELL_EMPTY;
            else
                cout << CELL_BLOCK;
        }
        cout << "+|\n";
    }

    cout << "+" << std::string(playW * 2 + 2, '-') << "+\n";

    // Hiển thị Game Over
    cout << "\n";
    cout << "  ============================\n";
    cout << "        G A M E   O V E R\n";
    cout << "  ============================\n";
    cout << "\n";
    cout << "  Final Level: " << level << "\n";
    cout << "  Total Lines: " << totalLines << "\n";
    cout << "\n";
    cout << "  Press any key to exit...\n";

    // Đợi người dùng nhấn phím
    if (kbhit()) {
        getch();
    }
}
