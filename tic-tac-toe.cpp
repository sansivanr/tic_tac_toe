#include <iostream>
using namespace std;

void draw_board(char board[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool check_win(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player)
        return true;
    return false;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player = 'X';
    int row, col;
    int turn;
    cout << "WELCOME TO TIC TAC TOE" << endl;

    for (turn = 0; turn < 9; turn++) {
        draw_board(board);

        while (true) {
            cout << "Player " << player << " Enter row (0 - 2) & col (0 - 2) :- ";
            if (!(cin >> row >> col) || row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                cout << "Invalid move. Please enter row (0 - 2) & col (0 - 2) again." << endl;
                cin.clear(); // clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard incorrect input
            } else {
                break;
            }
        }

        board[row][col] = player;

        if (check_win(board, player)) {
            draw_board(board);
            cout << "Player " << player << " Wins!" << endl;
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    draw_board(board);

    if (turn == 9 && !check_win(board, 'X') && !check_win(board, 'O')) {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
