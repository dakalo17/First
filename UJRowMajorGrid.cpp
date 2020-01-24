#include "UJRowMajorGrid.h"
#include <cstdlib>
UJRowMajorGrid::UJRowMajorGrid():UJRowMajorGrid(DEFAULT_ROWS,DEFAULT_COLS)
{

}
UJRowMajorGrid::UJRowMajorGrid(int intRows ,int intCols)
{
    _rows =intRows;
    _cols =intCols;

    array = new char*[_rows];

    for(int r=0;r<_rows;r++)
        for(int c=0;c<_cols;c++)
            array[r] = new char[_cols];

    array[0][0] = 'a';
    array[0][1] = 'b';
    array[0][2] = 'c';
    array[1][0] = 'd';
    array[1][1] = 'e';
    array[1][2] = 'f';
    array[2][0] = 'g';
    array[2][1] = 'h';
    array[2][2] = 'i';

}
UJRowMajorGrid::UJRowMajorGrid(const UJRowMajorGrid& objGrid)
{
    _rows = objGrid._rows;
    _cols = objGrid._cols;

    for(int r=0;r<_rows;r++)
        for(int c=0;c<_cols;c++)
            array[r][c] = objGrid.array[r][c];
}

bool UJRowMajorGrid::operator==(const UJRowMajorGrid&objGrid) const
{
     for(int r=0;r<_rows;r++)
        for(int c=0;c<_cols;c++)
           return this->array[r][c] == array[r][c];
    return false;
}


bool UJRowMajorGrid::operator!=(const UJRowMajorGrid&objGrid) const
{
     for(int r=0;r<_rows;r++)
        for(int c=0;c<_cols;c++)
           return this->array[r][c] != array[r][c];
    return true;
}
//Can access and modify values
char UJRowMajorGrid::operator()(const int&rIndex,const int&cIndex)
{
  //  if(rIndex)
}

char& UJRowMajorGrid::operator=(char chRHS)
{
    return  chRHS;

}

char UJRowMajorGrid::operator[](const int&Index)
{
    if(Index < 0 || Index > 8)
    {
        std::cerr<<"Index out of bound of array\n";
        exit(ERROR_INDEX_OUT_OF_BOUNDS);
    }

    if(Index >= 0 && Index <=2)
        return array[0][Index];
    else if(Index >= 3 && Index <=5)
        return array[1][Index-3];
    else if(Index >= 6 && Index <=8)
        return array[2][Index-6];
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
        for(int c=0;c<_cols;c++)
            delete[] array[r];

    delete[] array;
    array =0;
}
