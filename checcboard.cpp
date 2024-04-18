#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>

using namespace std;

class ChessBoardArray
{
protected:
    unsigned size, base;
    int *data;

    class Row
    {
    protected:
        ChessBoardArray &board;
        int row;

    public:
        Row(ChessBoardArray &a, int i) : board(a), row(i) {}
        int &operator[](int i) const
        {
            return board.select(row, i);
        }
    };

    class ConstRow
    {
    protected:
        const ChessBoardArray &board;
        int row;

    public:
        ConstRow(const ChessBoardArray &a, int i) : board(a), row(i) {}
        int operator[](int i) const
        {
            return board.select(row, i);
        }
    };

public:
    // constructor with parameters
    ChessBoardArray(unsigned size = 0, unsigned base = 0) : size(size), base(base), data(new int[(size * size + 1) / 2]) {}

    // copy constructor
    ChessBoardArray(const ChessBoardArray &a)
    {
        delete[] data;
        size = a.size;
        base = a.base;
        data = new int[(size * size + 1) / 2];
        // copy data from org to new array
        for (int i = 0; i < ((size * size + 1) / 2); i++)
        {
            data[i] = a.data[i];
        }
    }
    ~ChessBoardArray() { delete[] data; }

    ChessBoardArray &operator=(const ChessBoardArray &a)
    {
        delete[] data;
        size = a.size;
        base = a.base;
        data = new int[(size * size + 1) / 2];
        // copy data from org to new array
        for (int i = 0; i < ((size * size + 1) / 2); i++)
        {
            data[i] = a.data[i];
        }
        return *this;
    }

    int &select(int i, int j) { return data[loc(i, j)]; }
    int select(int i, int j) const { return data[loc(i, j)]; }

    const Row operator[](int i) { return Row(*this, i); }
    const ConstRow operator[](int i) const { return ConstRow(*this, i); }

    friend ostream &operator<<(ostream &out, const ChessBoardArray &a)
    {
        for (int i = 0; i < a.size; i++)
        {
            for (int j = 0; j < a.size; j++)
            {

                cout << setw(4);
                if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
                    cout << a.select(i + a.base, j + a.base);
                else
                    cout << 0;
            }
            cout << endl;
        }

        return out;
    }

private:
    unsigned int loc(int i, int j) const throw(out_of_range)
    {
        int di = i - base, dj = j - base;
        if (di < 0 || dj < 0 || di >= size || dj >= size)
            throw out_of_range("invalid block");

        if ((di % 2 == 0 && dj % 2 == 1) || (di % 2 == 1 && dj % 2 == 0))
            throw out_of_range("block is black");

        unsigned int n = di * size + dj;
        return n / 2;
    }
};

int main()
{
    ChessBoardArray a(4, 1);
    a[2][4] = 2;
    cout << a;
}