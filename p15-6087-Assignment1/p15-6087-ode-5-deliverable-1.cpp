#include<stdio.h>
#include<unistd.h>
#include<curses.h>
#define DELAY 60000
using namespace std;

int main(int argc, char *argv[])
{

	initscr();
	noecho();
	curs_set(FALSE);

	int max_x, max_y, i, c;
	int m = 1;     //Mass
	int F = 1;
	double a = F / m;   //Accerlation 
	getmaxyx(stdscr, max_y, max_x);

	int pos_x = 0, pos_y = max_y - 1, dir = 1, next_x;

	WINDOW *menu_win = newwin(max_y, max_x, 0, 0);
	keypad(menu_win, TRUE);

	int N = 10;   //Length of simulation
	double hGrowth, vGrowth;
	double hRate = 1, vRate = 1;   //second(s)
	double dt = 1;
	int iterations = N / dt;

	double *Horizontal = new double[iterations];
	double *Vertical = new double[iterations];
	Horizontal[0] = 0;    //Initial velocity of object
	Vertical[0] = 0;
	/*for(int i =0; i< iterations; i++)
	{
	hGrowth = Horizontal[i-1] + a * hRate;
	Horizontal[i] = Horizontal[i-1] + hGrowth * dt;

	vGrowth = Vertical[i-1] + a * vRate;
	Vertical[i] = Vertical[i-1] + vGrowth * dt;

	//cout<< i*dt <<"\t\t"<< growth<<"\t\t"<< P[i]<<"\n";
	}*/

	int val = 0;
	int flag = 1;
	for (i = 1; i< 5000; i++)
	{
		//sleep(1);
		clear();
		mvprintw(pos_y, pos_x, "o");
		refresh();
		hGrowth = a * hRate;
		Horizontal[i] = Horizontal[i - 1] + hGrowth * dt;

		if (flag) {
			c = wgetch(menu_win);
		}
		if (c == 'j')   //Press J for jump-Ball
		{
			pos_y = 20;
		}

		if (pos_y == 0)
		{
			flag = 1;
		}
		if (pos_x == 100 || pos_x == -1) {
			dir *= -1;
		}
		pos_x += (dir);

	}

	next_x = pos_x + dir;
	if (next_x == max_x)
	{
		pos_x = (max_x - 2);
	}
	if (next_x == 0)
	{
		pos_x = 2;
	}


	endwin();
	return 0;
}
