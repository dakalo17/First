#include"UJRowMajorGrid.h"

int main()
{
    UJRowMajorGrid g;

    for(int i=0;i<9;i++)
        std::cout<< "g[" << i << "] :" << g[i] <<std::endl;

    return 0;
}
