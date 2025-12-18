#include <conio.h>
#include <iostream>

using namespace std;
#define H 20
#define W 15
#define MIN_DELAY 100
#define BASE_DELAY 1000
#define SPEED_STEP 40
#define LINES_PER_LEVEL 5
#define CELL_EMPTY "  "
#define CELL_BLOCK "[]"

char board[H][W] = {};

int level = 1;
int totalLines = 0;
int fallDelay = BASE_DELAY;

int x, y, b;
char blocks[][4][4] = {{{' ', 'I', ' ', ' '},
                        {' ', 'I', ' ', ' '},
                        {' ', 'I', ' ', ' '},
                        {' ', 'I', ' ', ' '}},
                       {{' ', 'I', ' ', ' '},
                        {' ', 'I', ' ', ' '},
                        {' ', 'I', ' ', ' '},
                        {' ', 'I', ' ', ' '}},
                       {{' ', ' ', ' ', ' '},
                        {' ', 'O', 'O', ' '},
                        {' ', 'O', 'O', ' '},
                        {' ', ' ', ' ', ' '}},
                       {{' ', ' ', ' ', ' '},
                        {' ', 'O', 'O', ' '},
                        {' ', 'O', 'O', ' '},
                        {' ', ' ', ' ', ' '}},
                       {{' ', ' ', ' ', ' '},
                        {' ', 'O', 'O', ' '},
                        {' ', 'O', 'O', ' '},
                        {' ', ' ', ' ', ' '}},
                       {{' ', ' ', ' ', ' '},
                        {' ', 'O', 'O', ' '},
                        {' ', 'O', 'O', ' '},
                        {' ', ' ', ' ', ' '}},
                       {{' ', ' ', ' ', ' '},
                        {' ', 'O', 'O', ' '},
                        {' ', 'O', 'O', ' '},
                        {' ', ' ', ' ', ' '}},
                       {{' ', ' ', ' ', ' '},
                        {' ', 'O', 'O', ' '},
                        {' ', 'O', 'O', ' '},
                        {' ', ' ', ' ', ' '}},
                       {{' ', ' ', ' ', ' '},
                        {' ', 'O', 'O', ' '},
                        {' ', 'O', 'O', ' '},
                        {' ', ' ', ' ', ' '}},
                       {{' ', ' ', ' ', ' '},
                        {'I', 'I', 'I', 'I'},
                        {' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' '}},
                       {{' ', ' ', ' ', ' '},
                        {' ', 'O', 'O', ' '},
                        {' ', 'O', 'O', ' '},
                        {' ', ' ', ' ', ' '}},
                       {{' ', ' ', ' ', ' '},
                        {' ', 'T', ' ', ' '},
                        {'T', 'T', 'T', ' '},
                        {' ', ' ', ' ', ' '}},
                       {{' ', ' ', ' ', ' '},
                        {' ', 'S', 'S', ' '},
                        {'S', 'S', ' ', ' '},
                        {' ', ' ', ' ', ' '}},
                       {{' ', ' ', ' ', ' '},
                        {'Z', 'Z', ' ', ' '},
                        {' ', 'Z', 'Z', ' '},
                        {' ', ' ', ' ', ' '}},
                       {{' ', ' ', ' ', ' '},
                        {'J', ' ', ' ', ' '},
                        {'J', 'J', 'J', ' '},
                        {' ', ' ', ' ', ' '}},
                       {{' ', ' ', ' ', ' '},
                        {' ', ' ', 'L', ' '},
                        {'L', 'L', 'L', ' '},
                        {' ', ' ', ' ', ' '}}};
bool canMove(int dx, int dy) {
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (blocks[b][i][j] != ' ') {
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
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (blocks[b][i][j] != ' ')
        board[y + i][x + j] = blocks[b][i][j];
}
void boardDelBlock() {
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (blocks[b][i][j] != ' ')
        board[y + i][x + j] = ' ';
}
void initBoard() {
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      board[i][j] = ' ';
}

void draw() {
  system("cls");

  const int playW = W - 2;
  const int playH = H - 1;

  // Top border
  cout << "+" << string(playW * 2 + 2, '-') << "+\n";

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
  cout << "+" << string(playW * 2 + 2, '-') << "+\n";

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

int main() {
  srand(time(0));
  x = 5;
  y = 0;
  b = rand() % 7;
  initBoard();
  while (1) {
    boardDelBlock();
    if (kbhit()) {
      char c = getch();
      if (c == 'a' && canMove(-1, 0))
        x--;
      if (c == 'd' && canMove(1, 0))
        x++;
      if (c == 'x' && canMove(0, 1))
        y++;
      if (c == 'q')
        break;
    }
    if (canMove(0, 1))
      y++;
    else {
      block2Board();
      const int linesRemoved = removeLine();
      updateSpeed(linesRemoved);
      x = 5;
      y = 0;
      b = rand() % 7;
    }
    block2Board();
    draw();
    _sleep(fallDelay);
  }
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
