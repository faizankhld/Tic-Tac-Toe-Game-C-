#include<iostream>
#include<conio.h>
#include <fstream>
using namespace std;
class tic
{
	int n;
	char** ptr;
public:
	tic()
	{
		n = 3;
			ptr = new char*[3];
			for (int gt = 0; gt < 3; ++gt)
			{
				ptr[gt] = new char[3];
			}
	}
	tic(int a)
	{
	n = a;
	ptr = new char*[n];
	for (int b = 0; b < n; ++b)
	{
		ptr[b] = new char[n];
	}
    }
	void map()
 {
	char c = ' ';
	for (int a = 0; a < n; ++a)
	{
		for (int b = 0; b < n; ++b)                         //Storing Space In 2d array 
		{
			ptr[a][b] = c;
		
		}
    }

    }
	void draw()
	{
		{

	for (int a = 0; a < n; ++a)
    {
		for (int et=0; et < n; ++et)
		{
			cout << "     |";
		}
		cout << endl;                                        
		for (int b = 0; b < n; ++b)                          //   Drawing Diagram For Game  
		{
			cout << " " << ptr[a][b]<<"    ";
		}
		cout << endl;
		for (int rt = 0; rt < n; ++rt)
		{
			cout << "_____|";
		}
			cout << endl;
		
}

}
	}
	void input()
	{
		{
	int flag = n * n;
	int pt = 0;
	int player = 1;
	int ro, cl;
	int ee = 0;
	while (ee < 1)
	{
		while (pt < flag)
		{
			char ty = ' ';
			int tr = (player % 2);
			if (tr == 1)
			{
				int poi = 1;
				while (poi < 2)
				{
					cout << "Player 1 Turn " << endl;
					cout << "Enter the row: " << endl;
					cin >> ro;
					cout << "Enter the colomn: " << endl;
					cin >> cl;
					if (ro < n && cl < n)                                    
					{

						if (ptr[ro][cl] == ty)                  // checking element stored at this location is space if true then store player move else take again input 
						{
							ptr[ro][cl] = 'X';
						}

						else
						{
							int bcd = 1;
							while (bcd < 2)
							{
								cout << "Invalid Move" << endl;
								cout << "Enter the row: " << endl;
								cin >> ro;
								cout << "Enter the colomn: " << endl;
								cin >> cl;
								if (ptr[ro][cl] == ty)
								{
									ptr[ro][cl] = 'X';
									++bcd;
								}
							}
						}
						++poi;
					}
					else
					{
						cout << "Invalid Move" << endl;
					}
				}
			}
			else
			{
				int ut = 1;
				while (ut < 2)
				{
					cout << "Player 2 Turn" << endl;
					cout << "Enter the row: " << endl;
					cin >> ro;
					cout << "Enter the colomn: " << endl;
					cin >> cl;
					if (ro < n && cl < n)
					{
						if (ptr[ro][cl] == ty)
						{
							ptr[ro][cl] = 'O';

						}
						else
						{
							int abc = 1;
							while (abc < 2)
							{
								cout << "Invalid Move" << endl;
								cout << "Enter the row: " << endl;
								cin >> ro;
								cout << "Enter the colomn: " << endl;
								cin >> cl;
								if (ptr[ro][cl] == ty)
								{
									ptr[ro][cl] = 'O';
									++abc;
								}
							}
						}
						++ut;
					}
				}

			}
			system("cls");
			draw();
			winner();
			if (winner() == true)
			{
				if (tr == 1)
				{
					cout << "Winner Is Player " << "1" << endl;
					system("pause");
					pt = 100;
					
					break;
				}
				else
				{
					cout << "Winner Is Player " << "2" << endl;
					system("pause");
					pt = 100;                       // To end the game to false the loop condition
					
					break;
				}

			}
			char btt;
			cout << "Press Q To Quit Game" << endl;
			cout << "Press S To Save Game" << endl;
			cout << "Press any key to continue" << endl;
			btt = _getch();

			if (btt == 's')
			{
				ofstream fout;
				fout.open("game.txt");
				for (int ap = 0; ap < n; ++ap)
				{
					for (int bp = 0; bp < n; ++bp)
					{
						if (ptr[ap][bp] == ' ')
						{
							fout << 'S';
						}
						else
						{
							fout << ptr[ap][bp];
						}
					}

				}

				fout.close();
			}

			if (btt == 'q')
			{
				pt = 100;
			}
			++player;
			++pt;

		}
		cout << "Press N to Open New Game" << endl;
		cout << "Press S to Open Saved Game" << endl;
		
		char eyy;
		eyy = _getch();
		if (eyy == 'n')
		{
			system("cls");
			tic();
			map();
			draw();
			input();
			++ee;
		}
		if (eyy == 's')
		{
			char it;
			system("cls");
			tic();
			map();
			ifstream fin;
			fin.open("game.txt");
			for (int atp = 0; atp < n; ++atp)
			{
				for (int but = 0; but < n; ++but)
				{

					fin >> it;
					if (it == 'S')
					{
						ptr[atp][but]= ' ';
					}
					else
					{
						ptr[atp][but] = it;
					}
				}

			}
			draw();
			input();
			++ee;
		}
	}
}

	}
	bool winner()
	{
		{
	

	char dd = ' ';
	int wt = 0;
	for (int po = 0; po < n; po++)
	{
		int win = 0;
		for (int adt = 0; adt < n-1; ++adt)
		{
			int drd = adt + 1;
			if (ptr[po][adt] != dd && ptr[po][drd] != dd)
			{
				if (ptr[po][adt] == ptr[po][drd])
				{
					++win;
				}
				                                                            // Checking Win Condition Row Wise

			}
			else
			{
				adt = 100;                                
			}
		}
		if (win == n-1)
		{
			cout << "Game End " << endl;
			
			po = 100;
			return true;
		}

	}
	for (int po = 0; po < n; po++)
	{
		int win = 0;
		for (int adt = 0; adt < n - 1; ++adt)
		{
			int drd = adt + 1;
			if (ptr[adt][po] != dd && ptr[drd][po] != dd)
			{
				if (ptr[adt][po] == ptr[drd][po])                           //Checking Win Condition Colomn Wise
				{
					++win;
				}

				                                                               
			}
			else
			{
				adt = 100;
			}
		}
		if (win == n - 1)
		{
			cout << "Game End " << endl;

			po = 100;
			return true;
		}

	}
	int wint = 0;
	for (int al = 0; al < n - 1; ++al)
	{
		char dp = ' ';
		int bm = al + 1;
		
		if (ptr[al][al] != dp && ptr[bm][bm] != dp)
		{
			if (ptr[al][al] == ptr[bm][bm])
			{
				++wint;
			}                                                  // Checking Win Condition Diagnolly from Left Side
		}
		if (wint == n - 1)
		{
			cout << "Game End" << endl;
			return true;
		}
	}
	int ko = 0;
	for (int fg = 0, pl = n - 1; fg < n - 1 && pl >= 1; ++fg, --pl)
	{
		char kh = ' ';
		int xy = fg + 1;
		int cv = pl - 1;
		if (ptr[fg][pl] != kh && ptr[xy][cv] != kh)
		{
			if (ptr[fg][pl] == ptr[xy][cv])                           // Checking Win condition Diagnolly From Right Side
			{
				++ko;
			}

		}
		if (ko == n - 1)
		{
			cout << "Game Over" << endl;
			return true;
		}


	}
}
	}
	~tic()
	{
		{
	for (int app = 0; app < n; ++app)
	{
		delete[]ptr[app];
	}
	delete[]ptr;
	cout << "destructor called" << endl;
}
	}

};
int main()
{
	tic *obj = new tic;
	obj->map();
	obj->draw();
	obj->input();
	delete obj;
	

}
