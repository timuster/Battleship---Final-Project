#include "functions.h"

void initializeGrid(QString grid[10][10]) {
    for (int n=0; n<10; n++)             // initialize with dashes
        {   for (int r=0; r<10; r++)
            {
                grid[n][r] = '-';
            }
        }
}

int initialPromptGameSelection() {
    QString poc;

    cout << "Battleship! Destroy the 5 enemy ships before yours are destroyed." << endl;
    cout << "Make sure to format your coordinates as follows Ex: A1" << endl;
    cout << "Press 1 to play with the computer, Press 2 to play with a friend" << endl;

    while ((poc[0].unicode() != 49 && poc[0].unicode() != 50) | poc.length() > 1)
        cin >> poc; //entry that determines whether or not you play again

    return poc[0].unicode() - 48;
}

void promptPlayAgainstComputer() {
    cout << "You have selected to play against the computer" << endl;
    promptAircraftCarrier(player1Grid);
    promptBattleship(player1Grid);
    promptSubmarine(player1Grid);
    promptDestroyer(player1Grid);
    promptPatrolBoat(player1Grid);
    return;
}

void promptPlayAgainstPerson() {
    cout << "You have selected to play against a friend" << endl;
    cout << "Player one enter your name" << endl; // names are entered and used throughout the program
    cin >> player1;
    cout << "Player two enter your name" << endl;
    cin >> player2;

    //player 1 enter ships
    cout << player1 << " enter a coordinate for Ship 1 and don't let " << player2 << " see." << endl;
    promptAircraftCarrier(player1Grid);
    promptBattleship(player1Grid);
    promptSubmarine(player1Grid);
    promptDestroyer(player1Grid);
    promptPatrolBoat(player1Grid);
    clearScreen();

    //player 2 enter ships
    cout << player2 << " enter a coordinate for Ship 1 and don't let " << player1 << " see." << endl;
    promptAircraftCarrier(player2Grid);
    promptBattleship(player2Grid);
    promptSubmarine(player2Grid);
    promptDestroyer(player2Grid);
    promptPatrolBoat(player2Grid);
    clearScreen();
}

bool checkValidCoord(QString coord) {
    QString  number;

    if (coord.length() == 2)
        number = coord[1];
    else if (coord.length() == 3) {
        number = coord[1];
        number.append(coord[2]);
    }
    else
        return false;
    int test = coord[0].unicode();
    if (coord[0].unicode() < 65 | coord[0].unicode() > 74) { //if letter isn't between A-J
        cout << "You must choose a letter between A - J" << endl;
        return false;
    }

    if (number[0].isDigit()) {
        if (coord.length() == 3 && !number[1].isDigit())
            return false;
        int iNumber = number.toInt();
            if (iNumber <1 | iNumber > 10) {
                cout << "You must choose a number between 1 - 10" << endl;
                return false;
            }
            else
                return true;
    }
}

void promptAircraftCarrier(QString grid[10][10]) {
    cout << "Enter the coordinate for your Aircraft Carrier" << endl;
    QString coord;
    do {
        cin >> coord;
    } while (!checkValidCoord(coord) | !placeShip(grid, coord));
    return;
}

void promptBattleship(QString grid[10][10]) {
    cout << "Enter the coordinate for your Battleship" << endl;
    QString coord;
    do {
        cin >> coord;
    } while (!checkValidCoord(coord) | !placeShip(grid, coord));
    return;
}

void promptSubmarine(QString grid[10][10]) {
    cout << "Enter the coordinate for your Submarine" << endl;
    QString coord;
    do {
        cin >> coord;
    } while (!checkValidCoord(coord) | !placeShip(grid, coord));
    return;
}

void promptDestroyer(QString grid[10][10]) {
    cout << "Enter the coordinate for your Destroyer" << endl;
    QString coord;
    do {
        cin >> coord;
    } while (!checkValidCoord(coord) | !placeShip(grid, coord));
    return;
}

void promptPatrolBoat(QString grid[10][10]) {
    cout << "Enter the coordinate for your Patrol Boat" << endl;
    QString coord;
    do {
        cin >> coord;
    } while (!checkValidCoord(coord) | !placeShip(grid, coord));
    return;
}

bool placeShip(QString grid[10][10], QString coord) {
    int y = coord[0].unicode()-65; //x will be 0 for A and 9 for J
    QString number;
    if (coord.length() == 2)
        number = coord[1];
    else {
        number = coord[1];
        number.append(coord[2]);
    }
    int x = number.toInt() - 1; //1 will be 0 and 10 will be 9
    if (x > 9 | x <0 | y<0 | y>9 ) //check bounds for array
        return false;
    if (grid[x][y] != "-")
        return false;
    else {
        grid[x][y] = 'S';
        return true;
    }
}

void setupComputer(QString grid[10][10]) {
    int i = 0, x=0, y=0;
    while (i < 5) {
        do {
            x=rand() % 10;
            y=rand() % 10;
        } while (grid[x][y] == "S");

        grid[x][y] = 'S';
        i++;
    }
}

void displayGrid(QString grid[10][10]) {
    cout << "    ";
    cout.setFieldWidth(6);
    for (int r=65; r<75; r++)
        cout << char(r);

    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    for (int n=0; n<10; n++)
    {
        cout.setFieldWidth(2);
        cout << n+1 << "|";
        for (int q=0; q<10; q++){
            cout.setFieldWidth(3);
            cout << "   " << grid[n][q];
        }
        cout << endl;
    }

}

void playComputer() {
    QString coord, message, message2, endMessage;
    int x, y;

    cout << "\nThe S's on the grid are your ships" << endl;
    cout << "The O's mark where the computer is guessing on the top grid" << endl;
    cout << "The O's on the lower grid are your guesses" << endl;
    cout << "The X's are the computer's hits on the top grid and your hits on the lower grid" << endl;
    cout << "If you find all 5 computer ships you win." << endl;
    cout << "If the computer finds your 5 ships, you lose." << endl;
    cout << "Alright! All your ships are set in the grid below" << endl;
    cout << "Lets begin. You start. Guess a coordinate where you think an enemy ship is." << endl;
    while (!checkGameOver(player1Grid, player2Grid, endMessage)) {
        clearScreen();
        if (!message.isEmpty())
            cout << message;
        if (!message2.isEmpty())
            cout << message2;
        displayGrid(player1Grid);
        cout << endl;
        displayGrid(player1HitGrid);

        do {
            cin >> coord;
        } while(!checkValidCoord(coord) | !markGuess(player1HitGrid, player2Grid, coord, message));

        do {
            x =rand() % 10;
            y =rand() % 10;
        } while (!markComputerGuess(player1Grid, x, y, message2));
    }
    cout << endMessage;
    return;
}

void playFriend() {
    QString coord, coord2, message;
    cout << "\nThe S's on the grid are your ships" << endl;
    cout << "The O's on the top grid mark where " << player1 << " is guessing." << endl;
    cout << "The O's on the bottom grid mark where " << player2 << " is guessing." << endl;
    cout << "The X's represents hits and are marked on the same grids as the O's" << endl;
    cout << "The first person to sink all 5 ships wins" << endl;

    while (!checkGameOver(player1Grid, player2Grid, message)) {
        cout << player1 << " choose a Coordinate to hit." << endl;
        displayGrid(player1HitGrid);
        cout << endl;
        displayGrid(player2HitGrid);

        do {
            cin >> coord;
        } while(!checkValidCoord(coord) | !markGuess(player1HitGrid, player2Grid, coord, message));

        clearScreen();
        if (!message.isEmpty())
            cout << message;
        cout << player2 << " choose a Coordinate to hit." << endl;
        displayGrid(player1HitGrid);
        cout << endl;
        displayGrid(player2HitGrid);

        do {
            cin >> coord2;
        } while (!checkValidCoord(coord2) | !markGuess(player2HitGrid, player1Grid, coord2, message));
        clearScreen();
        if (!message.isEmpty())
            cout << message;
    }

    if (message == "You Win!\n")
        cout << player1 << " wins!" << endl;
    else if (message == "It's a draw!\n")
        cout << message;
    else
        cout << player2 << " wins!" << endl;
}

bool markGuess(QString grid[10][10], QString player2Grid[10][10], QString coord, QString& message) {
    message.clear();
    int y = coord[0].unicode()-65; //x will be 0 for A and 9 for J
    QString number;
    if (coord.length() == 2)
        number = coord[1];
    else {
        number = coord[1];
        number.append(coord[2]);
    }

    int x = number.toInt() - 1; //1 will be 0 and 10 will be 9

    if (x > 9 | x <0 | y<0 | y>9 ) //check bounds for array
        return false;

    if (grid[x][y] == "O" | grid[x][y] == "X") {
        cout << "You have already guessed that coordinate. Guess again." << endl;
        return false;
    }

    else if (player2Grid[x][y] == "S") {
        grid[x][y] = 'X';
        player2Grid[x][y] = 'X';
        message = "Hit!\n";
        return true;
    }

    else if (grid[x][y] == "-") {
        grid[x][y] = 'O';
        return true;
    }
    else
        return false;
}

bool markComputerGuess(QString grid[10][10], int x, int y, QString &message) {
    message.clear(); //clear out message everytime
    if (grid[x][y] == "O" | grid[x][y] == "X")
        return false;
    else if (grid[x][y] == "-") {
        grid[x][y] = 'O';
        return true;
    }
    else if (grid[x][y] == "S") {
        grid[x][y] = 'X';
        message = "The computer got a hit!\n";
        return true;
    }
    else
        return false;
}

bool checkGameOver(QString playerGrid[10][10], QString computerGrid[10][10], QString& message) {
    message.clear();
    bool playerHasShips = false, computerHasShips = false;
    for (int n=0; n<10; n++)
        {   for (int r=0; r<10; r++)
            {
                if (playerGrid[n][r] == "S")
                    playerHasShips = true;
                if (computerGrid[n][r] == "S")
                    computerHasShips = true;
            }
        }
    if (playerHasShips && !computerHasShips) {
        message = "You Win!\n";
        return true;
    }
    else if (!playerHasShips && computerHasShips) {
        message = "You Lost!\n";
        return true;
    }
    else if (!playerHasShips && !computerHasShips) {
        message = "It's a draw!\n";
        return true;
    }
    else
        return false;
}

void clearScreen() {
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
}
