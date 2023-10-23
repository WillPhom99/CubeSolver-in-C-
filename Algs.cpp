#include <string>
#include <iostream>
#include "Algs.h"
using namespace std;
#include "Rubik.h"

//Centers


string alg(int i,int s,string c)
{

    //cas mouvement 'L'
    switch(c[0])
    {
        case 'L':
        {
            if(c.length()==1)
            {
                if(i==1) return("2L");
                else if(i==s/2 and s%2==1) return("M");
                else if(i<s/2) return(to_string(i+1)+"L");
                else return(to_string(s-i)+"R'");
            }

            else if(c[1]=='2')
            {
                if(i==1) return("2L2");
                else if(i==s/2 and s%2==1) return("M2");
                else if(i<s/2) return(to_string(i+1)+"L2");
                else return(to_string(s-i)+"R2");
            }

            else
            {
                if(i==1) return("2L'");
                else if(i==s/2 and s%2==1) return("M'");
                else if(i<s/2) return(to_string(i+1)+"L'");
                else return(to_string(s-i)+"R");
            }
        }

    //cas mouvement 'R'

        case 'R':
        {
            if(c.length()==1)
            {
                if(i==1) return("2R");
                else if(i==s/2 and s%2==1) return("M'");
                else if(i<s/2) return(to_string(i+1)+"R");
                else return(to_string(s-i)+"L'");
            }

            if(c[1]=='2')
            {
                if(i==1) return("2R2");
                else if(i==s/2 and s%2==1) return("M2");
                else if(i<s/2) return(to_string(i+1)+"r2");
                else return(to_string(s-i)+"L2");
            }

            else
            {
                if(i==1) return("2R'");
                else if(i==s/2 and s%2==1) return("M");
                else if(i<s/2) return(to_string(i+1)+"R'");
                else return(to_string(s-i)+"L");
            }
        }

    //cas mouvement 'U'

        case 'U':
        {
            if(c.length()==1)
            {
                if(i==1) return("2U");
                else if(i==s/2 and s%2==1) return("E'");
                else if(i<s/2) return(to_string(i+1)+"U");
                else return(to_string(s-i)+"D'");
            }

            if(c[1]=='2')
            {
                if(i==1) return("2U2");
                else if(i==s/2 and s%2==1) return("E2");
                else if(i<s/2) return(to_string(i+1)+"U2");
                else return(to_string(s-i)+"D2");
            }

            else
            {
                if(i==1) return("2U'");
                else if(i==s/2 and s%2==1) return("E");
                else if(i<s/2) return(to_string(i+1)+"U'");
                else return(to_string(s-i)+"D");
            }
        }

    //cas mouvement 'D'

        case 'D':
        {
            if(c.length()==1)
            {
                if(i==1) return("2D");
                else if(i==s/2 and s%2==1) return("E");
                else if(i<s/2) return(to_string(i+1)+"D");
                else return(to_string(s-i)+"U'");
            }

            if(c[1]=='2')
            {
                if(i==1) return("2D2");
                else if(i==s/2 and s%2==1) return("E2");
                else if(i<s/2) return(to_string(i+1)+"D2");
                else return(to_string(s-i)+"U2");
            }

            else
            {
                if(i==1) return("2D'");
                else if(i==s/2 and s%2==1) return("E'");
                else if(i<s/2) return(to_string(i+1)+"D'");
                else return(to_string(s-i)+"U");
            }
        }
    }
}

string alg2(int i,char c)
{
    return(to_string(i+1)+c);
}

/*string return_3S_center_alg(char c1,char c2,int s,int i,int j)
{

    string l = alg(j,s,"L");
    string lp = alg(j,s,"L'");
    string l2 = alg(j,s,"L2");
    string r = alg(j,s,"R");
    string rp = alg(j,s,"R'");
    string r2 = alg(j,s,"R2");
    string u = alg(j,s,"U");
    string up = alg(j,s,"U'");
    string u2 = alg(j,s,"U2");
    string d = alg(j,s,"D");
    string dp = alg(j,s,"D'");
    string d2 = alg(j,s,"D2");
    string L = alg2(i,'L');
    string R = alg2(i,'R');
    string U = alg2(i,'U');
    string D = alg2(i,'D');

    if(c1 == 'A')
    {
        if(c2 == 'E') return(U+"' "+"U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+lp+" "+U);
        else if(c2 == 'F') return("F2 "+R+" "+d2+" "+R+"' U "+R+" "+d2+" "+R+"' U' F2");
        else if(c2 == 'G') return("F "+R+" "+d2+" "+R+"' U "+R+" "+d2+" "+R+"' U' F'");
        else if(c2 == 'H') return(R+" "+d2+" "+R+"' U "+R+" "+d2+" "+R+"' U'");
        else if(c2 == 'I') return("U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+lp);
        else if(c2 == 'J') return(R+"' "+u+" "+R+" U "+R+"' "+up+" "+R+" U'");
        else if(c2 == 'K') return("R2 U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+lp+" R2");
        else if(c2 == 'L') return("R2 "+R+"' "+u+" "+R+" U "+R+"' "+up+" "+R+" U' R2");
        else if(c2 == 'M') return("B "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" U' B'");
        else if(c2 == 'N') return(R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" U'");
        else if(c2 == 'O') return("B' "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" U' B");
        else if(c2 == 'P') return("B2 "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" U' B2");
        else if(c2 == 'Q') return("U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+lp);
        else if(c2 == 'R') return(R+"' "+up+" "+R+" U "+R+"' "+u+" "+R+" U'");
        else if(c2 == 'S') return("L2 U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+lp+" L2");
        else if(c2 == 'T') return("L2 "+R+"' "+up+" "+R+" U "+R+"' "+u+" "+R+" U' L2");
        else if(c2 == 'U') return(R+"' U "+R+" U' "+l2+" U "+R+"' U' "+l2+" "+R);
        else if(c2 == 'V') return("D' "+R+"' U "+R+" U' "+l2+" U "+R+"' U' "+l2+" "+R+" D");
        else if(c2 == 'W') return("D2 "+R+"' U "+R+" U' "+l2+" U "+R+"' U' "+l2+" "+R+" D2");
        else if(c2 == 'X') return("D "+R+"' U "+R+" U' "+l2+" U "+R+"' U' "+l2+" "+R+" D'");
        else return("");
    }

    else if(c1 == 'C')
    {
        if(c2 == 'E') return("F' "+R+" "+d2+" "+R+"' U' "+R+" "+d2+" "+R+"' U F");
        else if(c2 == 'F') return("F2 "+R+" "+d2+" "+R+"' U' "+R+" "+d2+" "+R+"' U F2");
        else if(c2 == 'G') return("F "+R+" "+d2+" "+R+"' U' "+R+" "+d2+" "+R+"' U F'");
        else if(c2 == 'H') return(R+" "+d2+" "+R+"' U' "+R+" "+d2+" "+R+"' U");
        else if(c2 == 'I') return("R "+R+"' "+u+" "+R+" U' "+R+"' "+up+" "+R+" U R'");
        else if(c2 == 'J') return(R+"' "+u+" "+R+" U' "+R+"' "+up+" "+R+" U");
        else if(c2 == 'K') return("U "+rp+" "+D+"' "+r+" U' "+rp+" "+D+" "+r);
        else if(c2 == 'L') return("R' U "+rp+" "+D+"' "+r+" U' "+rp+" "+D+" "+r+" R");
        else if(c2 == 'M') return("B "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" U B'");
        else if(c2 == 'N') return(R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" U");
        else if(c2 == 'O') return(D+"' "+"U "+rp+" "+D+"' "+r+" U' "+rp+" "+D+" "+r+" "+D);
        else if(c2 == 'P') return("B2 "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" U B2");
        else if(c2 == 'Q') return("L "+R+"' "+up+" "+R+" U' "+R+"' "+u+" "+R+" U L'");
        else if(c2 == 'R') return(R+"' "+up+" "+R+" U' "+R+"' "+u+" "+R+" U");
        else if(c2 == 'S') return("U "+rp+" "+D+" "+r+" U' "+rp+" "+D+"' "+r);
        else if(c2 == 'T') return("L2 "+R+"' "+up+" "+R+" U' "+R+"' "+u+" "+R+" U"+" L2");
        else if(c2 == 'U') return("D' "+L+" "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" U "+L+"' D");
        else if(c2 == 'V') return("D2 "+L+" "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" U "+L+"' D2");
        else if(c2 == 'W') return("D "+L+" "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" U "+L+"' D'");
        else if(c2 == 'X') return(L+" "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" U "+L+"'");
        else return("");
    }

    else if(c1 == 'D')
    {
        if(c2 == 'E') return("F U2 "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" F'");
        else if(c2 == 'F') return("U2 "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" "+L);
        else if(c2 == 'G') return("F' U2 "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" F");
        else if(c2 == 'H') return(R+" "+d2+" "+R+"' U2 "+R+" "+d2+" "+R+"' U2");
        else if(c2 == 'I') return("R "+R+"' "+u+" "+R+" U2 "+R+"' "+up+" "+R+" U2"+" R'");
        else if(c2 == 'J') return(R+"' "+u+" "+R+" U2 "+R+"' "+up+" "+R+" U2");
        else if(c2 == 'K') return("R U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"'"+" R'");
        else if(c2 == 'L') return("U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"'");
        else if(c2 == 'M') return("B "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" U2"+" B'");
        else if(c2 == 'N') return(R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" U2");
        else if(c2 == 'O') return("B' "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" U2"+" B");
        else if(c2 == 'P') return("U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"'");
        else if(c2 == 'Q') return("L "+R+"' "+up+" "+R+" U2 "+R+"' "+u+" "+R+" U2"+" L'");
        else if(c2 == 'R') return(R+"' "+up+" "+R+" U2 "+R+"' "+u+" "+R+" U2");
        else if(c2 == 'S') return("L U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"'"+" L'");
        else if(c2 == 'T') return("U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"'");
        else if(c2 == 'U') return(R+"' U2 "+R+" U' "+l2+" U "+R+"' U' "+l2+" U' "+R);
        else if(c2 == 'V') return("D' "+R+"' U2 "+R+" U' "+l2+" U "+R+"' U' "+l2+" U' "+R+" D");
        else if(c2 == 'W') return("D2 "+R+"' U2 "+R+" U' "+l2+" U "+R+"' U' "+l2+" U' "+R+" D2");
        else if(c2 == 'X') return("D "+R+"' U2 "+R+" U' "+l2+" U "+R+"' U' "+l2+" U' "+R+" D'");
        else return("");
    }

    else if(c1 == 'E')
    {
        if( c2 == 'A') return(U+"' "+l+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+U);
        else if(c2 == 'C') return("F' U' "+R+" "+d2+" "+R+"' U "+R+" "+d2+" "+R+"' F");
        else if(c2 == 'D') return("F "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" U2"+" F'");
        else if(c2 == 'I') return(lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"'");
        else if(c2 == 'J') return("R' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' R");
        else if(c2 == 'K') return("R2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' R2");
        else if(c2 == 'L') return("R "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' R'");
        else if(c2 == 'M') return(lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"2");
        else if(c2 == 'N') return("B' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"2 B");
        else if(c2 == 'O') return("B2 "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"2 B2");
        else if(c2 == 'P') return("B "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"2 B'");
        else if(c2 == 'Q') return(lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U);
        else if(c2 == 'R') return("L' "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" L");
        else if(c2 == 'S') return("L2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" L2");
        else if(c2 == 'T') return("L "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" L'");
        else if(c2 == 'U') return("D "+R+"2 U' "+lp+" U "+R+"2 U' "+l+" U D'");
        else if(c2 == 'V') return(R+"2 U' "+lp+" U "+R+"2 U' "+l+" U");
        else if(c2 == 'W') return("D' "+R+"2 U' "+lp+" U "+R+"2 U' "+l+" U D");
        else if(c2 == 'X') return("D2 "+R+"2 U' "+lp+" U "+R+"2 U' "+l+" U D2");
        else return("");
    }

    else if(c1 == 'F')
    {
        if(c2 == 'A') return("F2 U "+R+" "+d2+" "+R+"' U' "+R+" "+d2+" "+R+"' F2");
        else if( c2 == 'C') return("F2 U' "+R+" "+d2+" "+R+"' U "+R+" "+d2+" "+R+"' F2");
        else if(c2 == 'D') return(L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" U2");
        else if(c2 == 'I') return("F' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' F");
        else if(c2 == 'J') return("R' F' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' F R");
        else if(c2 == 'K') return("R2 F' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' F R2");
        else if(c2 == 'L') return("F2 "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" F2");
        else if(c2 == 'M') return("B "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"' B'");
        else if(c2 == 'N') return(u2+" "+L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"'");
        else if(c2 == 'O') return("B' "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"' B");
        else if(c2 == 'P') return("B2 "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"' B2");
        else if(c2 == 'Q') return("F' "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" F");
        else if(c2 == 'R') return("L' F' "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" F L");
        else if(c2 == 'S') return("L2 F' "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" F L2");
        else if(c2 == 'T') return("F2 "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" F2");
        else if(c2 == 'U') return("U' "+l2+" U "+R+" U' "+l2+" U "+R+"'");
        else if(c2 == 'V') return("D' U' "+l2+" U "+R+" U' "+l2+" U "+R+"' D");
        else if(c2 == 'W') return("D2 U' "+l2+" U "+R+" U' "+l2+" U "+R+"' D2");
        else if(c2 == 'X') return("D U' "+l2+" U "+R+" U' "+l2+" U "+R+"' D'");
        else return("");
    }

    else if(c1 == 'G')
    {
        if(c2 == 'A') return("F U "+R+" "+d2+" "+R+"' U' "+R+" "+d2+" "+R+"' F'");
        else if(c2 == 'C') return("F U' "+R+" "+d2+" "+R+"' U "+R+" "+d2+" "+R+"' F'");
        else if(c2 == 'D') return("F' "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" U2 F");
        else if(c2 == 'I') return("F2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' F2");
        else if(c2 == 'J') return("R' F2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' F2 R");
        else if(c2 == 'K') return("R2 F2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' F2 R2");
        else if(c2 == 'L') return("R F2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' F2 R'");
        else if(c2 == 'M') return("F2 "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"2 F2");
        else if(c2 == 'N') return("F' "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"' F");
        else if(c2 == 'O') return(D+"2 "+l+" U' "+lp+" "+D+"2 "+l+" U "+lp);
        else if(c2 == 'P') return("F "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2+" F'");
        else if(c2 == 'Q') return("F2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" F2");
        else if(c2 == 'R') return("L' F2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" F2 L");
        else if(c2 == 'S') return("L2 F2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" F2 L2");
        else if(c2 == 'T') return("L F2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" F2 L'");
        else if(c2 == 'U') return("F' U' "+l2+" U "+R+" U' "+l2+" U "+R+"' F");
        else if(c2 == 'V') return("D' F' U' "+l2+" U "+R+" U' "+l2+" U "+R+"' F D");
        else if(c2 == 'W') return("D2 F' U' "+l2+" U "+R+" U' "+l2+" U "+R+"' F D2");
        else if(c2 == 'X') return("D F' U' "+l2+" U "+R+" U' "+l2+" U "+R+"' F D'");
        else return("");
    }

    else if(c1 == 'H')
    {
        if(c2 == 'A') return("U "+R+" "+d2+" "+R+"' U' "+R+" "+d2+" "+R+"'");
        else if(c2 == 'C') return("U' "+R+" "+d2+" "+R+"' U "+R+" "+d2+" "+R+"'");
        else if(c2 == 'D') return("U2 "+R+" "+d2+" "+R+"' U2 "+R+" "+d2+" "+R+"'");
        else if(c2 == 'I') return("F "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"'"+" F'");
        else if(c2 == 'J') return("R2 "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" R2");
        else if(c2 == 'K') return("R "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" R'");
        else if(c2 == 'L') return(L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d);
        else if(c2 == 'M') return("B' "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2+" B");
        else if(c2 == 'N') return("B2 "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2+" B2");
        else if(c2 == 'O') return("B "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2+" B'");
        else if(c2 == 'P') return(L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2);
        else if(c2 == 'Q') return("L' "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" L");
        else if(c2 == 'R') return("L2 "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" L2");
        else if(c2 == 'S') return("L "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" L'");
        else if(c2 == 'T') return(L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp);
        else if(c2 == 'U') return("F2 U' "+l2+" U "+R+" U' "+l2+" U "+R+"' F2");
        else if(c2 == 'V') return("F2 D' U' "+l2+" U "+R+" U' "+l2+" U "+R+"' D F2");
        else if(c2 == 'W') return("F2 D2 U' "+l2+" U "+R+" U' "+l2+" U "+R+"' D2 F2");
        else if(c2 == 'X') return("F2 D U' "+l2+" U "+R+" U' "+l2+" U "+R+"' D' F2");
        else return("");
    }

    else if(c1 == 'I')
    {
        if(c2 == 'A') return(l+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U");
        else if(c2 == 'C') return("R U' "+R+"' "+u+" "+R+" U "+R+"' "+up+" "+R+" R'");
        else if(c2 == 'D') return("R U2 "+R+"' "+u+" "+R+" U2 "+R+"' "+up+" "+R+" R'");
        else if(c2 == 'E') return(U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l);
        else if(c2 == 'F') return("F' "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" F");
        else if(c2 == 'G') return("F2 "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" F2");
        else if(c2 == 'H') return("F "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" F'");
        else if(c2 == 'M') return(U+" "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"2");
        else if(c2 == 'N') return("B' "+U+" "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"2"+" B");
        else if(c2 == 'O') return(l2+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+lp);
        else if(c2 == 'P') return("R' "+dp+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d2+" R");
        else if(c2 == 'Q') return(U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U);
        else if(c2 == 'R') return("L' "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" L");
        else if(c2 == 'S') return("L2 "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" L2");
        else if(c2 == 'T') return("L "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" L'");
        else if(c2 == 'U') return(lp+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l2);
        else if(c2 == 'V') return("D' "+lp+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l2+" D");
        else if(c2 == 'W') return("D2 "+lp+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l2+" D2");
        else if(c2 == 'X') return("D "+lp+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l2+" D'");
        else return("");
    }

    else if(c1 == 'J')
    {
        if(c2 == 'A') return("U "+R+"' "+u+" "+R+" U' "+R+"' "+up+" "+R);
        else if(c2 == 'C') return("U' "+R+"' "+u+" "+R+" U "+R+"' "+up+" "+R);
        else if(c2 == 'D') return("U2 "+R+"' "+u+" "+R+" U2 "+R+"' "+up+" "+R);
        else if(c2 == 'E') return("R' "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" R");
        else if(c2 == 'F') return("R' F' "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" F R");
        else if(c2 == 'G') return("R' F2 "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" F2 R");
        else if(c2 == 'H') return("R2 "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" R2");
        else if(c2 == 'M') return("B "+up+" "+L+" U2 "+L+"' "+u+" "+L+" U2 "+L+"' B'");
        else if(c2 == 'N') return(up+" "+L+" U2 "+L+"' "+u+" "+L+" U2 "+L+"'");
        else if(c2 == 'O') return("B' "+up+" "+L+" U2 "+L+"' "+u+" "+L+" U2 "+L+"'"+" B");
        else if(c2 == 'P') return("B2 "+up+" "+L+" U2 "+L+"' "+u+" "+L+" U2 "+L+"'"+" B2");
        else if(c2 == 'Q') return("R' "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" R");
        else if(c2 == 'R') return("L' R' "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" R L");
        else if(c2 == 'S') return("L2 R' "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" R L2");
        else if(c2 == 'T') return("L R' "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" R L'");
        else if(c2 == 'U') return("R' "+lp+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l2+" R");
        else if(c2 == 'V') return("D' R' "+lp+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l2+" R"+" D");
        else if(c2 == 'W') return("D2 R' "+lp+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l2+" R"+" D2");
        else if(c2 == 'X') return("D R' "+lp+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l2+" R"+" D'");
        else return("");
    }

    else if(c1 == 'K')
    {
        if(c2 == 'A') return("R2 "+l+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U R2");
        else if(c2 == 'C') return(rp+" "+D+"' "+r+" U "+rp+" "+D+" "+r+" U'");
        else if(c2 == 'D') return("R "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 R'");
        else if(c2 == 'E') return("R2 "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" R2");
        else if(c2 == 'F') return("R2 F' "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" F R2");
        else if(c2 == 'G') return("R2 F2 "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" F2 R2");
        else if(c2 == 'H') return("R "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" R'");
        else if(c2 == 'M') return("B2 "+D+" "+l+" U' "+lp+" "+D+"' "+l+" U "+lp+" B2");
        else if(c2 == 'N') return("B "+D+" "+l+" U' "+lp+" "+D+"' "+l+" U "+lp+" B'");
        else if(c2 == 'O') return(D+" "+l+" U' "+lp+" "+D+"' "+l+" U "+lp);
        else if(c2 == 'P') return("R "+dp+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d2+" R'");
        else if(c2 == 'Q') return("R2 "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" R2");
        else if(c2 == 'R') return("L2 R "+dp+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+dp+" R' L2");
        else if(c2 == 'S') return("L2 R2 "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" R2 L2");
        else if(c2 == 'T') return("R "+dp+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+dp+" R'");
        else if(c2 == 'U') return("D "+D+" "+R+"2 U' "+l+" U "+R+"2 U' "+lp+" U "+D+"' D'");
        else if(c2 == 'V') return(D+" "+R+"2 U' "+l+" U "+R+"2 U' "+lp+" U "+D+"'");
        else if(c2 == 'W') return("D' "+D+" "+R+"2 U' "+l+" U "+R+"2 U' "+lp+" U "+D+"' D");
        else if(c2 == 'X') return("D2 "+D+" "+R+"2 U' "+l+" U "+R+"2 U' "+lp+" U "+D+"' D2");
        else return("");
    }

    else if(c1 == 'L')
    {
        if(c2 == 'A') return("R "+l+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U R'");
        else if(c2 == 'C') return("R' "+rp+" "+D+"' "+r+" U "+rp+" "+D+" "+r+" U'"+" R");
        else if(c2 == 'D') return(L+" "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2");
        else if(c2 == 'E') return("F' "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" F");
        else if(c2 == 'F') return("F2 "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" F2");
        else if(c2 == 'G') return("F "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" F'");
        else if(c2 == 'H') return(dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L);
        else if(c2 == 'M') return("B' "+dp+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d2+" B");
        else if(c2 == 'N') return("B2 "+dp+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d2+" B2");
        else if(c2 == 'O') return("B "+dp+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d2+" B'");
        else if(c2 == 'P') return(dp+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d2);
        else if(c2 == 'Q') return("L' "+dp+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+dp+" L");
        else if(c2 == 'R') return("L2 "+dp+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+dp+" L2");
        else if(c2 == 'S') return("L "+dp+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+dp+" L'");
        else if(c2 == 'T') return(dp+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+dp);
        else if(c2 == 'U') return("D' "+L+"' "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+"2 D");
        else if(c2 == 'V') return("D2 "+L+"' "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+"2 D2");
        else if(c2 == 'W') return("D "+L+"' "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+"2 D'");
        else if(c2 == 'X') return(L+"' "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+"2");
        else return("");
    }

    else if(c1 == 'M')
    {
        if(c2 == 'A') return("B U "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" B'");
        else if(c2 == 'C') return("B U' "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" B'");
        else if(c2 == 'D') return("B U2 "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" B'");
        else if(c2 == 'E') return(U+"2 "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l);
        else if(c2 == 'F') return("F' "+U+"2 "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" F");
        else if(c2 == 'G') return("F2 "+U+"2 "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" F2");
        else if(c2 == 'H') return("F "+U+"2 "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" F'");
        else if(c2 == 'I') return(U+"2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"'");
        else if(c2 == 'J') return("R' "+U+"2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"' R");
        else if(c2 == 'K') return("R2 "+U+"2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"' R2");
        else if(c2 == 'L') return("R "+U+"2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"' R'");
        else if(c2 == 'Q') return(U+"2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U);
        else if(c2 == 'R') return("L' "+U+"2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+" L");
        else if(c2 == 'S') return("L2 "+U+"2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+" L2");
        else if(c2 == 'T') return("L "+U+"2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+" L'");
        else if(c2 == 'U') return("D "+U+"2 "+R+"2 U' "+lp+" U "+R+"2 U' "+l+" U "+U+"2 D'");
        else if(c2 == 'V') return(U+"2 "+R+"2 U' "+lp+" U "+R+"2 U' "+l+" U "+U+"2");
        else if(c2 == 'W') return("D' "+U+"2 "+R+"2 U' "+lp+" U "+R+"2 U' "+l+" U "+U+"2 D");
        else if(c2 == 'X') return("D2 "+U+"2 "+R+"2 U' "+lp+" U "+R+"2 U' "+l+" U "+U+"2 D2");
        else return("");
    }

    else if(c1 == 'N')
    {
        if(c2 == 'A') return("U "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R);
        else if(c2 == 'C') return("U' "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R);
        else if(c2 == 'D') return("U2 "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R);
        else if(c2 == 'E') return("B' "+U+"2 "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" B");
        else if(c2 == 'F') return(L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2);
        else if(c2 == 'G') return("F' "+L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" F");
        else if(c2 == 'H') return("F2 "+L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" F2");
        else if(c2 == 'I') return("B' "+U+"2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"'"+" B");
        else if(c2 == 'J') return(L+" U2 "+L+"' "+up+" "+L+" U2 "+L+"' "+u);
        else if(c2 == 'K') return("B "+l+" U' "+lp+" "+D+" "+l+" U "+lp+" "+D+"' B'");
        else if(c2 == 'L') return("B2 "+d2+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d+" B2");
        else if(c2 == 'Q') return("L "+L+" U2 "+L+"' "+u+" "+L+" U2 "+L+"' "+up+" L'");
        else if(c2 == 'R') return(L+" U2 "+L+"' "+u+" "+L+" U2 "+L+"' "+up);
        else if(c2 == 'S') return("L' "+L+" U2 "+L+"' "+u+" "+L+" U2 "+L+"' "+up+" L");
        else if(c2 == 'T') return("L2 "+L+" U2 "+L+"' "+u+" "+L+" U2 "+L+"' "+up+" L2");
        else if(c2 == 'U') return("D' "+L+" "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" U2 "+L+"' D");
        else if(c2 == 'V') return("D2 "+L+" "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" U2 "+L+"' D2");
        else if(c2 == 'W') return("D "+L+" "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" U2 "+L+"' D'");
        else if(c2 == 'X') return(L+" "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" U2 "+L+"'");
        else return("");
    }

    else if(c1 == 'O')
    {
        if(c2 == 'A') return("B' U "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" B");
        else if(c2 == 'C') return(D+"' "+rp+" "+D+"' "+r+" U "+rp+" "+D+" "+r+" U'"+" "+D);
        else if(c2 == 'D') return("B' U2 "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" B");
        else if(c2 == 'E') return("B2 "+U+"2 "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" B2");
        else if(c2 == 'F') return("B' "+L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" B");
        else if(c2 == 'G') return(l+" U' "+lp+" "+D+"2 "+l+" U "+lp+" "+D+"2");
        else if(c2 == 'H') return("B "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" B'");
        else if(c2 == 'I') return(l+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l2);
        else if(c2 == 'J') return("B' "+L+" U2 "+L+"' "+up+" "+L+" U2 "+L+"' "+u+" B");
        else if(c2 == 'K') return(l+" U' "+lp+" "+D+" "+l+" U "+lp+" "+D+"'");
        else if(c2 == 'L') return("B "+d2+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d+" B'");
        else if(c2 == 'Q') return("L2 "+l+" U' "+lp+" "+D+"' "+l+" U "+lp+" "+D+" L2");
        else if(c2 == 'R') return("L "+l+" U' "+lp+" "+D+"' "+l+" U "+lp+" "+D+" L'");
        else if(c2 == 'S') return(l+" U' "+lp+" "+D+"' "+l+" U "+lp+" "+D);
        else if(c2 == 'T') return("L' "+l+" U' "+lp+" "+D+"' "+l+" U "+lp+" "+D+" L");
        else if(c2 == 'U') return("D "+R+"2 U' "+l+" U "+R+"2 U' "+lp+" U D'");
        else if(c2 == 'V') return(R+"2 U' "+l+" U "+R+"2 U' "+lp+" U");
        else if(c2 == 'W') return("D' "+R+"2 U' "+l+" U "+R+"2 U' "+lp+" U D");
        else if(c2 == 'X') return("D2 "+R+"2 U' "+l+" U "+R+"2 U' "+lp+" U D2");
        else return("");
    }

    else if(c1 == 'P')
    {
        if(c2 == 'A') return("B2 U "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" B2");
        else if(c2 == 'C') return("B2 U' "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" B2");
        else if(c2 == 'D') return(L+" "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2");
        else if(c2 == 'E') return("F' "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" F");
        else if(c2 == 'F') return("F2 "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" F2");
        else if(c2 == 'G') return("F "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" F'");
        else if(c2 == 'H') return(d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L);
        else if(c2 == 'I') return("R' "+d2+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d+" R");
        else if(c2 == 'J') return("R2 "+d2+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d+" R2");
        else if(c2 == 'K') return("R "+d2+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d+" R'");
        else if(c2 == 'L') return(d2+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d);
        else if(c2 == 'Q') return("L' "+d2+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+dp+" L");
        else if(c2 == 'R') return("L2 "+d2+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+dp+" L2");
        else if(c2 == 'S') return("L "+d2+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+dp+" L'");
        else if(c2 == 'T') return(d2+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+dp);
        else if(c2 == 'U') return("D' "+L+"' "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+"2 D");
        else if(c2 == 'V') return("D2 "+L+"' "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+"2 D2");
        else if(c2 == 'W') return("D "+L+"' "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+"2 D'");
        else if(c2 == 'X') return(L+"' "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+"2");
        else return("");
    }

    else if(c1 == 'Q')
    {
        if(c2 == 'A') return(l+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U");
        else if(c2 == 'C') return("L U' "+R+"' "+up+" "+R+" U "+R+"' "+u+" "+R+" L'");
        else if(c2 == 'D') return("L U2 "+R+"' "+up+" "+R+" U2 "+R+"' "+u+" "+R+" L'");
        else if(c2 == 'E') return(U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l);
        else if(c2 == 'F') return("F' "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" F");
        else if(c2 == 'G') return("F2 "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" F2");
        else if(c2 == 'H') return("F "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" F'");
        else if(c2 == 'I') return(U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"'");
        else if(c2 == 'J') return("R' "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' R");
        else if(c2 == 'K') return("R2 "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' R2");
        else if(c2 == 'L') return("R "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' R'");
        else if(c2 == 'M') return(U+"' "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"2");
        else if(c2 == 'N') return("L "+u+" "+L+" U2 "+L+"' "+up+" "+L+" U2 "+L+"' L'");
        else if(c2 == 'O') return("L2 "+D+"' "+l+" U' "+lp+" "+D+" "+l+" U "+lp+" L2");
        else if(c2 == 'P') return("L' "+d+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d2+" L");
        else if(c2 == 'U') return(lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2);
        else if(c2 == 'V') return("D' "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" D");
        else if(c2 == 'W') return("D2 "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" D2");
        else if(c2 == 'X') return("D "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" D'");
        else return("");
    }

    else if(c1 == 'R')
    {
        if(c2 == 'A') return("U "+R+"' "+up+" "+R+" U' "+R+"' "+u+" "+R);
        else if(c2 == 'C') return("U' "+R+"' "+up+" "+R+" U "+R+"' "+u+" "+R);
        else if(c2 == 'D') return("U2 "+R+"' "+up+" "+R+" U2 "+R+"' "+u+" "+R);
        else if(c2 == 'E') return("L' "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" L");
        else if(c2 == 'F') return("L' F' "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" F L");
        else if(c2 == 'G') return("L' F2 "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" F2 L");
        else if(c2 == 'H') return("L2 "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" L2");
        else if(c2 == 'I') return("L' "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' L");
        else if(c2 == 'J') return("L' R' "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' R L");
        else if(c2 == 'K') return("L2 R "+d+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d+" R' L2");
        else if(c2 == 'L') return("L2 "+d+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d+" L2");
        else if(c2 == 'M') return("L' "+U+"' "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"2"+" L");
        else if(c2 == 'N') return(u+" "+L+" U2 "+L+"' "+up+" "+L+" U2 "+L+"'");
        else if(c2 == 'O') return("L "+D+"' "+l+" U' "+lp+" "+D+" "+l+" U "+lp+" L'");
        else if(c2 == 'P') return("L2 "+d+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d2+" L2");
        else if(c2 == 'U') return("L' "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" L");
        else if(c2 == 'V') return("L' D' "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" D L");
        else if(c2 == 'W') return("L' D2 "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" D2 L");
        else if(c2 == 'X') return("L' D "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" D' L");
        else return("");
    }

    else if(c1 == 'S')
    {
        if(c2 == 'A') return("L2 "+l+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U L2");
        else if(c2 == 'C') return(rp+" "+D+" "+r+" U "+rp+" "+D+"' "+r+" U'");
        else if(c2 == 'D') return("L "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 L'");
        else if(c2 == 'E') return("L2 "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" L2");
        else if(c2 == 'F') return("L2 F' "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" F L2");
        else if(c2 == 'G') return("L2 F2 "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" F2 L2");
        else if(c2 == 'H') return("L "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" L'");
        else if(c2 == 'I') return("L2 "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' L2");
        else if(c2 == 'J') return("L2 R' "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' R L2");
        else if(c2 == 'K') return("L2 R2 "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' R2 L2");
        else if(c2 == 'L') return("L "+d+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d+" L'");
        else if(c2 == 'M') return("L2 "+U+"' "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"2 L2");
        else if(c2 == 'N') return("L' "+u+" "+L+" U2 "+L+"' "+up+" "+L+" U2 "+L+"' L");
        else if(c2 == 'O') return(D+"' "+l+" U' "+lp+" "+D+" "+l+" U "+lp);
        else if(c2 == 'P') return("L "+d+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d2+" L'");
        else if(c2 == 'U') return("L2 "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" L2");
        else if(c2 == 'V') return(D+"' "+R+"2 U' "+l+" U "+R+"2 U' "+lp+" U"+" "+D);
        else if(c2 == 'W') return("L2 D2 "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" D2 L2");
        else if(c2 == 'X') return("L2 D "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" D' L2");
        else return("");
    }

    else if(c1 == 'T')
    {
        if(c2 == 'A') return("L2 U "+R+"' "+up+" "+R+" U' "+R+"' "+u+" "+R+" L2");
        else if(c2 == 'C') return("L2 U' "+R+"' "+up+" "+R+" U "+R+"' "+u+" "+R+" L2");
        else if(c2 == 'D') return(L+" "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2");
        else if(c2 == 'E') return("L "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" L'");
        else if(c2 == 'F') return("F2 "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" F2");
        else if(c2 == 'G') return("F "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" F'");
        else if(c2 == 'H') return(d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L);
        else if(c2 == 'I') return("L "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"'"+" L'");
        else if(c2 == 'J') return("L R' "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' R L'");
        else if(c2 == 'K') return("R "+d+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d+" R'");
        else if(c2 == 'L') return(d+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d);
        else if(c2 == 'M') return("L "+U+"' "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"2"+" L'");
        else if(c2 == 'N') return("L2 "+u+" "+L+" U2 "+L+"' "+up+" "+L+" U2 "+L+"'"+" L2");
        else if(c2 == 'O') return("L' "+D+"' "+l+" U' "+lp+" "+D+" "+l+" U "+lp+" L");
        else if(c2 == 'P') return(d+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d2);
        else if(c2 == 'U') return("D' "+L+"' "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+"2 D");
        else if(c2 == 'V') return("D2 "+L+"' "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+"2 D2");
        else if(c2 == 'W') return("D "+L+"' "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+"2 D'");
        else if(c2 == 'X') return(L+"' "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+"2");
        else return("");
    }

    else if(c1 == 'U')
    {
        if(c2 == 'A') return(R+"' "+l2+" U "+R+" U' "+l2+" U "+R+"' U' "+R);
        else if(c2 == 'C') return("D' "+L+" U' "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" "+L+"' D");
        else if(c2 == 'D') return(R+"' U "+l2+" U "+R+" U' "+l2+" U "+R+"' U2 "+R);
        else if(c2 == 'E') return("D U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2 D'");
        else if(c2 == 'F') return(R+" U' "+l2+" U "+R+"' U' "+l2+" U");
        else if(c2 == 'G') return("F' "+R+" U' "+l2+" U "+R+"' U' "+l2+" U"+" F");
        else if(c2 == 'H') return("F2 "+R+" U' "+l2+" U "+R+"' U' "+l2+" U"+" F2");
        else if(c2 == 'I') return(l2+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l);
        else if(c2 == 'J') return("R' "+l2+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l+" R");
        else if(c2 == 'K') return("D "+D+" U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2"+" "+D+"' D'");
        else if(c2 == 'L') return("D' "+L+"2 U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" "+L+" D");
        else if(c2 == 'M') return("D "+U+"2 U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2"+" "+U+"2 D'");
        else if(c2 == 'N') return("D' "+L+" U2 "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" "+L+"' D");
        else if(c2 == 'O') return("D U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2 D'");
        else if(c2 == 'P') return("D' "+L+"2 U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+" D");
        else if(c2 == 'Q') return(l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l);
        else if(c2 == 'R') return("L' "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" L");
        else if(c2 == 'S') return("L2 "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" L2");
        else if(c2 == 'T') return("D' "+L+"2 U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" "+L+" D");
        else return("");
    }

    else if(c1 == 'V')
    {
        if(c2 == 'A') return("D' "+R+"' "+l2+" U "+R+" U' "+l2+" U "+R+"' U' "+R+" D");
        else if(c2 == 'C') return("D2 "+L+" U' "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" "+L+"'"+" D2");
        else if(c2 == 'D') return("D' "+R+"' U "+l2+" U "+R+" U' "+l2+" U "+R+"' U2 "+R+" D");
        else if(c2 == 'E') return("U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2");
        else if(c2 == 'F') return("F' U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2 F");
        else if(c2 == 'G') return("F2 U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2 F2");
        else if(c2 == 'H') return("F U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2 F'");
        else if(c2 == 'I') return("D' "+l2+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l+" D");
        else if(c2 == 'J') return("D' R' "+l2+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l+" R"+" D");
        else if(c2 == 'K') return(D+" U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2"+" "+D+"'");
        else if(c2 == 'L') return("D2 "+L+"2 U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" "+L+" D2");
        else if(c2 == 'M') return(U+"2 U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2"+" "+U+"2");
        else if(c2 == 'N') return("D2 "+L+" U2 "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" "+L+"' D2");
        else if(c2 == 'O') return("U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2");
        else if(c2 == 'P') return("B' U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2"+" B");
        else if(c2 == 'Q') return("D' "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" D");
        else if(c2 == 'R') return("L' D' "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" D L");
        else if(c2 == 'S') return(D+"' U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2"+" "+D);
        else if(c2 == 'T') return("D2 "+L+"2 U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" "+L+" D2");
        else return("");
    }

    else if(c1 == 'W')
    {
        if(c2 == 'A') return("D2 "+R+"' "+l2+" U "+R+" U' "+l2+" U "+R+"' U' "+R+" D2");
        else if(c2 == 'C') return("D "+L+" U' "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" "+L+"' D'");
        else if(c2 == 'D') return("D2 "+R+"' U "+l2+" U "+R+" U' "+l2+" U "+R+"' U2 "+R+" D2");
        else if(c2 == 'E') return("D' U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2 D");
        else if(c2 == 'F') return("D2 "+R+" U' "+l2+" U "+R+"' U' "+l2+" U"+" D2");
        else if(c2 == 'G') return("D2 F' "+R+" U' "+l2+" U "+R+"' U' "+l2+" U F D2");
        else if(c2 == 'H') return("F2 D2 "+R+" U' "+l2+" U "+R+"' U' "+l2+" U D2 F2");
        else if(c2 == 'I') return("D2 "+l2+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l+" D2");
        else if(c2 == 'J') return("D2 R' "+l2+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l+" R D2");
        else if(c2 == 'K') return("D' "+D+" U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2"+" "+D+"' D");
        else if(c2 == 'L') return("D "+L+"2 U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" "+L+" D'");
        else if(c2 == 'M') return("D' "+U+"2 U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2"+" "+U+"2 D");
        else if(c2 == 'N') return("D "+L+" U2 "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" "+L+"' D'");
        else if(c2 == 'O') return("D' U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2 D");
        else if(c2 == 'P') return("D "+L+"2 U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+" D'");
        else if(c2 == 'Q') return("D2 "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" D2");
        else if(c2 == 'R') return("L' D2 "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" D2 L");
        else if(c2 == 'S') return("L2 D2 "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" D2 L2");
        else if(c2 == 'T') return("D "+L+"2 U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" "+L+" D'");
        else return("");
    }

    else if(c1 == 'X')
    {
        if(c2 == 'A') return("D "+R+"' "+l2+" U "+R+" U' "+l2+" U "+R+"' U' "+R+" D'");
        else if(c2 == 'C') return(L+" U' "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" "+L+"'");
        else if(c2 == 'D') return("D "+R+"' U "+l2+" U "+R+" U' "+l2+" U "+R+"' U2 "+R+" D'");
        else if(c2 == 'E') return("D2 U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2 D2");
        else if(c2 == 'F') return("D "+R+" U' "+l2+" U "+R+"' U' "+l2+" U D'");
        else if(c2 == 'G') return("D F' "+R+" U' "+l2+" U "+R+"' U' "+l2+" U F D'");
        else if(c2 == 'H') return("F2 D "+R+" U' "+l2+" U "+R+"' U' "+l2+" U D' F2");
        else if(c2 == 'I') return("D "+l2+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l+" D'");
        else if(c2 == 'J') return("D R' "+l2+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l+" R D'");
        else if(c2 == 'K') return("D2 "+D+" U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2"+" "+D+"' D2");
        else if(c2 == 'L') return(L+"2 U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" "+L);
        else if(c2 == 'M') return("D2 "+U+"2 U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2"+" "+U+"2 D2");
        else if(c2 == 'N') return(L+" U2 "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" "+L+"'");
        else if(c2 == 'O') return("D2 U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2 D2");
        else if(c2 == 'P') return(L+"2 U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2+" "+L);
        else if(c2 == 'Q') return("D "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" D'");
        else if(c2 == 'R') return("L' D "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" D' L");
        else if(c2 == 'S') return("L2 D "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" D' L2");
        else if(c2 == 'T') return(L+"2 U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" "+L);
        else return("");
    }

    else return("");
}*/

string return_3S_center_alg(char c1,char c2,int s,int i,int j)
{

    string l = alg(j,s,"L");
    string lp = alg(j,s,"L'");
    string l2 = alg(j,s,"L2");
    string r = alg(j,s,"R");
    string rp = alg(j,s,"R'");
    string r2 = alg(j,s,"R2");
    string u = alg(j,s,"U");
    string up = alg(j,s,"U'");
    string u2 = alg(j,s,"U2");
    string d = alg(j,s,"D");
    string dp = alg(j,s,"D'");
    string d2 = alg(j,s,"D2");
    string L = alg2(i,'L');
    string R = alg2(i,'R');
    string U = alg2(i,'U');
    string D = alg2(i,'D');

    switch(c1)
    {
        case 'A':
        {
            switch(c2)
            {
            
                case 'E': return(U+"' "+"U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+lp+" "+U); 
                case 'F': return("F2 "+R+" "+d2+" "+R+"' U "+R+" "+d2+" "+R+"' U' F2"); 
                case 'G': return("F "+R+" "+d2+" "+R+"' U "+R+" "+d2+" "+R+"' U' F'"); 
                case 'H': return(R+" "+d2+" "+R+"' U "+R+" "+d2+" "+R+"' U'"); 
                case 'I': return("U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+lp); 
                case 'J': return(R+"' "+u+" "+R+" U "+R+"' "+up+" "+R+" U'"); 
                case 'K': return("R2 U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+lp+" R2"); 
                case 'L': return("R2 "+R+"' "+u+" "+R+" U "+R+"' "+up+" "+R+" U' R2"); 
                case 'M': return("B "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" U' B'"); 
                case 'N': return(R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" U'"); 
                case 'O': return("B' "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" U' B"); 
                case 'P': return("B2 "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" U' B2"); 
                case 'Q': return("U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+lp); 
                case 'R': return(R+"' "+up+" "+R+" U "+R+"' "+u+" "+R+" U'"); 
                case 'S': return("L2 U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+lp+" L2"); 
                case 'T': return("L2 "+R+"' "+up+" "+R+" U "+R+"' "+u+" "+R+" U' L2"); 
                case 'U': return(R+"' U "+R+" U' "+l2+" U "+R+"' U' "+l2+" "+R); 
                case 'V': return("D' "+R+"' U "+R+" U' "+l2+" U "+R+"' U' "+l2+" "+R+" D"); 
                case 'W': return("D2 "+R+"' U "+R+" U' "+l2+" U "+R+"' U' "+l2+" "+R+" D2"); 
                case 'X': return("D "+R+"' U "+R+" U' "+l2+" U "+R+"' U' "+l2+" "+R+" D'"); 
                default: return(""); 
            }
        }

        case 'C':
        {
            switch(c2)
            {
                case 'E': return("F' "+R+" "+d2+" "+R+"' U' "+R+" "+d2+" "+R+"' U F"); 
                case 'F': return("F2 "+R+" "+d2+" "+R+"' U' "+R+" "+d2+" "+R+"' U F2"); 
                case 'G': return("F "+R+" "+d2+" "+R+"' U' "+R+" "+d2+" "+R+"' U F'"); 
                case 'H': return(R+" "+d2+" "+R+"' U' "+R+" "+d2+" "+R+"' U"); 
                case 'I': return("R "+R+"' "+u+" "+R+" U' "+R+"' "+up+" "+R+" U R'"); 
                case 'J': return(R+"' "+u+" "+R+" U' "+R+"' "+up+" "+R+" U"); 
                case 'K': return("U "+rp+" "+D+"' "+r+" U' "+rp+" "+D+" "+r); 
                case 'L': return("R' U "+rp+" "+D+"' "+r+" U' "+rp+" "+D+" "+r+" R"); 
                case 'M': return("B "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" U B'"); 
                case 'N': return(R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" U"); 
                case 'O': return(D+"' "+"U "+rp+" "+D+"' "+r+" U' "+rp+" "+D+" "+r+" "+D); 
                case 'P': return("B2 "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" U B2"); 
                case 'Q': return("L "+R+"' "+up+" "+R+" U' "+R+"' "+u+" "+R+" U L'"); 
                case 'R': return(R+"' "+up+" "+R+" U' "+R+"' "+u+" "+R+" U"); 
                case 'S': return("U "+rp+" "+D+" "+r+" U' "+rp+" "+D+"' "+r); 
                case 'T': return("L2 "+R+"' "+up+" "+R+" U' "+R+"' "+u+" "+R+" U"+" L2"); 
                case 'U': return("D' "+L+" "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" U "+L+"' D"); 
                case 'V': return("D2 "+L+" "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" U "+L+"' D2"); 
                case 'W': return("D "+L+" "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" U "+L+"' D'"); 
                case 'X': return(L+" "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" U "+L+"'"); 
                default: return(""); 
            }
        }

        case 'D':
        {
            switch(c2)
            {
                case 'E': return("F U2 "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" F'"); 
                case 'F': return("U2 "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" "+L); 
                case 'G': return("F' U2 "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" F"); 
                case 'H': return(R+" "+d2+" "+R+"' U2 "+R+" "+d2+" "+R+"' U2"); 
                case 'I': return("R "+R+"' "+u+" "+R+" U2 "+R+"' "+up+" "+R+" U2"+" R'"); 
                case 'J': return(R+"' "+u+" "+R+" U2 "+R+"' "+up+" "+R+" U2"); 
                case 'K': return("R U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"'"+" R'"); 
                case 'L': return("U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"'"); 
                case 'M': return("B "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" U2"+" B'"); 
                case 'N': return(R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" U2"); 
                case 'O': return("B' "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" U2"+" B"); 
                case 'P': return("U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"'"); 
                case 'Q': return("L "+R+"' "+up+" "+R+" U2 "+R+"' "+u+" "+R+" U2"+" L'"); 
                case 'R': return(R+"' "+up+" "+R+" U2 "+R+"' "+u+" "+R+" U2"); 
                case 'S': return("L U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"'"+" L'"); 
                case 'T': return("U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"'"); 
                case 'U': return(R+"' U2 "+R+" U' "+l2+" U "+R+"' U' "+l2+" U' "+R); 
                case 'V': return("D' "+R+"' U2 "+R+" U' "+l2+" U "+R+"' U' "+l2+" U' "+R+" D"); 
                case 'W': return("D2 "+R+"' U2 "+R+" U' "+l2+" U "+R+"' U' "+l2+" U' "+R+" D2"); 
                case 'X': return("D "+R+"' U2 "+R+" U' "+l2+" U "+R+"' U' "+l2+" U' "+R+" D'"); 
                default: return("");
            } 
        }

        case 'E':
        {
            switch(c2)
            {
                case 'A': return(U+"' "+l+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+U); 
                case 'C': return("F' U' "+R+" "+d2+" "+R+"' U "+R+" "+d2+" "+R+"' F"); 
                case 'D': return("F "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" U2"+" F'"); 
                case 'I': return(lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"'"); 
                case 'J': return("R' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' R"); 
                case 'K': return("R2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' R2"); 
                case 'L': return("R "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' R'"); 
                case 'M': return(lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"2"); 
                case 'N': return("B' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"2 B"); 
                case 'O': return("B2 "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"2 B2"); 
                case 'P': return("B "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"2 B'"); 
                case 'Q': return(lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U); 
                case 'R': return("L' "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" L"); 
                case 'S': return("L2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" L2"); 
                case 'T': return("L "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" L'"); 
                case 'U': return("D "+R+"2 U' "+lp+" U "+R+"2 U' "+l+" U D'"); 
                case 'V': return(R+"2 U' "+lp+" U "+R+"2 U' "+l+" U"); 
                case 'W': return("D' "+R+"2 U' "+lp+" U "+R+"2 U' "+l+" U D"); 
                case 'X': return("D2 "+R+"2 U' "+lp+" U "+R+"2 U' "+l+" U D2"); 
                default: return(""); 
            }
        }

        case 'F':
        {
            switch(c2)
            {
                case 'A': return("F2 U "+R+" "+d2+" "+R+"' U' "+R+" "+d2+" "+R+"' F2"); 
                case 'C': return("F2 U' "+R+" "+d2+" "+R+"' U "+R+" "+d2+" "+R+"' F2"); 
                case 'D': return(L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" U2"); 
                case 'I': return("F' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' F"); 
                case 'J': return("R' F' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' F R"); 
                case 'K': return("R2 F' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' F R2"); 
                case 'L': return("F2 "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" F2"); 
                case 'M': return("B "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"' B'"); 
                case 'N': return(u2+" "+L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"'"); 
                case 'O': return("B' "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"' B"); 
                case 'P': return("B2 "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"' B2"); 
                case 'Q': return("F' "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" F"); 
                case 'R': return("L' F' "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" F L"); 
                case 'S': return("L2 F' "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" F L2"); 
                case 'T': return("F2 "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" F2"); 
                case 'U': return("U' "+l2+" U "+R+" U' "+l2+" U "+R+"'"); 
                case 'V': return("D' U' "+l2+" U "+R+" U' "+l2+" U "+R+"' D"); 
                case 'W': return("D2 U' "+l2+" U "+R+" U' "+l2+" U "+R+"' D2"); 
                case 'X': return("D U' "+l2+" U "+R+" U' "+l2+" U "+R+"' D'"); 
                default: return(""); 
            }
        }

        case 'G':
        {
            switch(c2)
            {
                case 'A': return("F U "+R+" "+d2+" "+R+"' U' "+R+" "+d2+" "+R+"' F'"); 
                case 'C': return("F U' "+R+" "+d2+" "+R+"' U "+R+" "+d2+" "+R+"' F'"); 
                case 'D': return("F' "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" U2 F"); 
                case 'I': return("F2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' F2"); 
                case 'J': return("R' F2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' F2 R"); 
                case 'K': return("R2 F2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' F2 R2"); 
                case 'L': return("R F2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' F2 R'"); 
                case 'M': return("F2 "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"2 F2"); 
                case 'N': return("F' "+u2+" "+L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"' F"); 
                case 'O': return(D+"2 "+l+" U' "+lp+" "+D+"2 "+l+" U "+lp); 
                case 'P': return("F "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2+" F'"); 
                case 'Q': return("F2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" F2"); 
                case 'R': return("L' F2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" F2 L"); 
                case 'S': return("L2 F2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" F2 L2"); 
                case 'T': return("L F2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" F2 L'"); 
                case 'U': return("F' U' "+l2+" U "+R+" U' "+l2+" U "+R+"' F"); 
                case 'V': return("D' F' U' "+l2+" U "+R+" U' "+l2+" U "+R+"' F D"); 
                case 'W': return("D2 F' U' "+l2+" U "+R+" U' "+l2+" U "+R+"' F D2"); 
                case 'X': return("D F' U' "+l2+" U "+R+" U' "+l2+" U "+R+"' F D'"); 
                default: return(""); 
            }
        }

        case 'H':
        {
            switch(c2)
            {
                case 'A': return("U "+R+" "+d2+" "+R+"' U' "+R+" "+d2+" "+R+"'"); 
                case 'C': return("U' "+R+" "+d2+" "+R+"' U "+R+" "+d2+" "+R+"'"); 
                case 'D': return("U2 "+R+" "+d2+" "+R+"' U2 "+R+" "+d2+" "+R+"'"); 
                case 'I': return("F "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"'"+" F'"); 
                case 'J': return("R2 "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" R2"); 
                case 'K': return("R "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" R'"); 
                case 'L': return(L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d); 
                case 'M': return("B' "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2+" B"); 
                case 'N': return("B2 "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2+" B2"); 
                case 'O': return("B "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2+" B'"); 
                case 'P': return(L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2); 
                case 'Q': return("L' "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" L"); 
                case 'R': return("L2 "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" L2"); 
                case 'S': return("L "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" L'"); 
                case 'T': return(L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp); 
                case 'U': return("F2 U' "+l2+" U "+R+" U' "+l2+" U "+R+"' F2"); 
                case 'V': return("F2 D' U' "+l2+" U "+R+" U' "+l2+" U "+R+"' D F2"); 
                case 'W': return("F2 D2 U' "+l2+" U "+R+" U' "+l2+" U "+R+"' D2 F2"); 
                case 'X': return("F2 D U' "+l2+" U "+R+" U' "+l2+" U "+R+"' D' F2"); 
                default: return(""); 
            }
        }

        case 'I':
        {
            switch(c2)
            {
                case 'A': return(l+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U"); 
                case 'C': return("R U' "+R+"' "+u+" "+R+" U "+R+"' "+up+" "+R+" R'"); 
                case 'D': return("R U2 "+R+"' "+u+" "+R+" U2 "+R+"' "+up+" "+R+" R'"); 
                case 'E': return(U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l); 
                case 'F': return("F' "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" F"); 
                case 'G': return("F2 "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" F2"); 
                case 'H': return("F "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" F'"); 
                case 'M': return(U+" "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"2"); 
                case 'N': return("B' "+U+" "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"2"+" B"); 
                case 'O': return(l2+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+lp); 
                case 'P': return("R' "+dp+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d2+" R"); 
                case 'Q': return(U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U); 
                case 'R': return("L' "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" L"); 
                case 'S': return("L2 "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" L2"); 
                case 'T': return("L "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" L'"); 
                case 'U': return(lp+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l2); 
                case 'V': return("D' "+lp+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l2+" D"); 
                case 'W': return("D2 "+lp+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l2+" D2"); 
                case 'X': return("D "+lp+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l2+" D'"); 
                default: return(""); 
            }
        }

        case 'J':
        {
            switch(c2)
            {
                case 'A': return("U "+R+"' "+u+" "+R+" U' "+R+"' "+up+" "+R); 
                case 'C': return("U' "+R+"' "+u+" "+R+" U "+R+"' "+up+" "+R); 
                case 'D': return("U2 "+R+"' "+u+" "+R+" U2 "+R+"' "+up+" "+R); 
                case 'E': return("R' "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" R"); 
                case 'F': return("R' F' "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" F R"); 
                case 'G': return("R' F2 "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" F2 R"); 
                case 'H': return("R2 "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" R2"); 
                case 'M': return("B "+up+" "+L+" U2 "+L+"' "+u+" "+L+" U2 "+L+"' B'"); 
                case 'N': return(up+" "+L+" U2 "+L+"' "+u+" "+L+" U2 "+L+"'"); 
                case 'O': return("B' "+up+" "+L+" U2 "+L+"' "+u+" "+L+" U2 "+L+"'"+" B"); 
                case 'P': return("B2 "+up+" "+L+" U2 "+L+"' "+u+" "+L+" U2 "+L+"'"+" B2"); 
                case 'Q': return("R' "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" R"); 
                case 'R': return("L' R' "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" R L"); 
                case 'S': return("L2 R' "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" R L2"); 
                case 'T': return("L R' "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" R L'"); 
                case 'U': return("R' "+lp+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l2+" R"); 
                case 'V': return("D' R' "+lp+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l2+" R"+" D"); 
                case 'W': return("D2 R' "+lp+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l2+" R"+" D2"); 
                case 'X': return("D R' "+lp+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l2+" R"+" D'"); 
                default: return(""); 
            }
        }

        case 'K':
        {
            switch(c2)
            {
                case 'A': return("R2 "+l+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U R2"); 
                case 'C': return(rp+" "+D+"' "+r+" U "+rp+" "+D+" "+r+" U'"); 
                case 'D': return("R "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 R'"); 
                case 'E': return("R2 "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" R2"); 
                case 'F': return("R2 F' "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" F R2"); 
                case 'G': return("R2 F2 "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" F2 R2"); 
                case 'H': return("R "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" R'"); 
                case 'M': return("B2 "+D+" "+l+" U' "+lp+" "+D+"' "+l+" U "+lp+" B2"); 
                case 'N': return("B "+D+" "+l+" U' "+lp+" "+D+"' "+l+" U "+lp+" B'"); 
                case 'O': return(D+" "+l+" U' "+lp+" "+D+"' "+l+" U "+lp); 
                case 'P': return("R "+dp+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d2+" R'"); 
                case 'Q': return("R2 "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" R2"); 
                case 'R': return("L2 R "+dp+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+dp+" R' L2"); 
                case 'S': return("L2 R2 "+U+" "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+" R2 L2"); 
                case 'T': return("R "+dp+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+dp+" R'"); 
                case 'U': return("D "+D+" "+R+"2 U' "+l+" U "+R+"2 U' "+lp+" U "+D+"' D'"); 
                case 'V': return(D+" "+R+"2 U' "+l+" U "+R+"2 U' "+lp+" U "+D+"'"); 
                case 'W': return("D' "+D+" "+R+"2 U' "+l+" U "+R+"2 U' "+lp+" U "+D+"' D"); 
                case 'X': return("D2 "+D+" "+R+"2 U' "+l+" U "+R+"2 U' "+lp+" U "+D+"' D2"); 
                default: return(""); 
            }
        }

        case 'L':
        {
            switch(c2)
            {
                case 'A': return("R "+l+" "+U+" "+lp+" U' "+l+" "+U+"' "+lp+" U R'"); 
                case 'C': return("R' "+rp+" "+D+"' "+r+" U "+rp+" "+D+" "+r+" U'"+" R"); 
                case 'D': return(L+" "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2"); 
                case 'E': return("F' "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" F"); 
                case 'F': return("F2 "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" F2"); 
                case 'G': return("F "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" F'"); 
                case 'H': return(dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L); 
                case 'M': return("B' "+dp+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d2+" B"); 
                case 'N': return("B2 "+dp+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d2+" B2"); 
                case 'O': return("B "+dp+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d2+" B'"); 
                case 'P': return(dp+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d2); 
                case 'Q': return("L' "+dp+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+dp+" L"); 
                case 'R': return("L2 "+dp+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+dp+" L2"); 
                case 'S': return("L "+dp+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+dp+" L'"); 
                case 'T': return(dp+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+dp); 
                case 'U': return("D' "+L+"' "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+"2 D"); 
                case 'V': return("D2 "+L+"' "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+"2 D2"); 
                case 'W': return("D "+L+"' "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+"2 D'"); 
                case 'X': return(L+"' "+dp+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+"2"); 
                default: return(""); 
            }
        }

        case 'M':
        {
            switch(c2)
            {
                case 'A': return("B U "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" B'"); 
                case 'C': return("B U' "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" B'"); 
                case 'D': return("B U2 "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" B'"); 
                case 'E': return(U+"2 "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l); 
                case 'F': return("F' "+U+"2 "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" F"); 
                case 'G': return("F2 "+U+"2 "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" F2"); 
                case 'H': return("F "+U+"2 "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" F'"); 
                case 'I': return(U+"2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"'"); 
                case 'J': return("R' "+U+"2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"' R"); 
                case 'K': return("R2 "+U+"2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"' R2"); 
                case 'L': return("R "+U+"2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"' R'"); 
                case 'Q': return(U+"2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U); 
                case 'R': return("L' "+U+"2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+" L"); 
                case 'S': return("L2 "+U+"2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+" L2"); 
                case 'T': return("L "+U+"2 "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+" L'"); 
                case 'U': return("D "+U+"2 "+R+"2 U' "+lp+" U "+R+"2 U' "+l+" U "+U+"2 D'"); 
                case 'V': return(U+"2 "+R+"2 U' "+lp+" U "+R+"2 U' "+l+" U "+U+"2"); 
                case 'W': return("D' "+U+"2 "+R+"2 U' "+lp+" U "+R+"2 U' "+l+" U "+U+"2 D"); 
                case 'X': return("D2 "+U+"2 "+R+"2 U' "+lp+" U "+R+"2 U' "+l+" U "+U+"2 D2"); 
                default: return(""); 
            }
        }

        case 'N':
        {
            switch(c2)
            {
                case 'A': return("U "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R); 
                case 'C': return("U' "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R); 
                case 'D': return("U2 "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R); 
                case 'E': return("B' "+U+"2 "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" B"); 
                case 'F': return(L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2); 
                case 'G': return("F' "+L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" F"); 
                case 'H': return("F2 "+L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" F2"); 
                case 'I': return("B' "+U+"2 "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"'"+" B"); 
                case 'J': return(L+" U2 "+L+"' "+up+" "+L+" U2 "+L+"' "+u); 
                case 'K': return("B "+l+" U' "+lp+" "+D+" "+l+" U "+lp+" "+D+"' B'"); 
                case 'L': return("B2 "+d2+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d+" B2"); 
                case 'Q': return("L "+L+" U2 "+L+"' "+u+" "+L+" U2 "+L+"' "+up+" L'"); 
                case 'R': return(L+" U2 "+L+"' "+u+" "+L+" U2 "+L+"' "+up); 
                case 'S': return("L' "+L+" U2 "+L+"' "+u+" "+L+" U2 "+L+"' "+up+" L"); 
                case 'T': return("L2 "+L+" U2 "+L+"' "+u+" "+L+" U2 "+L+"' "+up+" L2"); 
                case 'U': return("D' "+L+" "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" U2 "+L+"' D"); 
                case 'V': return("D2 "+L+" "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" U2 "+L+"' D2"); 
                case 'W': return("D "+L+" "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" U2 "+L+"' D'"); 
                case 'X': return(L+" "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" U2 "+L+"'"); 
                default: return(""); 
            }
        }

        case 'O':
        {
            switch(c2)
            {
                case 'A': return("B' U "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" B"); 
                case 'C': return(D+"' "+rp+" "+D+"' "+r+" U "+rp+" "+D+" "+r+" U'"+" "+D); 
                case 'D': return("B' U2 "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" B"); 
                case 'E': return("B2 "+U+"2 "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" B2"); 
                case 'F': return("B' "+L+" U2 "+L+"' "+u2+" "+L+" U2 "+L+"' "+u2+" B"); 
                case 'G': return(l+" U' "+lp+" "+D+"2 "+l+" U "+lp+" "+D+"2"); 
                case 'H': return("B "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" B'"); 
                case 'I': return(l+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l2); 
                case 'J': return("B' "+L+" U2 "+L+"' "+up+" "+L+" U2 "+L+"' "+u+" B"); 
                case 'K': return(l+" U' "+lp+" "+D+" "+l+" U "+lp+" "+D+"'"); 
                case 'L': return("B "+d2+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d+" B'"); 
                case 'Q': return("L2 "+l+" U' "+lp+" "+D+"' "+l+" U "+lp+" "+D+" L2"); 
                case 'R': return("L "+l+" U' "+lp+" "+D+"' "+l+" U "+lp+" "+D+" L'"); 
                case 'S': return(l+" U' "+lp+" "+D+"' "+l+" U "+lp+" "+D); 
                case 'T': return("L' "+l+" U' "+lp+" "+D+"' "+l+" U "+lp+" "+D+" L"); 
                case 'U': return("D "+R+"2 U' "+l+" U "+R+"2 U' "+lp+" U D'"); 
                case 'V': return(R+"2 U' "+l+" U "+R+"2 U' "+lp+" U"); 
                case 'W': return("D' "+R+"2 U' "+l+" U "+R+"2 U' "+lp+" U D"); 
                case 'X': return("D2 "+R+"2 U' "+l+" U "+R+"2 U' "+lp+" U D2"); 
                default: return(""); 
            }
        }

        case 'P':
        {
            switch(c2)
            {
                case 'A': return("B2 U "+R+"' "+u2+" "+R+" U' "+R+"' "+u2+" "+R+" B2"); 
                case 'C': return("B2 U' "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" B2"); 
                case 'D': return(L+" "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2"); 
                case 'E': return("F' "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" F"); 
                case 'F': return("F2 "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" F2"); 
                case 'G': return("F "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" F'"); 
                case 'H': return(d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L); 
                case 'I': return("R' "+d2+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d+" R"); 
                case 'J': return("R2 "+d2+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d+" R2"); 
                case 'K': return("R "+d2+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d+" R'"); 
                case 'L': return(d2+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d); 
                case 'Q': return("L' "+d2+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+dp+" L"); 
                case 'R': return("L2 "+d2+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+dp+" L2"); 
                case 'S': return("L "+d2+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+dp+" L'"); 
                case 'T': return(d2+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+dp); 
                case 'U': return("D' "+L+"' "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+"2 D"); 
                case 'V': return("D2 "+L+"' "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+"2 D2"); 
                case 'W': return("D "+L+"' "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+"2 D'"); 
                case 'X': return(L+"' "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+"2"); 
                default: return(""); 
            }
        }

        case 'Q':
        {
            switch(c2)
            {
                case 'A': return(l+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U"); 
                case 'C': return("L U' "+R+"' "+up+" "+R+" U "+R+"' "+u+" "+R+" L'"); 
                case 'D': return("L U2 "+R+"' "+up+" "+R+" U2 "+R+"' "+u+" "+R+" L'"); 
                case 'E': return(U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l); 
                case 'F': return("F' "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" F"); 
                case 'G': return("F2 "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" F2"); 
                case 'H': return("F "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" F'"); 
                case 'I': return(U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"'"); 
                case 'J': return("R' "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' R"); 
                case 'K': return("R2 "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' R2"); 
                case 'L': return("R "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' R'"); 
                case 'M': return(U+"' "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"2"); 
                case 'N': return("L "+u+" "+L+" U2 "+L+"' "+up+" "+L+" U2 "+L+"' L'"); 
                case 'O': return("L2 "+D+"' "+l+" U' "+lp+" "+D+" "+l+" U "+lp+" L2"); 
                case 'P': return("L' "+d+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d2+" L"); 
                case 'U': return(lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2); 
                case 'V': return("D' "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" D"); 
                case 'W': return("D2 "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" D2"); 
                case 'X': return("D "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" D'");
                default: return("");
            }
        }

        case 'R':
        {
            switch(c2)
            {
                case 'A': return("U "+R+"' "+up+" "+R+" U' "+R+"' "+u+" "+R);
                case 'C': return("U' "+R+"' "+up+" "+R+" U "+R+"' "+u+" "+R);
                case 'D': return("U2 "+R+"' "+up+" "+R+" U2 "+R+"' "+u+" "+R);
                case 'E': return("L' "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" L");
                case 'F': return("L' F' "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" F L");
                case 'G': return("L' F2 "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" F2 L");
                case 'H': return("L2 "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" L2");
                case 'I': return("L' "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' L");
                case 'J': return("L' R' "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' R L");
                case 'K': return("L2 R "+d+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d+" R' L2");
                case 'L': return("L2 "+d+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d+" L2");
                case 'M': return("L' "+U+"' "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"2"+" L");
                case 'N': return(u+" "+L+" U2 "+L+"' "+up+" "+L+" U2 "+L+"'");
                case 'O': return("L "+D+"' "+l+" U' "+lp+" "+D+" "+l+" U "+lp+" L'");
                case 'P': return("L2 "+d+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d2+" L2");
                case 'U': return("L' "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" L");
                case 'V': return("L' D' "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" D L");
                case 'W': return("L' D2 "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" D2 L");
                case 'X': return("L' D "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" D' L");
                default: return("");
            }
        }

        case 'S':
        {
            switch(c2)
            {
                case 'A': return("L2 "+l+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U L2");
                case 'C': return(rp+" "+D+" "+r+" U "+rp+" "+D+"' "+r+" U'");
                case 'D': return("L "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 L'");
                case 'E': return("L2 "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" L2");
                case 'F': return("L2 F' "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" F L2");
                case 'G': return("L2 F2 "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" F2 L2");
                case 'H': return("L "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" L'");
                case 'I': return("L2 "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' L2");
                case 'J': return("L2 R' "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' R L2");
                case 'K': return("L2 R2 "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' R2 L2");
                case 'L': return("L "+d+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d+" L'");
                case 'M': return("L2 "+U+"' "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"2 L2");
                case 'N': return("L' "+u+" "+L+" U2 "+L+"' "+up+" "+L+" U2 "+L+"' L");
                case 'O': return(D+"' "+l+" U' "+lp+" "+D+" "+l+" U "+lp);
                case 'P': return("L "+d+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d2+" L'");
                case 'U': return("L2 "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" L2");
                case 'V': return(D+"' "+R+"2 U' "+l+" U "+R+"2 U' "+lp+" U"+" "+D);
                case 'W': return("L2 D2 "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" D2 L2");
                case 'X': return("L2 D "+lp+" "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l2+" D' L2");
                default: return("");
            }
        }

        case 'T':
        {
            switch(c2)
            {
                case 'A': return("L2 U "+R+"' "+up+" "+R+" U' "+R+"' "+u+" "+R+" L2");
                case 'C': return("L2 U' "+R+"' "+up+" "+R+" U "+R+"' "+u+" "+R+" L2");
                case 'D': return(L+" "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2");
                case 'E': return("L "+U+"' "+lp+" U' "+l+" "+U+" "+lp+" U "+l+" L'");
                case 'F': return("F2 "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" F2");
                case 'G': return("F "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+" F'");
                case 'H': return(d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L);
                case 'I': return("L "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"'"+" L'");
                case 'J': return("L R' "+U+"' "+lp+" U' "+l+" "+U+"2 "+lp+" U "+l+" "+U+"' R L'");
                case 'K': return("R "+d+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d+" R'");
                case 'L': return(d+" "+L+"' U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d);
                case 'M': return("L "+U+"' "+lp+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+"2"+" L'");
                case 'N': return("L2 "+u+" "+L+" U2 "+L+"' "+up+" "+L+" U2 "+L+"'"+" L2");
                case 'O': return("L' "+D+"' "+l+" U' "+lp+" "+D+" "+l+" U "+lp+" L");
                case 'P': return(d+" "+L+"' U2 "+L+" "+d+" "+L+"' U2 "+L+" "+d2);
                case 'U': return("D' "+L+"' "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+"2 D");
                case 'V': return("D2 "+L+"' "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+"2 D2");
                case 'W': return("D "+L+"' "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+"2 D'");
                case 'X': return(L+"' "+d+" "+L+"' U2 "+L+" "+dp+" "+L+"' U2 "+L+"2");
                default: return("");
            }
        }

        case 'U':
        {
            switch(c2)
            {
                case 'A': return(R+"' "+l2+" U "+R+" U' "+l2+" U "+R+"' U' "+R);
                case 'C': return("D' "+L+" U' "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" "+L+"' D");
                case 'D': return(R+"' U "+l2+" U "+R+" U' "+l2+" U "+R+"' U2 "+R);
                case 'E': return("D U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2 D'");
                case 'F': return(R+" U' "+l2+" U "+R+"' U' "+l2+" U");
                case 'G': return("F' "+R+" U' "+l2+" U "+R+"' U' "+l2+" U"+" F");
                case 'H': return("F2 "+R+" U' "+l2+" U "+R+"' U' "+l2+" U"+" F2");
                case 'I': return(l2+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l);
                case 'J': return("R' "+l2+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l+" R");
                case 'K': return("D "+D+" U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2"+" "+D+"' D'");
                case 'L': return("D' "+L+"2 U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" "+L+" D");
                case 'M': return("D "+U+"2 U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2"+" "+U+"2 D'");
                case 'N': return("D' "+L+" U2 "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" "+L+"' D");
                case 'O': return("D U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2 D'");
                case 'P': return("D' "+L+"2 U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+" D");
                case 'Q': return(l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l);
                case 'R': return("L' "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" L");
                case 'S': return("L2 "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" L2");
                case 'T': return("D' "+L+"2 U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" "+L+" D");
                default: return("");
            }
        }

        case 'V':
        {
            switch(c2)
            {
                case 'A': return("D' "+R+"' "+l2+" U "+R+" U' "+l2+" U "+R+"' U' "+R+" D");
                case 'C': return("D2 "+L+" U' "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" "+L+"'"+" D2");
                case 'D': return("D' "+R+"' U "+l2+" U "+R+" U' "+l2+" U "+R+"' U2 "+R+" D");
                case 'E': return("U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2");
                case 'F': return("F' U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2 F");
                case 'G': return("F2 U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2 F2");
                case 'H': return("F U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2 F'");
                case 'I': return("D' "+l2+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l+" D");
                case 'J': return("D' R' "+l2+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l+" R"+" D");
                case 'K': return(D+" U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2"+" "+D+"'");
                case 'L': return("D2 "+L+"2 U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" "+L+" D2");
                case 'M': return(U+"2 U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2"+" "+U+"2");
                case 'N': return("D2 "+L+" U2 "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" "+L+"' D2");
                case 'O': return("U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2");
                case 'P': return("B' U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2"+" B");
                case 'Q': return("D' "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" D");
                case 'R': return("L' D' "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" D L");
                case 'S': return(D+"' U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2"+" "+D);
                case 'T': return("D2 "+L+"2 U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" "+L+" D2");
                default: return("");
            }
        }

        case 'W':
        {
            switch(c2)
            {
                case 'A': return("D2 "+R+"' "+l2+" U "+R+" U' "+l2+" U "+R+"' U' "+R+" D2");
                case 'C': return("D "+L+" U' "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" "+L+"' D'");
                case 'D': return("D2 "+R+"' U "+l2+" U "+R+" U' "+l2+" U "+R+"' U2 "+R+" D2");
                case 'E': return("D' U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2 D");
                case 'F': return("D2 "+R+" U' "+l2+" U "+R+"' U' "+l2+" U"+" D2");
                case 'G': return("D2 F' "+R+" U' "+l2+" U "+R+"' U' "+l2+" U F D2");
                case 'H': return("F2 D2 "+R+" U' "+l2+" U "+R+"' U' "+l2+" U D2 F2");
                case 'I': return("D2 "+l2+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l+" D2");
                case 'J': return("D2 R' "+l2+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l+" R D2");
                case 'K': return("D' "+D+" U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2"+" "+D+"' D");
                case 'L': return("D "+L+"2 U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" "+L+" D'");
                case 'M': return("D' "+U+"2 U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2"+" "+U+"2 D");
                case 'N': return("D "+L+" U2 "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" "+L+"' D'");
                case 'O': return("D' U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2 D");
                case 'P': return("D "+L+"2 U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2+" "+L+" D'");
                case 'Q': return("D2 "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" D2");
                case 'R': return("L' D2 "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" D2 L");
                case 'S': return("L2 D2 "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" D2 L2");
                case 'T': return("D "+L+"2 U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" "+L+" D'");
                default: return("");
            }
        }

        case 'X':
        {
            switch(c2)
            {
                case 'A': return("D "+R+"' "+l2+" U "+R+" U' "+l2+" U "+R+"' U' "+R+" D'");
                case 'C': return(L+" U' "+R+"' "+u2+" "+R+" U "+R+"' "+u2+" "+R+" "+L+"'");
                case 'D': return("D "+R+"' U "+l2+" U "+R+" U' "+l2+" U "+R+"' U2 "+R+" D'");
                case 'E': return("D2 U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2 D2");
                case 'F': return("D "+R+" U' "+l2+" U "+R+"' U' "+l2+" U D'");
                case 'G': return("D F' "+R+" U' "+l2+" U "+R+"' U' "+l2+" U F D'");
                case 'H': return("F2 D "+R+" U' "+l2+" U "+R+"' U' "+l2+" U D' F2");
                case 'I': return("D "+l2+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l+" D'");
                case 'J': return("D R' "+l2+" U' "+l+" "+U+" "+lp+" U "+l+" "+U+"' "+l+" R D'");
                case 'K': return("D2 "+D+" U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2"+" "+D+"' D2");
                case 'L': return(L+"2 U2 "+L+" "+dp+" "+L+"' U2 "+L+" "+d+" "+L);
                case 'M': return("D2 "+U+"2 U' "+lp+" U "+R+"2 U' "+l+" U "+R+"2"+" "+U+"2 D2");
                case 'N': return(L+" U2 "+R+"' "+u2+" "+R+" U2 "+R+"' "+u2+" "+R+" "+L+"'");
                case 'O': return("D2 U' "+l+" U "+R+"2 U' "+lp+" U "+R+"2 D2");
                case 'P': return(L+"2 U2 "+L+" "+d2+" "+L+"' U2 "+L+" "+d2+" "+L);
                case 'Q': return("D "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" D'");
                case 'R': return("L' D "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" D' L");
                case 'S': return("L2 D "+l2+" U' "+l+" "+U+"' "+lp+" U "+l+" "+U+" "+l+" D' L2");
                case 'T': return(L+"2 U2 "+L+" "+d+" "+L+"' U2 "+L+" "+dp+" "+L);
                default: return("");
            }
        }

        defalut: return("");
    }
}

// Corners

string return_single_corner_alg(char n)
{
    if(n=='B') return ("R D' R U' R' U' R U R' F' R U R' U' R' F R D R'");
    else if(n=='C') return ("F R U' R' U' R U R' F' R U R' U' R' F R F'");
    else if(n=='D') return ("F U' R' U' R U R' F' R U R' U' R' F R2 F'");
    else if(n=='E') return ("F' D R U' R' U' R U R' F' R U R' U' R' F R D' F");
    else if(n=='F') return ("F2 D R U' R' U' R U R' F' R U R' U' R' F R D' F2");
    else if(n=='G') return ("D R2 U' R' U' R U R' F' R U R' U' R' F D'");
    else if(n=='H') return ("D R U' R' U' R U R' F' R U R' U' R' F R D'");
    else if(n=='I') return ("U' R' U' R U R' F' R U R' U' R' F R2");
    else if(n=='J') return ("R' U' R' U' R U R' F' R U R' U' R' F R'");
    else if(n=='K') return ("R2 U' R' U' R U R' F' R U R' U' R' F");
    else if(n=='L') return ("R U' R' U' R U R' F' R U R' U' R' F R");
    else if(n=='M') return ("R' F R U' R' U' R U R' F' R U R' U' R' F R F' R");
    else if(n=='O') return ("D' R2 U' R' U' R U R' F' R U R' U' R' F D");
    else if(n=='P') return ("D' R U' R' U' R U R' F' R U R' U' R' F R D");
    else if(n=='R') return ("F2 R U' R' U' R U R' F' R U R' U' R' F R F2");
    else if(n=='S') return ("D2 R2 U' R' U' R U R' F' R U R' U' R' F D2");
    else if(n=='T') return ("D2 R U' R' U' R U R' F' R U R' U' R' F R D2");
    else if(n=='U') return ("F' R U' R' U' R U R' F' R U R' U' R' F R F");
    else if(n=='V') return ("D' F' R U' R' U' R U R' F' R U R' U' R' F R F D");
    else if(n=='W') return ("D2 F' R U' R' U' R U R' F' R U R' U' R' F R F D2");
    else if(n=='X') return ("D F' R U' R' U' R U R' F' R U R' U' R' F R F D'");
    else return "";
}

string return_BHC_alg(char c1,char c2)
{   
    if(c1 == 'B')
    {
        if (c1 == 'B' and c2 == 'C')  return("R' F R' B2 R F' R' B2 R2");
        else if (c1 == 'B' and c2 == 'D')  return("L2 B2 L' F' L B2 L' F L'");
        else if (c1 == 'B' and c2 == 'F')  return("R' F' L F R F' L' F");
        else if (c1 == 'B' and c2 == 'E')  return("L' B' R' B L B' R B");
        else if (c1 == 'B' and c2 == 'G')  return("U B' D B U' B' D' B");
        else if (c1 == 'B' and c2 == 'H')  return("U R D2 R' U' R D2 R'");
        else if (c1 == 'B' and c2 == 'R')  return("B' U2 B' D' B U2 B' D B2");
        else if (c1 == 'B' and c2 == 'S')  return("U B' D2 B U' B' D2 B");
        else if (c1 == 'B' and c2 == 'T')  return("U R D' R' U' R D R'");
        else if (c1 == 'B' and c2 == 'O')  return("L B' R' B L' B' R B");
        else if (c1 == 'B' and c2 == 'P')  return("U B' D' B U' B' D B");
        else if (c1 == 'B' and c2 == 'I')  return("B2 D B' U2 B D' B' U2 B'");
        else if (c1 == 'B' and c2 == 'K')  return("U R D R' U' R D' R'");
        else if (c1 == 'B' and c2 == 'L')  return("B D2 B' U' B D2 B' U");
        else if (c1 == 'B' and c2 == 'V')  return("R2 D' L2 D R2 D' L2 D");
        else if (c1 == 'B' and c2 == 'U')  return("L2 B' R' B L2 B' R B");
        else if (c1 == 'B' and c2 == 'W')  return("D' R2 D' L2 D R2 D' L2 D2");
        else if (c1 == 'B' and c2 == 'X')  return("D2 R2 D' L2 D R2 D' L2 D'");
        else if (c1 == 'B' and c2 == 'J')  return("B U2 B' U' B U' B' F' U2 F U F' U F");
        else if (c1 == 'B' and c2 == 'M')  return("F' U' F U' F' U2 F B U B' U B U2 B'");
        else return "";
    }
    
    else if(c1 == 'C')
    {
        if (c1 == 'C' and c2 == 'B')  return("R2 B2 R F R' B2 R F' R");
        else if (c1 == 'C' and c2 == 'D')  return("L' B L' F2 L B' L' F2 L2");
        else if (c1 == 'C' and c2 == 'E')  return("R2 B2 R F2 R' B2 R F2 R");
        else if (c1 == 'C' and c2 == 'G')  return("U2 F D F' U2 F D' F'");
        else if (c1 == 'C' and c2 == 'H')  return("B D' B' U2 B D B' U2");
        else if (c1 == 'C' and c2 == 'R')  return("B L2 B R2 B' L2 B R2 B2");
        else if (c1 == 'C' and c2 == 'S')  return("U2 R' D R U2 R' D' R");
        else if (c1 == 'C' and c2 == 'T')  return("U2 F D2 F' U2 F D2 F'");
        else if (c1 == 'C' and c2 == 'M')  return("L' B2 L' F2 L B2 L' F2 L2");
        else if (c1 == 'C' and c2 == 'O')  return("U2 R' D2 R U2 R' D2 R");
        else if (c1 == 'C' and c2 == 'P')  return("U2 F D' F' U2 F D F'");
        else if (c1 == 'C' and c2 == 'J')  return("F2 L2 F' R2 F L2 F' R2 F'");
        else if (c1 == 'C' and c2 == 'K')  return("L' D L U2 L' D' L U2");
        else if (c1 == 'C' and c2 == 'L')  return("U2 R' D' R U2 R' D R");
        else if (c1 == 'C' and c2 == 'V')  return("L' U2 L U R2 U' L' U R2 U L");
        else if (c1 == 'C' and c2 == 'U')  return("U' F2 U F2 U L2 U' F2 U' F2 U L2");
        else if (c1 == 'C' and c2 == 'W')  return("U2 F' U2 F R2 F R2 F' R2 B' R2 B");
        else if (c1 == 'C' and c2 == 'X')  return("L' B' L2 B' R B L2 B' R' B2 L");
        else if (c1 == 'C' and c2 == 'I')  return("U R U2 R' L' U' L U' L' U2 L R U R'");
        else if (c1 == 'C' and c2 == 'F')  return("R U' R' L' U2 L U L' U L R U2 R' U'");

        else return "";
    }

    else if(c1 == 'D')
    {
        if (c1 == 'D' and c2 == 'B')  return("L F' L B2 L' F L B2 L2");
        else if (c1 == 'D' and c2 == 'C')  return("L2 F2 L B L' F2 L B' L");
        else if (c1 == 'D' and c2 == 'F')  return("L2 D' L U2 L' D L U2 L");
        else if (c1 == 'D' and c2 == 'G')  return("L' D2 L U L' D2 L U'");
        else if (c1 == 'D' and c2 == 'H')  return("U' F' D' F U F' D F");
        else if (c1 == 'D' and c2 == 'S')  return("U' L D L' U L D' L'");
        else if (c1 == 'D' and c2 == 'T')  return("L' D' L U L' D L U'");
        else if (c1 == 'D' and c2 == 'M')  return("L U2 L D L' U2 L D' L2");
        else if (c1 == 'D' and c2 == 'O')  return("U' F' D F U F' D' F");
        else if (c1 == 'D' and c2 == 'P')  return("U' L D2 L' U L D2 L'");
        else if (c1 == 'D' and c2 == 'J')  return("R' F R B' R' F' R B");
        else if (c1 == 'D' and c2 == 'I')  return("L' B' L F' L' B L F");
        else if (c1 == 'D' and c2 == 'K')  return("U' F' D2 F U F' D2 F");
        else if (c1 == 'D' and c2 == 'L')  return("U' L D' L' U L D L'");
        else if (c1 == 'D' and c2 == 'V')  return("L' B' L F2 L' B L F2");
        else if (c1 == 'D' and c2 == 'U')  return("D F2 D B2 D' F2 D B2 D2");
        else if (c1 == 'D' and c2 == 'W')  return("D' F2 D B2 D' F2 D B2");
        else if (c1 == 'D' and c2 == 'X')  return("D2 F2 D B2 D' F2 D B2 D");
        else if (c1 == 'D' and c2 == 'E')  return("L' U2 L U L' U L R U2 R' U' R U' R'");
        else if (c1 == 'D' and c2 == 'R')  return("R U R' U R U2 R' L' U' L U' L' U2 L");
        else return "";
    }

    else if(c1 == 'F')
    {
        if (c1 == 'F' and c2 == 'B')  return("F' L F R' F' L' F R");
        else if (c1 == 'F' and c2 == 'D')  return("L' U2 L' D' L U2 L' D L2");
        else if (c1 == 'F' and c2 == 'E')  return("U' R' U L U' R U L'");
        else if (c1 == 'F' and c2 == 'G')  return("F R' B2 R F' R' B2 R");
        else if (c1 == 'F' and c2 == 'H')  return("F2 D' B D F2 D' B' D");
        else if (c1 == 'F' and c2 == 'R')  return("F2 D F' U2 F D' F' U2 F'");
        else if (c1 == 'F' and c2 == 'S')  return("U' L B2 L' F' L B2 L' F U");
        else if (c1 == 'F' and c2 == 'T')  return("D F2 D' B D F2 D' B'");
        else if (c1 == 'F' and c2 == 'M')  return("F' L U2 L' F L F' U2 F L'");
        else if (c1 == 'F' and c2 == 'O')  return("B R2 B' L' B R2 B' L");
        else if (c1 == 'F' and c2 == 'P')  return("F' L F R2 F' L' F R2");
        else if (c1 == 'F' and c2 == 'J')  return("R' F' R B' R' F R B");
        else if (c1 == 'F' and c2 == 'K')  return("U' R B' L2 B R' B' L2 B U");
        else if (c1 == 'F' and c2 == 'L')  return("D' F2 D' B D F2 D' B' D2");
        else if (c1 == 'F' and c2 == 'V')  return("F' L F R F' L' F R'");
        else if (c1 == 'F' and c2 == 'U')  return("D R' D' L2 D R D' L2");
        else if (c1 == 'F' and c2 == 'W')  return("B2 L F' L' B2 L F L'");
        else if (c1 == 'F' and c2 == 'X')  return("D2 R' D' L2 D R D' L2 D'");
        else return "";
    }

    else if(c1 == 'E')
    {
        if (c1 == 'E' and c2 == 'B')  return("L F R' F' L' F R F'");
        else if (c1 == 'E' and c2 == 'C')  return("R' F2 R' B2 R F2 R' B2 R2");
        else if (c1 == 'E' and c2 == 'F')  return("U B U' F' U B' U' F");
        else if (c1 == 'E' and c2 == 'G')  return("U B U' F2 U B' U' F2");
        else if (c1 == 'E' and c2 == 'H')  return("U B U' F U B' U' F'");
        else if (c1 == 'E' and c2 == 'S')  return("U2 R U' L2 U R' U' L2 U'");
        else if (c1 == 'E' and c2 == 'T')  return("D F' D' B D F D' B'");
        else if (c1 == 'E' and c2 == 'M')  return("R2 F2 R' B2 R F2 R' B2 R'");
        else if (c1 == 'E' and c2 == 'O')  return("U' F U' B2 U F' U' B2 U2");
        else if (c1 == 'E' and c2 == 'P')  return("U R' U' L' U R U' L");
        else if (c1 == 'E' and c2 == 'J')  return("U R U' L' U R' U' L");
        else if (c1 == 'E' and c2 == 'I')  return("L F R F' L' F R' F'");
        else if (c1 == 'E' and c2 == 'K')  return("L U' R2 U L' U' R2 U");
        else if (c1 == 'E' and c2 == 'L')  return("L U' R U L' U' R' U");
        else if (c1 == 'E' and c2 == 'V')  return("U R2 U' L' U R2 U' L");
        else if (c1 == 'E' and c2 == 'U')  return("U2 F2 U' B' U F2 U' B U'");
        else if (c1 == 'E' and c2 == 'W')  return("R F2 R' B2 R F2 R' B2");
        else if (c1 == 'E' and c2 == 'X')  return("U' L2 U' R' U L2 U' R U2");
        else return "";
    }

    else if(c1 == 'G')
    {
        if (c1 == 'G' and c2 == 'B')  return("U' L' D2 L U L' D2 L");
        else if (c1 == 'G' and c2 == 'C')  return("U2 L' D2 L U2 L' D2 L");
        else if (c1 == 'G' and c2 == 'D')  return("U L' D2 L U' L' D2 L");
        else if (c1 == 'G' and c2 == 'F')  return("R' B2 R F R' B2 R F'");
        else if (c1 == 'G' and c2 == 'E')  return("F2 U B U' F2 U B' U'");
        else if (c1 == 'G' and c2 == 'H')  return("F D' B D F' D' B' D");
        else if (c1 == 'G' and c2 == 'R')  return("B L2 B R' B' L2 B R B2");
        else if (c1 == 'G' and c2 == 'S')  return("D' F U' F' D F U F'");
        else if (c1 == 'G' and c2 == 'T')  return("B' L F2 L' B L F2 L'");
        else if (c1 == 'G' and c2 == 'M')  return("U' B2 D B U2 B' D' B U2 B U");
        else if (c1 == 'G' and c2 == 'O')  return("D2 B' U' B D2 B' U B");
        else if (c1 == 'G' and c2 == 'P')  return("F2 L F R2 F' L' F R2 F");
        else if (c1 == 'G' and c2 == 'J')  return("U F' U' B' U F U' B");
        else if (c1 == 'G' and c2 == 'I')  return("D2 L' D' R2 D L D' R2 D'");
        else if (c1 == 'G' and c2 == 'K')  return("R U2 R' D' R U2 R' D");
        else if (c1 == 'G' and c2 == 'U')  return("U' R U' F2 U R' U' R F2 R' U2");
        else if (c1 == 'G' and c2 == 'W')  return("D' F' D B2 D' F D B2");
        else if (c1 == 'G' and c2 == 'X')  return("U' L2 U' R U L2 U' R' U2");
        else if (c1 == 'G' and c2 == 'L')  return("R U R U2 R' L' U' L U' L' U2 L R U R2");
        else if (c1 == 'G' and c2 == 'V')  return("R2 U' R' L' U2 L U L' U L R U2 R' U' R'");
        else return "";
    }

    else if(c1 == 'H')
    {
        if (c1 == 'H' and c2 == 'B')  return("U' B D' B' U B D B'");
        else if (c1 == 'H' and c2 == 'C')  return("U2 B D' B' U2 B D B'");
        else if (c1 == 'H' and c2 == 'D')  return("U B D' B' U' B D B'");
        else if (c1 == 'H' and c2 == 'F')  return("D' B D F2 D' B' D F2");
        else if (c1 == 'H' and c2 == 'E')  return("F U B U' F' U B' U'");
        else if (c1 == 'H' and c2 == 'G')  return("F' R' B2 R F R' B2 R");
        else if (c1 == 'H' and c2 == 'R')  return("D' B L2 B' D B D' L2 D B'");
        else if (c1 == 'H' and c2 == 'T')  return("L' F' L B L' F L B'");
        else if (c1 == 'H' and c2 == 'M')  return("R2 F' R' B2 R F R' B2 R'");
        else if (c1 == 'H' and c2 == 'O')  return("B' L2 B' R' B L2 B' R B2");
        else if (c1 == 'H' and c2 == 'P')  return("D2 R' U R D2 R' U' R");
        else if (c1 == 'H' and c2 == 'J')  return("U F2 U' B' U F2 U' B");
        else if (c1 == 'H' and c2 == 'I')  return("U' L F' R2 F L' F' R2 F U");
        else if (c1 == 'H' and c2 == 'K')  return("U' F R2 F' L' F R2 F' L U");
        else if (c1 == 'H' and c2 == 'L')  return("D F' U2 F D' F' U2 F");
        else if (c1 == 'H' and c2 == 'V')  return("R' D2 R' U R D2 R' U' R2");
        else if (c1 == 'H' and c2 == 'W')  return("R F' R' B2 R F R' B2");
        else if (c1 == 'H' and c2 == 'X')  return("D2 R D' L2 D R' D' L2 D'");
        else if (c1 == 'H' and c2 == 'S')  return("F L' F' B' L2 B L B' L B F L2 F' L'");
        else if (c1 == 'H' and c2 == 'U')  return("L F L2 F' B' L' B L' B' L2 B F L F'");
        else return "";
    }

    else if(c1 == 'R')
    {
        if (c1 == 'R' and c2 == 'B')  return("B2 D' B U2 B' D B U2 B");
        else if (c1 == 'R' and c2 == 'C')  return("B2 R2 B' L2 B R2 B' L2 B'");
        else if (c1 == 'R' and c2 == 'F')  return("F U2 F D F' U2 F D' F2");
        else if (c1 == 'R' and c2 == 'G')  return("B2 R' B' L2 B R B' L2 B'");
        else if (c1 == 'R' and c2 == 'H')  return("B D' L2 D B' D' B L2 B' D");
        else if (c1 == 'R' and c2 == 'S')  return("F' L2 F' R' F L2 F' R F2");
        else if (c1 == 'R' and c2 == 'T')  return("F U2 F D2 F' U2 F D2 F2");
        else if (c1 == 'R' and c2 == 'M')  return("R' F U2 F' R F R' U2 R F'");
        else if (c1 == 'R' and c2 == 'O')  return("B2 R B' L2 B R' B' L2 B'");
        else if (c1 == 'R' and c2 == 'P')  return("F U2 F D' F' U2 F D F2");
        else if (c1 == 'R' and c2 == 'J')  return("F' L2 F' R2 F L2 F' R2 F2");
        else if (c1 == 'R' and c2 == 'I')  return("B' R U2 R' B R B' U2 B R'");
        else if (c1 == 'R' and c2 == 'K')  return("F' L2 F' R F L2 F' R' F2");
        else if (c1 == 'R' and c2 == 'L')  return("U2 B U2 B D2 B' U2 B D2 B2 U2");
        else if (c1 == 'R' and c2 == 'V')  return("B2 D B U2 B' D' B U2 B");
        else if (c1 == 'R' and c2 == 'U')  return("B2 D2 B U2 B' D2 B U2 B");
        else if (c1 == 'R' and c2 == 'W')  return("U' L2 D L U2 L' D' L U2 L U");
        else if (c1 == 'R' and c2 == 'X')  return("D F' L2 F D' F' D L2 D' F");
        else return "";
    }

    else if(c1 == 'S')
    {
        if (c1 == 'S' and c2 == 'B')  return("B' D2 B U B' D2 B U'");
        else if (c1 == 'S' and c2 == 'C')  return("R' D R U2 R' D' R U2");
        else if (c1 == 'S' and c2 == 'D')  return("L D L' U' L D' L' U");
        else if (c1 == 'S' and c2 == 'F')  return("U' F' L B2 L' F L B2 L' U");
        else if (c1 == 'S' and c2 == 'E')  return("U L2 U R U' L2 U R' U2");
        else if (c1 == 'S' and c2 == 'G')  return("F U' F' D' F U F' D");
        else if (c1 == 'S' and c2 == 'R')  return("F2 R' F L2 F' R F L2 F");
        else if (c1 == 'S' and c2 == 'T')  return("D F D' B D F' D' B'");
        else if (c1 == 'S' and c2 == 'M')  return("R2 D R U2 R' D' R U2 R");
        else if (c1 == 'S' and c2 == 'O')  return("F U' F' D F U F' D'");
        else if (c1 == 'S' and c2 == 'P')  return("U' L' B2 L F L' B2 L F' U");
        else if (c1 == 'S' and c2 == 'J')  return("R' F2 R B' R' F2 R B");
        else if (c1 == 'S' and c2 == 'I')  return("F2 R B' R' F2 R B R'");
        else if (c1 == 'S' and c2 == 'K')  return("F U' F' D2 F U F' D2");
        else if (c1 == 'S' and c2 == 'L')  return("R F2 R B' R' F2 R B R2");
        else if (c1 == 'S' and c2 == 'V')  return("F' D B2 D' F D B2 D'");
        else if (c1 == 'S' and c2 == 'W')  return("B2 U' F U B2 U' F' U");
        else if (c1 == 'S' and c2 == 'X')  return("F U' L2 U F' U' F L2 F' U");
        else return "";
    }

    else if(c1 == 'T')
    {
        if (c1 == 'T' and c2 == 'B')  return("U' L' D' L U L' D L");
        else if (c1 == 'T' and c2 == 'C')  return("U2 L' D' L U2 L' D L");
        else if (c1 == 'T' and c2 == 'D')  return("U L' D' L U' L' D L");
        else if (c1 == 'T' and c2 == 'F')  return("L F' L' B' L F L' B");
        else if (c1 == 'T' and c2 == 'E')  return("U' F' U B' U' F U B");
        else if (c1 == 'T' and c2 == 'G')  return("L F2 L' B' L F2 L' B");
        else if (c1 == 'T' and c2 == 'H')  return("L U L' D' L U' L' D");
        else if (c1 == 'T' and c2 == 'R')  return("F2 D2 F' U2 F D2 F' U2 F'");
        else if (c1 == 'T' and c2 == 'S')  return("U' F U B' U' F' U B");
        else if (c1 == 'T' and c2 == 'M')  return("L' B2 L' F' L B2 L' F L2");
        else if (c1 == 'T' and c2 == 'P')  return("L U L' D L U' L' D'");
        else if (c1 == 'T' and c2 == 'J')  return("U2 L2 U' R' U L2 U' R U'");
        else if (c1 == 'T' and c2 == 'I')  return("B L' F2 L B' L' F2 L");
        else if (c1 == 'T' and c2 == 'K')  return("L2 F L' B2 L F' L' B2 L'");
        else if (c1 == 'T' and c2 == 'L')  return("L U L' D2 L U' L' D2");
        else if (c1 == 'T' and c2 == 'V')  return("U' F2 U B' U' F2 U B");
        else if (c1 == 'T' and c2 == 'U')  return("F' D2 F' U2 F D2 F' U2 F2");
        else if (c1 == 'T' and c2 == 'W')  return("L2 D2 L' U' L D2 L' U L'");
        else return "";
    }

    else if(c1 == 'M')
    {
        if (c1 == 'M' and c2 == 'C')  return("L2 F2 L B2 L' F2 L B2 L");
        else if (c1 == 'M' and c2 == 'D')  return("L2 D L' U2 L D' L' U2 L'");
        else if (c1 == 'M' and c2 == 'F')  return("L F' U2 F L' F' L U2 L' F");
        else if (c1 == 'M' and c2 == 'E')  return("R B2 R F2 R' B2 R F2 R2");
        else if (c1 == 'M' and c2 == 'G')  return("U' B' U2 B' D B U2 B' D' B2 U");
        else if (c1 == 'M' and c2 == 'H')  return("R B2 R F' R' B2 R F R2");
        else if (c1 == 'M' and c2 == 'R')  return("F R' U2 R F' R' F U2 F' R");
        else if (c1 == 'M' and c2 == 'S')  return("R' U2 R' D R U2 R' D' R2");
        else if (c1 == 'M' and c2 == 'T')  return("L2 F' L B2 L' F L B2 L");
        else if (c1 == 'M' and c2 == 'O')  return("R' U2 R' D2 R U2 R' D2 R2");
        else if (c1 == 'M' and c2 == 'P')  return("R B2 R F R' B2 R F' R2");
        else if (c1 == 'M' and c2 == 'I')  return("R' U2 R' D' R U2 R' D R2");
        else if (c1 == 'M' and c2 == 'K')  return("L' D B2 D' L D L' B2 L D'");
        else if (c1 == 'M' and c2 == 'L')  return("L2 F L B2 L' F' L B2 L");
        else if (c1 == 'M' and c2 == 'V')  return("L2 D' L' U2 L D L' U2 L'");
        else if (c1 == 'M' and c2 == 'U')  return("U2 R2 D2 R' U2 R D2 R' U2 R' U2");
        else if (c1 == 'M' and c2 == 'W')  return("L2 D2 L' U2 L D2 L' U2 L'");
        else if (c1 == 'M' and c2 == 'X')  return("D' R B2 R' D R D' B2 D R'");
        else return "";
    }

    else if(c1 == 'O')
    {
        if (c1 == 'O' and c2 == 'B')  return("U' B D B' U B D' B'");
        else if (c1 == 'O' and c2 == 'C')  return("U2 B D B' U2 B D' B'");
        else if (c1 == 'O' and c2 == 'D')  return("U B D B' U' B D' B'");
        else if (c1 == 'O' and c2 == 'F')  return("L' B R2 B' L B R2 B'");
        else if (c1 == 'O' and c2 == 'E')  return("U2 B2 U F U' B2 U F' U");
        else if (c1 == 'O' and c2 == 'G')  return("D2 R U2 R' D2 R U2 R'");
        else if (c1 == 'O' and c2 == 'H')  return("B2 R' B L2 B' R B L2 B");
        else if (c1 == 'O' and c2 == 'R')  return("B L2 B R B' L2 B R' B2");
        else if (c1 == 'O' and c2 == 'S')  return("D F U' F' D' F U F'");
        else if (c1 == 'O' and c2 == 'M')  return("R2 D2 R U2 R' D2 R U2 R");
        else if (c1 == 'O' and c2 == 'P')  return("U R' U' L U R U' L'");
        else if (c1 == 'O' and c2 == 'J')  return("U R U' L U R' U' L'");
        else if (c1 == 'O' and c2 == 'I')  return("L' D' R2 D L D' R2 D");
        else if (c1 == 'O' and c2 == 'K')  return("L' B R B' L B R' B'");
        else if (c1 == 'O' and c2 == 'L')  return("B' R2 B L B' R2 B L'");
        else if (c1 == 'O' and c2 == 'V')  return("U R2 U' L U R2 U' L'");
        else if (c1 == 'O' and c2 == 'U')  return("D F' D B2 D' F D B2 D2");
        else if (c1 == 'O' and c2 == 'W')  return("R D2 R U2 R' D2 R U2 R2");
        else if (c1 == 'O' and c2 == 'T')  return("R B R' B R B2 R' L' B' L B' L' B2 L");
        else if (c1 == 'O' and c2 == 'X')  return("L' B2 L B L' B L R B2 R' B' R B' R'");
        else return "";
    }

    else if(c1 == 'P')
    {
        if (c1 == 'P' and c2 == 'B')  return("R' B L B' R B L' B'");
        else if (c1 == 'P' and c2 == 'C')  return("F D' F' U2 F D F' U2");
        else if (c1 == 'P' and c2 == 'D')  return("L D2 L' U' L D2 L' U");
        else if (c1 == 'P' and c2 == 'F')  return("R2 F' L F R2 F' L' F");
        else if (c1 == 'P' and c2 == 'E')  return("L' U R' U' L U R U'");
        else if (c1 == 'P' and c2 == 'G')  return("F' R2 F' L F R2 F' L' F2");
        else if (c1 == 'P' and c2 == 'H')  return("R' U R D2 R' U' R D2");
        else if (c1 == 'P' and c2 == 'R')  return("F2 D' F' U2 F D F' U2 F'");
        else if (c1 == 'P' and c2 == 'S')  return("U' F L' B2 L F' L' B2 L U");
        else if (c1 == 'P' and c2 == 'T')  return("D L U L' D' L U' L'");
        else if (c1 == 'P' and c2 == 'M')  return("R2 F R' B2 R F' R' B2 R'");
        else if (c1 == 'P' and c2 == 'O')  return("L U R' U' L' U R U'");
        else if (c1 == 'P' and c2 == 'J')  return("U' B2 U' F' U B2 U' F U2");
        else if (c1 == 'P' and c2 == 'I')  return("U' R F2 R' B' R F2 R' B U");
        else if (c1 == 'P' and c2 == 'L')  return("D' F' U2 F D F' U2 F");
        else if (c1 == 'P' and c2 == 'V')  return("R D' L2 D R' D' L2 D");
        else if (c1 == 'P' and c2 == 'U')  return("L2 U R' U' L2 U R U'");
        else if (c1 == 'P' and c2 == 'X')  return("R' U B2 U' R U R' B2 R U'");
        else return "";
    }

    else if(c1 == 'J')
    {
        if (c1 == 'J' and c2 == 'C')  return("F R2 F L2 F' R2 F L2 F2");
        else if (c1 == 'J' and c2 == 'D')  return("L F L' B L F' L' B'");
        else if (c1 == 'J' and c2 == 'F')  return("L F' L' B L F L' B'");
        else if (c1 == 'J' and c2 == 'E')  return("U' F' U B U' F U B'");
        else if (c1 == 'J' and c2 == 'G')  return("L F2 L' B L F2 L' B'");
        else if (c1 == 'J' and c2 == 'H')  return("B' U F2 U' B U F2 U'");
        else if (c1 == 'J' and c2 == 'R')  return("F2 R2 F L2 F' R2 F L2 F");
        else if (c1 == 'J' and c2 == 'S')  return("U' F U B U' F' U B'");
        else if (c1 == 'J' and c2 == 'T')  return("U R' U L2 U' R U L2 U2");
        else if (c1 == 'J' and c2 == 'O')  return("L U R U' L' U R' U'");
        else if (c1 == 'J' and c2 == 'P')  return("U2 F' U B2 U' F U B2 U");
        else if (c1 == 'J' and c2 == 'I')  return("U' L' U R U' L U R'");
        else if (c1 == 'J' and c2 == 'K')  return("U' L' U R' U' L U R");
        else if (c1 == 'J' and c2 == 'L')  return("U' L' U R2 U' L U R2");
        else if (c1 == 'J' and c2 == 'V')  return("U' F2 U B U' F2 U B'");
        else if (c1 == 'J' and c2 == 'U')  return("L2 U R U' L2 U R' U'");
        else if (c1 == 'J' and c2 == 'W')  return("U2 R2 U L U' R2 U L' U");
        else if (c1 == 'J' and c2 == 'X')  return("U B2 U F U' B2 U F' U2");
        else return "";
    }

    else if(c1 == 'I')
    {
        if (c1 == 'I' and c2 == 'B')  return("B U2 B D B' U2 B D' B2");
        else if (c1 == 'I' and c2 == 'D')  return("F' L' B' L F L' B L");
        else if (c1 == 'I' and c2 == 'E')  return("L' B' R B L B' R' B");
        else if (c1 == 'I' and c2 == 'G')  return("D R2 D L' D' R2 D L D2");
        else if (c1 == 'I' and c2 == 'H')  return("U' F' R2 F L F' R2 F L' U");
        else if (c1 == 'I' and c2 == 'R')  return("R B' U2 B R' B' R U2 R' B");
        else if (c1 == 'I' and c2 == 'S')  return("R B' R' F2 R B R' F2");
        else if (c1 == 'I' and c2 == 'T')  return("L' F2 L B L' F2 L B'");
        else if (c1 == 'I' and c2 == 'M')  return("R2 D' R U2 R' D R U2 R");
        else if (c1 == 'I' and c2 == 'O')  return("L B' R B L' B' R' B");
        else if (c1 == 'I' and c2 == 'P')  return("U' B' R F2 R' B R F2 R' U");
        else if (c1 == 'I' and c2 == 'J')  return("U F U' B' U F' U' B");
        else if (c1 == 'I' and c2 == 'K')  return("R2 D L' D' R2 D L D'");
        else if (c1 == 'I' and c2 == 'L')  return("R' F L2 F' R F L2 F'");
        else if (c1 == 'I' and c2 == 'V')  return("F D B2 D' F' D B2 D'");
        else if (c1 == 'I' and c2 == 'U')  return("L2 B' R B L2 B' R' B");
        else if (c1 == 'I' and c2 == 'W')  return("D' F D B2 D' F' D B2");
        else if (c1 == 'I' and c2 == 'X')  return("D2 F D B2 D' F' D B2 D");
        else return "";
    }

    else if(c1 == 'K')
    {
        if (c1 == 'K' and c2 == 'B')  return("U' L' D L U L' D' L");
        else if (c1 == 'K' and c2 == 'C')  return("U2 L' D L U2 L' D' L");
        else if (c1 == 'K' and c2 == 'D')  return("U L' D L U' L' D' L");
        else if (c1 == 'K' and c2 == 'F')  return("U' B' L2 B R B' L2 B R' U");
        else if (c1 == 'K' and c2 == 'E')  return("U' R2 U L U' R2 U L'");
        else if (c1 == 'K' and c2 == 'G')  return("D' R U2 R' D R U2 R'");
        else if (c1 == 'K' and c2 == 'H')  return("U' L' F R2 F' L F R2 F' U");
        else if (c1 == 'K' and c2 == 'R')  return("F2 R F L2 F' R' F L2 F");
        else if (c1 == 'K' and c2 == 'S')  return("D2 F U' F' D2 F U F'");
        else if (c1 == 'K' and c2 == 'T')  return("L B2 L F L' B2 L F' L2");
        else if (c1 == 'K' and c2 == 'M')  return("D L' B2 L D' L' D B2 D' L");
        else if (c1 == 'K' and c2 == 'O')  return("D B' U' B D' B' U B");
        else if (c1 == 'K' and c2 == 'J')  return("D L' D' R D L D' R'");
        else if (c1 == 'K' and c2 == 'I')  return("D L' D' R2 D L D' R2");
        else if (c1 == 'K' and c2 == 'L')  return("D L' D' R' D L D' R");
        else if (c1 == 'K' and c2 == 'V')  return("F D2 F U' F' D2 F U F2");
        else if (c1 == 'K' and c2 == 'U')  return("F' R F L2 F' R' F L2");
        else if (c1 == 'K' and c2 == 'X')  return("D2 F' D B2 D' F D B2 D");
        else if (c1 == 'K' and c2 == 'P')  return("U B' U' D' B2 D B D' B D U B2 U' B'");
        else if (c1 == 'K' and c2 == 'W')  return("B U B2 U' D' B' D B' D' B2 D U B U'");
        else return "";
    }

    else if(c1 == 'L')
    {
        if (c1 == 'L' and c2 == 'B')  return("U' B D2 B' U B D2 B'");
        else if (c1 == 'L' and c2 == 'C')  return("U2 B D2 B' U2 B D2 B'");
        else if (c1 == 'L' and c2 == 'D')  return("U B D2 B' U' B D2 B'");
        else if (c1 == 'L' and c2 == 'F')  return("D2 B D F2 D' B' D F2 D");
        else if (c1 == 'L' and c2 == 'E')  return("U' R U L U' R' U L'");
        else if (c1 == 'L' and c2 == 'H')  return("F' U2 F D F' U2 F D'");
        else if (c1 == 'L' and c2 == 'R')  return("U2 B2 D2 B' U2 B D2 B' U2 B' U2");
        else if (c1 == 'L' and c2 == 'S')  return("R2 B' R' F2 R B R' F2 R'");
        else if (c1 == 'L' and c2 == 'T')  return("F' U2 F D2 F' U2 F D2");
        else if (c1 == 'L' and c2 == 'M')  return("L' B2 L' F L B2 L' F' L2");
        else if (c1 == 'L' and c2 == 'O')  return("L B' R2 B L' B' R2 B");
        else if (c1 == 'L' and c2 == 'P')  return("F' U2 F D' F' U2 F D");
        else if (c1 == 'L' and c2 == 'J')  return("F L2 F' R2 F L2 F' R2");
        else if (c1 == 'L' and c2 == 'I')  return("F L2 F' R' F L2 F' R");
        else if (c1 == 'L' and c2 == 'K')  return("F L2 F' R F L2 F' R'");
        else if (c1 == 'L' and c2 == 'U')  return("L2 B' R2 B L2 B' R2 B");
        else if (c1 == 'L' and c2 == 'W')  return("U' B' D2 B' U B D2 B' U' B2 U");
        else if (c1 == 'L' and c2 == 'X')  return("U B2 U F' U' B2 U F U2");
        else return "";
    }

    else if(c1 == 'V')
    {
        if (c1 == 'V' and c2 == 'B')  return("D' L2 D R2 D' L2 D R2");
        else if (c1 == 'V' and c2 == 'C')  return("L' U' R2 U' L U R2 U' L' U2 L");
        else if (c1 == 'V' and c2 == 'D')  return("F2 L' B' L F2 L' B L");
        else if (c1 == 'V' and c2 == 'F')  return("D' L2 D R' D' L2 D R");
        else if (c1 == 'V' and c2 == 'E')  return("L' U R2 U' L U R2 U'");
        else if (c1 == 'V' and c2 == 'H')  return("R2 U R D2 R' U' R D2 R");
        else if (c1 == 'V' and c2 == 'R')  return("B' U2 B' D B U2 B' D' B2");
        else if (c1 == 'V' and c2 == 'S')  return("D B2 D' F' D B2 D' F");
        else if (c1 == 'V' and c2 == 'T')  return("L' F L B L' F' L B'");
        else if (c1 == 'V' and c2 == 'M')  return("L U2 L D' L' U2 L D L2");
        else if (c1 == 'V' and c2 == 'O')  return("L U R2 U' L' U R2 U'");
        else if (c1 == 'V' and c2 == 'P')  return("D' L2 D R D' L2 D R'");
        else if (c1 == 'V' and c2 == 'J')  return("B U' F2 U B' U' F2 U");
        else if (c1 == 'V' and c2 == 'I')  return("F' R B' R' F R B R'");
        else if (c1 == 'V' and c2 == 'K')  return("F2 U' F' D2 F U F' D2 F'");
        else if (c1 == 'V' and c2 == 'U')  return("L2 U R2 U' L2 U R2 U'");
        else if (c1 == 'V' and c2 == 'W')  return("R F R' B2 R F' R' B2");
        else if (c1 == 'V' and c2 == 'X')  return("L2 U2 R2 U' L2 U R2 U' L2 U' L2");
        else return "";
    }

    else if(c1 == 'U')
    {
        if (c1 == 'U' and c2 == 'B')  return("L2 D R2 D' L2 D R2 D'");
        else if (c1 == 'U' and c2 == 'C')  return("U2 F' L2 F L2 F U2 F' L2 F' L2 F");
        else if (c1 == 'U' and c2 == 'D')  return("D2 B2 D' F2 D B2 D' F2 D'");
        else if (c1 == 'U' and c2 == 'F')  return("L2 D R' D' L2 D R D'");
        else if (c1 == 'U' and c2 == 'E')  return("U B' U F2 U' B U F2 U2");
        else if (c1 == 'U' and c2 == 'G')  return("U2 L2 U2 L' D2 L U2 L' D2 L' U2");
        else if (c1 == 'U' and c2 == 'R')  return("B' U2 B' D2 B U2 B' D2 B2");
        else if (c1 == 'U' and c2 == 'T')  return("F2 U2 F D2 F' U2 F D2 F");
        else if (c1 == 'U' and c2 == 'M')  return("U2 R U2 R D2 R' U2 R D2 R2 U2");
        else if (c1 == 'U' and c2 == 'O')  return("D2 B2 D' F' D B2 D' F D'");
        else if (c1 == 'U' and c2 == 'P')  return("U R' U' L2 U R U' L2");
        else if (c1 == 'U' and c2 == 'J')  return("U R U' L2 U R' U' L2");
        else if (c1 == 'U' and c2 == 'I')  return("B' R B L2 B' R' B L2");
        else if (c1 == 'U' and c2 == 'K')  return("L2 F' R F L2 F' R' F");
        else if (c1 == 'U' and c2 == 'L')  return("L2 D R D' L2 D R' D'");
        else if (c1 == 'U' and c2 == 'V')  return("U R2 U' L2 U R2 U' L2");
        else if (c1 == 'U' and c2 == 'W')  return("U' L2 U B2 U B2 U' B2 D' B2 D L2");
        else if (c1 == 'U' and c2 == 'X')  return("U B2 U F2 U' B2 U F2 U2");
        else return "";
    }

    else if(c1 == 'W')
    {
        if (c1 == 'W' and c2 == 'B')  return("D2 L2 D R2 D' L2 D R2 D");
        else if (c1 == 'W' and c2 == 'C')  return("U' B2 U B2 U R2 U' B2 U' B2 U R2");
        else if (c1 == 'W' and c2 == 'D')  return("L F L' B2 L F' L' B2");
        else if (c1 == 'W' and c2 == 'F')  return("L F' L' B2 L F L' B2");
        else if (c1 == 'W' and c2 == 'E')  return("U' F' U B2 U' F U B2");
        else if (c1 == 'W' and c2 == 'G')  return("L F2 L' B2 L F2 L' B2");
        else if (c1 == 'W' and c2 == 'H')  return("B2 R F' R' B2 R F R'");
        else if (c1 == 'W' and c2 == 'R')  return("U' L' U2 L' D L U2 L' D' L2 U");
        else if (c1 == 'W' and c2 == 'S')  return("U' F U B2 U' F' U B2");
        else if (c1 == 'W' and c2 == 'T')  return("L U' L D2 L' U L D2 L2");
        else if (c1 == 'W' and c2 == 'M')  return("L U2 L D2 L' U2 L D2 L2");
        else if (c1 == 'W' and c2 == 'O')  return("R2 U2 R' D2 R U2 R' D2 R'");
        else if (c1 == 'W' and c2 == 'J')  return("U' L U' R2 U L' U' R2 U2");
        else if (c1 == 'W' and c2 == 'I')  return("B2 D' F D B2 D' F' D");
        else if (c1 == 'W' and c2 == 'L')  return("U' B2 U B D2 B' U' B D2 B U");
        else if (c1 == 'W' and c2 == 'V')  return("U' F2 U B2 U' F2 U B2");
        else if (c1 == 'W' and c2 == 'U')  return("U B2 U' L2 U' L2 U L2 D L2 D' B2");
        else if (c1 == 'W' and c2 == 'X')  return("U' L2 U' R2 U L2 U' R2 U2");
        else return "";
    }

    else if(c1 == 'X')
    {
        if (c1 == 'X' and c2 == 'B')  return("D L2 D R2 D' L2 D R2 D2");
        else if (c1 == 'X' and c2 == 'C')  return("L' B2 R B L2 B' R' B L2 B L");
        else if (c1 == 'X' and c2 == 'D')  return("D' B2 D' F2 D B2 D' F2 D2");
        else if (c1 == 'X' and c2 == 'F')  return("D L2 D R' D' L2 D R D2");
        else if (c1 == 'X' and c2 == 'E')  return("U2 R' U L2 U' R U L2 U");
        else if (c1 == 'X' and c2 == 'G')  return("U2 R U L2 U' R' U L2 U");
        else if (c1 == 'X' and c2 == 'H')  return("D L2 D R D' L2 D R' D2");
        else if (c1 == 'X' and c2 == 'R')  return("F' D L2 D' F D F' L2 F D'");
        else if (c1 == 'X' and c2 == 'S')  return("U' F L2 F' U F U' L2 U F'");
        else if (c1 == 'X' and c2 == 'M')  return("R D' B2 D R' D' R B2 R' D");
        else if (c1 == 'X' and c2 == 'P')  return("U R' B2 R U' R' U B2 U' R");
        else if (c1 == 'X' and c2 == 'J')  return("U2 F U' B2 U F' U' B2 U'");
        else if (c1 == 'X' and c2 == 'I')  return("D' B2 D' F D B2 D' F' D2");
        else if (c1 == 'X' and c2 == 'K')  return("D' B2 D' F' D B2 D' F D2");
        else if (c1 == 'X' and c2 == 'L')  return("U2 F' U' B2 U F U' B2 U'");
        else if (c1 == 'X' and c2 == 'V')  return("L2 U L2 U R2 U' L2 U R2 U2 L2");
        else if (c1 == 'X' and c2 == 'U')  return("U2 F2 U' B2 U F2 U' B2 U'");
        else if (c1 == 'X' and c2 == 'W')  return("U2 R2 U L2 U' R2 U L2 U");
        else return "";
    }

    else return ("");
}

string return_corner_parity(int size)
{
  return "U2 R U R' U' "+to_string(size/2)+"Rw2 F2 U2 "+to_string(size/2)+"Rw2 R2 U2 F2 "+to_string(size/2)+"Rw2 U R U' R' U2";
}

// Edges

string return_single_edge_alg(char n)
{
    if(n=='A') return("M2");
    else if(n=='B') return("R' U R U' M2 U R' U' R");
    else if(n=='C') return("U2 M' U2 M'");
    else if(n=='D') return("L U' L' U M2 U' L U L'");
    else if(n=='E') return("D M' U R2 U' M U R2 U' D' M2");
    else if(n=='F') return("U R U' M2 U R' U'");
    else if(n=='H') return("U' L' U M2 U' L U");
    else if(n=='I') return("B' R B M2 B' R' B");
    else if(n=='J') return("R' B' R B M2 B' R' B R");
    else if(n=='K') return("B' R' B M2 B' R B");
    else if(n=='L') return("B' R2 B M2 B' R2 B");
    else if(n=='M') return("B' R B U R2 U' M2 U R2 U' B' R' B");
    else if(n=='N') return("U' L U M2 U' L' U");
    else if(n=='O') return("M2 D U R2 U' M' U R2 U' M D'");
    else if(n=='P') return("U R' U' M2 U R U'");
    else if(n=='Q') return("B L' B' M2 B L B'");
    else if(n=='R') return("B L2 B' M2 B L2 B'");
    else if(n=='S') return("B L B' M2 B L' B'");
    else if(n=='T') return("L B L' B' M2 B L B' L'");
    else if(n=='V') return("U R2 U' M2 U R2 U'");
    else if(n=='W') return("M U2 M U2");
    else if(n=='X') return("U' L2 U M2 U' L2 U");
    else return "";
}

string return_BHE_alg(char c1,char c2)
{
    if (c1 == 'X' and c2 == 'W') return("S2 D S D2 S' D S2");
    else if (c1 == 'X' and c2 == 'V') return("M2 D M' D2 M D M2");
    else if (c1 == 'X' and c2 == 'K') return("S' R F' R' S R F R'");
    else if (c1 == 'X' and c2 == 'J') return("D' L E L' D L E' L'");
    else if (c1 == 'X' and c2 == 'L') return("R' S' R F' R' S R F");
    else if (c1 == 'X' and c2 == 'I') return("M' U M D M' U' M D'");
    else if (c1 == 'X' and c2 == 'F') return("D' L E2 L' D L E2 L'");
    else if (c1 == 'X' and c2 == 'H') return("D2 B' E' B D B' E B D");
    else if (c1 == 'X' and c2 == 'E') return("F E' F' D F E F' D'");
    else if (c1 == 'X' and c2 == 'R') return("D2 B E2 B' D B E2 B' D");
    else if (c1 == 'X' and c2 == 'T') return("F' E2 F D F' E2 F D'");
    else if (c1 == 'X' and c2 == 'Q') return("S L F L' S' L F' L'");
    else if (c1 == 'X' and c2 == 'O') return("B' L B M B' L' B M'");
    else if (c1 == 'X' and c2 == 'N') return("F E F' D F E' F' D'");
    else if (c1 == 'X' and c2 == 'P') return("F' E' F D F' E F D'");
    else if (c1 == 'X' and c2 == 'M') return("D' S U' S' D S U S'");
    else if (c1 == 'X' and c2 == 'B') return("S2 U F2 U' S2 U F2 U'");
    else if (c1 == 'X' and c2 == 'A') return("U' L2 U M2 U' L2 U M2");
    else if (c1 == 'X' and c2 == 'C') return("U' S2 U F2 U' S2 U F2");
    else if (c1 == 'X' and c2 == 'D') return("L2 U M2 U' L2 U M2 U'");
    else if (c1 == 'W' and c2 == 'X') return("L F E F' D2 F E' F' D2 L'");
    else if (c1 == 'W' and c2 == 'V') return("R' F' E' F D2 F' E F D2 R");
    else if (c1 == 'W' and c2 == 'K') return("F' R F' M2 F R' F' M2 F2");
    else if (c1 == 'W' and c2 == 'J') return("M' F2 M B' M' F2 M B");
    else if (c1 == 'W' and c2 == 'L') return("F M B2 M' F' M B2 M'");
    else if (c1 == 'W' and c2 == 'I') return("M' U M D2 M' U' M D2");
    else if (c1 == 'W' and c2 == 'F') return("D2 B E B' D2 B E' B'");
    else if (c1 == 'W' and c2 == 'H') return("D2 B' E' B D2 B' E B");
    else if (c1 == 'W' and c2 == 'E') return("F' E F D2 F' E' F D2");
    else if (c1 == 'W' and c2 == 'S') return("B2 M2 B L B' M2 B L' B");
    else if (c1 == 'W' and c2 == 'R') return("D2 B E2 B' D2 B E2 B'");
    else if (c1 == 'W' and c2 == 'T') return("M' F2 M B M' F2 M B'");
    else if (c1 == 'W' and c2 == 'Q') return("M' U' M D2 M' U M D2");
    else if (c1 == 'W' and c2 == 'N') return("F E F' D2 F E' F' D2");
    else if (c1 == 'W' and c2 == 'P') return("F' E' F D2 F' E F D2");
    else if (c1 == 'W' and c2 == 'M') return("D2 B E' B' D2 B E B'");
    else if (c1 == 'W' and c2 == 'B') return("D S D2 S' D2 S D2 S' D");
    else if (c1 == 'W' and c2 == 'A') return("M' D2 M D2");
    else if (c1 == 'W' and c2 == 'C') return("D2 M D2 M'");
    else if (c1 == 'W' and c2 == 'D') return("D S' D2 S D");
    else if (c1 == 'V' and c2 == 'X') return("R' D F' E' F D' F' E F R");
    else if (c1 == 'V' and c2 == 'W') return("R B E B' D2 B E' B' D2 R'");
    else if (c1 == 'V' and c2 == 'J') return("F E2 F' D' F E2 F' D");
    else if (c1 == 'V' and c2 == 'L') return("D2 B' E2 B D' B' E2 B D'");
    else if (c1 == 'V' and c2 == 'I') return("D R E' R' D' R E R'");
    else if (c1 == 'V' and c2 == 'F') return("D2 B E B' D' B E' B' D'");
    else if (c1 == 'V' and c2 == 'H') return("D R' E2 R D' R' E2 R");
    else if (c1 == 'V' and c2 == 'E') return("F' E F D' F' E' F D");
    else if (c1 == 'V' and c2 == 'S') return("S L' F L S' L' F' L");
    else if (c1 == 'V' and c2 == 'R') return("D R E R' D' R E' R'");
    else if (c1 == 'V' and c2 == 'T') return("F' E2 F D' F' E2 F D");
    else if (c1 == 'V' and c2 == 'Q') return("M' U' M D' M' U M D");
    else if (c1 == 'V' and c2 == 'O') return("B R' B' M B R B' M'");
    else if (c1 == 'V' and c2 == 'N') return("F E F' D' F E' F' D");
    else if (c1 == 'V' and c2 == 'P') return("F' E' F D' F' E F D");
    else if (c1 == 'V' and c2 == 'M') return("D S' U S D' S' U' S");
    else if (c1 == 'V' and c2 == 'B') return("D S' U2 S D' S' U2 S");
    else if (c1 == 'V' and c2 == 'A') return("U R2 U' M2 U R2 U' M2");
    else if (c1 == 'V' and c2 == 'C') return("M' U2 M D' M' U2 M D");
    else if (c1 == 'V' and c2 == 'D') return("S2 U' F2 U S2 U' F2 U");
    else if (c1 == 'K' and c2 == 'X') return("R F' R' S' R F R' S");
    else if (c1 == 'K' and c2 == 'W') return("F2 M2 F R F' M2 F R' F");
    else if (c1 == 'K' and c2 == 'J') return("R' B M2 B' R B M2 B'");
    else if (c1 == 'K' and c2 == 'L') return("F2 L' S2 L F' L' S2 L F'");
    else if (c1 == 'K' and c2 == 'I') return("R2 U M' U' R2 U M U'");
    else if (c1 == 'K' and c2 == 'F') return("R D' S2 D F D' S2 D F' R'");
    else if (c1 == 'K' and c2 == 'H') return("L R F' R' S' R F R' S L'");
    else if (c1 == 'K' and c2 == 'E') return("U' R2 U M' U' R2 U M");
    else if (c1 == 'K' and c2 == 'S') return("L2 S2 L F L' S2 L F' L");
    else if (c1 == 'K' and c2 == 'R') return("L' S2 L F L' S2 L F'");
    else if (c1 == 'K' and c2 == 'T') return("B2 R' B M2 B' R B M2 B");
    else if (c1 == 'K' and c2 == 'Q') return("R F' R' S2 R F R' S2");
    else if (c1 == 'K' and c2 == 'O') return("M' F' R F M F' R' F");
    else if (c1 == 'K' and c2 == 'N') return("R' B' D2 B E' B' D2 B E R");
    else if (c1 == 'K' and c2 == 'P') return("S F' E' F D F' E F D' S'");
    else if (c1 == 'K' and c2 == 'M') return("U R2 U M' U' R2 U M U2");
    else if (c1 == 'K' and c2 == 'B') return("R F' R' S R F R' S'");
    else if (c1 == 'K' and c2 == 'A') return("M2 F' R F M2 F' R' F");
    else if (c1 == 'K' and c2 == 'C') return("U' S' U F2 U' S U F2");
    else if (c1 == 'K' and c2 == 'D') return("U2 S' U F2 U' S U F2 U");
    else if (c1 == 'J' and c2 == 'X') return("D F E2 F' D' F E2 F'");
    else if (c1 == 'J' and c2 == 'W') return("D2 F E2 F' D2 F E2 F'");
    else if (c1 == 'J' and c2 == 'V') return("D' F E2 F' D F E2 F'");
    else if (c1 == 'J' and c2 == 'K') return("B M2 B' R' B M2 B' R");
    else if (c1 == 'J' and c2 == 'L') return("E B2 E' F' E B2 E' F");
    else if (c1 == 'J' and c2 == 'I') return("B M2 B' R B M2 B' R'");
    else if (c1 == 'J' and c2 == 'F') return("B' D2 B E B' D2 B E'");
    else if (c1 == 'J' and c2 == 'H') return("B' D2 B' E' B D2 B' E B2");
    else if (c1 == 'J' and c2 == 'E') return("M F' R2 F M' F' R2 F");
    else if (c1 == 'J' and c2 == 'S') return("R2 F' R S2 R' F R S2 R");
    else if (c1 == 'J' and c2 == 'R') return("B' D2 B E2 B' D2 B E2");
    else if (c1 == 'J' and c2 == 'T') return("B' M B2 M' B2 M B2 M' B'");
    else if (c1 == 'J' and c2 == 'Q') return("D' S' D' B' D S D' B D2");
    else if (c1 == 'J' and c2 == 'O') return("M' F' R2 F M F' R2 F");
    else if (c1 == 'J' and c2 == 'N') return("B' D2 B E' B' D2 B E");
    else if (c1 == 'J' and c2 == 'M') return("E2 F E' B E F' E' B' E'");
    else if (c1 == 'J' and c2 == 'B') return("D' S2 D' B' D S2 D' B D2");
    else if (c1 == 'J' and c2 == 'A') return("M2 F' R2 F M2 F' R2 F");
    else if (c1 == 'J' and c2 == 'C') return("F E' F2 E F2 E' F2 E F");
    else if (c1 == 'J' and c2 == 'D') return("D S2 D B' D' S2 D B D2");
    else if (c1 == 'L' and c2 == 'X') return("F' R' S' R F R' S R");
    else if (c1 == 'L' and c2 == 'W') return("B' E2 B D2 B' E2 B D2");
    else if (c1 == 'L' and c2 == 'V') return("D B' E2 B D B' E2 B D2");
    else if (c1 == 'L' and c2 == 'K') return("F L' S2 L F L' S2 L F2");
    else if (c1 == 'L' and c2 == 'J') return("R2 B M2 B' R2 B M2 B'");
    else if (c1 == 'L' and c2 == 'I') return("D S D' F D S' D' F'");
    else if (c1 == 'L' and c2 == 'H') return("E' L D' L' E L D L'");
    else if (c1 == 'L' and c2 == 'E') return("U' R U M' U' R' U M");
    else if (c1 == 'L' and c2 == 'S') return("F' R S2 R' F R S2 R'");
    else if (c1 == 'L' and c2 == 'R') return("D F2 L S L' F2 L S' L' D'");
    else if (c1 == 'L' and c2 == 'T') return("E2 B D2 B' E2 B D2 B'");
    else if (c1 == 'L' and c2 == 'Q') return("D' S' D F D' S D F'");
    else if (c1 == 'L' and c2 == 'O') return("F' E B E' F E B' E'");
    else if (c1 == 'L' and c2 == 'N') return("M B M' F M B' M' F'");
    else if (c1 == 'L' and c2 == 'P') return("E R D R' E' R D' R'");
    else if (c1 == 'L' and c2 == 'M') return("F' E B' E' F E B E'");
    else if (c1 == 'L' and c2 == 'B') return("D' S2 D F D' S2 D F'");
    else if (c1 == 'L' and c2 == 'A') return("B' R2 B M2 B' R2 B M2");
    else if (c1 == 'L' and c2 == 'C') return("R F2 D S D' F2 D S' D' R'");
    else if (c1 == 'L' and c2 == 'D') return("D S2 D' F D S2 D' F'");
    else if (c1 == 'I' and c2 == 'X') return("D M' U M D' M' U' M");
    else if (c1 == 'I' and c2 == 'W') return("M U' M' D2 M U M' D2");
    else if (c1 == 'I' and c2 == 'V') return("R E' R' D R E R' D'");
    else if (c1 == 'I' and c2 == 'K') return("U M' U' R2 U M U' R2");
    else if (c1 == 'I' and c2 == 'J') return("R B M2 B' R' B M2 B'");
    else if (c1 == 'I' and c2 == 'L') return("F D S D' F' D S' D'");
    else if (c1 == 'I' and c2 == 'F') return("U D R' D' M D R D' M' U'");
    else if (c1 == 'I' and c2 == 'H') return("R' E' L D' L' E L D L' R");
    else if (c1 == 'I' and c2 == 'E') return("S D S' U' S D' S' U");
    else if (c1 == 'I' and c2 == 'S') return("S2 L' F L S2 L' F' L");
    else if (c1 == 'I' and c2 == 'R') return("F' D S D' F D S' D'");
    else if (c1 == 'I' and c2 == 'T') return("D2 B D' S D B' D' S' D'");
    else if (c1 == 'I' and c2 == 'Q') return("S D S' U2 S D' S' U2");
    else if (c1 == 'I' and c2 == 'O') return("M' F' R' F M F' R F");
    else if (c1 == 'I' and c2 == 'N') return("E F' D S D' F D S' D' E'");
    else if (c1 == 'I' and c2 == 'P') return("S F' E' F D' F' E F D S'");
    else if (c1 == 'I' and c2 == 'M') return("S D S' U S D' S' U'");
    else if (c1 == 'I' and c2 == 'A') return("M2 F' R' F M2 F' R F");
    else if (c1 == 'I' and c2 == 'C') return("F2 D S D' F2 D S' D'");
    else if (c1 == 'I' and c2 == 'D') return("S' U' F2 U S U' F2 U");
    else if (c1 == 'F' and c2 == 'X') return("L E2 L' D' L E2 L' D");
    else if (c1 == 'F' and c2 == 'W') return("B E B' D2 B E' B' D2");
    else if (c1 == 'F' and c2 == 'V') return("D B E B' D B E' B' D2");
    else if (c1 == 'F' and c2 == 'K') return("R' F E2 F' D' F E2 F' D R");
    else if (c1 == 'F' and c2 == 'J') return("R' D R E' R' D' R E");
    else if (c1 == 'F' and c2 == 'I') return("U M D R' D' M' D R D' U'");
    else if (c1 == 'F' and c2 == 'H') return("R' D R' E2 R D' R' E2 R2");
    else if (c1 == 'F' and c2 == 'E') return("M D R' D' M' D R D'");
    else if (c1 == 'F' and c2 == 'S') return("M' F R' S' R F' R' S R M");
    else if (c1 == 'F' and c2 == 'R') return("R' D R E R' D' R E'");
    else if (c1 == 'F' and c2 == 'T') return("B2 E B' D2 B E' B' D2 B'");
    else if (c1 == 'F' and c2 == 'Q') return("R U F2 U' S U F2 U' S' R'");
    else if (c1 == 'F' and c2 == 'O') return("M' D R' D' M D R D'");
    else if (c1 == 'F' and c2 == 'N') return("R' D R E2 R' D' R E2");
    else if (c1 == 'F' and c2 == 'P') return("R2 B' M B R2 B' M' B");
    else if (c1 == 'F' and c2 == 'M') return("B' R2 B' M B R2 B' M' B2");
    else if (c1 == 'F' and c2 == 'B') return("R U' M2 U R' U' M2 U");
    else if (c1 == 'F' and c2 == 'A') return("U R U' M2 U R' U' M2");
    else if (c1 == 'F' and c2 == 'C') return("D2 M2 D' R' D M2 D' R D'");
    else if (c1 == 'F' and c2 == 'D') return("U2 R U' M2 U R' U' M2 U'");
    else if (c1 == 'H' and c2 == 'X') return("D' B' E' B D' B' E B D2");
    else if (c1 == 'H' and c2 == 'W') return("B' E' B D2 B' E B D2");
    else if (c1 == 'H' and c2 == 'V') return("R' E2 R D R' E2 R D'");
    else if (c1 == 'H' and c2 == 'K') return("M' F' L S L' F L S' L' M");
    else if (c1 == 'H' and c2 == 'J') return("B2 E' B D2 B' E B D2 B");
    else if (c1 == 'H' and c2 == 'L') return("L D' L' E' L D L' E");
    else if (c1 == 'H' and c2 == 'I') return("R' L D' L' E' L D L' E R");
    else if (c1 == 'H' and c2 == 'F') return("R2 E2 R D R' E2 R D' R");
    else if (c1 == 'H' and c2 == 'E') return("M D' L D M' D' L' D");
    else if (c1 == 'H' and c2 == 'S') return("E F' R S2 R' F R S2 R' E'");
    else if (c1 == 'H' and c2 == 'T') return("E' B D2 B' E B D2 B'");
    else if (c1 == 'H' and c2 == 'Q') return("U' M D' L D M' D' L' D U");
    else if (c1 == 'H' and c2 == 'O') return("M' D' L D M D' L' D");
    else if (c1 == 'H' and c2 == 'N') return("L2 B M B' L2 B M' B'");
    else if (c1 == 'H' and c2 == 'P') return("E2 R D R' E2 R D' R'");
    else if (c1 == 'H' and c2 == 'M') return("B L2 B M B' L2 B M' B2");
    else if (c1 == 'H' and c2 == 'B') return("U2 L' U M2 U' L U M2 U");
    else if (c1 == 'H' and c2 == 'A') return("U' L' U M2 U' L U M2");
    else if (c1 == 'H' and c2 == 'C') return("U L' U M2 U' L U M2 U2");
    else if (c1 == 'H' and c2 == 'D') return("L' U M2 U' L U M2 U'");
    else if (c1 == 'E' and c2 == 'X') return("S U S' D' S U' S' D");
    else if (c1 == 'E' and c2 == 'W') return("D2 F' E F D2 F' E' F");
    else if (c1 == 'E' and c2 == 'V') return("S' U' S D S' U S D'");
    else if (c1 == 'E' and c2 == 'K') return("M' U' R2 U M U' R2 U");
    else if (c1 == 'E' and c2 == 'J') return("F' R2 F M F' R2 F M'");
    else if (c1 == 'E' and c2 == 'L') return("M' U' R U M U' R' U");
    else if (c1 == 'E' and c2 == 'I') return("U' S D S' U S D' S'");
    else if (c1 == 'E' and c2 == 'F') return("D R' D' M D R D' M'");
    else if (c1 == 'E' and c2 == 'H') return("D' L D M D' L' D M'");
    else if (c1 == 'E' and c2 == 'S') return("F L' F' M F L F' M'");
    else if (c1 == 'E' and c2 == 'R') return("M' U L' U' M U L U'");
    else if (c1 == 'E' and c2 == 'T') return("F L2 F' M F L2 F' M'");
    else if (c1 == 'E' and c2 == 'Q') return("U S' D' S U' S' D S");
    else if (c1 == 'E' and c2 == 'O') return("D2 F2 D S' D' F2 D S D");
    else if (c1 == 'E' and c2 == 'N') return("D' L' D M D' L D M'");
    else if (c1 == 'E' and c2 == 'P') return("D R D' M D R' D' M'");
    else if (c1 == 'E' and c2 == 'M') return("F' E' F U2 F' E F U2");
    else if (c1 == 'E' and c2 == 'B') return("D R2 D' M D R2 D' M'");
    else if (c1 == 'E' and c2 == 'A') return("U' S' U' F2 U S U' F2 U2");
    else if (c1 == 'E' and c2 == 'D') return("D' L2 D M D' L2 D M'");
    else if (c1 == 'S' and c2 == 'W') return("B' L B' M2 B L' B' M2 B2");
    else if (c1 == 'S' and c2 == 'V') return("L' F L S L' F' L S'");
    else if (c1 == 'S' and c2 == 'K') return("L' F L' S2 L F' L' S2 L2");
    else if (c1 == 'S' and c2 == 'J') return("B2 L B' M2 B L' B' M2 B'");
    else if (c1 == 'S' and c2 == 'L') return("R S2 R' F' R S2 R' F");
    else if (c1 == 'S' and c2 == 'I') return("L' F L S2 L' F' L S2");
    else if (c1 == 'S' and c2 == 'F') return("M' R' S' R F R' S R F' M");
    else if (c1 == 'S' and c2 == 'H') return("D F L' S2 L F' L' S2 L D'");
    else if (c1 == 'S' and c2 == 'E') return("U L2 U' M' U L2 U' M");
    else if (c1 == 'S' and c2 == 'R') return("F2 R S2 R' F R S2 R' F");
    else if (c1 == 'S' and c2 == 'T') return("L B' M2 B L' B' M2 B");
    else if (c1 == 'S' and c2 == 'Q') return("L2 U' M' U L2 U' M U");
    else if (c1 == 'S' and c2 == 'O') return("M' F L' F' M F L F'");
    else if (c1 == 'S' and c2 == 'N') return("F B D' B' E' B D B' E F'");
    else if (c1 == 'S' and c2 == 'P') return("S' F' E' F D' F' E F D S");
    else if (c1 == 'S' and c2 == 'M') return("S' D S' U S D' S' U' S2");
    else if (c1 == 'S' and c2 == 'B') return("L' F L' S' L F' L' S L2");
    else if (c1 == 'S' and c2 == 'A') return("B L B' M2 B L' B' M2");
    else if (c1 == 'S' and c2 == 'C') return("U S U' F2 U S' U' F2");
    else if (c1 == 'S' and c2 == 'D') return("S U' F2 U S' U' F2 U");
    else if (c1 == 'R' and c2 == 'X') return("D2 R E R' D' R E' R' D'");
    else if (c1 == 'R' and c2 == 'W') return("B E2 B' D2 B E2 B' D2");
    else if (c1 == 'R' and c2 == 'V') return("R E R' D R E' R' D'");
    else if (c1 == 'R' and c2 == 'K') return("F L' S2 L F' L' S2 L");
    else if (c1 == 'R' and c2 == 'J') return("E2 B' D2 B E2 B' D2 B");
    else if (c1 == 'R' and c2 == 'L') return("M2 F' M F2 M' F' M2");
    else if (c1 == 'R' and c2 == 'I') return("D S D' F' D S' D' F");
    else if (c1 == 'R' and c2 == 'F') return("E R' D R E' R' D' R");
    else if (c1 == 'R' and c2 == 'E') return("U L' U' M' U L U' M");
    else if (c1 == 'R' and c2 == 'S') return("F' R S2 R' F' R S2 R' F2");
    else if (c1 == 'R' and c2 == 'T') return("F E' B2 E F' E' B2 E");
    else if (c1 == 'R' and c2 == 'Q') return("D' S' D F' D' S D F");
    else if (c1 == 'R' and c2 == 'O') return("D' S D F' D' S' D F");
    else if (c1 == 'R' and c2 == 'N') return("F L S' L' F' L S L'");
    else if (c1 == 'R' and c2 == 'P') return("M B' M' F' M B M' F");
    else if (c1 == 'R' and c2 == 'M') return("F E' B E F' E' B' E");
    else if (c1 == 'R' and c2 == 'B') return("D' S2 D F' D' S2 D F");
    else if (c1 == 'R' and c2 == 'A') return("B L2 B' M2 B L2 B' M2");
    else if (c1 == 'R' and c2 == 'C') return("U' D' S2 D F' D' S2 D F U");
    else if (c1 == 'R' and c2 == 'D') return("D S2 D' F' D S2 D' F");
    else if (c1 == 'T' and c2 == 'X') return("D F' E2 F D' F' E2 F");
    else if (c1 == 'T' and c2 == 'W') return("D2 F' E2 F D2 F' E2 F");
    else if (c1 == 'T' and c2 == 'V') return("D' F' E2 F D F' E2 F");
    else if (c1 == 'T' and c2 == 'K') return("B' M2 B' R' B M2 B' R B2");
    else if (c1 == 'T' and c2 == 'J') return("B M B2 M' B2 M B2 M' B");
    else if (c1 == 'T' and c2 == 'L') return("B D2 B' E2 B D2 B' E2");
    else if (c1 == 'T' and c2 == 'I') return("D S D B D' S' D B' D2");
    else if (c1 == 'T' and c2 == 'F') return("R2 E' R D R' E R D' R");
    else if (c1 == 'T' and c2 == 'H') return("B D2 B' E' B D2 B' E");
    else if (c1 == 'T' and c2 == 'E') return("M F L2 F' M' F L2 F'");
    else if (c1 == 'T' and c2 == 'S') return("B' M2 B L B' M2 B L'");
    else if (c1 == 'T' and c2 == 'R') return("B' M2 B L2 B' M2 B L2");
    else if (c1 == 'T' and c2 == 'Q') return("B' M2 B L' B' M2 B L");
    else if (c1 == 'T' and c2 == 'O') return("M' F L2 F' M F L2 F'");
    else if (c1 == 'T' and c2 == 'P') return("B D2 B' E B D2 B' E'");
    else if (c1 == 'T' and c2 == 'M') return("E2 F' E B' E' F E B E");
    else if (c1 == 'T' and c2 == 'B') return("D' S2 D' B D S2 D' B' D2");
    else if (c1 == 'T' and c2 == 'A') return("M2 F L2 F' M2 F L2 F'");
    else if (c1 == 'T' and c2 == 'C') return("F' E F2 E' F2 E F2 E' F'");
    else if (c1 == 'T' and c2 == 'D') return("D S2 D B D' S2 D B' D2");
    else if (c1 == 'Q' and c2 == 'X') return("L' E L D' L' E' L D");
    else if (c1 == 'Q' and c2 == 'W') return("M U M' D2 M U' M' D2");
    else if (c1 == 'Q' and c2 == 'V') return("D' M' U' M D M' U M");
    else if (c1 == 'Q' and c2 == 'K') return("S2 R F' R' S2 R F R'");
    else if (c1 == 'Q' and c2 == 'J') return("D2 B' D S' D' B D S D");
    else if (c1 == 'Q' and c2 == 'L') return("R' S2 R F' R' S2 R F");
    else if (c1 == 'Q' and c2 == 'I') return("U2 S D S' U2 S D' S'");
    else if (c1 == 'Q' and c2 == 'F') return("M' R S R' F R S' R' F' M");
    else if (c1 == 'Q' and c2 == 'H') return("U' D' L D M D' L' D M' U");
    else if (c1 == 'Q' and c2 == 'E') return("S' D' S U S' D S U'");
    else if (c1 == 'Q' and c2 == 'S') return("U' M' U L2 U' M U L2");
    else if (c1 == 'Q' and c2 == 'R') return("F' D' S' D F D' S D");
    else if (c1 == 'Q' and c2 == 'T') return("L' B' M2 B L B' M2 B");
    else if (c1 == 'Q' and c2 == 'O') return("M' F L F' M F L' F'");
    else if (c1 == 'Q' and c2 == 'N') return("S' F E F' D F E' F' D' S");
    else if (c1 == 'Q' and c2 == 'P') return("E' F D' S' D F' D' S D E");
    else if (c1 == 'Q' and c2 == 'M') return("S' D' S U' S' D S U");
    else if (c1 == 'Q' and c2 == 'B') return("S U F2 U' S' U F2 U'");
    else if (c1 == 'Q' and c2 == 'A') return("M2 F L F' M2 F L' F'");
    else if (c1 == 'Q' and c2 == 'C') return("F2 D' S' D F2 D' S D");
    else if (c1 == 'O' and c2 == 'X') return("M B' L B M' B' L' B");
    else if (c1 == 'O' and c2 == 'V') return("M B R' B' M' B R B'");
    else if (c1 == 'O' and c2 == 'K') return("F' R F M' F' R' F M");
    else if (c1 == 'O' and c2 == 'J') return("F' R2 F M' F' R2 F M");
    else if (c1 == 'O' and c2 == 'L') return("M D' R' D M' D' R D");
    else if (c1 == 'O' and c2 == 'I') return("F' R' F M' F' R F M");
    else if (c1 == 'O' and c2 == 'F') return("M B R2 B' M' B R2 B'");
    else if (c1 == 'O' and c2 == 'H') return("M B' L2 B M' B' L2 B");
    else if (c1 == 'O' and c2 == 'E') return("D S D F2 D' S' D F2 D2");
    else if (c1 == 'O' and c2 == 'S') return("F L' F' M' F L F' M");
    else if (c1 == 'O' and c2 == 'R') return("F' D' S D F D' S' D");
    else if (c1 == 'O' and c2 == 'T') return("F L2 F' M' F L2 F' M");
    else if (c1 == 'O' and c2 == 'Q') return("F L F' M' F L' F' M");
    else if (c1 == 'O' and c2 == 'N') return("D S D' B D S' D' B'");
    else if (c1 == 'O' and c2 == 'P') return("D S D' B' D S' D' B");
    else if (c1 == 'O' and c2 == 'M') return("D S D' B2 D S' D' B2");
    else if (c1 == 'O' and c2 == 'B') return("M B R B' M' B R' B'");
    else if (c1 == 'O' and c2 == 'A') return("B' E' B' D2 B E B' D2 B2");
    else if (c1 == 'O' and c2 == 'C') return("F2 D' S D F2 D' S' D");
    else if (c1 == 'O' and c2 == 'D') return("M B' L' B M' B' L B");
    else if (c1 == 'N' and c2 == 'X') return("D F E F' D' F E' F'");
    else if (c1 == 'N' and c2 == 'W') return("D2 F E F' D2 F E' F'");
    else if (c1 == 'N' and c2 == 'V') return("D' F E F' D F E' F'");
    else if (c1 == 'N' and c2 == 'K') return("S D F E F' D' F E' F' S'");
    else if (c1 == 'N' and c2 == 'J') return("E' B' D2 B E B' D2 B");
    else if (c1 == 'N' and c2 == 'L') return("F M B M' F' M B' M'");
    else if (c1 == 'N' and c2 == 'I') return("S D' F E F' D F E' F' S'");
    else if (c1 == 'N' and c2 == 'F') return("E2 R' D R E2 R' D' R");
    else if (c1 == 'N' and c2 == 'H') return("B M B' L2 B M' B' L2");
    else if (c1 == 'N' and c2 == 'E') return("F' L2 F M' F' L2 F M");
    else if (c1 == 'N' and c2 == 'S') return("F E' B D' B' E B D B' F'");
    else if (c1 == 'N' and c2 == 'R') return("L' S L F L' S' L F'");
    else if (c1 == 'N' and c2 == 'Q') return("E D' S' D F' D' S D F E'");
    else if (c1 == 'N' and c2 == 'O') return("B D S D' B' D S' D'");
    else if (c1 == 'N' and c2 == 'P') return("E F E' B2 E F' E' B2");
    else if (c1 == 'N' and c2 == 'M') return("E F E' B E F' E' B'");
    else if (c1 == 'N' and c2 == 'B') return("R' E2 R' D R E2 R' D' R2");
    else if (c1 == 'N' and c2 == 'A') return("M2 D' L' D M2 D' L D");
    else if (c1 == 'N' and c2 == 'C') return("F2 M B M' F2 M B' M'");
    else if (c1 == 'N' and c2 == 'D') return("B M B' L' B M' B' L");
    else if (c1 == 'P' and c2 == 'X') return("D F' E' F D' F' E F");
    else if (c1 == 'P' and c2 == 'W') return("D2 F' E' F D2 F' E F");
    else if (c1 == 'P' and c2 == 'V') return("D' F' E' F D F' E F");
    else if (c1 == 'P' and c2 == 'K') return("F' E B' D B E' B' D' B F");
    else if (c1 == 'P' and c2 == 'L') return("R S' R' F' R S R' F");
    else if (c1 == 'P' and c2 == 'I') return("E' D S D' F D S' D' F' E");
    else if (c1 == 'P' and c2 == 'F') return("B' M B R2 B' M' B R2");
    else if (c1 == 'P' and c2 == 'H') return("E2 L D' L' E2 L D L'");
    else if (c1 == 'P' and c2 == 'E') return("F R2 F' M' F R2 F' M");
    else if (c1 == 'P' and c2 == 'S') return("S' D' F' E' F D F' E F S");
    else if (c1 == 'P' and c2 == 'R') return("F' M B' M' F M B M'");
    else if (c1 == 'P' and c2 == 'T') return("E B D2 B' E' B D2 B'");
    else if (c1 == 'P' and c2 == 'Q') return("S' D F' E' F D' F' E F S");
    else if (c1 == 'P' and c2 == 'O') return("B' D' S' D B D' S D");
    else if (c1 == 'P' and c2 == 'N') return("E' F' E B2 E' F E B2");
    else if (c1 == 'P' and c2 == 'M') return("E' F' E B' E' F E B");
    else if (c1 == 'P' and c2 == 'B') return("B' M B R B' M' B R'");
    else if (c1 == 'P' and c2 == 'A') return("M2 D R D' M2 D R' D'");
    else if (c1 == 'P' and c2 == 'C') return("F2 M B' M' F2 M B M'");
    else if (c1 == 'P' and c2 == 'D') return("L E2 L D' L' E2 L D L2");
    else if (c1 == 'M' and c2 == 'X') return("S U' S' D' S U S' D");
    else if (c1 == 'M' and c2 == 'W') return("B E' B' D2 B E B' D2");
    else if (c1 == 'M' and c2 == 'V') return("S' U S D S' U' S D'");
    else if (c1 == 'M' and c2 == 'K') return("F' R F' M F R' F' M' F2");
    else if (c1 == 'M' and c2 == 'J') return("F' R2 F' M F R2 F' M' F2");
    else if (c1 == 'M' and c2 == 'L') return("E B' E' F' E B E' F");
    else if (c1 == 'M' and c2 == 'I') return("U S D S' U' S D' S'");
    else if (c1 == 'M' and c2 == 'F') return("D R' D M' D' R D M D2");
    else if (c1 == 'M' and c2 == 'H') return("D' L D' M' D L' D' M D2");
    else if (c1 == 'M' and c2 == 'E') return("U2 F' E' F U2 F' E F");
    else if (c1 == 'M' and c2 == 'S') return("F L' F M F' L F M' F2");
    else if (c1 == 'M' and c2 == 'R') return("E' B E F E' B' E F'");
    else if (c1 == 'M' and c2 == 'T') return("F L2 F M F' L2 F M' F2");
    else if (c1 == 'M' and c2 == 'Q') return("U' S' D' S U S' D S");
    else if (c1 == 'M' and c2 == 'O') return("B2 D S D' B2 D S' D'");
    else if (c1 == 'M' and c2 == 'N') return("B E F E' B' E F' E'");
    else if (c1 == 'M' and c2 == 'P') return("B' E' F' E B E' F E");
    else if (c1 == 'M' and c2 == 'B') return("S' U' S' D' S U S' D S2");
    else if (c1 == 'M' and c2 == 'C') return("U' S U F2 U' S' U F2");
    else if (c1 == 'M' and c2 == 'D') return("S U S D S' U' S D' S2");
    else if (c1 == 'B' and c2 == 'X') return("U F2 U' S2 U F2 U' S2");
    else if (c1 == 'B' and c2 == 'W') return("D S D2 S' D");
    else if (c1 == 'B' and c2 == 'V') return("U' M2 U R2 U' M2 U R2");
    else if (c1 == 'B' and c2 == 'K') return("R2 D R E' R' D' R E R");
    else if (c1 == 'B' and c2 == 'J') return("D2 B' D S2 D' B D S2 D");
    else if (c1 == 'B' and c2 == 'L') return("F D' S2 D F' D' S2 D");
    else if (c1 == 'B' and c2 == 'F') return("U' M2 U R U' M2 U R'");
    else if (c1 == 'B' and c2 == 'H') return("U' M2 U' L' U M2 U' L U2");
    else if (c1 == 'B' and c2 == 'E') return("S2 D' S U S' D S U' S");
    else if (c1 == 'B' and c2 == 'S') return("L2 S' L F L' S L F' L");
    else if (c1 == 'B' and c2 == 'R') return("F' D' S2 D F D' S2 D");
    else if (c1 == 'B' and c2 == 'T') return("D2 B D S2 D' B' D S2 D");
    else if (c1 == 'B' and c2 == 'Q') return("U F2 U' S U F2 U' S'");
    else if (c1 == 'B' and c2 == 'O') return("B R B' M B R' B' M'");
    else if (c1 == 'B' and c2 == 'N') return("U' M2 U' L U M2 U' L' U2");
    else if (c1 == 'B' and c2 == 'P') return("R B' M B R' B' M' B");
    else if (c1 == 'B' and c2 == 'M') return("S2 D' S U' S' D S U S");
    else if (c1 == 'B' and c2 == 'A') return("M2 D R2 D' M2 D R2 D'");
    else if (c1 == 'B' and c2 == 'C') return("F2 D' S2 D F2 D' S2 D");
    else if (c1 == 'B' and c2 == 'D') return("U M D2 M' U2 M D2 M' U");
    else if (c1 == 'A' and c2 == 'X') return("M2 U' L2 U M2 U' L2 U");
    else if (c1 == 'A' and c2 == 'W') return("D2 M' D2 M");
    else if (c1 == 'A' and c2 == 'V') return("M2 U R2 U' M2 U R2 U'");
    else if (c1 == 'A' and c2 == 'K') return("F' R F M2 F' R' F M2");
    else if (c1 == 'A' and c2 == 'J') return("F' R2 F M2 F' R2 F M2");
    else if (c1 == 'A' and c2 == 'L') return("M2 B' R2 B M2 B' R2 B");
    else if (c1 == 'A' and c2 == 'I') return("F' R' F M2 F' R F M2");
    else if (c1 == 'A' and c2 == 'F') return("D R' D' M2 D R D' M2");
    else if (c1 == 'A' and c2 == 'H') return("D' L D M2 D' L' D M2");
    else if (c1 == 'A' and c2 == 'E') return("U2 F2 U' S U F2 U' S' U'");
    else if (c1 == 'A' and c2 == 'S') return("F L' F' M2 F L F' M2");
    else if (c1 == 'A' and c2 == 'R') return("M2 B L2 B' M2 B L2 B'");
    else if (c1 == 'A' and c2 == 'T') return("F L2 F' M2 F L2 F' M2");
    else if (c1 == 'A' and c2 == 'Q') return("F L F' M2 F L' F' M2");
    else if (c1 == 'A' and c2 == 'O') return("B2 D2 B E' B' D2 B E B");
    else if (c1 == 'A' and c2 == 'N') return("D' L' D M2 D' L D M2");
    else if (c1 == 'A' and c2 == 'P') return("D R D' M2 D R' D' M2");
    else if (c1 == 'A' and c2 == 'B') return("D R2 D' M2 D R2 D' M2");
    else if (c1 == 'A' and c2 == 'C') return("F2 M F2 M'");
    else if (c1 == 'A' and c2 == 'D') return("D' L2 D M2 D' L2 D M2");
    else if (c1 == 'C' and c2 == 'X') return("F2 U' S2 U F2 U' S2 U");
    else if (c1 == 'C' and c2 == 'W') return("F2 M' F2 M");
    else if (c1 == 'C' and c2 == 'V') return("F2 U S2 U' F2 U S2 U'");
    else if (c1 == 'C' and c2 == 'K') return("F2 U' S' U F2 U' S U");
    else if (c1 == 'C' and c2 == 'J') return("F' E' F2 E F2 E' F2 E F'");
    else if (c1 == 'C' and c2 == 'L') return("R D S D' F2 D S' D' F2 R'");
    else if (c1 == 'C' and c2 == 'I') return("D S D' F2 D S' D' F2");
    else if (c1 == 'C' and c2 == 'F') return("D R' D M2 D' R D M2 D2");
    else if (c1 == 'C' and c2 == 'H') return("D' L D' M2 D L' D' M2 D2");
    else if (c1 == 'C' and c2 == 'S') return("F2 U S U' F2 U S' U'");
    else if (c1 == 'C' and c2 == 'R') return("L' D' S' D F2 D' S D F2 L");
    else if (c1 == 'C' and c2 == 'T') return("F E F2 E' F2 E F2 E' F");
    else if (c1 == 'C' and c2 == 'Q') return("D' S' D F2 D' S D F2");
    else if (c1 == 'C' and c2 == 'O') return("D' S D F2 D' S' D F2");
    else if (c1 == 'C' and c2 == 'N') return("M B M' F2 M B' M' F2");
    else if (c1 == 'C' and c2 == 'P') return("M B' M' F2 M B M' F2");
    else if (c1 == 'C' and c2 == 'M') return("F2 U' S U F2 U' S' U");
    else if (c1 == 'C' and c2 == 'B') return("D' S2 D F2 D' S2 D F2");
    else if (c1 == 'C' and c2 == 'A') return("M F2 M' F2");
    else if (c1 == 'C' and c2 == 'D') return("D S2 D' F2 D S2 D' F2");
    else if (c1 == 'D' and c2 == 'X') return("U M2 U' L2 U M2 U' L2");
    else if (c1 == 'D' and c2 == 'W') return("D S' D2 S D2 S' D2 S D");
    else if (c1 == 'D' and c2 == 'V') return("U' F2 U S2 U' F2 U S2");
    else if (c1 == 'D' and c2 == 'K') return("R2 S R' F' R S' R' F R'");
    else if (c1 == 'D' and c2 == 'J') return("D2 B' D' S2 D B D' S2 D'");
    else if (c1 == 'D' and c2 == 'L') return("F D S2 D' F' D S2 D'");
    else if (c1 == 'D' and c2 == 'I') return("U' F2 U S' U' F2 U S");
    else if (c1 == 'D' and c2 == 'F') return("U M2 U R U' M2 U R' U2");
    else if (c1 == 'D' and c2 == 'H') return("U M2 U' L' U M2 U' L");
    else if (c1 == 'D' and c2 == 'E') return("F' L F M' F' L' F M");
    else if (c1 == 'D' and c2 == 'S') return("U' F2 U S U' F2 U S'");
    else if (c1 == 'D' and c2 == 'R') return("F' D S2 D' F D S2 D'");
    else if (c1 == 'D' and c2 == 'T') return("D2 B D' S2 D B' D' S2 D'");
    else if (c1 == 'D' and c2 == 'O') return("B' L' B M B' L B M'");
    else if (c1 == 'D' and c2 == 'N') return("L' B M B' L B M' B'");
    else if (c1 == 'D' and c2 == 'P') return("U M2 U R' U' M2 U R U2");
    else if (c1 == 'D' and c2 == 'M') return("S2 D S' U S D' S' U' S'");
    else if (c1 == 'D' and c2 == 'B') return("U' M' U2 M U2 M' U2 M U'");
    else if (c1 == 'D' and c2 == 'A') return("M2 D' L2 D M2 D' L2 D");
    else if (c1 == 'D' and c2 == 'C') return("F2 D S2 D' F2 D S2 D'");

    else if (c1 == 'A' and c2 == 'M') return("F2 M' U M' U M' U2 M U M U M U2 F2");
    else if (c1 == 'B' and c2 == 'I') return("U M' F M' F M' F2 M F M F M F2 U'");
    else if (c1 == 'C' and c2 == 'E') return("M' F M' F M' F2 M F M F M F2");
    else if (c1 == 'D' and c2 == 'Q') return("U' M' F M' F M' F2 M F M F M F2 U");

    else if (c1 == 'F' and c2 == 'L') return("R U M' F M' F M' F2 M F M F M F2 U' R'");
    else if (c1 == 'H' and c2 == 'R') return("L' U' M' F M' F M' F2 M F M F M F2 U L");
    else if (c1 == 'J' and c2 == 'P') return("B' M D M D M D2 M' D M' D M' D2 B");
    else if (c1 == 'K' and c2 == 'V') return("R2 U M' F M' F M' F2 M F M F M F2 U' R2");

    else if (c1 == 'N' and c2 == 'T') return("B M D M D M D2 M' D M' D M' D2 B'");
    else if (c1 == 'O' and c2 == 'W') return("M D M D M D2 M' D M' D M' D2");
    else if (c1 == 'S' and c2 == 'X') return("L2 U' M' F M' F M' F2 M F M F M F2 U L2");

    else return "";
}

string return_edge_parity() 
{
  return("U' F2 U M2 U' F2 U");
}

// Wings

stack<string> split_inv(string scr)
{
    stack<string> tmp;
    string word = "";
    int i = 0;
    for(auto x : scr)
    {
        if(x == ' ')
        {
            tmp.push(word);
            word = "";
            i++;
        }
        else 
        {
            word = word+x;
        }
    }
    tmp.push(word);

    return tmp;
}

string invert(string scr)
{
    stack<string> st = split_inv(scr);
    string s;
    while (!st.empty()) 
    {
        string c = st.top();
        int len_c = c.length();
        if(c[len_c-1] == '\'') s = s+c.substr(0,len_c-1)+" ";
        else if(c[len_c-1] == '2') s = s+c+" ";
        else s = s+c+"' ";
        st.pop();
    }
    return s;
}


string r2(int i)
{
    return (to_string(i+1)+"R");
}

string l2(int i)
{
    return (to_string(i+1)+"L");
}

string f2(int i)
{
    return (to_string(i+1)+"F");
}

string b2(int i)
{
    return (to_string(i+1)+"B");
}

string u2(int i)
{
    return (to_string(i+1)+"U");
}

string d2(int i)
{
    return (to_string(i+1)+"D");
}

string return_3S_wing_alg(char c1,char c2,int t,int size)
{
    int s = (size-1)/2-t;

    if(c1 == 'A')
    {
        if(c2 == 'A') return "";
        else if(c2 =='B') return(r2(s)+"2 R' U R U' "+r2(s)+"2 U R' U' R");
        else if(c2 =='C') return("U R' U2 R U' "+r2(s)+"2 U R' U' "+r2(s)+"2 U' R U'");
        else if(c2 =='D') return(r2(s)+"2 L U' L' U "+r2(s)+"2 U' L U L'");
        else if(c2 =='E') return("D U R2 U' "+r2(s)+" U R2 U' "+r2(s)+"' D'");
        else if(c2 =='F') return(r2(s)+"2 U R U' "+r2(s)+"2 U R' U'");
        else if(c2 =='G') return("U "+r2(s)+"' D2 "+r2(s)+"' U' "+r2(s)+" D2 "+r2(s)+"' U "+r2(s)+"2 U'");
        else if(c2 =='H') return(r2(s)+"2 U' L' U "+r2(s)+"2 U' L U");
        else if(c2 =='I') return(r2(s)+"2 B' R B "+r2(s)+"2 B' R' B");
        else if(c2 =='J') return(r2(s)+"2 R' B' R B "+r2(s)+"2 B' R' B R");
        else if(c2 =='K') return(r2(s)+"2 B' R' B "+r2(s)+"2 B' R B");
        else if(c2 =='L') return(r2(s)+"2 B' R2 B "+r2(s)+"2 B' R2 B");
        else if(c2 =='M') return("U2 "+l2(s)+"2 D2 "+l2(s)+" U2 "+l2(s)+"' D2 "+l2(s)+" U2 "+l2(s)+" U2");
        else if(c2 =='N') return(r2(s)+"2 U' L U "+r2(s)+"2 U' L' U");
        else if(c2 =='O') return("F' B' R2 B "+r2(s)+"' B' R2 B "+r2(s)+" F");
        else if(c2 =='P') return(r2(s)+"2 U R' U' "+r2(s)+"2 U R U'");
        else if(c2 =='Q') return(r2(s)+"2 B L' B' "+r2(s)+"2 B L B'");
        else if(c2 =='R') return(r2(s)+"2 B L2 B' "+r2(s)+"2 B L2 B'");
        else if(c2 =='S') return(r2(s)+"2 B L B' "+r2(s)+"2 B L' B'");
        else if(c2 =='T') return(r2(s)+"2 L B L' B' "+r2(s)+"2 B L B' L'");
        else if(c2 =='V') return(r2(s)+"2 U R2 U' "+r2(s)+"2 U R2 U'");
        else if(c2 =='W') return("D' R' D "+r2(s)+"2 U R' U' "+r2(s)+"2 U R U' D' R D");
        else if(c2 =='X') return(r2(s)+"2 U' L2 U "+r2(s)+"2 U' L2 U");
        else return("");
    }

    else if(c1 == 'B')
    {
        if(c2 =='A') return("R' U R U' "+r2(s)+"2 U R' U' R "+r2(s)+"2");
        else if(c2 =='C') return("U2 L U' L' U "+r2(s)+"2 U' L U L' "+r2(s)+"2 U2");
        else if(c2 =='D') return("R' U2 R U' "+r2(s)+"2 U R' U' "+r2(s)+"2 U' R");
        else if(c2 =='E') return(r2(s)+" R' U R U' "+r2(s)+" U R' U' R "+r2(s)+"2");
        else if(c2 =='F') return("U' "+r2(s)+"2 U R U' "+r2(s)+"2 U R'");
        else if(c2 =='G') return(r2(s)+"' D2 "+r2(s)+"' U' "+r2(s)+" D2 "+r2(s)+"' U "+r2(s)+"2");
        else if(c2 =='H') return("U' "+r2(s)+"2 U' L' U "+r2(s)+"2 U' L U2");
        else if(c2 =='I') return("U "+l2(s)+"2 D2 "+l2(s)+" U2 "+l2(s)+"' D2 "+l2(s)+" U2 "+l2(s)+" U'");
        else if(c2 =='J') return(d2(s)+"' U' "+r2(s)+"2 U R U' "+r2(s)+"2 U R' "+d2(s));
        else if(c2 =='K') return(f2(s)+" R F' R' "+f2(s)+"' R F R'");
        else if(c2 =='L') return(u2(s)+"' U' "+r2(s)+"2 U R' U' "+r2(s)+"2 U R "+u2(s));
        else if(c2 =='M') return("U' "+r2(s)+"2 B L' B' "+r2(s)+"2 B L B' U");
        else if(c2 =='N') return("U' "+r2(s)+"2 U' L U "+r2(s)+"2 U' L' U2");
        else if(c2 =='O') return(r2(s)+" D R2 D' "+r2(s)+"' D R2 D'");
        else if(c2 =='P') return("U' "+r2(s)+"2 U R' U' "+r2(s)+"2 U R");
        else if(c2 =='Q') return("U F2 U' "+f2(s)+" U F2 U' "+f2(s)+"'");
        else if(c2 =='R') return("L' U F2 U' "+f2(s)+" U F2 U' "+f2(s)+"' L");
        else if(c2 =='S') return("L2 U F2 U' "+f2(s)+" U F2 U' "+f2(s)+"' L2");
        else if(c2 =='T') return("L U F2 U' "+f2(s)+" U F2 U' "+f2(s)+"' L'");
        else if(c2 =='V') return("U' "+r2(s)+"2 U R2 U' "+r2(s)+"2 U R2");
        else if(c2 =='W') return("B2 R' U R U' "+r2(s)+"2 U R' U' R "+r2(s)+"2 B2");
        else if(c2 =='X') return("U' "+r2(s)+"2 U' L2 U "+r2(s)+"2 U' L2 U2");
        else return("");
    }

    else if(c1 == 'C')
    {
        if(c2 =='A') return("U R' U "+r2(s)+"2 U R U' "+r2(s)+"2 U R' U2 R U'");
        else if(c2 =='B') return("U2 "+r2(s)+"2 L U' L' U "+r2(s)+"2 U' L U L' U2");
        else if(c2 =='D') return("U2 "+r2(s)+"2 R' U R U' "+r2(s)+"2 U R' U' R U2");
        else if(c2 =='E') return(l2(s)+"2 D2 "+l2(s)+" U2 "+l2(s)+"' D2 "+l2(s)+" U2 "+l2(s));
        else if(c2 =='F') return("U2 "+r2(s)+"2 U R U' "+r2(s)+"2 U R' U");
        else if(c2 =='G') return(l2(s)+"2 "+r2(s)+" U2 "+r2(s)+"' D2 "+r2(s)+" U2 "+r2(s)+"' D2 "+l2(s)+"2");
        else if(c2 =='H') return("U2 "+r2(s)+"2 U' L' U "+r2(s)+"2 U' L U'");
        else if(c2 =='I') return("U2 "+r2(s)+"2 B L' B' "+r2(s)+"2 B L B' U2");
        else if(c2 =='J') return("U2 "+r2(s)+"2 R' B' R B "+r2(s)+"2 B' R' B R U2");
        else if(c2 =='K') return("U2 "+r2(s)+"2 B' R' B "+r2(s)+"2 B' R B U2");
        else if(c2 =='L') return("U2 "+r2(s)+"2 B' R2 B "+r2(s)+"2 B' R2 B U2");
        else if(c2 =='M') return(l2(s)+"' D2 "+r2(s)+" U2 "+r2(s)+"' D2 "+r2(s)+" U2 "+r2(s)+"' "+l2(s));
        else if(c2 =='N') return("U2 "+r2(s)+"2 U' L U "+r2(s)+"2 U' L' U U2");
        else if(c2 =='O') return("F2 "+l2(s)+"' B2 "+l2(s)+" F2 "+l2(s)+"' B2 "+l2(s));
        else if(c2 =='P') return("U2 "+r2(s)+"2 U R' U' "+r2(s)+"2 U R U");
        else if(c2 =='Q') return("U2 "+r2(s)+"2 B' R B "+r2(s)+"2 B' R' B U2");
        else if(c2 =='R') return("U2 "+r2(s)+"2 B L2 B' "+r2(s)+"2 B L2 B' U2");
        else if(c2 =='S') return("U2 "+r2(s)+"2 B L B' "+r2(s)+"2 B L' B' U2");
        else if(c2 =='T') return("U2 "+r2(s)+"2 L B L' B' "+r2(s)+"2 B L B' L' U2");
        else if(c2 =='V') return("U2 "+r2(s)+"2 U R2 U' "+r2(s)+"2 U R2 U");
        else if(c2 =='W') return(l2(s)+"' U "+l2(s)+" D2 "+r2(s)+" U "+r2(s)+"' D2 "+r2(s)+" U' "+r2(s)+"' "+l2(s)+"' U' "+l2(s));
        else if(c2 =='X') return("U2 " +r2(s)+"2 U' L2 U "+r2(s)+"2 U' L2 U'");
        else return("");
    }

    else if(c1 == 'D')
    {
        if(c2 =='A') return("L U' L' U "+r2(s)+"2 U' L U L' "+r2(s)+"2");
        else if(c2 =='B') return("R' U "+r2(s)+"2 U R U' "+r2(s)+"2 U R' U2 R");
        else if(c2 =='C') return("U2 R' U R U' "+r2(s)+"2 U R' U' R "+r2(s)+"2 U2");
        else if(c2 =='E') return(r2(s)+" L U' L' U "+r2(s)+" U' L U L' "+r2(s)+"2");
        else if(c2 =='F') return("U "+r2(s)+"2 U R U' "+r2(s)+"2 U R' U2");
        else if(c2 =='G') return(l2(s)+"2 U "+r2(s)+"2 B' R B "+r2(s)+"2 B' R' B U' "+l2(s)+"2");
        else if(c2 =='H') return("U "+r2(s)+"2 U' L' U "+r2(s)+"2 U' L");
        else if(c2 =='I') return("U' F2 U "+b2(s)+" U' F2 U "+b2(s)+"'");
        else if(c2 =='J') return("R' U' F2 U "+b2(s)+" U' F2 U "+b2(s)+"' R");
        else if(c2 =='K') return("R2 U' F2 U "+b2(s)+" U' F2 U "+b2(s)+"' R2");
        else if(c2 =='L') return("R U' F2 U "+b2(s)+" U' F2 U "+b2(s)+"' R'");
        else if(c2 =='M') return("U "+r2(s)+"2 B' R B "+r2(s)+"2 B' R' B U'");
        else if(c2 =='N') return("U "+r2(s)+"2 U' L U "+r2(s)+"2 U' L'");
        else if(c2 =='O') return(r2(s)+" D' L2 D "+r2(s)+"' D' L2 D");
        else if(c2 =='P') return("U "+r2(s)+"2 U R' U' "+r2(s)+"2 U R U2");
        else if(c2 =='Q') return("U' "+l2(s)+"2 D2 "+l2(s)+" U2 "+l2(s)+"' D2 "+l2(s)+" U2 "+l2(s)+" U");
        else if(c2 =='R') return(d2(s)+"' U "+r2(s)+"2 U' L U "+r2(s)+"2 U' L' "+d2(s));
        else if(c2 =='S') return(b2(s)+" L' F L "+b2(s)+"' L' F' L");
        else if(c2 =='T') return(u2(s)+"' U "+r2(s)+"2 U' L' U "+r2(s)+"2 U' L "+u2(s));
        else if(c2 =='V') return("U "+r2(s)+"2 U R2 U' "+r2(s)+"2 U R2 U2");
        else if(c2 =='W') return("B2 L U' L' U "+r2(s)+"2 U' L U L' "+r2(s)+"2 B2");
        else if(c2 =='X') return("U "+r2(s)+"2 U' L2 U "+r2(s)+"2 U' L2");
        else return("");
    }

    else if(c1 == 'E')
    {
        if(c2 =='A') return("D "+r2(s)+" U R2 U' "+r2(s)+"' U R2 U' D'");
        else if(c2 =='B') return(r2(s)+" F R' F' "+r2(s)+"' F R F'");
        else if(c2 =='C') return(l2(s)+"' U2 "+l2(s)+"' D2 "+l2(s)+" U2 "+l2(s)+"' D2 "+l2(s)+"2");
        else if(c2 =='D') return(r2(s)+" F' L F "+r2(s)+"' F' L' F");
        else if(c2 =='E') return("");
        else if(c2 =='F') return(r2(s)+"2 U R U' "+r2(s)+"' U R' U' "+r2(s)+"'");
        else if(c2 =='G') return(l2(s)+"2 U2 "+l2(s)+"' D2 "+l2(s)+" U2 "+l2(s)+"' D2 "+l2(s)+"'");
        else if(c2 =='H') return(r2(s)+"2 U' L' U "+r2(s)+"' U' L U "+r2(s)+"'");
        else if(c2 =='I') return("U' "+b2(s)+"' D "+b2(s)+" U "+b2(s)+"' D' "+b2(s));
        else if(c2 =='J') return(r2(s)+" U' R' U "+r2(s)+"' U' R U");
        else if(c2 =='K') return(r2(s)+" U' R2 U "+r2(s)+"' U' R2 U");
        else if(c2 =='L') return(r2(s)+" U' R U "+r2(s)+"' U' R' U");
        else if(c2 =='M') return("U2 "+l2(s)+"' D2 "+l2(s)+" U2 "+l2(s)+"' D2 "+l2(s));
        else if(c2 =='N') return(r2(s)+"2 U' L U "+r2(s)+"' U' L' U "+r2(s)+"'");
        else if(c2 =='O') return("U' D' R2 D "+r2(s)+"' D' R2 D "+r2(s)+" U");
        else if(c2 =='P') return(r2(s)+"2 U R' U' "+r2(s)+"' U R U' "+r2(s)+"'");
        else if(c2 =='Q') return("U "+f2(s)+"' D' "+f2(s)+" U' "+f2(s)+"' D "+f2(s));
        else if(c2 =='R') return(r2(s)+" U L' U' "+r2(s)+"' U L U'");
        else if(c2 =='S') return(r2(s)+" U L2 U' "+r2(s)+"' U L2 U'");
        else if(c2 =='T') return(r2(s)+" U L U' "+r2(s)+"' U L' U'");
        else if(c2 =='V') return(r2(s)+"2 U R2 U' "+r2(s)+"' U R2 U' "+r2(s)+"'");
        else if(c2 =='W') return(l2(s)+" U2 "+l2(s)+"' D2 "+l2(s)+" U2 "+l2(s)+"' D2 ");
        else if(c2 =='X') return(r2(s)+"2 U' L2 U "+r2(s)+"' U' L2 U "+r2(s)+"'");
        else return("");
    }

    else if(c1 == 'F')
    {
        if(c2 =='A') return("U R U' "+r2(s)+"2 U R' U' "+r2(s)+"2");
        else if(c2 =='B') return("R U' "+r2(s)+"2 U R' U' "+r2(s)+"2 U");
        else if(c2 =='C') return("U' R U' "+r2(s)+"2 U R' U' "+r2(s)+"2 U2");
        else if(c2 =='D') return("U2 R U' "+r2(s)+"2 U R' U' "+r2(s)+"2"+" U'");
        else if(c2 =='E') return(r2(s)+" U R U' "+r2(s)+" U R' U' "+r2(s)+"2");
        else if(c2 =='G') return(l2(s)+"' U' R U' "+r2(s)+"2 U R' U' "+r2(s)+"2 U2 "+l2(s));
        else if(c2 =='H') return("L2 "+d2(s)+"2 L' D' L "+d2(s)+"2 L' D L'");
        else if(c2 =='I') return("U "+r2(s)+" U R U' "+r2(s)+" U R' U' "+r2(s)+"2 U'");
        else if(c2 =='J') return("R' D R "+d2(s)+"' R' D' R "+d2(s));
        else if(c2 =='K') return(d2(s)+" R' U "+r2(s)+" U' R' U "+r2(s)+"' U' R2 "+d2(s)+"'");
        else if(c2 =='L') return(u2(s)+"' R U' "+r2(s)+"2 U R2 U' "+r2(s)+"2 U R "+u2(s));
        else if(c2 =='M') return("U2 "+r2(s)+" U R U' "+r2(s)+" U R' U' "+r2(s)+"2 U2");
        else if(c2 =='N') return(d2(s)+"2 L' D' L "+d2(s)+"2 L' D L");
        else if(c2 =='O') return(r2(s)+"' U R U' "+r2(s)+"' U R' U' "+r2(s)+"2");
        else if(c2 =='P') return("R U' "+r2(s)+"2 U R2 U' "+r2(s)+"2 U R");
        else if(c2 =='Q') return("L R' D R "+d2(s)+" R' D' R "+d2(s)+"' L'");
        else if(c2 =='R') return("R' D R "+d2(s)+" R' D' R "+d2(s)+"'");
        else if(c2 =='S') return("L' R' D R "+d2(s)+" R' D' R "+d2(s)+"' L");
        else if(c2 =='T') return("L2 R' D R "+d2(s)+" R' D' R "+d2(s)+"' L2");
        else if(c2 =='V') return("R U' "+r2(s)+"2 U R U' "+r2(s)+"2 U R2");
        else if(c2 =='W') return("B2 U R U' "+r2(s)+"2 U R' U' "+r2(s)+"2 B2");
        else if(c2 =='X') return("L "+d2(s)+"2 L' D' L "+d2(s)+"2 L' D");
        else return("");
    }

    else if(c1 == 'G')
    {
        if(c2 =='A') return("U "+r2(s)+"2 U' "+r2(s)+" D2 "+r2(s)+"' U "+r2(s)+" D2 "+r2(s)+" U'");
        else if(c2 =='B') return(r2(s)+"2 U' "+r2(s)+" D2 "+r2(s)+"' U "+r2(s)+" D2 "+r2(s));
        else if(c2 =='C') return(l2(s)+"2 D2 "+r2(s)+" U2 "+r2(s)+"' D2 "+r2(s)+" U2 "+r2(s)+"' "+l2(s)+"2");
        else if(c2 =='D') return(l2(s)+"2 L2 D "+r2(s)+" U2 "+r2(s)+"' D' "+r2(s)+" U2 "+r2(s)+"' L2 "+l2(s)+"2");
        else if(c2 =='E') return(l2(s)+" D2 "+l2(s)+" U2 "+l2(s)+"' D2 "+l2(s)+" U2 "+l2(s)+"2");
        else if(c2 =='F') return(l2(s)+"' U2 "+r2(s)+"2 U R U' "+r2(s)+"2 U R' U "+l2(s));
        else if(c2 =='H') return(l2(s)+"' U2 "+r2(s)+"2 U' L' U "+r2(s)+"2 U' L U' "+l2(s));
        else if(c2 =='I') return(l2(s)+" "+r2(s)+" U "+r2(s)+"' D2 "+r2(s)+" U' "+r2(s)+"' D2 "+l2(s)+"'");
        else if(c2 =='J') return(l2(s)+"' U2 "+r2(s)+"2 R' B' R B "+r2(s)+"2 B' R' B R U2 "+l2(s));
        else if(c2 =='K') return(l2(s)+"' U2 "+r2(s)+"2 B' R' B "+r2(s)+"2 B' R B U2 "+l2(s));
        else if(c2 =='L') return(l2(s)+"' U2 "+r2(s)+"2 B' R2 B "+r2(s)+"2 B' R2 B U2 "+l2(s));
        else if(c2 =='M') return("U2 "+l2(s)+" D2 "+l2(s)+" U2 "+l2(s)+"' D2 "+l2(s)+" U2 "+l2(s)+"2 U2");
        else if(c2 =='N') return(l2(s)+"' U2 " +r2(s)+"2 U' L U "+r2(s)+"2 U' L' U' "+l2(s));
        else if(c2 =='O') return(l2(s)+"' F2 "+l2(s)+"' B2 "+l2(s)+" F2 "+l2(s)+"' B2 "+l2(s)+"2");
        else if(c2 =='P') return(l2(s)+"' U2 "+r2(s)+"2 U R' U' "+r2(s)+"2 U R U "+l2(s));
        else if(c2 =='Q') return(l2(s)+" "+r2(s)+" U' "+r2(s)+"' D2 "+r2(s)+" U "+r2(s)+"' D2 "+l2(s)+"'");
        else if(c2 =='R') return(l2(s)+"' U2 " +r2(s)+"2 B L2 B' "+r2(s)+"2 B L2 B' U2 "+l2(s));
        else if(c2 =='S') return(l2(s)+"' U2 " +r2(s)+"2 B L B' "+r2(s)+"2 B L' B' U2 "+l2(s));
        else if(c2 =='T') return(l2(s)+"' U2 " +r2(s)+"2 L B L' B' "+r2(s)+"2 B L B' L' U2 "+l2(s));
        else if(c2 =='V') return(l2(s)+"2 D' "+r2(s)+" U2 "+r2(s)+"' D "+r2(s)+" U2 "+r2(s)+"' "+l2(s)+"2");
        else if(c2 =='W') return(l2(s)+" "+r2(s)+" U2 "+r2(s)+"' D2 "+r2(s)+" U2 "+r2(s)+"' D2 "+l2(s)+"'");
        else if(c2 =='X') return(l2(s)+"2 D "+r2(s)+" U2 "+r2(s)+"' D' "+r2(s)+" U2 "+r2(s)+"' "+l2(s)+"2");
        else return("");
    }


    else if(c1 == 'H')
    {
        if(c2 =='A') return("U' L' U "+r2(s)+"2 U' L U "+r2(s)+"2");
        else if(c2 =='B') return("U2 L' U "+r2(s)+"2 U' L U "+r2(s)+"2"+" U");
        else if(c2 =='C') return("U L' U "+r2(s)+"2 U' L U "+r2(s)+"2"+" U2");
        else if(c2 =='D') return("L' U "+r2(s)+"2 U' L U "+r2(s)+"2"+" U'");
        else if(c2 =='E') return(r2(s)+" U' L' U "+r2(s)+" U' L U "+r2(s)+"2");
        else if(c2 =='F') return("R2 "+u2(s)+"2 R D R' "+u2(s)+"2 R D' R");
        else if(c2 =='G') return(l2(s)+"' U L' U "+r2(s)+"2 U' L U "+r2(s)+"2 U2 "+l2(s));
        else if(c2 =='I') return("R' L D' L' "+u2(s)+" L D L' "+u2(s)+"' R");
        else if(c2 =='J') return("R2 L D' L' "+u2(s)+" L D L' "+u2(s)+"' R2");
        else if(c2 =='K') return("R L D' L' "+u2(s)+" L D L' "+u2(s)+"' R'");
        else if(c2 =='L') return("L D' L' "+u2(s)+" L D L' "+u2(s)+"'");
        else if(c2 =='M') return("U2 "+r2(s)+" U' L' U "+r2(s)+" U' L U "+r2(s)+"2 U2");
        else if(c2 =='N') return("L' U "+r2(s)+"2 U' L2 U "+r2(s)+"2 U' L'");
        else if(c2 =='O') return(r2(s)+"' U' L' U "+r2(s)+"' U' L U "+r2(s)+"2");
        else if(c2 =='P') return(u2(s)+"2 R D R' "+u2(s)+"2 R D' R'");
        else if(c2 =='Q') return("U' "+r2(s)+" U' L' U "+r2(s)+" U' L U "+r2(s)+"2 U");
        else if(c2 =='R') return(d2(s)+"' L' U "+r2(s)+"2 U' L2 U "+r2(s)+"2 U' L' "+d2(s));
        else if(c2 =='S') return(u2(s)+" L U' "+r2(s)+" U L U' "+r2(s)+"' U L2 "+u2(s)+"'");
        else if(c2 =='T') return("L D' L' "+u2(s)+"' L D L' "+u2(s));
        else if(c2 =='V') return("R' "+u2(s)+"2 R D R' "+u2(s)+"2 R D'");
        else if(c2 =='W') return("B2 U' L' U "+r2(s)+"2 U' L U "+r2(s)+"2 B2");
        else if(c2 =='X') return("L' U "+r2(s)+"2 U' L' U "+r2(s)+"2 U' L2");
        else return("");
    }

    else if(c1 == 'I')
    {
        if(c2 =='A') return("B' R B "+r2(s)+"2 B' R' B "+r2(s)+"2");
        else if(c2 =='B') return(f2(s)+"' U2 "+f2(s)+"' D' "+f2(s)+" U2 "+f2(s)+"' D "+f2(s)+"2");
        else if(c2 =='C') return(l2(s)+"' "+b2(s)+"' D "+b2(s)+" U "+b2(s)+"' D' "+b2(s)+" U' "+l2(s));
        else if(c2 =='D') return(b2(s)+" U' F2 U "+b2(s)+"' U' F2 U");
        else if(c2 =='E') return(b2(s)+"' D "+b2(s)+" U' "+b2(s)+"' D' "+b2(s)+" U");
        else if(c2 =='F') return("U "+r2(s)+"2 U R U' "+r2(s)+"' U R' U' "+r2(s)+"' U'");
        else if(c2 =='G') return(l2(s)+" D2 "+r2(s)+" U "+r2(s)+"' D2 "+r2(s)+" U' "+r2(s)+"' "+l2(s)+"'");
        else if(c2 =='H') return("U "+r2(s)+"2 U' L' U "+r2(s)+"' U' L U "+r2(s)+"' U'");
        else if(c2 =='J') return("U "+r2(s)+" U' R' U "+r2(s)+"' U' R");
        else if(c2 =='K') return("U "+r2(s)+" U' R2 U "+r2(s)+"' U' R2");
        else if(c2 =='L') return("U "+r2(s)+" U' R U "+r2(s)+"' U' R'");
        else if(c2 =='M') return(b2(s)+"' D "+b2(s)+" U "+b2(s)+"' D' "+b2(s)+" U'");
        else if(c2 =='N') return("U "+r2(s)+"2 U' L U "+r2(s)+"' U' L' U "+r2(s)+"' U'");
        else if(c2 =='O') return("D' R2 D "+r2(s)+"' D' R2 D "+r2(s));
        else if(c2 =='P') return("U "+r2(s)+"2 U R' U' "+r2(s)+"' U R U' "+r2(s)+"' U'");
        else if(c2 =='Q') return("U2 "+f2(s)+"' D' "+f2(s)+" U2 "+f2(s)+"' D "+f2(s));
        else if(c2 =='R') return("L' U2 "+f2(s)+"' D' "+f2(s)+" U2 "+f2(s)+"' D "+f2(s)+" L");
        else if(c2 =='S') return("L2 U2 "+f2(s)+"' D' "+f2(s)+" U2 "+f2(s)+"' D "+f2(s)+" L2");
        else if(c2 =='T') return("L U2 "+f2(s)+"' D' "+f2(s)+" U2 "+f2(s)+"' D "+f2(s)+" L'");
        else if(c2 =='V') return("D' "+r2(s)+" U "+r2(s)+"' D "+r2(s)+" U' "+r2(s)+"'");
        else if(c2 =='W') return("D2 "+r2(s)+" U "+r2(s)+"' D2 "+r2(s)+" U' "+r2(s)+"'");
        else if(c2 =='X') return("D "+r2(s)+" U "+r2(s)+"' D' "+r2(s)+" U' "+r2(s)+"'");
        else return("");
    }

    else if(c1 == 'J')
    {
        if(c2 =='A') return("R' B' R B "+r2(s)+"2 B' R' B R "+r2(s)+"2");
        else if(c2 =='B') return("U' R' B' R B "+r2(s)+"2 B' R' B R "+r2(s)+"2 U");
        else if(c2 =='C') return("U2 R' B' R B "+r2(s)+"2 B' R' B R "+r2(s)+"2 U2");
        else if(c2 =='D') return("U R' B' R B "+r2(s)+"2 B' R' B R "+r2(s)+"2 U'");
        else if(c2 =='E') return("U' R' U "+r2(s)+" U' R U "+r2(s)+"'");
        else if(c2 =='F') return(d2(s)+"' R' D R "+d2(s)+" R' D' R");
        else if(c2 =='G') return(l2(s)+"2 U R' U "+r2(s)+" U' R U "+r2(s)+"' U2 "+l2(s)+"2");
        else if(c2 =='H') return("B "+r2(s)+"2 U' L' U "+r2(s)+"2 U' L U B'");
        else if(c2 =='I') return("R' U "+r2(s)+" U' R U "+r2(s)+"' U'");
        else if(c2 =='K') return("R' U "+r2(s)+" U' R' U "+r2(s)+"' U' R2");
        else if(c2 =='L') return("R' U "+r2(s)+" U' R2 U "+r2(s)+"' U' R'");
        else if(c2 =='M') return("U R' U "+r2(s)+" U' R U "+r2(s)+"' U2");
        else if(c2 =='N') return(d2(s)+" L' D' L "+d2(s)+"' L' D L");
        else if(c2 =='O') return("D' R D "+r2(s)+"' D' R' D "+r2(s));
        else if(c2 =='P') return(u2(s)+" R' U "+r2(s)+" U' R2 U "+r2(s)+"' U' R' "+u2(s)+"'");
        else if(c2 =='Q') return("R' U2 "+f2(s)+"' D' "+f2(s)+" U2 "+f2(s)+"' D "+f2(s)+" R");
        else if(c2 =='R') return("B' D2 B "+d2(s)+"2 B' D2 B "+d2(s)+"2");
        else if(c2 =='S') return("L' B' D2 B "+d2(s)+"2 B' D2 B "+d2(s)+"2 L");
        else if(c2 =='T') return("L2 B' D2 B "+d2(s)+"2 B' D2 B "+d2(s)+"2 L2");
        else if(c2 =='V') return("B "+r2(s)+"2 U R2 U' "+r2(s)+"2 U R2 U' B'");
        else if(c2 =='W') return("R' D2 "+r2(s)+" U "+r2(s)+"' D2 "+r2(s)+" U' "+r2(s)+"' R");
        else if(c2 =='X') return("R' D "+r2(s)+" U "+r2(s)+"' D' "+r2(s)+" U' "+r2(s)+"' R");
        else return("");
    }

    else if(c1 == 'K')
    {
        if(c2 =='A') return("B' R' B "+r2(s)+"2 B' R B "+r2(s)+"2");
        else if(c2 =='B') return("U' B' R' B "+r2(s)+"2 B' R B "+r2(s)+"2 U");
        else if(c2 =='C') return("U2 B' R' B "+r2(s)+"2 B' R B "+r2(s)+"2 U2");
        else if(c2 =='D') return("U B' R' B "+r2(s)+"2 B' R B "+r2(s)+"2 U'");
        else if(c2 =='E') return("U' R2 U "+r2(s)+" U' R2 U "+r2(s)+"'");
        else if(c2 =='F') return(d2(s)+" R2 U "+r2(s)+" U' R U "+r2(s)+"' U' R "+d2(s)+"'");
        else if(c2 =='G') return(l2(s)+"2 U R2 U "+r2(s)+" U' R2 U "+r2(s)+"' U2 "+l2(s)+"2");
        else if(c2 =='H') return("R "+u2(s)+" L D' L' "+u2(s)+"' L D L' R'");
        else if(c2 =='I') return("R2 U "+r2(s)+" U' R2 U "+r2(s)+"' U'");
        else if(c2 =='J') return("R2 U "+r2(s)+" U' R U "+r2(s)+"' U' R");
        else if(c2 =='L') return("R2 U "+r2(s)+" U' R' U "+r2(s)+"' U' R'");
        else if(c2 =='M') return("U R2 U "+r2(s)+" U' R2 U "+r2(s)+"' U2");
        else if(c2 =='N') return("B "+r2(s)+" F' R F "+r2(s)+"' F' R' F B'");
        else if(c2 =='O') return(r2(s)+" F' R F "+r2(s)+"' F' R' F");
        else if(c2 =='P') return("B' "+r2(s)+" F' R F "+r2(s)+"' F' R' F B");
        else if(c2 =='Q') return("U2 R2 U "+r2(s)+" U' R2 U "+r2(s)+"' U");
        else if(c2 =='R') return("L' U2 R2 U "+r2(s)+" U' R2 U "+r2(s)+"' U L");
        else if(c2 =='S') return("L2 U2 R2 U "+r2(s)+" U' R2 U "+r2(s)+"' U L2");
        else if(c2 =='T') return("L U2 R2 U "+r2(s)+" U' R2 U "+r2(s)+"' U L'");
        else if(c2 =='V') return(f2(s)+"' U' "+r2(s)+"2 U R2 U' "+r2(s)+"2 U R2 "+f2(s));
        else if(c2 =='W') return("R2 D2 "+r2(s)+" U "+r2(s)+"' D2 "+r2(s)+" U' "+r2(s)+"' R2");
        else if(c2 =='X') return("R2 D "+r2(s)+" U "+r2(s)+"' D' "+r2(s)+" U' "+r2(s)+"' R2");
        else return("");
    }

    else if(c1 == 'L')
    {
        if(c2 =='A') return("B' R2 B "+r2(s)+"2 B' R2 B "+r2(s)+"2");
        else if(c2 =='B') return("U' B' R2 B "+r2(s)+"2 B' R2 B "+r2(s)+"2 U");
        else if(c2 =='C') return("U2 B' R2 B "+r2(s)+"2 B' R2 B "+r2(s)+"2 U2");
        else if(c2 =='D') return("U B' R2 B "+r2(s)+"2 B' R2 B "+r2(s)+"2 U'");
        else if(c2 =='E') return("U' R U "+r2(s)+" U' R' U "+r2(s)+"'");
        else if(c2 =='F') return(d2(s)+" R U "+r2(s)+" U' R2 U "+r2(s)+"' U' R "+d2(s)+"'");
        else if(c2 =='G') return(l2(s)+"2 U R U "+r2(s)+" U' R' U "+r2(s)+"' U2 "+l2(s)+"2");
        else if(c2 =='H') return(u2(s)+" L D' L' "+u2(s)+"' L D L'");
        else if(c2 =='I') return("R U "+r2(s)+" U' R' U "+r2(s)+"' U'");
        else if(c2 =='J') return("R U "+r2(s)+" U' R2 U "+r2(s)+"' U' R");
        else if(c2 =='K') return("R U "+r2(s)+" U' R U "+r2(s)+"' U' R2");
        else if(c2 =='M') return("U R U "+r2(s)+" U' R' U "+r2(s)+"' U2");
        else if(c2 =='N') return("L2 "+u2(s)+" L D' L' "+u2(s)+"' L D L");
        else if(c2 =='O') return("D' R' D "+r2(s)+"' D' R D "+r2(s));
        else if(c2 =='P') return(r2(s)+"' B' "+r2(s)+" F "+r2(s)+"' B "+r2(s)+" F'");
        else if(c2 =='Q') return("R U2 "+f2(s)+"' D' "+f2(s)+" U2 "+f2(s)+"' D "+f2(s)+" R'");
        else if(c2 =='R') return("L2 "+u2(s)+"2 B D2 B' "+u2(s)+"2 B D2 B' L2");
        else if(c2 =='S') return("L "+u2(s)+"2 B D2 B' "+u2(s)+"2 B D2 B' L'");
        else if(c2 =='T') return(u2(s)+"2 B D2 B' "+u2(s)+"2 B D2 B'");
        else if(c2 =='V') return(b2(s)+" R U "+r2(s)+" U' R' U "+r2(s)+"' U' "+b2(s)+"'");
        else if(c2 =='W') return("R D2 "+r2(s)+" U "+r2(s)+"' D2 "+r2(s)+" U' "+r2(s)+"' R'");
        else if(c2 =='X') return("R D "+r2(s)+" U "+r2(s)+"' D' "+r2(s)+" U' "+r2(s)+"' R'");
        else return("");
    }

    else if(c1 == 'M')
    {
        if(c2 =='A') return("U2 "+l2(s)+"' U2 "+l2(s)+"' D2 "+l2(s)+" U2 "+l2(s)+"' D2 "+l2(s)+"2 U2");
        else if(c2 =='B') return("U' B L' B' "+r2(s)+"2 B L B' "+r2(s)+"2 U");
        else if(c2 =='C') return(l2(s)+"' "+r2(s)+" U2 "+r2(s)+"' D2 "+r2(s)+" U2 "+r2(s)+"' D2 "+l2(s));
        else if(c2 =='D') return("U B' R B "+r2(s)+"2 B' R' B "+r2(s)+"2 U'");
        else if(c2 =='E') return(l2(s)+"' D2 "+l2(s)+" U2 "+l2(s)+"' D2 "+l2(s)+" U2");
        else if(c2 =='F') return("U2 "+r2(s)+"2 U R U' "+r2(s)+"' U R' U' "+r2(s)+"' U2");
        else if(c2 =='G') return("U2 "+l2(s)+"2 U2 "+l2(s)+"' D2 "+l2(s)+" U2 "+l2(s)+"' D2 "+l2(s)+"' U2");
        else if(c2 =='H') return("U2 "+r2(s)+"2 U' L' U "+r2(s)+"' U' L U "+r2(s)+"' U2");
        else if(c2 =='I') return("U "+b2(s)+"' D "+b2(s)+" U' "+b2(s)+"' D' "+b2(s));
        else if(c2 =='J') return("U2 "+r2(s)+" U' R' U "+r2(s)+"' U' R U'");
        else if(c2 =='K') return("U2 "+r2(s)+" U' R2 U "+r2(s)+"' U' R2 U'");
        else if(c2 =='L') return("U2 "+r2(s)+" U' R U "+r2(s)+"' U' R' U'");
        else if(c2 =='N') return("U2 "+r2(s)+"2 U' L U "+r2(s)+"' U' L' U "+r2(s)+"' U2");
        else if(c2 =='O') return("U D' R2 D "+r2(s)+"' D' R2 D "+r2(s)+" U'");
        else if(c2 =='P') return("U2 "+r2(s)+"2 U R' U' "+r2(s)+"' U R U' "+r2(s)+"' U2");
        else if(c2 =='Q') return("U' "+f2(s)+"' D' "+f2(s)+" U "+f2(s)+"' D "+f2(s));
        else if(c2 =='R') return("U2 "+r2(s)+" U L' U' "+r2(s)+"' U L U");
        else if(c2 =='S') return("U2 "+r2(s)+" U L2 U' "+r2(s)+"' U L2 U");
        else if(c2 =='T') return("U2 "+r2(s)+" U L U' "+r2(s)+"' U L' U");
        else if(c2 =='V') return("D' "+r2(s)+" U2 "+r2(s)+"' D "+r2(s)+" U2 "+r2(s)+"'");
        else if(c2 =='W') return("D2 "+r2(s)+" U2 "+r2(s)+"' D2 "+r2(s)+" U2 "+r2(s)+"'");
        else if(c2 =='X') return("D "+r2(s)+" U2 "+r2(s)+"' D' "+r2(s)+" U2 "+r2(s)+"'");
        else return("");
    }

    else if(c1 == 'N')
    {
        if(c2 =='A') return("U' L U "+r2(s)+"2 U' L' U "+r2(s)+"2");
        else if(c2 =='B') return("U2 L U "+r2(s)+"2 U' L' U "+r2(s)+"2 U");
        else if(c2 =='C') return("U L U "+r2(s)+"2 U' L' U "+r2(s)+"2 U2");
        else if(c2 =='D') return("L U "+r2(s)+"2 U' L' U "+r2(s)+"2 U'");
        else if(c2 =='E') return(r2(s)+" U' L U "+r2(s)+" U' L' U "+r2(s)+"2");
        else if(c2 =='F') return("L' D' L "+d2(s)+"2 L' D L "+d2(s)+"2");
        else if(c2 =='G') return(l2(s)+"' U L U "+r2(s)+"2 U' L' U "+r2(s)+"2 U2 "+l2(s));
        else if(c2 =='H') return("L U "+r2(s)+"2 U' L2 U "+r2(s)+"2 U' L");
        else if(c2 =='I') return("R L' D' L "+d2(s)+" L' D L "+d2(s)+"' R'");
        else if(c2 =='J') return("L' D' L "+d2(s)+" L' D L "+d2(s)+"'");
        else if(c2 =='K') return("R' L' D' L "+d2(s)+" L' D L "+d2(s)+"' R");
        else if(c2 =='L') return("R2 L' D' L "+d2(s)+" L' D L "+d2(s)+"' R2");
        else if(c2 =='M') return("U2 "+r2(s)+" U' L U "+r2(s)+" U' L' U "+r2(s)+"2 U2");
        else if(c2 =='O') return(r2(s)+"' U' L U "+r2(s)+"' U' L' U "+r2(s)+"2");
        else if(c2 =='P') return(d2(s)+" F "+d2(s)+"' B2 "+d2(s)+" F' "+d2(s)+"' B2");
        else if(c2 =='Q') return("U' "+r2(s)+" U' L U "+r2(s)+" U' L' U "+r2(s)+"2 U");
        else if(c2 =='R') return("F' "+r2(s)+"' B "+r2(s)+" F "+r2(s)+"' B' "+r2(s));
        else if(c2 =='S') return("B F L' F' "+r2(s)+" F L F' "+r2(s)+"' B'");
        else if(c2 =='T') return(u2(s)+"' L U "+r2(s)+"2 U' L2 U "+r2(s)+"2 U' L "+u2(s));
        else if(c2 =='V') return("R L' D' L "+d2(s)+"2 L' D L "+d2(s)+"2 R'");
        else if(c2 =='W') return("B2 U R' U' "+r2(s)+"2 U R U' "+r2(s)+"2 B2");
        else if(c2 =='X') return("L U "+r2(s)+"2 U' L U "+r2(s)+"2 U' L2");
        else return("");
    }

    else if(c1 == 'O')
    {
        if(c2 =='A') return("U D R2 D' "+r2(s)+" D R2 D' "+r2(s)+"' U'");
        else if(c2 =='B') return("D R2 D' "+r2(s)+" D R2 D' "+r2(s)+"'");
        else if(c2 =='C') return(l2(s)+"' B2 "+l2(s)+" F2 "+l2(s)+"' B2 "+l2(s)+" F2");
        else if(c2 =='D') return("D' L2 D "+r2(s)+" D' L2 D "+r2(s)+"'");
        else if(c2 =='E') return("U' "+r2(s)+"' D' R2 D "+r2(s)+" D' R2 D U");
        else if(c2 =='F') return(r2(s)+"2 U R U' "+r2(s)+" U R' U' "+r2(s));
        else if(c2 =='G') return(l2(s)+"2 B2 "+l2(s)+" F2 "+l2(s)+"' B2 "+l2(s)+" F2 "+l2(s));
        else if(c2 =='H') return(r2(s)+"2 U' L' U "+r2(s)+" U' L U "+r2(s));
        else if(c2 =='I') return(r2(s)+"' D' R2 D "+r2(s)+" D' R2 D");
        else if(c2 =='J') return(r2(s)+"' D' R D "+r2(s)+" D' R' D");
        else if(c2 =='K') return("F' R F "+r2(s)+" F' R' F "+r2(s)+"'");
        else if(c2 =='L') return(r2(s)+"' D' R' D "+r2(s)+" D' R D");
        else if(c2 =='M') return("U "+r2(s)+"' D' R2 D "+r2(s)+" D' R2 D U'");
        else if(c2 =='N') return(r2(s)+"2 U' L U "+r2(s)+" U' L' U "+r2(s));
        else if(c2 =='P') return(r2(s)+"2 U R' U' "+r2(s)+" U R U' "+r2(s));
        else if(c2 =='Q') return(r2(s)+"' D L2 D' "+r2(s)+" D L2 D'");
        else if(c2 =='R') return(r2(s)+"' D L D' "+r2(s)+" D L' D'");
        else if(c2 =='S') return("F L' F' "+r2(s)+" F L F' "+r2(s)+"'");
        else if(c2 =='T') return(r2(s)+"' D L' D' "+r2(s)+" D L D'");
        else if(c2 =='V') return(r2(s)+"2 U R2 U' "+r2(s)+" U R2 U' "+r2(s));
        else if(c2 =='W') return(l2(s)+" B2 "+l2(s)+" F2 "+l2(s)+"' B2 "+l2(s)+" F2 "+l2(s)+"2");
        else if(c2 =='X') return(r2(s)+"2 U' L2 U "+r2(s)+" U' L2 U "+r2(s));
        else return("");
    }

    else if(c1 == 'P')
    {
        if(c2 =='A') return("U R' U' "+r2(s)+"2 U R U' "+r2(s)+"2");
        else if(c2 =='B') return("R' U' "+r2(s)+"2 U R U' "+r2(s)+"2 U");
        else if(c2 =='C') return("U' R' U' "+r2(s)+"2 U R U' "+r2(s)+"2 U2");
        else if(c2 =='D') return("U2 R' U' "+r2(s)+"2 U R U' "+r2(s)+"2 U'");
        else if(c2 =='E') return(r2(s)+" U R' U' "+r2(s)+" U R U' "+r2(s)+"2");
        else if(c2 =='F') return("R' U' "+r2(s)+"2 U R2 U' "+r2(s)+"2 U R'");
        else if(c2 =='G') return(l2(s)+"' U' R' U' "+r2(s)+"2 U R U' "+r2(s)+"2 U2 "+l2(s));
        else if(c2 =='H') return("R D R' "+u2(s)+"2 R D' R' "+u2(s)+"2");
        else if(c2 =='I') return("U "+r2(s)+" U R' U' "+r2(s)+" U R U' "+r2(s)+"2 U'");
        else if(c2 =='J') return(d2(s)+"' R' U' "+r2(s)+"2 U R2 U' "+r2(s)+"2 U R' "+d2(s));
        else if(c2 =='K') return("B' F' R F "+r2(s)+" F' R' F "+r2(s)+"' B");
        else if(c2 =='L') return("F "+r2(s)+"' B' "+r2(s)+" F' "+r2(s)+"' B "+r2(s));
        else if(c2 =='M') return("U2 "+r2(s)+" U R' U' "+r2(s)+" U R U' "+r2(s)+"2 U2");
        else if(c2 =='N') return("B2 "+d2(s)+" F "+d2(s)+"' B2 "+d2(s)+" F' "+d2(s)+"'");
        else if(c2 =='O') return(r2(s)+"' U R' U' "+r2(s)+"' U R U' "+r2(s)+"2");
        else if(c2 =='Q') return("L' R D R' "+u2(s)+" R D' R' "+u2(s)+"' L");
        else if(c2 =='R') return("L2 R D R' "+u2(s)+" R D' R' "+u2(s)+"' L2");
        else if(c2 =='S') return("L R D R' "+u2(s)+" R D' R' "+u2(s)+"' L'");
        else if(c2 =='T') return("R D R' "+u2(s)+" R D' R' "+u2(s)+"'");
        else if(c2 =='V') return("R' U' "+r2(s)+"2 U R' U' "+r2(s)+"2 U R2");
        else if(c2 =='W') return("B2 U' L U "+r2(s)+"2 U' L' U "+r2(s)+"2 B2");
        else if(c2 =='X') return("L' R D R' "+u2(s)+"2 R D' R' "+u2(s)+"2 L");
        else return("");
    }

    else if(c1 == 'Q')
    {
        if(c2 =='A') return("B L' B' "+r2(s)+"2 B L B' "+r2(s)+"2");
        else if(c2 =='B') return(f2(s)+" U F2 U' "+f2(s)+"' U F2 U'");
        else if(c2 =='C') return("U2 B' R B "+r2(s)+"2 B' R' B "+r2(s)+"2 U2");
        else if(c2 =='D') return(b2(s)+"' "+f2(s)+"' D' "+f2(s)+" U2 "+f2(s)+"' D "+f2(s)+" U2 "+b2(s));
        else if(c2 =='E') return(f2(s)+"' D' "+f2(s)+" U "+f2(s)+"' D "+f2(s)+" U'");
        else if(c2 =='F') return("R' D' "+r2(s)+" U' "+r2(s)+"' D "+r2(s)+" U "+r2(s)+"' R");
        else if(c2 =='G') return(l2(s)+" D2 "+r2(s)+" U' "+r2(s)+"' D2 "+r2(s)+" U "+r2(s)+"' "+l2(s)+"'");
        else if(c2 =='H') return("U' "+r2(s)+"2 U' L' U "+r2(s)+"' U' L U "+r2(s)+"' U");
        else if(c2 =='I') return(f2(s)+"' D' "+f2(s)+" U2 "+f2(s)+"' D "+f2(s)+" U2");
        else if(c2 =='J') return("R' "+f2(s)+"' D' "+f2(s)+" U2 "+f2(s)+"' D "+f2(s)+" U2 R");
        else if(c2 =='K') return("R2 "+f2(s)+"' D' "+f2(s)+" U2 "+f2(s)+"' D "+f2(s)+" U2 R2");
        else if(c2 =='L') return("R "+f2(s)+"' D' "+f2(s)+" U2 "+f2(s)+"' D "+f2(s)+" U2 R'");
        else if(c2 =='M') return(f2(s)+"' D' "+f2(s)+" U' "+f2(s)+"' D "+f2(s)+" U");
        else if(c2 =='N') return("B' "+f2(s)+"' D' "+f2(s)+" U' "+f2(s)+"' D "+f2(s)+" U B");
        else if(c2 =='O') return("D L2 D' "+r2(s)+"' D L2 D' "+r2(s));
        else if(c2 =='P') return("R D' "+r2(s)+" U' "+r2(s)+"' D "+r2(s)+" U "+r2(s)+"' R'");
        else if(c2 =='R') return("U' "+r2(s)+" U L' U' "+r2(s)+"' U L");
        else if(c2 =='S') return("U' "+r2(s)+" U L2 U' "+r2(s)+"' U L2");
        else if(c2 =='T') return("U' "+r2(s)+" U L U' "+r2(s)+"' U L'");
        else if(c2 =='V') return("D' "+r2(s)+" U' "+r2(s)+"' D "+r2(s)+" U "+r2(s)+"'");
        else if(c2 =='W') return("D2 "+r2(s)+" U' "+r2(s)+"' D2 "+r2(s)+" U "+r2(s)+"'");
        else if(c2 =='X') return("D "+r2(s)+" U' "+r2(s)+"' D' "+r2(s)+" U "+r2(s)+"'");
        else return("");
    }

    else if(c1 == 'R')
    {   
        if(c2 =='A') return("B L2 B' "+r2(s)+"2 B L2 B' "+r2(s)+"2");
        else if(c2 =='B') return("U' B L2 B' "+r2(s)+"2 B L2 B' "+r2(s)+"2 U");
        else if(c2 =='C') return("U2 B L2 B' "+r2(s)+"2 B L2 B' "+r2(s)+"2 U2");
        else if(c2 =='D') return("U B L2 B' "+r2(s)+"2 B L2 B' "+r2(s)+"2 U'");
        else if(c2 =='E') return("U L' U' "+r2(s)+" U L U' "+r2(s)+"'");
        else if(c2 =='F') return(d2(s)+" R' D R "+d2(s)+"' R' D' R");
        else if(c2 =='G') return(l2(s)+"' U2 B L2 B' "+r2(s)+"2 B L2 B' "+r2(s)+"2 U2 "+l2(s));
        else if(c2 =='H') return(u2(s)+" L' U' "+r2(s)+" U L2 U' "+r2(s)+"' U L' "+u2(s)+"'");
        else if(c2 =='I') return("U2 L' U' "+r2(s)+" U L U' "+r2(s)+"' U'");
        else if(c2 =='J') return(d2(s)+"2 B' D2 B "+d2(s)+"2 B' D2 B");
        else if(c2 =='K') return("R' "+d2(s)+"2 B' D2 B "+d2(s)+"2 B' D2 B R");
        else if(c2 =='L') return("R2 "+d2(s)+"2 B' D2 B "+d2(s)+"2 B' D2 B R2");
        else if(c2 =='M') return("U' L' U' "+r2(s)+" U L U' "+r2(s)+"' U2");
        else if(c2 =='N') return(r2(s)+"' B "+r2(s)+" F' "+r2(s)+"' B' "+r2(s)+" F");
        else if(c2 =='O') return("D L D' "+r2(s)+"' D L' D' "+r2(s));
        else if(c2 =='P') return("R2 "+d2(s)+" R' D R "+d2(s)+"' R' D' R'");
        else if(c2 =='Q') return("L' U' "+r2(s)+" U L U' "+r2(s)+"' U");
        else if(c2 =='S') return("L' U' "+r2(s)+" U L' U' "+r2(s)+"' U L2");
        else if(c2 =='T') return("L' U' "+r2(s)+" U L2 U' "+r2(s)+"' U L'");
        else if(c2 =='V') return("L' D' "+r2(s)+" U' "+r2(s)+"' D "+r2(s)+" U "+r2(s)+"' L");
        else if(c2 =='W') return("L' D2 "+r2(s)+" U' "+r2(s)+"' D2 "+r2(s)+" U "+r2(s)+"' L");
        else if(c2 =='X') return("F2 U' "+f2(s)+"2 U F' U' "+f2(s)+"2 U F'");
        else return("");
    }

    else if(c1 == 'S')
    {
        if(c2 =='A') return("B L B' "+r2(s)+"2 B L' B' "+r2(s)+"2");
        else if(c2 =='B') return("U' B L B' "+r2(s)+"2 B L' B' "+r2(s)+"2 U");
        else if(c2 =='C') return("U2 B L B' "+r2(s)+"2 B L' B' "+r2(s)+"2 U2");
        else if(c2 =='D') return("U B L B' "+r2(s)+"2 B L' B' "+r2(s)+"2 U'");
        else if(c2 =='E') return("U L2 U' "+r2(s)+" U L2 U' "+r2(s)+"'");
        else if(c2 =='F') return("L' "+d2(s)+" R' D R "+d2(s)+"' R' D' R L");
        else if(c2 =='G') return(l2(s)+"' U2 B L B' "+r2(s)+"2 B L' B' "+r2(s)+"2 U2 "+l2(s));
        else if(c2 =='H') return(u2(s)+" L2 U' "+r2(s)+" U L' U' "+r2(s)+"' U L' "+u2(s)+"'");
        else if(c2 =='I') return("U2 L2 U' "+r2(s)+" U L2 U' "+r2(s)+"' U'");
        else if(c2 =='J') return("R' U2 L2 U' "+r2(s)+" U L2 U' "+r2(s)+"' U' R");
        else if(c2 =='K') return(b2(s)+"2 U "+r2(s)+" U' R2 U "+r2(s)+"' U' R2 "+b2(s)+"2");
        else if(c2 =='L') return("R U2 L2 U' "+r2(s)+" U L2 U' "+r2(s)+"' U' R'");
        else if(c2 =='M') return("U' L2 U' "+r2(s)+" U L2 U' "+r2(s)+"' U2");
        else if(c2 =='N') return(b2(s)+"' U "+r2(s)+"2 U' L U "+r2(s)+"2 U' L' "+b2(s));
        else if(c2 =='O') return(r2(s)+" F L' F' "+r2(s)+"' F L F'");
        else if(c2 =='P') return("L' R2 "+d2(s)+" R' D R "+d2(s)+"' R' D' R' L");
        else if(c2 =='Q') return("L2 U' "+r2(s)+" U L2 U' "+r2(s)+"' U");
        else if(c2 =='R') return("L2 U' "+r2(s)+" U L U' "+r2(s)+"' U L");
        else if(c2 =='T') return("L2 U' "+r2(s)+" U L' U' "+r2(s)+"' U L'");
        else if(c2 =='V') return("L2 D' "+r2(s)+" U' "+r2(s)+"' D "+r2(s)+" U "+r2(s)+"' L2");
        else if(c2 =='W') return("L2 D2 "+r2(s)+" U' "+r2(s)+"' D2 "+r2(s)+" U "+r2(s)+"' L2");
        else if(c2 =='X') return(b2(s)+"' U "+r2(s)+"2 U' L2 U "+r2(s)+"2 U' L2 "+b2(s));
        else return("");
    }

    else if(c1 == 'T')
    {
        if(c2 =='A') return("L B L' B' "+r2(s)+"2 B L B' L' "+r2(s)+"2");
        else if(c2 =='B') return("U' L B L' B' "+r2(s)+"2 B L B' L' "+r2(s)+"2 U");
        else if(c2 =='C') return("U2 L B L' B' "+r2(s)+"2 B L B' L' "+r2(s)+"2 U2");
        else if(c2 =='D') return("U L B L' B' "+r2(s)+"2 B L B' L' "+r2(s)+"2 U'");
        else if(c2 =='E') return("U L U' "+r2(s)+" U L' U' "+r2(s)+"'");
        else if(c2 =='F') return("B' "+r2(s)+"2 U R U' "+r2(s)+"2 U R' U' B");
        else if(c2 =='G') return(l2(s)+" L D2 "+r2(s)+" U' "+r2(s)+"' D2 "+r2(s)+" U "+r2(s)+"' L' "+l2(s)+"'");
        else if(c2 =='H') return(u2(s)+"' L D' L' "+u2(s)+" L D L'");
        else if(c2 =='I') return("R' B D2 B' "+u2(s)+"2 B D2 B' "+u2(s)+"2 R");
        else if(c2 =='J') return("R2 B D2 B' "+u2(s)+"2 B D2 B' "+u2(s)+"2 R2");
        else if(c2 =='K') return("R B D2 B' "+u2(s)+"2 B D2 B' "+u2(s)+"2 R'");
        else if(c2 =='L') return("B D2 B' "+u2(s)+"2 B D2 B' "+u2(s)+"2");
        else if(c2 =='M') return("U' L U' "+r2(s)+" U L' U' "+r2(s)+"' U2");
        else if(c2 =='N') return(d2(s)+" L U' "+r2(s)+" U L2 U' "+r2(s)+"' U L "+d2(s)+"'");
        else if(c2 =='O') return("D L' D' "+r2(s)+"' D L D' "+r2(s));
        else if(c2 =='P') return(u2(s)+" R D R' "+u2(s)+"' R D' R'");
        else if(c2 =='R') return("L U' "+r2(s)+" U L2 U' "+r2(s)+"' U L");
        else if(c2 =='S') return("L U' "+r2(s)+" U L U' "+r2(s)+"' U L2");
        else if(c2 =='Q') return("L U' "+r2(s)+" U L' U' "+r2(s)+"' U");
        else if(c2 =='V') return("L D' "+r2(s)+" U' "+r2(s)+"' D "+r2(s)+" U "+r2(s)+"' L'");
        else if(c2 =='W') return("L D2 "+r2(s)+" U' "+r2(s)+"' D2 "+r2(s)+" U "+r2(s)+"' L'");
        else if(c2 =='X') return("B' "+r2(s)+"2 U' L2 U "+r2(s)+"2 U' L2 U B");
        else return("");
    }

    else if(c1 == 'V')
    {
        if(c2 =='A') return("U R2 U' "+r2(s)+"2 U R2 U' "+r2(s)+"2");
        else if(c2 =='B') return("R2 U' "+r2(s)+"2 U R2 U' "+r2(s)+"2 U");
        else if(c2 =='C') return("U' R2 U' "+r2(s)+"2 U R2 U' "+r2(s)+"2 U2");
        else if(c2 =='D') return("U2 R2 U' "+r2(s)+"2 U R2 U' "+r2(s)+"2 U'");
        else if(c2 =='E') return(r2(s)+" U R2 U' "+r2(s)+" U R2 U' "+r2(s)+"2");
        else if(c2 =='F') return("R2 U' "+r2(s)+"2 U R' U' "+r2(s)+"2 U R'");
        else if(c2 =='G') return(l2(s)+"2 "+r2(s)+" U2 "+r2(s)+"' D' "+r2(s)+" U2 "+r2(s)+"' D "+l2(s)+"2");
        else if(c2 =='H') return("D R' "+u2(s)+"2 R D' R' "+u2(s)+"2 R");
        else if(c2 =='I') return(r2(s)+" U "+r2(s)+"' D' "+r2(s)+" U' "+r2(s)+"' D");
        else if(c2 =='J') return("B U R2 U' "+r2(s)+"2 U R2 U' "+r2(s)+"2 B'");
        else if(c2 =='K') return(f2(s)+"' R2 U' "+r2(s)+"2 U R2 U' "+r2(s)+"2 U "+f2(s));
        else if(c2 =='L') return(u2(s)+" D R' "+u2(s)+"2 R D' R' "+u2(s)+"2 R "+u2(s)+"'");
        else if(c2 =='M') return(r2(s)+" U2 "+r2(s)+"' D' "+r2(s)+" U2 "+r2(s)+"' D");
        else if(c2 =='N') return("R "+d2(s)+"2 L' D' L "+d2(s)+"2 L' D L R'");
        else if(c2 =='O') return(r2(s)+"' U R2 U' "+r2(s)+"' U R2 U' "+r2(s)+"2");
        else if(c2 =='P') return("R2 U' "+r2(s)+"2 U R U' "+r2(s)+"2 U R");
        else if(c2 =='Q') return(r2(s)+" U' "+r2(s)+"' D' "+r2(s)+" U "+r2(s)+"' D");
        else if(c2 =='R') return("L' "+r2(s)+" U' "+r2(s)+"' D' "+r2(s)+" U "+r2(s)+"' D L");
        else if(c2 =='S') return("L2 "+r2(s)+" U' "+r2(s)+"' D' "+r2(s)+" U "+r2(s)+"' D L2");
        else if(c2 =='T') return("L "+r2(s)+" U' "+r2(s)+"' D' "+r2(s)+" U "+r2(s)+"' D L'");
        else if(c2 =='W') return("B2 U R2 U' "+r2(s)+"2 U R2 U' "+r2(s)+"2 B2");
        else if(c2 =='X') return("R2 U F2 U' "+f2(s)+"2 U F2 U' "+f2(s)+"2 R2");
        else return("");
    }

    else if(c1 == 'W')   
    {
        if(c2 =='A') return("D' R' D U R' U' "+r2(s)+"2 U R U' "+r2(s)+"2 D' R D");
        else if(c2 =='B') return("B2 "+r2(s)+"2 R' U R U' "+r2(s)+"2 U R' U' R B2");
        else if(c2 =='C') return("U2 D' R' D U R' U' "+r2(s)+"2 U R U' "+r2(s)+"2 D' R D U2");
        else if(c2 =='D') return("B2 "+r2(s)+"2 L U' L' U "+r2(s)+"2 U' L U L' B2");
        else if(c2 =='E') return("U' "+r2(s)+" U "+r2(s)+"' D2 "+r2(s)+" U' "+r2(s)+"' D2 U");
        else if(c2 =='F') return("B2 "+r2(s)+"2 U R U' "+r2(s)+"2 U R' U' B2");
        else if(c2 =='G') return(l2(s)+" D2 "+r2(s)+" U2 "+r2(s)+"' D2 "+r2(s)+" U2 "+r2(s)+"' "+l2(s)+"'");
        else if(c2 =='H') return("B2 "+r2(s)+"2 U' L' U "+r2(s)+"2 U' L U B2");
        else if(c2 =='I') return(r2(s)+" U "+r2(s)+"' D2 "+r2(s)+" U' "+r2(s)+"' D2");
        else if(c2 =='J') return("R' "+r2(s)+" U "+r2(s)+"' D2 "+r2(s)+" U' "+r2(s)+"' D2 R");
        else if(c2 =='K') return("R2 "+r2(s)+" U "+r2(s)+"' D2 "+r2(s)+" U' "+r2(s)+"' D2 R2");
        else if(c2 =='L') return("R "+r2(s)+" U "+r2(s)+"' D2 "+r2(s)+" U' "+r2(s)+"' D2 R'");
        else if(c2 =='M') return(r2(s)+" U2 "+r2(s)+"' D2 "+r2(s)+" U2 "+r2(s)+"' D2");
        else if(c2 =='N') return("B2 "+r2(s)+"2 U R' U' "+r2(s)+"2 U R U' B2");
        else if(c2 =='O') return(l2(s)+"2 F2 "+l2(s)+"' B2 "+l2(s)+" F2 "+l2(s)+"' B2 "+l2(s)+"'");
        else if(c2 =='P') return("B2 "+r2(s)+"2 U' L U "+r2(s)+"2 U' L' U"+" B2");
        else if(c2 =='Q') return(r2(s)+" U' "+r2(s)+"' D2 "+r2(s)+" U "+r2(s)+"' D2");
        else if(c2 =='R') return("L' "+r2(s)+" U' "+r2(s)+"' D2 "+r2(s)+" U "+r2(s)+"' D2"+" L");
        else if(c2 =='S') return("L2 "+r2(s)+" U' "+r2(s)+"' D2 "+r2(s)+" U "+r2(s)+"' D2"+" L2");
        else if(c2 =='T') return("L "+r2(s)+" U' "+r2(s)+"' D2 "+r2(s)+" U "+r2(s)+"' D2"+" L'");
        else if(c2 =='V') return("B2 "+r2(s)+"2 U R2 U' "+r2(s)+"2 U R2 U' B2");
        else if(c2 =='X') return("B2 "+r2(s)+"2 U' L2 U "+r2(s)+"2 U' L2 U B2");
        else return("");
    }

    else if(c1 == 'X')
    {
        if(c2 =='A') return("U' L2 U "+r2(s)+"2 U' L2 U "+r2(s)+"2");
        else if(c2 =='B') return("U2 L2 U "+r2(s)+"2 U' L2 U "+r2(s)+"2 U");
        else if(c2 =='C') return("U L2 U "+r2(s)+"2 U' L2 U "+r2(s)+"2 U2");
        else if(c2 =='D') return("L2 U "+r2(s)+"2 U' L2 U "+r2(s)+"2 U'");
        else if(c2 =='E') return(r2(s)+" U' L2 U "+r2(s)+" U' L2 U "+r2(s)+"2");
        else if(c2 =='F') return("D' L "+d2(s)+"2 L' D L "+d2(s)+"2 L'");
        else if(c2 =='G') return(l2(s)+"2 "+r2(s)+" U2 "+r2(s)+"' D "+r2(s)+" U2 "+r2(s)+"' D' "+l2(s)+"2");
        else if(c2 =='H') return("L2 U "+r2(s)+"2 U' L U "+r2(s)+"2 U' L");
        else if(c2 =='I') return(r2(s)+" U "+r2(s)+"' D "+r2(s)+" U' "+r2(s)+"' D'");
        else if(c2 =='J') return("R' "+r2(s)+" U "+r2(s)+"' D "+r2(s)+" U' "+r2(s)+"' D' R");
        else if(c2 =='K') return("R2 "+r2(s)+" U "+r2(s)+"' D "+r2(s)+" U' "+r2(s)+"' D' R2");
        else if(c2 =='L') return("R "+r2(s)+" U "+r2(s)+"' D "+r2(s)+" U' "+r2(s)+"' D' R'");
        else if(c2 =='M') return(r2(s)+" U2 "+r2(s)+"' D "+r2(s)+" U2 "+r2(s)+"' D'");
        else if(c2 =='N') return("L2 U "+r2(s)+"2 U' L' U "+r2(s)+"2 U' L'");
        else if(c2 =='O') return(r2(s)+"' U' L2 U "+r2(s)+"' U' L2 U "+r2(s)+"2");
        else if(c2 =='P') return("L' "+u2(s)+"2 R D R' "+u2(s)+"2 R D' R' L");
        else if(c2 =='Q') return(r2(s)+" U' "+r2(s)+"' D "+r2(s)+" U "+r2(s)+"' D'");
        else if(c2 =='R') return(f2(s)+" U' "+r2(s)+" U L' U' "+r2(s)+"' U L "+f2(s)+"'");
        else if(c2 =='S') return(b2(s)+"' L2 U "+r2(s)+"2 U' L2 U "+r2(s)+"2 U' "+b2(s));
        else if(c2 =='T') return("B' U' L2 U "+r2(s)+"2 U' L2 U "+r2(s)+"2 B");
        else if(c2 =='V') return("R2 "+f2(s)+"2 U F2 U' "+f2(s)+"2 U F2 U' R2");
        else if(c2 =='W') return("B2 U' L2 U "+r2(s)+"2 U' L2 U "+r2(s)+"2 B2");
        else return("");
    }

    else return("");
}

string return_wing_parity(int size, int i)
{
    string str = "";
    int s = (size-1)/2-i;
    str = str+l2(s)+"' F2 "+l2(s)+"' F2 D2 "+l2(s)+"' D2 "+r2(s)+" F2 "+r2(s)+"' F2 "+l2(s)+"2";
    return str;
}
