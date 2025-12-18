#include <iostream>
#include <string>
using namespace std;

// ====== chỉnh theo game của bạn ======
const int W = 10;
const int H = 20;

// 1 cell = 2 ký tự ngang để nhìn vuông
#define CELL_EMPTY "  "
#define CELL_BLOCK "[]"

// ANSI (giảm nhấp nháy, chạy tốt trên VS Code Terminal)
static inline void clearScreen() { cout << "\x1b[2J"; }
static inline void homeCursor()  { cout << "\x1b[H"; }
static inline void hideCursor(bool on = true) {
    cout << (on ? "\x1b[?25l" : "\x1b[?25h");
}

// vẽ 1 ô
static inline void drawCell(int v) {
    cout << (v ? CELL_BLOCK : CELL_EMPTY);
}

// board[y][x]: 0 trống, !=0 là block
void drawBoard(int board[H][W]) {
    homeCursor();

    cout << "[Tuan 2] UI - Frame + Square Blocks\n\n";

    // ===== Top border (+2 vì có 2 cột '+') =====
    cout << "+" << string(W * 2 + 2, '-') << "+\n";

    // ===== Nội dung board =====
    for (int y = 0; y < H; y++) {
        cout << "|";   // viền trái

        cout << "+";   // cột trang trí trái

        for (int x = 0; x < W; x++)
            drawCell(board[y][x]);

        cout << "+";   // cột trang trí phải

        cout << "|\n"; // viền phải
    }

    // ===== Bottom border =====
    cout << "+" << string(W * 2 + 2, '-') << "+\n";
}

int main() {
    int board[H][W] = {0};

    // ===== Demo cho thấy UI =====
    for (int x = 0; x < W; x++)
        board[H - 1][x] = 1;

    // khối T
    board[6][4] = 1;
    board[7][3] = 1;
    board[7][4] = 1;
    board[7][5] = 1;

    clearScreen();
    hideCursor(true);

    drawBoard(board);

    hideCursor(false);
    return 0;
}
