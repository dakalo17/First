#ifndef UJROWMAJORGRID_H_INCLUDED
#define UJROWMAJORGRID_H_INCLUDED
#include<iostream>

class UJRowMajorGrid
{
public:

    UJRowMajorGrid();
    UJRowMajorGrid(int,int);
    UJRowMajorGrid(const UJRowMajorGrid&);
    ///Operator overloading

    /// == Operator
    bool operator==(const UJRowMajorGrid&) const;

    /// != Operator
    bool operator!=(const UJRowMajorGrid&) const;

    /// () Operator
    char operator() (const int&,const int&);

    /// [] Operator
    char operator[](const int&);

    /// = Operator
    char& operator=(char);
    /// Outputting every letter << operator
    friend std::ostream& operator<<(std::ostream& sLHS,const UJRowMajorGrid& objLHS);

    ~UJRowMajorGrid();

    const static int DEFAULT_ROWS = 3;
    const static int DEFAULT_COLS = 3;
    const static int ERROR_INDEX_OUT_OF_BOUNDS =-2;

private:
    char **array;
    int _rows;
    int _cols;
};

#endif // UJROWMAJORGRID_H_INCLUDED
