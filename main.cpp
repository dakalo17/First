#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstdio>
using namespace std;

void draw(int row,int col)
{

    for(int r=0;r<row;r++)
    {
        for(int c=0;c<col;c++)
        {
            if(!(r == 0 || r == row-1) &&
               !(c == 0 || c == col-1)
               )
                std::cout<<"  ";
            else
                std::cout<< ". " ;
        }
        std::cout<<std::endl;
    }
}

int main(int argc,char*argv[])
{
    if(argc != 3)
        return -34;

    bool Cond=true;
    int size =1;
	
    draw(atoi(argv[1]),atoi(argv[2]));
    while(Cond)
    {
        char key = '\0';
        cin >> key;
        switch(key)
        {
            case 'A':
            case 'a':
            {

                system("cls");
                std::cout<< '('  << size/2 << ',' << size/2<<')'  << std::endl;

                draw(atoi(argv[1])+size,atoi(argv[2])+size);

                size ++;
            }
                break;
            case 'X':
            case 'x':
            {
                Cond = false;
            }
        }
    }
    return 0;
}
