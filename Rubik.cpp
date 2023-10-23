#include <iostream>
#include <fstream>
#include "Rubik.h"
#include <vector>
#include <string>
#include <ctime>

using namespace std;
using Face = char**;

int NumberOfCentersType(int size)
{
    if(size%2 == 0) return ((size-2)*(size-2))/4;
    else return ((size-2)*(size-2)-1)/4;
}

Cube::Cube(int size)
{
    size_cube = size;

    White = new char*[size];
    Blue = new char*[size];
    Orange = new char*[size];
    Green = new char*[size];
    Red = new char*[size];
    Yellow = new char*[size];
    
    for(int i=0;i<size;i++)
    {
        White[i] = new char[size];
        Blue[i] = new char[size];
        Orange[i] = new char[size];
        Green[i] = new char[size];
        Red[i] = new char[size];
        Yellow[i] = new char[size];
    }
    
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            White[i][j] = '0';
            Blue[i][j] = '1';
            Orange[i][j] = '2';
            Green[i][j] = '3';
            Red[i][j] = '4';
            Yellow[i][j] = '5';
        }
    }

}

Cube::Cube()
{
    size_cube = 1;

    White = new char*[1];
    Blue = new char*[1];
    Orange = new char*[1];
    Green = new char*[1];
    Red = new char*[1];
    Yellow = new char*[1];
    
    White[0] = new char[1];
    Blue[0] = new char[1];
    Orange[0] = new char[1];
    Green[0] = new char[1];
    Red[0] = new char[1];
    Yellow[0] = new char[1];
}

Cube::Cube(const Cube& c1)
{
    size_cube = c1.size_cube;

    White = new char*[size_cube];
    Blue = new char*[size_cube];
    Orange = new char*[size_cube];
    Green = new char*[size_cube];
    Red = new char*[size_cube];
    Yellow = new char*[size_cube];
    
    for(int i=0;i<size_cube;i++)
    {
        White[i] = new char[size_cube];
        Blue[i] = new char[size_cube];
        Orange[i] = new char[size_cube];
        Green[i] = new char[size_cube];
        Red[i] = new char[size_cube];
        Yellow[i] = new char[size_cube];
    }
    
    for(int i=0;i<size_cube;i++)
    {
        for(int j=0;j<size_cube;j++)
        {
            White[i][j] = c1.White[i][j];
            Blue[i][j] = c1.Blue[i][j];
            Orange[i][j] = c1.Orange[i][j];
            Green[i][j] = c1.Green[i][j];
            Red[i][j] = c1.Red[i][j];
            Yellow[i][j] = c1.Yellow[i][j];
        }
    }
}

Cube& Cube::operator=(const Cube& c)
{
    if (this == &c) 
    {
        return *this;
    }

    if (size_cube != c.size_cube) 
    {
        for(int i=0;i<size_cube;i++)
        {
            delete[] White[i];
            delete[] Blue[i];
            delete[] Orange[i];
            delete[] Green[i];
            delete[] Red[i];
            delete[] Yellow[i];
        }

        delete[] White;
        delete[] Blue;
        delete[] Orange;
        delete[] Green;
        delete[] Red;
        delete[] Yellow;

        size_cube = c.size_cube;

        White = new char*[size_cube];
        Blue = new char*[size_cube];
        Orange = new char*[size_cube];
        Green = new char*[size_cube];
        Red = new char*[size_cube];
        Yellow = new char*[size_cube];
        
        for(int i=0;i<size_cube;i++)
        {
            White[i] = new char[size_cube];
            Blue[i] = new char[size_cube];
            Orange[i] = new char[size_cube];
            Green[i] = new char[size_cube];
            Red[i] = new char[size_cube];
            Yellow[i] = new char[size_cube];
        }
    }

    for(int i=0;i<size_cube;i++)
    {
        for(int j=0;j<size_cube;j++)
        {
            White[i][j] = c.White[i][j];
            Blue[i][j] = c.Blue[i][j];
            Orange[i][j] = c.Orange[i][j];
            Green[i][j] = c.Green[i][j];
            Red[i][j] = c.Red[i][j];
            Yellow[i][j] = c.Yellow[i][j];
        }
    }

    return *this;
}

Cube::~Cube()
{
    for(int i=0;i<size_cube;i++)
    {
        delete[] White[i];
        delete[] Blue[i];
        delete[] Orange[i];
        delete[] Green[i];
        delete[] Red[i];
        delete[] Yellow[i];
    }

    delete[] White;
    delete[] Blue;
    delete[] Orange;
    delete[] Green;
    delete[] Red;
    delete[] Yellow;
}

void Cube::print_face(Face f)
{
    for(int i=0;i<size_cube;i++)
    {
        for(int j=0;j<size_cube;j++)
            switch (f[i][j])
            {
            case '0':
                cout << 'W';
                break;
            case '1':
                cout << 'B';
                break;
            case '2':
                cout << 'O';
                break;
            case '3':
                cout << 'G';
                break;
            case '4':
                cout << 'R';
                break;
            case '5':
                cout << 'Y';
                break;
            }
        cout << endl;
    }
}

void Cube::print_cube()
{
    print_face(White);
    cout << endl;
    print_face(Blue);
    cout << endl;
    print_face(Orange);
    cout << endl;
    print_face(Green);
    cout << endl;
    print_face(Red);
    cout << endl;
    print_face(Yellow);
}

bool Cube::is_solved()
{
    for(int i=0;i<size_cube;i++)
    {
        for(int j=0;j<size_cube;j++)
        {
            if(White[i][j] != '0') return false;
            if(Blue[i][j] != '1') return false;
            if(Orange[i][j] != '2') return false;
            if(Green[i][j] != '3') return false;
            if(Red[i][j] != '4') return false;
            if(Yellow[i][j] != '5') return false;
        }
    }
    return true;
}

void Cube::swap_own(Face &f, int NumberOfTurns)
{
    int n = size_cube - 1;

    if(NumberOfTurns == 1)
    {
        for(int i=0;i<n;i++)
        {
            swap(f[0][i],f[i][n]);
            swap(f[0][i],f[n][n-i]);
            swap(f[0][i],f[n-i][0]);
        }

        int sh = size_cube - 2;
        int x = sh;

        for(int j=0;j<sh/2;j=j+1)
        {
            for(int i=0;i<x-1;i=i+1)
            {
                swap(f[j+1][i+j+1],f[i+j+1][sh-j]);
                swap(f[j+1][i+j+1],f[sh-j][sh-i-j]);
                swap(f[j+1][i+j+1],f[sh-i-j][j+1]);
            }

            x = x - 2;
        }     
    }

    else if(NumberOfTurns == 2)
    {
        for(int i=0;i<n;i++)
        {
            swap(f[0][i],f[n][n-i]);
            swap(f[i][n],f[n-i][0]);
        }

        int sh = size_cube - 2;
        int x = sh;
        
        for(int j=0;j<sh/2;j=j+1)
        {
            for(int i=0;i<x-1;i=i+1)
            {           
                swap(f[j+1][i+j+1],f[sh-j][sh-i-j]);
                swap(f[i+j+1][sh-j],f[sh-i-j][j+1]);
            }

            x = x - 2;
        }       
    }

    else if(NumberOfTurns == 3)
    {
        for(int i=0;i<n;i++)
        {
            swap(f[0][i],f[n-i][0]);
            swap(f[0][i],f[n][n-i]);
            swap(f[0][i],f[i][n]);
        }
        
        int sh = size_cube - 2;
        int x = sh;
        
        for(int j=0;j<sh/2;j=j+1)
        {
            for(int i=0;i<x-1;i=i+1)
            {
                swap(f[j+1][i+j+1],f[sh-i-j][j+1]);
                swap(f[j+1][i+j+1],f[sh-j][sh-i-j]);
                swap(f[j+1][i+j+1],f[i+j+1][sh-j]);
            }

            x = x - 2;
        }   
    }
    
}

void Cube::U(int slice, int NumberOfTurns)
{
    if(slice == 1)
    {
        swap_own(White, NumberOfTurns);
    }

    if(slice == size_cube)
    {
        D(1,3*NumberOfTurns);       
    }

    else
    {
        int sl = slice - 1;

        if(NumberOfTurns == 1)
        {
            swap(Orange[sl],Blue[sl]);
            swap(Orange[sl],Red[sl]);
            swap(Orange[sl],Green[sl]);
        }

        else if(NumberOfTurns == 2)
        {
            swap(Orange[sl],Red[sl]);
            swap(Blue[sl],Green[sl]); 
        }

        else if(NumberOfTurns == 3)
        {
            swap(Orange[sl],Green[sl]);
            swap(Orange[sl],Red[sl]);
            swap(Orange[sl],Blue[sl]);   
        }
    }
}

// Mouvement D

void Cube::D(int slice, int NumberOfTurns)
{
    if(slice == 1)
    {
        swap_own(Yellow, NumberOfTurns);
    }

    if(slice == size_cube)
    {
        U(1,3*NumberOfTurns);
    }

    else
    {   
        int n = size_cube - 1;
        int sl = slice - 1;

        if(NumberOfTurns == 1)
        {
            swap(Orange[n-sl],Green[n-sl]);
            swap(Orange[n-sl],Red[n-sl]);
            swap(Orange[n-sl],Blue[n-sl]);      
        }

        else if(NumberOfTurns == 2)
        {     
            swap(Orange[n-sl],Red[n-sl]);
            swap(Blue[n-sl],Green[n-sl]);
        }

        else if(NumberOfTurns == 3)
        {
            swap(Orange[n-sl],Blue[n-sl]);
            swap(Orange[n-sl],Red[n-sl]);
            swap(Orange[n-sl],Green[n-sl]);
        }
    }
}

// Mouvement R

void Cube::R(int slice, int NumberOfTurns)
{
    if(slice == 1)
    {
        swap_own(Orange, NumberOfTurns);
    }

    if(slice == size_cube)
    {
        L(1,3*NumberOfTurns);
    }

    else
    {
        int n = size_cube - 1;
        int sl = slice - 1;

        int i,j;

        if(NumberOfTurns == 1)
        {
            for(int i=0;i<size_cube;i++)
            {   
                swap(White[i][n-sl],Green[n-i][sl]);
                swap(White[i][n-sl],Yellow[i][n-sl]);
                swap(White[i][n-sl],Blue[i][n-sl]);
            }
        }

        else if(NumberOfTurns == 2)
        {
            for(int i=0;i<size_cube;i++)
            {   
                swap(White[i][n-sl],Yellow[i][n-sl]);
                swap(Green[n-i][sl],Blue[i][n-sl]);
            }
        }

        else if(NumberOfTurns == 3)
        {
            for(int i=0;i<size_cube;i++)
            {   
                swap(White[i][n-sl],Blue[i][n-sl]);
                swap(White[i][n-sl],Yellow[i][n-sl]);
                swap(White[i][n-sl],Green[n-i][sl]);
            }
        }
    }
}

// Mouvement L

void Cube::L(int slice, int NumberOfTurns)
{
    if(slice == 1)
    {
        swap_own(Red, NumberOfTurns);
    }

    if(slice == size_cube)
    {
        R(1,3*NumberOfTurns);
    }

    else
    {
        int n = size_cube - 1;
        int sl = slice - 1;

        if(NumberOfTurns == 1)
        {
            for(int i=0;i<size_cube;i++)
            {   
                swap(White[i][sl],Blue[i][sl]);
                swap(White[i][sl],Yellow[i][sl]);
                swap(White[i][sl],Green[n-i][n-sl]);
            }
        }

        else if(NumberOfTurns == 2)
        {
            for(int i=0;i<size_cube;i++)
            {   
                swap(White[i][sl],Yellow[i][sl]);
                swap(Green[n-i][n-sl],Blue[i][sl]);
            }
        }

        else if(NumberOfTurns == 3)
        {
            for(int i=0;i<size_cube;i++)
            {   
                swap(White[i][sl],Green[n-i][n-sl]);
                swap(White[i][sl],Yellow[i][sl]);
                swap(White[i][sl],Blue[i][sl]);
            }
        }
    }
}

// Mouvement F

void Cube::F(int slice, int NumberOfTurns)
{
    if(slice == 1)
    {
        swap_own(Blue, NumberOfTurns);
    }

    if(slice == size_cube)
    {
        B(1,3*NumberOfTurns);
    }

    else
    {
        int n = size_cube - 1;
        int sl = slice - 1;

        if(NumberOfTurns == 1)
        {
            for(int i=0;i<size_cube;i++)
            {   
                swap(White[n-sl][i],Orange[i][sl]);
                swap(White[n-sl][i],Yellow[sl][n-i]);
                swap(White[n-sl][i],Red[n-i][n-sl]);
            }
        }

        else if(NumberOfTurns == 2)
        {
            for(int i=0;i<size_cube;i++)
            {   
                swap(White[n-sl][i],Yellow[sl][n-i]);
                swap(Red[n-i][n-sl],Orange[i][sl]);
            }
        }

        else if(NumberOfTurns == 3)
        {
            for(int i=0;i<size_cube;i++)
            {   
                swap(White[n-sl][i],Red[n-i][n-sl]);
                swap(White[n-sl][i],Yellow[sl][n-i]);
                swap(White[n-sl][i],Orange[i][sl]);
            }
        }
    }
}

// Mouvement B

void Cube::B(int slice, int NumberOfTurns)
{
    if(slice == 1)
    {
        swap_own(Green, NumberOfTurns);
    }

    if(slice == size_cube)
    {
        F(1,3*NumberOfTurns);
    }

    else
    {
        int n = size_cube - 1;
        int sl = slice - 1;

        if(NumberOfTurns == 1)
        {
            for(int i=0;i<size_cube;i++)
            {   
                swap(White[sl][i],Red[n-i][sl]);
                swap(White[sl][i],Yellow[n-sl][n-i]);
                swap(White[sl][i],Orange[i][n-sl]);
            }
        }

        else if(NumberOfTurns == 2)
        {
            for(int i=0;i<size_cube;i++)
            {   
                swap(White[sl][i],Yellow[n-sl][n-i]);
                swap(Red[n-i][sl],Orange[i][n-sl]);
            }
        }

        else if(NumberOfTurns == 3)
        {
            for(int i=0;i<size_cube;i++)
            {   
                swap(White[sl][i],Orange[i][n-sl]);
                swap(White[sl][i],Yellow[n-sl][n-i]);
                swap(White[sl][i],Red[n-i][sl]);
            }
        }
    }
}


void Cube::Uw(int slice, int NumberOfTurns)
{
    for(int i=1;i<slice+1;i++) U(i,NumberOfTurns);
}

void Cube::Dw(int slice, int NumberOfTurns)
{
    for(int i=1;i<slice+1;i++) D(i,NumberOfTurns);
}

void Cube::Rw(int slice, int NumberOfTurns)
{
    for(int i=1;i<slice+1;i++) R(i,NumberOfTurns);
}

void Cube::Lw(int slice, int NumberOfTurns)
{
    for(int i=1;i<slice+1;i++) L(i,NumberOfTurns);
}

void Cube::Fw(int slice, int NumberOfTurns)
{
    for(int i=1;i<slice+1;i++) F(i,NumberOfTurns);
}

void Cube::Bw(int slice, int NumberOfTurns)
{
    for(int i=1;i<slice+1;i++) B(i,NumberOfTurns);
}

void Cube::x(int NumberOfTurns)
{
    Rw(size_cube,NumberOfTurns);
}

void Cube::y(int NumberOfTurns) 
{
    Uw(size_cube,NumberOfTurns);
}

void Cube::z(int NumberOfTurns) 
{
    Fw(size_cube,NumberOfTurns);
}

void Cube::apply_move(Move m)
{
    int n = m.nb_w();
    int NumberOfTurns = m.NumberOfTurns();
    char sgl_move = m.ext_sgl_move();

    if(sgl_move == 'U')
    {
        if(!m.is_wide()) U(n,NumberOfTurns);
        else Uw(n,NumberOfTurns);
    }
    else if(sgl_move == 'D')
    {
        if(!m.is_wide()) D(n,NumberOfTurns);
        else Dw(n,NumberOfTurns);
    }
    else if(sgl_move == 'R')
    {
        if(!m.is_wide()) R(n,NumberOfTurns);
        else Rw(n,NumberOfTurns);
    }
    else if(sgl_move == 'L')
    {
        if(!m.is_wide()) L(n,NumberOfTurns);
        else Lw(n,NumberOfTurns);
    }
    else if(sgl_move == 'F')
    {
        if(!m.is_wide()) F(n,NumberOfTurns);
        else Fw(n,NumberOfTurns);
    }
    else if(sgl_move == 'B')
    {
        if(!m.is_wide()) B(n,NumberOfTurns);
        else Bw(n,NumberOfTurns);
    }
    else if(sgl_move == 'M') L(size_cube/2+1,NumberOfTurns);
    else if(sgl_move == 'E') D(size_cube/2+1,NumberOfTurns);
    else if(sgl_move == 'S') F(size_cube/2+1,NumberOfTurns);

    else if(sgl_move == 'x') x(NumberOfTurns);
    else if(sgl_move == 'y') y(NumberOfTurns);
    else if(sgl_move == 'z') z(NumberOfTurns);

}

vector<string> split(string scr)
{
    vector<string> tmp;
    string word = "";
    int i = 0;
    for(auto x : scr)
    {
        if(x == ' ')
        {
            tmp.push_back(word);
            word = "";
            i++;
        }
        else if(x != '\n') 
        {
            word = word+x;
        }
    }
    tmp.push_back(word);

    return tmp;
}

void print_str(vector<string> str)
{
    int i = 0;
    while(str[i] != "")
    {
        cout << str[i] << endl;
        i++;
    }
}

void Cube::apply_alg(string alg)
{
    vector<string> m = split(alg);

    int i;
    for(std::vector<string>::iterator it = m.begin() ; it != m.end(); ++it)
    {
        apply_move(Move(*it));
    }
}






Move::Move(string move)
{
    m = move;
}

bool Move::is_wide()
{
    int len = m.length();
    int i;
    for(i=0;i<len;i++)
    {
        if(m[i] == 'w') return true;
    }
    return false;
}

int Move::NumberOfTurns()
{
    int len = m.length();
    if(m[len-1] == '\'') return 3;
    if(m[len-1] == '2') return 2;
    else return 1;
}

int Move::nb_w()
{
    string s;
    int i = 0;
    while(isdigit(m[i]))
    {
        s = s+m[i];
        i = i+1;
    }
    if(s.length() == 0)
    {
        if(is_wide())
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return stoi(s);
    }
}

char Move::ext_sgl_move()
{
    int i = 0;
    while(isdigit(m[i]))
    {
        i++;
    }
    return m[i];
}

string Move::return_move()
{
    return m;
}

void Move::print_move()
{
    cout << m << endl;
}






void AutomaticScramble(Cube& cube, int size)
{
    srand(time(NULL));
    int NumberOfMoves;
    if(size == 2)
    {
        NumberOfMoves = 15;
    }
    else if(size == 3)
    {
        NumberOfMoves = 25;
    }
    else if(size == 4)
    {
        NumberOfMoves = 45;
    }
    else
    {
        NumberOfMoves = 60+30*(size-5);
    }

    for(int n=0;n<NumberOfMoves;n++)
    {
        string move = "";
        char AllPossibleMoves[6] = {'U','D','R','L','F','B'};
        string NumberOfTurns[3] = {"","2","'"};
        int i = rand()%(size/2)+1;
        int j = rand()%6;
        int k = rand()%3;
        if(i == 1)
        {
            move = move + AllPossibleMoves[j] + NumberOfTurns[k];
            cube.apply_move(Move(move));
        }
        else
        {
            move = move + to_string(i) + AllPossibleMoves[j] + NumberOfTurns[k];
            cube.apply_move(Move(move));
        }

        //if(n%3000 == 0) cout << n << endl;
    }

}

string GenerateScramble(int size)
{
    srand(time(NULL));
    string scramble = "";
    int NumberOfMoves;
    if(size == 2)
    {
        NumberOfMoves = 15;
    }
    else if(size == 3)
    {
        NumberOfMoves = 25;
    }
    else if(size == 4)
    {
        NumberOfMoves = 45;
    }
    else
    {
        NumberOfMoves = 60+30*(size-5);
    }
 
    for(int n=0;n<NumberOfMoves;n++)
    {
        string move = "";
        char AllPossibleMoves[6] = {'U','D','R','L','F','B'};
        string NumberOfTurns[3] = {"","2","'"};
        int i = rand()%(size/2)+1;
        int j = rand()%6;
        int k = rand()%3;
        if(i == 1)
        {
            move = move + AllPossibleMoves[j] + NumberOfTurns[k];
            scramble = scramble + move + " ";
        }
        else
        {
            move = move + to_string(i) + AllPossibleMoves[j] + NumberOfTurns[k];
            scramble = scramble + move + " ";
        }
    }

    ofstream myfile;
    myfile.open ("Scramble.txt");
    myfile << scramble;
    myfile.close();

    return scramble;
}