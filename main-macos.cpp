#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;
#define H 20
#define W 15
char board[H][W] = {};

// Cross-platform replacements for Windows conio.h functions
bool kbhit() {
  struct termios oldt, newt;
  int ch;
  int oldf;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
  if (ch != EOF) {
    ungetc(ch, stdin);
    return true;
  }
  return false;
}

char getch() {
  struct termios oldt, newt;
  char ch;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
}

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
      if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
        board[i][j] = '#';
      else
        board[i][j] = ' ';
}

void draw() {
  system("clear");

  for (int i = 0; i < H; i++, cout << endl)
    for (int j = 0; j < W; j++)
      cout << board[i][j];
}

void removeLine() {
  // TODO: Implement line removal logic
}
new[i][j] = old[3 - j][i]
bool canRotate(char newBlock[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (newBlock[i][j] != ' ') {
                int xt = x + j;
                int yt = y + i;

                if (xt < 1 || xt >= W - 1 || yt < 1 || yt >= H - 1)
                    return false;

                if (board[yt][xt] != ' ')
                    return false;
            }
        }
    }
    return true;
}
void rotateBlock() {
    char temp[4][4];

    // Xoay 90 độ
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            temp[i][j] = blocks[b][3 - j][i];

    // Nếu xoay hợp lệ thì cập nhật block
    if (canRotate(temp)) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                blocks[b][i][j] = temp[i][j];
    }
}
if (kbhit()) {
    char c = getch();

    if (c == 'a' && canMove(-1, 0)) x--;
    if (c == 'd' && canMove(1, 0))  x++;
    if (c == 's' && canMove(0, 1))  y++;

    if (c == 'w') {   // XOAY KHỐI
        boardDelBlock();
        rotateBlock();
        block2Board();
    }

    if (c == 'q') break;
}

int main() {
  srand(time(nullptr));
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
      if (c == 's' && canMove(0, 1))
        y++;
      if (c == 'q')
        break;
    }
    if (canMove(0, 1))
      y++;
    else {
      block2Board();
      removeLine();
      x = 5;
      y = 0;
      b = rand() % 7;
    }
    block2Board();
    draw();
    this_thread::sleep_for(chrono::milliseconds(500));
  }
  return 0;
}
