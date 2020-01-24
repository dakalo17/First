#include "UJRowMajorGrid.h"
#include <cstdlib>
UJRowMajorGrid::UJRowMajorGrid():UJRowMajorGrid(DEFAULT_ROWS,DEFAULT_COLS){}
UJRowMajorGrid::UJRowMajorGrid(int intRows ,int intCols)
{
    _rows =intRows;
    _cols =intCols;

    array = new char*[_rows];

    for(int r=0;r<_rows;r++)
    {
        array[r] = new char[_cols];
        for(int c=0;c<_cols;c++)
        {
            array[r][c] = r+c+1;
        }
    }
}
UJRowMajorGrid::UJRowMajorGrid(const UJRowMajorGrid& objGrid)
{
    _rows = objGrid._rows;
    _cols = objGrid._cols;

    for(int r=0;r<_rows;r++)
        for(int c=0;c<_cols;c++)
            this->array[r][c] = objGrid.array[r][c];
}

bool UJRowMajorGrid::operator==(const UJRowMajorGrid&objGrid) const
{
     for(int r=0;r<_rows;r++)
     {
        for(int c=0;c<_cols;c++)
        {
            if(this->array[r][c] != array[r][c])
                return false;
        }
     }

    return true;
}


bool UJRowMajorGrid::operator!=(const UJRowMajorGrid&objGrid) const
{
    return objGrid != *this;
}
//Can access and modify values
char &UJRowMajorGrid::operator()(const int&rIndex,const int&cIndex)
{
    return this->array[rIndex][cIndex];
}

char& UJRowMajorGrid::operator=(char chRHS)
{
    return  chRHS;
}

char &UJRowMajorGrid::operator[](const int&Index)
{
    if(Index < 0)
    {
        std::cerr<<"Index out of bound of array\n";
        exit(ERROR_INDEX_OUT_OF_BOUNDS);
    }
    int size = 2;
    int count= 0;
    int set =0;

    while(1)
    {
        if(Index >= set && Index<=size)
            return array[count][Index-set];
        set +=3;
        size+=3;
        count++;
    }
}

std::ostream&operator<<(std::ostream& sLHS,const UJRowMajorGrid& objLHS)
{
    for(int r=0;r<objLHS._rows;r++)
        for(int c=0;c<objLHS._cols;c++)
            sLHS << objLHS.array[r][c]  << ' ';
    sLHS << '\n';
    return sLHS;
}

UJRowMajorGrid::~UJRowMajorGrid()
{
    for(int r=0;r<_rows;r++)
        delete[] array[r];

    delete[] array;
    array =0;
}
