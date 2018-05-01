#include <iostream>
#include <cstring>

using namespace std;

class Game{
	private:
		int score =0;
		string name;
	public:
		char board_size[100][100];
		int board_rows;
		int board_columns;
		int mines;
		int selected_squares[100][100];
		int bomb_squares[100][100];
		
		Game(){
			setname();
		}
		
	void setname(){
		cout << "Please name your game: ";
		cin >> name;
	}
	
	void getname(){
		cout << name;
	}
		
	void getscore(){
		cout << score;
	}
	
	int setscore(){
		//score = score + x;
	}
	
};

class MineSweeper: public Game{
	public:
		/*char board_size[100][100];
		int board_rows = 0;
		int board_columns = 0;
		int mines = 0;
		int selected_squares[100][100];
		int bomb_squares[100][100];*/
	
	MineSweeper(){
		setname();
		setboard();
	}
	
	void setname(){
		
	}
	
	void setboard(){
		for(int i=0; i < board_rows; i++){
					
			for(int j=0; j < board_columns; j++){
				 board_size[i][j] = 'O';
			}
			cout << endl;
		}
		
		for(int i=0; i < board_rows; i++){
					
			for(int j=0; j < board_columns; j++){
				 bomb_squares[i][j] = 0;
			}
			cout << endl;
		}
				
		for(int i = 0; i < mines; i++){

			int X = (rand() % board_rows);
			int Y = (rand() % board_columns);

			if(bomb_squares[X][Y] != 1){

				bomb_squares[X][Y] = 1;	

			}

			else{

				i--;
			}

		}
		//print_board();
	}
	
	int get_square(int A,int B){
		if (bomb_squares[A][B] != 1){
			bomb_squares[A][B] = 9;
			cout << "WORKING ISH"<< endl;
		}
		else if (bomb_squares[A][B] == 1){
			cout << "You have found a bomb!";
			bomb_squares[A][B] = 2;
			//cout << "would you like to continue? y or n" <<endl;
			//keep_running = false;
			
		}
	}
	void print_board(){
		
		cout << "----------------------------------------------" << endl;
		for(int i=0; i < board_rows; i++){
				//cout << " - ";
			for(int j=0; j < board_columns; j++){
					cout << bomb_squares[i][j] <<" ";
			}
			cout << endl;
		}
		cout << "----------------------------------------------" << endl;
		
		/*cout << "TESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTEST"<<endl;
			for(int i=0; i < board_rows; i++){
				//cout << " - ";
			for(int j=0; j < board_columns; j++){
					cout << bomb_squares[i][j] <<" ";
			}
			cout << endl;
		}
		cout << "TESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTESTTEST"<<endl;*/
	}
	
};

int main(){
	bool keep_running = true;
	int action = 0;
	char quit = 'n';
	int X = 0;
	int Y = 0;
	
	
	/*Game game;
	
	
	cout << "Please enter the number of ROWS you would like: "<<endl;
	cin >> game.board_rows;
	cout << "Please enter the number of COLUMNS you would like: "<<endl;
	cin >> game.board_columns;
	cout << "How many mines would you like to have?"<<endl;
	cin >> game.mines;*/
	
	MineSweeper minesweeper;
	
	cout << "Please enter the number of ROWS you would like: "<<endl;
	cin >> minesweeper.board_rows;
	cout << "Please enter the number of COLUMNS you would like: "<<endl;
	cin >> minesweeper.board_columns;
	cout << "How many mines would you like to have?"<<endl;
	cin >> minesweeper.mines;
	

	while (keep_running){
		cout << "Please enter the X and Y coordinates you want to sweep:"<< endl;
		cout << "X: ";
		cin >> X;
		
		X=X -1;
		
		cout << "Y: ";
		cin >> Y;
		
		Y=Y -1;
		
		//minesweeper.selected_squares[X][Y];
		minesweeper.get_square(X,Y);
		minesweeper.print_board();
		
	}

	
}