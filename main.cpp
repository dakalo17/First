#include"UJRowMajorGrid.h"

int main()
{
    UJRowMajorGrid g;
    //g[1] = 'A';

    for(int i=0;i<9;i++)
        std::cout<< "g[" << i << "] :" << g[i] <<std::endl;

    return 0;
}
