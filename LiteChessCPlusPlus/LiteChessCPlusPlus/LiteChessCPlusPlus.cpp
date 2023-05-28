#include <iostream>
using namespace std;

const int SIZE = 8;

// Структура для представления игровой доски
struct Board {
    char squares[SIZE][SIZE];
};

// Инициализация доски
void initializeBoard(Board& board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3)
                    board.squares[i][j] = 'B';  // черные шашки
                else if (i > 4)
                    board.squares[i][j] = 'W';  // белые шашки
                else
                    board.squares[i][j] = ' ';  // пустая клетка
            }
            else {
                board.squares[i][j] = ' ';  // пустая клетка
            }
        }
    }
}

// Вывод игровой доски на экран
void printBoard(const Board& board) {
    cout << "  0 1 2 3 4 5 6 7" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i;
        for (int j = 0; j < SIZE; j++) {
            cout << " " << board.squares[i][j];
        }
        cout << endl;
    }
}

// Проверка допустимости хода
bool isValidMove(const Board& board, int fromRow, int fromCol, int toRow, int toCol, char currentPlayer) {
    // Проверяем, что начальная позиция содержит шашку текущего игрока
    /*if (board.squares[fromRow][fromCol] != currentPlayer)
        return false;

    // Проверяем, что конечная позиция пустая
    if (board.squares[toRow][toCol] != ' ')
        return false;

    // Проверяем, что ход находится на диагонали
    if (abs(toRow - fromRow) != abs(toCol - fromCol))
        return false;

    // Проверяем, что ход находится на одну клетку вперед или назад
    //if (abs(toRow - fromRow) != 1)
    //   return false;

    // Проверяем, что ход идет вправо или влево
    if (abs(toCol - fromCol) != 1)
        return false;

    // Дополнительные проверки для дамок
    if (currentPlayer == 'W') {
        if (fromRow > toRow)
            return false;
    }
    else if (currentPlayer == 'B') {
        if (fromRow < toRow)
            return false;
    }*/

    return true;
}

// Выполнение хода
void makeMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) {
    char currentPlayer = board.squares[fromRow][fromCol];

    // Перемещаем шашку на новую позицию
    board.squares[toRow][toCol] = currentPlayer;
    board.squares[fromRow][fromCol] = ' ';

    // Проверяем, было ли это превращение в дамку
    if ((currentPlayer == 'W' && toRow == SIZE - 1) || (currentPlayer == 'B' && toRow == 0)) {
        board.squares[toRow][toCol] = toupper(currentPlayer);  // Превращаем в дамку
    }
}

// Проверка наличия возможных ходов для игрока
bool hasValidMove(const Board& board, char currentPlayer) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board.squares[i][j] == currentPlayer || board.squares[i][j] == toupper(currentPlayer)) {
                // Проверяем возможные ходы для шашки
                if ((board.squares[i][j] == currentPlayer && isValidMove(board, i, j, i + 1, j - 1, currentPlayer)) ||
                    (board.squares[i][j] == currentPlayer && isValidMove(board, i, j, i + 1, j + 1, currentPlayer)) ||
                    (board.squares[i][j] == toupper(currentPlayer) && isValidMove(board, i, j, i - 1, j - 1, currentPlayer)) ||
                    (board.squares[i][j] == toupper(currentPlayer) && isValidMove(board, i, j, i - 1, j + 1, currentPlayer))) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Board board;
    char currentPlayer = 'B';

    initializeBoard(board);

    while (true) {
        printBoard(board);

        // Проверяем наличие возможных ходов для текущего игрока
        if (!hasValidMove(board, currentPlayer)) {
            cout << "Игрок " << currentPlayer << " не имеет возможных ходов. Игра завершена." << endl;
            break;
        }

        int fromRow, fromCol, toRow, toCol;
        cout << "Ход игрока " << currentPlayer << endl;
        cout << "Введите начальную позицию шашки (строка столбец): ";
        cin >> fromRow >> fromCol;
        cout << "Введите конечную позицию шашки (строка столбец): ";
        cin >> toRow >> toCol;

        // Проверяем допустимость хода
        if (!isValidMove(board, fromRow, fromCol, toRow, toCol, currentPlayer)) {
            cout << "Недопустимый ход. Попробуйте еще раз." << endl;
            continue;
        }

        // Выполняем ход
        makeMove(board, fromRow, fromCol, toRow, toCol);

        // Переключаем игрока
        currentPlayer = (currentPlayer == 'B') ? 'W' : 'B';
    }

    return 0;
}