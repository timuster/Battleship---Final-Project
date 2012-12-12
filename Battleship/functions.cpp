#include "functions.h"
int i;

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
    clearScreen();
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
    	{
    	cout<<"There is already a ship placed at that point"<<endl;
        return false;
        }
    else {
        grid[x][y] = 'S';
        return true;
        }
    }

bool placeShip2(QString grid[10][10], QString coord, QString coord1) 
{
    int y = coord[0].unicode()-65; //x will be 0 for A and 9 for J
    QString number;
    if (coord.length() == 2)
        number = coord[1];
    else {
        number = coord[1];
        number.append(coord[2]);
    }
    
    int y1 = coord1[0].unicode()-65; //x will be 0 for A and 9 for J
    QString number1;
    if (coord1.length() == 2)
        number1 = coord1[1];
    else {
        number1 = coord1[1];
        number1.append(coord1[2]);
    }
    
///
    
    int x = number.toInt() - 1; //1 will be 0 and 10 will be 9
    int x1 = number1.toInt() - 1;
    
    if (x > 9 | x <0 | y<0 | y>9 ) //check bounds for array
        return false;
    if (x1 > 9 | x1 <0 | y1<0 | y1>9 ) //check bounds for array
        return false;
// If numbers are same        
    if (x==x1)
    	{
    	if (y>y1)
    		{ for (i=y1+1; i<=y; i++)
    			{	
    			 if (grid[x][i] != "-")
    				{cout<<"There is already a ship placed at that point"<<endl;
       				return false;}
   				  else 
   				  {
        			grid[x][i] = 'S';
        			}
    			}
    			return true;
    		}
    	
    	else if (y1>y)
    		{ for (i=y+1; i<=y1; i++)
    			{	
    			 if (grid[x][i] != "-")
    				{cout<<"There is already a ship placed at that point"<<endl;
       				return false;}
   				  else 
   				  {
        			grid[x][i] = 'S';
        			}
    			}
    			return true;
    		}
    	}

// if alphabets are same

    if (y==y1)
    	{ 
    	if (x>x1)
    		{ for (i=x1+1; i<=x; i++)
    			{	
    			 if (grid[i][y] != "-")
    				{cout<<"There is already a ship placed at that point"<<endl;
       				return false;}
   				  else 
   				  {	
        			grid[i][y] = 'S';
        			}
    			}
    			return true;
    		}
    	
    	else if (x1>x)
    		{ for (i=x+1; i<=x1; i++)
    			{	
    			 if (grid[i][y] != "-")
    				{cout<<"There is already a ship placed at that point"<<endl;
       				return false;}
   				  else 
   				  {
        			grid[i][y] = 'S';
        			}
    			}
    			return true;
    		}
    	}
    
    

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
bool checkValidCoordAircraftCarrier(QString coord, QString coord1) {
    QString  number;
    QString	number1;
    
    


//first y coordinate input
    if (coord.length() == 2)
        number = coord[1];
    else if (coord.length() == 3) {
        number = coord[1];
        number.append(coord[2]);
    }
    else
        return false;

//second y coordinate input

    if (coord1.length() == 2)
        number1 = coord1[1];
    else if (coord1.length() == 3) {
        number1 = coord1[1];
        number1.append(coord1[2]);
    }
    else
        return false;        
        
int iNumber = number.toInt();
int iNumber1 = number1.toInt();
//check if y coordinate inputs are within 1-10

    if (number[0].isDigit()) 
    {
        if (coord.length() == 3 && !number[1].isDigit())
            return false;
            if (iNumber <1 | iNumber > 10) 
            {
                cout << "You must choose a number between 1 - 10" << endl;
                return false;
            }

    }
        
//test if entered x coordinate is between A-J        
    int test = coord[0].unicode();
   
    if (coord[0].unicode() < 65 | coord[0].unicode() > 74) 
    { //if letter isn't between A-J
        cout << "You must choose a letter between A - J" << endl;
        return false;
    }

//test if entered x coordinate is valid for ship type  
    
    if (coord[0].unicode() == coord1[0].unicode()) //if letters are same; numbers must have difference of 5
    { 
   
    	
    	if (abs(iNumber-iNumber1)==4)
    		return true;
    	else
    		{
    			cout<<"Invalid ship size or placement." << endl << "You can only place ships horizontally or vertically." <<endl<<"Aircraft carriers = 5 blocks."<<endl<<"Please enter coordinates again."<<endl;
        		return false;
        	}
        	   	
    }
    else if (abs(coord[0].unicode() - coord1[0].unicode())==4) //if letters have a difference of 5; numbers must be same
    	{
    
    	
    	if (iNumber==iNumber1)
    		return true;
    	else
    		{
    			cout<<"Invalid ship size or placement." << endl << "You can only place ships horizontally or vertically." <<endl<<"Aircraft carriers = 5 blocks."<<endl<<"Please enter coordinates again."<<endl;
        		return false;
        	}
    	
    	}
    	
    else
    {
    			cout<<"Invalid ship size or placement." << endl << "You can only place ships horizontally or vertically." <<endl<<"Aircraft carriers = 5 blocks."<<endl<<"Please enter coordinates again."<<endl;
        		return false;   
    }
    
}
bool checkValidCoordBattleship(QString coord, QString coord1)
{
	QString  number;
	QString	number1;

//first y coordinate input
    if (coord.length() == 2)
        number = coord[1];
    else if (coord.length() == 3) {
        number = coord[1];
        number.append(coord[2]);
    }
    else
        return false;

//second y coordinate input

    if (coord1.length() == 2)
        number1 = coord1[1];
    else if (coord1.length() == 3) {
        number1 = coord1[1];
        number1.append(coord1[2]);
    }
    else
        return false;        
        
int iNumber = number.toInt();
int iNumber1 = number1.toInt();
//check if y coordinate inputs are within 1-10

    if (number[0].isDigit()) 
    {
        if (coord.length() == 3 && !number[1].isDigit())
            return false;
            if (iNumber <1 | iNumber > 10) 
            {
                cout << "You must choose a number between 1 - 10" << endl;
                return false;
            }

    }
        
//test if entered x coordinate is between A-J        
    int test = coord[0].unicode();
   
    if (coord[0].unicode() < 65 | coord[0].unicode() > 74) 
    { //if letter isn't between A-J
        cout << "You must choose a letter between A - J" << endl;
        return false;
    }

//test if entered x coordinate is valid for ship type  
    
    if (coord[0].unicode() == coord1[0].unicode()) //if letters are same; numbers must have difference of 4
    { 
   
    	
    	if (abs(iNumber-iNumber1)==3)
    		return true;
    	else
    		{
    			cout<<"Invalid ship size or placement." << endl << "You can only place ships horizontally or vertically." <<endl<<"Battleship = 4 blocks."<<endl<<"Please enter coordinates again."<<endl;
        		return false;
        	}
        	   	
    }
    else if (abs(coord[0].unicode() - coord1[0].unicode())==3) //if letters have a difference of 4; numbers must be same
    	{
    
    	
    	if (iNumber==iNumber1)
    		return true;
    	else
    		{
    			cout<<"Invalid ship size or placement." << endl << "You can only place ships horizontally or vertically." <<endl<<"Battleship = 4 blocks."<<endl<<"Please enter coordinates again."<<endl;
        		return false;
        	}
    	
    	}
    	
    else
    {
    			cout<<"Invalid ship size or placement." << endl << "You can only place ships horizontally or vertically." <<endl<<"Battleship = 4 blocks."<<endl<<"Please enter coordinates again."<<endl;
        		return false;   
    }
}
bool checkValidCoordSubmarine(QString coord, QString coord1)
{
	QString  number;
	QString	number1;

//first y coordinate input
    if (coord.length() == 2)
        number = coord[1];
    else if (coord.length() == 3) {
        number = coord[1];
        number.append(coord[2]);
    }
    else
        return false;

//second y coordinate input

    if (coord1.length() == 2)
        number1 = coord1[1];
    else if (coord1.length() == 3) {
        number1 = coord1[1];
        number1.append(coord1[2]);
    }
    else
        return false;        
        
int iNumber = number.toInt();
int iNumber1 = number1.toInt();
//check if y coordinate inputs are within 1-10

    if (number[0].isDigit()) 
    {
        if (coord.length() == 3 && !number[1].isDigit())
            return false;
            if (iNumber <1 | iNumber > 10) 
            {
                cout << "You must choose a number between 1 - 10" << endl;
                return false;
            }

    }
        
//test if entered x coordinate is between A-J        
    int test = coord[0].unicode();
   
    if (coord[0].unicode() < 65 | coord[0].unicode() > 74) 
    { //if letter isn't between A-J
        cout << "You must choose a letter between A - J" << endl;
        return false;
    }

//test if entered x coordinate is valid for ship type  
    
    if (coord[0].unicode() == coord1[0].unicode()) //if letters are same; numbers must have difference of 3
    { 
   
    	
    	if (abs(iNumber-iNumber1)==2)
    		return true;
    	else
    		{
    			cout<<"Invalid ship size or placement." << endl << "You can only place ships horizontally or vertically." <<endl<<"Submarine = 3 blocks."<<endl<<"Please enter coordinates again."<<endl;
        		return false;
        	}
        	   	
    }
    else if (abs(coord[0].unicode() - coord1[0].unicode())==2) //if letters have a difference of 3; numbers must be same
    	{
    
    	
    	if (iNumber==iNumber1)
    		return true;
    	else
    		{
    			cout<<"Invalid ship size or placement." << endl << "You can only place ships horizontally or vertically." <<endl<<"Submarine = 3 blocks."<<endl<<"Please enter coordinates again."<<endl;
        		return false;
        	}
    	
    	}
    	
    else
    {
    			cout<<"Invalid ship size or placement." << endl << "You can only place ships horizontally or vertically." <<endl<<"Submarine = 3 blocks."<<endl<<"Please enter coordinates again."<<endl;
        		return false;   
    }
}
bool checkValidCoordDestroyer(QString coord, QString coord1)
{
	QString  number;
	QString	number1;

//first y coordinate input
    if (coord.length() == 2)
        number = coord[1];
    else if (coord.length() == 3) {
        number = coord[1];
        number.append(coord[2]);
    }
    else
        return false;

//second y coordinate input

    if (coord1.length() == 2)
        number1 = coord1[1];
    else if (coord1.length() == 3) {
        number1 = coord1[1];
        number1.append(coord1[2]);
    }
    else
        return false;        
        
int iNumber = number.toInt();
int iNumber1 = number1.toInt();
//check if y coordinate inputs are within 1-10

    if (number[0].isDigit()) 
    {
        if (coord.length() == 3 && !number[1].isDigit())
            return false;
            if (iNumber <1 | iNumber > 10) 
            {
                cout << "You must choose a number between 1 - 10" << endl;
                return false;
            }

    }
        
//test if entered x coordinate is between A-J        
    int test = coord[0].unicode();
   
    if (coord[0].unicode() < 65 | coord[0].unicode() > 74) 
    { //if letter isn't between A-J
        cout << "You must choose a letter between A - J" << endl;
        return false;
    }

//test if entered x coordinate is valid for ship type  
    
    if (coord[0].unicode() == coord1[0].unicode()) //if letters are same; numbers must have difference of 3
    { 
   
    	
    	if (abs(iNumber-iNumber1)==2)
    		return true;
    	else
    		{
    			cout<<"Invalid ship size or placement." << endl << "You can only place ships horizontally or vertically." <<endl<<"Destroyer = 3 blocks."<<endl<<"Please enter coordinates again."<<endl;
        		return false;
        	}
        	   	
    }
    else if (abs(coord[0].unicode() - coord1[0].unicode())==2) //if letters have a difference of 3; numbers must be same
    	{
    
    	
    	if (iNumber==iNumber1)
    		return true;
    	else
    		{
    			cout<<"Invalid ship size or placement." << endl << "You can only place ships horizontally or vertically." <<endl<<"Destroyer = 3 blocks."<<endl<<"Please enter coordinates again."<<endl;
        		return false;
        	}
    	
    	}
    	
    else
    {
    			cout<<"Invalid ship size or placement." << endl << "You can only place ships horizontally or vertically." <<endl<<"Destroyer = 3 blocks."<<endl<<"Please enter coordinates again."<<endl;
        		return false;   
    }
}
bool checkValidCoordPatrolBoat(QString coord, QString coord1)
{
	QString  number;
	QString	number1;

//first y coordinate input
    if (coord.length() == 2)
        number = coord[1];
    else if (coord.length() == 3) {
        number = coord[1];
        number.append(coord[2]);
    }
    else
        return false;

//second y coordinate input

    if (coord1.length() == 2)
        number1 = coord1[1];
    else if (coord1.length() == 3) {
        number1 = coord1[1];
        number1.append(coord1[2]);
    }
    else
        return false;        
        
int iNumber = number.toInt();
int iNumber1 = number1.toInt();
//check if y coordinate inputs are within 1-10

    if (number[0].isDigit()) 
    {
        if (coord.length() == 3 && !number[1].isDigit())
            return false;
            if (iNumber <1 | iNumber > 10) 
            {
                cout << "You must choose a number between 1 - 10" << endl;
                return false;
            }

    }
        
//test if entered x coordinate is between A-J        
    int test = coord[0].unicode();
   
    if (coord[0].unicode() < 65 | coord[0].unicode() > 74) 
    { //if letter isn't between A-J
        cout << "You must choose a letter between A - J" << endl;
        return false;
    }

//test if entered x coordinate is valid for ship type  
    
    if (coord[0].unicode() == coord1[0].unicode()) //if letters are same; numbers must have difference of 2
    { 
   
    	
    	if (abs(iNumber-iNumber1)==1)
    		return true;
    	else
    		{
    			cout<<"Invalid ship size or placement." << endl << "You can only place ships horizontally or vertically." <<endl<<"Patrol Boat = 2 blocks."<<endl<<"Please enter coordinates again."<<endl;
        		return false;
        	}
        	   	
    }
    else if (abs(coord[0].unicode() - coord1[0].unicode())==1) //if letters have a difference of 2; numbers must be same
    	{
    
    	
    	if (iNumber==iNumber1)
    		return true;
    	else
    		{
    			cout<<"Invalid ship size or placement." << endl << "You can only place ships horizontally or vertically." <<endl<<"Patrol Boat = 2 blocks."<<endl<<"Please enter coordinates again."<<endl;
        		return false;
        	}
    	
    	}
    	
    else
    {
    			cout<<"Invalid ship size or placement." << endl << "You can only place ships horizontally or vertically." <<endl<<"Patrol Boat = 2 blocks."<<endl<<"Please enter coordinates again."<<endl;
        		return false;   
    }
}

void promptAircraftCarrier(QString grid[10][10]) {
    cout << "Enter the coordinate for your Aircraft Carrier" << endl;
    QString coord;
    do {
        cin >> coord;
    } while (!checkValidCoord(coord) | !placeShip(grid, coord)); //check already existing point in placeShip


    cout << "Enter the second coordinate for your Aircraft Carrier" << endl;
    
    QString coord1;
	coord1 = coord;
    do {
        cin >> coord;
    } while (!checkValidCoordAircraftCarrier(coord, coord1) | !placeShip2(grid, coord,coord1));
    
    
    return;
}

void promptBattleship(QString grid[10][10]) {
    cout << "Enter the coordinate for your Battleship" << endl;
    QString coord;
    do {
        cin >> coord;
    } while (!checkValidCoord(coord) | !placeShip(grid, coord));
    
    cout << "Enter the second coordinate for your Battleship" << endl;
    
    QString coord1;
	coord1 = coord;
    do {
        cin >> coord;
    } while (!checkValidCoordBattleship(coord, coord1) | !placeShip2(grid, coord,coord1));    
    
    
    return;
}

void promptSubmarine(QString grid[10][10]) {
    cout << "Enter the coordinate for your Submarine" << endl;
    QString coord;
    do {
        cin >> coord;
    } while (!checkValidCoord(coord) | !placeShip(grid, coord));


    cout << "Enter the second coordinate for your Submarine" << endl;
    
    QString coord1;
	coord1 = coord;
    do {
        cin >> coord;
    } while (!checkValidCoordSubmarine(coord, coord1) | !placeShip2(grid, coord,coord1));   
    
    
    return;
}

void promptDestroyer(QString grid[10][10]) {
    cout << "Enter the coordinate for your Destroyer" << endl;
    QString coord;
    do {
        cin >> coord;
    } while (!checkValidCoord(coord) | !placeShip(grid, coord));


    cout << "Enter the second coordinate for your Destroyer" << endl;
    
    QString coord1;
	coord1 = coord;
    do {
        cin >> coord;
    } while (!checkValidCoordDestroyer(coord, coord1) | !placeShip2(grid, coord,coord1));   
    
    
    return;
}

void promptPatrolBoat(QString grid[10][10]) {
    cout << "Enter the coordinate for your Patrol Boat" << endl;
    QString coord;
    do {
        cin >> coord;
    } while (!checkValidCoord(coord) | !placeShip(grid, coord));
    
    

    cout << "Enter the second coordinate for your Patrol Boat" << endl;
    
    QString coord1;
	coord1 = coord;
    do {
        cin >> coord;
    } while (!checkValidCoordPatrolBoat(coord, coord1) | !placeShip2(grid, coord,coord1));   
    
    
    return;
}

void setupComputer(QString grid[10][10]) 
{
    int i = 0, x=0, y=0, x2=0, y2=0,f=0;
 
//aircraft carrier
do
{   
        do 
        {
            x=rand() % 10;
            y=rand() % 10;
        } while (grid[x][y] == "S");
        
         
        if (x>y)
        {	x2=x;
        	y2=y+4;
        	for(i=y;i<=y2;i++)
        	{ if (grid[x2][i]!="S")
        		{
        		grid[x2][i]='S';
        		f=0;
        		}
        	  else
        	  	f=1;
        	}
        
        }
        else
        {	y2=y;
        	x2=x+4;
        	for(i=x;i<=x2;i++)
        	{	if (grid[i][y2]!="S")
        		{
        		grid[i][y2]='S';
        		f=0;
        		}
        		else
        			f=1;;
        	}
        }
        
}while(f==1);

//battleship   
do
{   
        do 
        {
            x=rand() % 10;
            y=rand() % 10;
        } while (grid[x][y] == "S");
        
         
        if (x>y)
        {	x2=x;
        	y2=y+3;
        	for(i=y;i<=y2;i++)
        	{ if (grid[x2][i]!="S")
        		{
        		grid[x2][i]='S';
        		f=0;
        		}
        	  else
        	  	f=1;
        	}
        
        }
        else
        {	y2=y;
        	x2=x+3;
        	for(i=x;i<=x2;i++)
        	{	if (grid[i][y2]!="S")
        		{
        		grid[i][y2]='S';
        		f=0;
        		}
        		else
        			f=1;;
        	}
        }
        
}while(f==1);
        
//submarine  
do
{   
        do 
        {
            x=rand() % 10;
            y=rand() % 10;
        } while (grid[x][y] == "S");
        
         
        if (x>y)
        {	x2=x;
        	y2=y+2;
        	for(i=y;i<=y2;i++)
        	{ if (grid[x2][i]!="S")
        		{
        		grid[x2][i]='S';
        		f=0;
        		}
        	  else
        	  	f=1;
        	}
        
        }
        else
        {	y2=y;
        	x2=x+2;
        	for(i=x;i<=x2;i++)
        	{	if (grid[i][y2]!="S")
        		{
        		grid[i][y2]='S';
        		f=0;
        		}
        		else
        			f=1;;
        	}
        }
        
}while(f==1);

//destroyer 
do
{   
        do 
        {
            x=rand() % 10;
            y=rand() % 10;
        } while (grid[x][y] == "S");
        
         
        if (x>y)
        {	x2=x;
        	y2=y+2;
        	for(i=y;i<=y2;i++)
        	{ if (grid[x2][i]!="S")
        		{
        		grid[x2][i]='S';
        		f=0;
        		}
        	  else
        	  	f=1;
        	}
        
        }
        else
        {	y2=y;
        	x2=x+2;
        	for(i=x;i<=x2;i++)
        	{	if (grid[i][y2]!="S")
        		{
        		grid[i][y2]='S';
        		f=0;
        		}
        		else
        			f=1;;
        	}
        }
        
}while(f==1);

//patrol boat 
do
{   
        do 
        {
            x=rand() % 10;
            y=rand() % 10;
        } while (grid[x][y] == "S");
        
         
        if (x>y)
        {	x2=x;
        	y2=y+1;
        	for(i=y;i<=y2;i++)
        	{ if (grid[x2][i]!="S")
        		{
        		grid[x2][i]='S';
        		f=0;
        		}
        	  else
        	  	f=1;
        	}
        
        }
        else
        {	y2=y;
        	x2=x+1;
        	for(i=x;i<=x2;i++)
        	{	if (grid[i][y2]!="S")
        		{
        		grid[i][y2]='S';
        		f=0;
        		}
        		else
        			f=1;;
        	}
        }
        
}while(f==1);
        
} //setup computer ends

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
