#include <iostream>
#include <cstring>

using namespace std;

class game{
	private:
		string name;
		int score =0;
	public:
		int x =0;
	
		game(){
			setname();
		}
		
		void getname(){
			cout << name;
		}
		
		void getscore(){
			cout << score;
		}
		
		void setname(){
			cout << "What is your game name? "<<endl;
			cin >> name;
		}
		
		int setscore(){
			score = score + x;
		}
			
};

class Mine_Sweeper: public game{
	private:
		int board[1000][1000];
		int board_rows;
		int board_columns;
		int selected_squares;
		int bomb_squares;
		int mines;
		char x = '-';
		char y = '-';
	public:
	
		
		
		void setname(){
			cout << endl;
			getname();
			cout << endl;
		}
		void setsize(){
			cout << "Please enter the number of ROWS you would like: "<<endl;
			cin >> board_rows;
			cout << "Please enter the number of COLUMNS you would like: "<<endl;
			cin >> board_columns;
			
			for(int i=0; i < board_rows; i++){
				
				for(int j=0; j < board_columns; j++){
					 board[i][j] = 0;
				}
				cout << endl;
			}
			
			for(int i = 0; i < mines; i++)

		{

			int X = (rand() % board_rows);

			int Y = (rand() % board_columns);

			if(bomb_squares[X][Y] != 1)

			{

				bomb_squares[X][Y] = 1;	

			}

			else

			{

				i--;

			}

		}
			
		}
		void setmines(){
			cout << "How many mines would you like to have?"<<endl;
			cin >> mines;
		}
		
		
		void print_board(){
			cout << "----------------------------------------------" << endl;
			for(int i=0; i < board_rows; i++){
				cout << " - ";
				for(int j=0; j < board_columns; j++){
					cout << "- ";
				}
				cout << endl;
			}
			cout << "----------------------------------------------" << endl;
		}
		
		void get_square(){
			
		}
		Mine_Sweeper(){
			setname();
			setmines();
			setsize();
			print_board();
		}
		
};

int main(){
	bool program_running = true;
	
	
	Mine_Sweeper mine_sweeper;
	
	//game_name;
	//while(program_running){
	//mine_sweeper.print_board();
	//}
	return 0;
	
}