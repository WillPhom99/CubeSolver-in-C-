#include "Rubik.h"
#include "Solve.h"
#include "Solution.h"
#include "Algs.h"
#include <string>
#include <iostream>
#include <fstream>
#include <omp.h>

using namespace std;

void solve_cube(Cube& cube)
{
    size_t len = 0;

    int size = cube.size_cube;

    string Corners, Edges, Centers, Wings;

    string Alg;
    int i,j,x,k,m;

    if(size == 2)
    {
        // Coins

        Corners = "";

        Corners = Corners + CornerToLetter(cube.White[0][0],cube.Red[0][0]);
        Corners = Corners + CornerToLetter(cube.White[0][size-1],cube.Green[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][size-1],cube.Orange[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][0],cube.Blue[0][0]);

        Corners = Corners + CornerToLetter(cube.Blue[0][0],cube.Red[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[0][size-1],cube.White[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][size-1],cube.Orange[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][0],cube.Yellow[0][0]);

        Corners = Corners + CornerToLetter(cube.Orange[0][0],cube.Blue[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[0][size-1],cube.White[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][size-1],cube.Green[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][0],cube.Yellow[0][size-1]);

        Corners = Corners + CornerToLetter(cube.Green[0][0],cube.Orange[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Green[0][size-1],cube.White[0][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][size-1],cube.Red[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][0],cube.Yellow[size-1][size-1]);

        Corners = Corners + CornerToLetter(cube.Red[0][0],cube.Green[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Red[0][size-1],cube.White[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][size-1],cube.Blue[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][0],cube.Yellow[size-1][0]);

        Corners = Corners + CornerToLetter(cube.Yellow[0][0],cube.Red[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[0][size-1],cube.Blue[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][size-1],cube.Orange[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][0],cube.Green[size-1][size-1]);

        string CornerSolution = SolveCorner(Corners);

        int len_corners = CornerSolution.size();
        string tmp_corners = CornerSolution; 
        tmp_corners.push_back('A');

        i = 0;
        while(i<len_corners)
        {
            Alg = return_BHC_alg(tmp_corners[i],tmp_corners[i+1]);
            if(Alg.length() > 0 && i+1<len_corners)
            {
                cube.apply_alg(Alg);
                i = i+2;
            }
            else
            {
                Alg = return_single_corner_alg(tmp_corners[i]);
                cube.apply_alg(Alg);
                i++;
            }
        }
    }

    else if(size == 3)
    {
        // Edges
  
        Edges = "";

        int mid = size/2;

        Edges = Edges + EdgeToLetter(cube.White[0][mid],cube.Green[0][mid]);
        Edges = Edges + EdgeToLetter(cube.White[mid][size-1],cube.Orange[0][mid]);
        Edges = Edges + EdgeToLetter(cube.White[size-1][mid],cube.Blue[0][mid]);
        Edges = Edges + EdgeToLetter(cube.White[mid][0],cube.Red[0][mid]);

        Edges = Edges + EdgeToLetter(cube.Blue[0][mid],cube.White[size-1][mid]);
        Edges = Edges + EdgeToLetter(cube.Blue[mid][size-1],cube.Orange[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Blue[size-1][mid],cube.Yellow[0][mid]);
        Edges = Edges + EdgeToLetter(cube.Blue[mid][0],cube.Red[mid][size-1]);

        Edges = Edges + EdgeToLetter(cube.Orange[0][mid],cube.White[mid][size-1]);
        Edges = Edges + EdgeToLetter(cube.Orange[mid][size-1],cube.Green[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Orange[size-1][mid],cube.Yellow[mid][size-1]);
        Edges = Edges + EdgeToLetter(cube.Orange[mid][0],cube.Blue[mid][size-1]);

        Edges = Edges + EdgeToLetter(cube.Green[0][mid],cube.White[0][mid]);
        Edges = Edges + EdgeToLetter(cube.Green[mid][size-1],cube.Red[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Green[size-1][mid],cube.Yellow[size-1][mid]);
        Edges = Edges + EdgeToLetter(cube.Green[mid][0],cube.Orange[mid][size-1]);

        Edges = Edges + EdgeToLetter(cube.Red[0][mid],cube.White[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Red[mid][size-1],cube.Blue[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Red[size-1][mid],cube.Yellow[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Red[mid][0],cube.Green[mid][size-1]);

        Edges = Edges + EdgeToLetter(cube.Yellow[0][mid],cube.Blue[size-1][mid]);
        Edges = Edges + EdgeToLetter(cube.Yellow[mid][size-1],cube.Orange[size-1][mid]);
        Edges = Edges + EdgeToLetter(cube.Yellow[size-1][mid],cube.Green[size-1][mid]);
        Edges = Edges + EdgeToLetter(cube.Yellow[mid][0],cube.Red[size-1][mid]); 


        string EdgeSolution = SolveEdge(Edges);
        int len_edges = EdgeSolution.size();
        string tmp_edges = EdgeSolution;
        tmp_edges.push_back('Z');

        i = 0;

        while(i<len_edges)
        {
            Alg = return_BHE_alg(tmp_edges[i],tmp_edges[i+1]);
            if(Alg.length() > 0 && i+1<len_edges)
            {
                cube.apply_alg(Alg);
                i = i+2;
            }
            else
            {
                Alg = return_single_edge_alg(tmp_edges[i]);
                cube.apply_alg(Alg);
                i++;
            }
        }

        if(EdgeSolution.length()%2 == 1)
        {
            Alg = return_edge_parity();
            cube.apply_alg(Alg);
        }

        // Coins

        Corners = "";

        Corners = Corners + CornerToLetter(cube.White[0][0],cube.Red[0][0]);
        Corners = Corners + CornerToLetter(cube.White[0][size-1],cube.Green[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][size-1],cube.Orange[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][0],cube.Blue[0][0]);

        Corners = Corners + CornerToLetter(cube.Blue[0][0],cube.Red[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[0][size-1],cube.White[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][size-1],cube.Orange[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][0],cube.Yellow[0][0]);

        Corners = Corners + CornerToLetter(cube.Orange[0][0],cube.Blue[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[0][size-1],cube.White[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][size-1],cube.Green[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][0],cube.Yellow[0][size-1]);

        Corners = Corners + CornerToLetter(cube.Green[0][0],cube.Orange[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Green[0][size-1],cube.White[0][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][size-1],cube.Red[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][0],cube.Yellow[size-1][size-1]);

        Corners = Corners + CornerToLetter(cube.Red[0][0],cube.Green[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Red[0][size-1],cube.White[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][size-1],cube.Blue[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][0],cube.Yellow[size-1][0]);

        Corners = Corners + CornerToLetter(cube.Yellow[0][0],cube.Red[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[0][size-1],cube.Blue[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][size-1],cube.Orange[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][0],cube.Green[size-1][size-1]);

        string CornerSolution = SolveCorner(Corners);

        int len_corners = CornerSolution.size();
        string tmp_corners = CornerSolution; 
        tmp_corners.push_back('A');

        i = 0;
        while(i<len_corners)
        {
            Alg = return_BHC_alg(tmp_corners[i],tmp_corners[i+1]);
            if(Alg.length() > 0 && i+1<len_corners)
            {
                cube.apply_alg(Alg);
                i = i+2;
            }
            else
            {
                Alg = return_single_corner_alg(tmp_corners[i]);
                cube.apply_alg(Alg);
                i++;
            }
        }
    }

    else 
    {
        int s = size-2;

        double charg = 0;
        
        k = 0;
        x = s;

        for(int j=0;j<s/2;j=j+1)
        {
            for(int i=0;i<x-1;i=i+1)
            {
                Centers = "";

                Centers = Centers + cube.White[j+1][i+j+1];
                Centers = Centers + cube.White[i+j+1][s-j];
                Centers = Centers + cube.White[s-j][s-i-j];
                Centers = Centers + cube.White[s-i-j][j+1];

                Centers = Centers + cube.Blue[j+1][i+j+1];
                Centers = Centers + cube.Blue[i+j+1][s-j];
                Centers = Centers + cube.Blue[s-j][s-i-j];
                Centers = Centers + cube.Blue[s-i-j][j+1];

                Centers = Centers + cube.Orange[j+1][i+j+1];
                Centers = Centers + cube.Orange[i+j+1][s-j];
                Centers = Centers + cube.Orange[s-j][s-i-j];
                Centers = Centers + cube.Orange[s-i-j][j+1];

                Centers = Centers + cube.Green[j+1][i+j+1];
                Centers = Centers + cube.Green[i+j+1][s-j];
                Centers = Centers + cube.Green[s-j][s-i-j];
                Centers = Centers + cube.Green[s-i-j][j+1];

                Centers = Centers + cube.Red[j+1][i+j+1];
                Centers = Centers + cube.Red[i+j+1][s-j];
                Centers = Centers + cube.Red[s-j][s-i-j];
                Centers = Centers + cube.Red[s-i-j][j+1];

                Centers = Centers + cube.Yellow[j+1][i+j+1];
                Centers = Centers + cube.Yellow[i+j+1][s-j];
                Centers = Centers + cube.Yellow[s-j][s-i-j];
                Centers = Centers + cube.Yellow[s-i-j][j+1];
            
                string CenterSolution = SolveCenter(Centers);

                int len_centers = CenterSolution.size();
                if(len_centers%2 == 1) CenterSolution.push_back('A');

                m = 0;
                while(m<len_centers)
                {
                    char* c1;
                    char* c2;

                    switch(CenterSolution[m])

                    {
                        case 'A':  c1 = &(cube.White[j+1][i+j+1]); break;
                        case 'C':  c1 = &(cube.White[s-j][s-i-j]); break;
                        case 'D':  c1 = &(cube.White[s-i-j][j+1]); break;

                        case 'E':  c1 = &(cube.Blue[j+1][i+j+1]); break;
                        case 'F':  c1 = &(cube.Blue[i+j+1][s-j]); break;
                        case 'G':  c1 = &(cube.Blue[s-j][s-i-j]); break;
                        case 'H':  c1 = &(cube.Blue[s-i-j][j+1]); break;

                        case 'I':  c1 = &(cube.Orange[j+1][i+j+1]); break;
                        case 'J':  c1 = &(cube.Orange[i+j+1][s-j]); break;
                        case 'K':  c1 = &(cube.Orange[s-j][s-i-j]); break;
                        case 'L':  c1 = &(cube.Orange[s-i-j][j+1]); break;

                        case 'M':  c1 = &(cube.Green[j+1][i+j+1]); break;
                        case 'N':  c1 = &(cube.Green[i+j+1][s-j]); break;
                        case 'O':  c1 = &(cube.Green[s-j][s-i-j]); break;
                        case 'P':  c1 = &(cube.Green[s-i-j][j+1]); break;

                        case 'Q':  c1 = &(cube.Red[j+1][i+j+1]); break;
                        case 'R':  c1 = &(cube.Red[i+j+1][s-j]); break;
                        case 'S':  c1 = &(cube.Red[s-j][s-i-j]); break;
                        case 'T':  c1 = &(cube.Red[s-i-j][j+1]); break;

                        case 'U':  c1 = &(cube.Yellow[j+1][i+j+1]); break;
                        case 'V':  c1 = &(cube.Yellow[i+j+1][s-j]); break;
                        case 'W':  c1 = &(cube.Yellow[s-j][s-i-j]); break;
                        case 'X':  c1 = &(cube.Yellow[s-i-j][j+1]); break;
                    }


                    switch(CenterSolution[m+1])

                    {
                        case 'A':  c2 = &(cube.White[j+1][i+j+1]); break;
                        case 'C':  c2 = &(cube.White[s-j][s-i-j]); break;
                        case 'D':  c2 = &(cube.White[s-i-j][j+1]); break;

                        case 'E':  c2 = &(cube.Blue[j+1][i+j+1]); break;
                        case 'F':  c2 = &(cube.Blue[i+j+1][s-j]); break;
                        case 'G':  c2 = &(cube.Blue[s-j][s-i-j]); break;
                        case 'H':  c2 = &(cube.Blue[s-i-j][j+1]); break;

                        case 'I':  c2 = &(cube.Orange[j+1][i+j+1]); break;
                        case 'J':  c2 = &(cube.Orange[i+j+1][s-j]); break;
                        case 'K':  c2 = &(cube.Orange[s-j][s-i-j]); break;
                        case 'L':  c2 = &(cube.Orange[s-i-j][j+1]); break;

                        case 'M':  c2 = &(cube.Green[j+1][i+j+1]); break;
                        case 'N':  c2 = &(cube.Green[i+j+1][s-j]); break;
                        case 'O':  c2 = &(cube.Green[s-j][s-i-j]); break;
                        case 'P':  c2 = &(cube.Green[s-i-j][j+1]); break;

                        case 'Q':  c2 = &(cube.Red[j+1][i+j+1]); break;
                        case 'R':  c2 = &(cube.Red[i+j+1][s-j]); break;
                        case 'S':  c2 = &(cube.Red[s-j][s-i-j]); break;
                        case 'T':  c2 = &(cube.Red[s-i-j][j+1]); break;

                        case 'U':  c2 = &(cube.Yellow[j+1][i+j+1]); break;
                        case 'V':  c2 = &(cube.Yellow[i+j+1][s-j]); break;
                        case 'W':  c2 = &(cube.Yellow[s-j][s-i-j]); break;
                        case 'X':  c2 = &(cube.Yellow[s-i-j][j+1]); break;
                    }

                    char* buffer = &(cube.White[i+j+1][s-j]);

                    swap(*buffer,*c1);
                    swap(*buffer,*c2);

                    m = m+2;
                }

                if(k == charg*250000)
                {
                    cout << k*100/NumberOfCentersType(size) << " %\n";
                    charg++;
                }
                
                k++;
            }
            x = x-2;
        }

        if(size%2 == 0)
        {
            // Wings

            int lim;
            
            m = 0; lim = size/2-1;
            
            int charg = 0;

            while(m<lim)
            {
                Wings = "";

                int a = size/2+m;
                int b = (size-1)/2-m;
                int c = size-1;

                Wings = Wings + EdgeToLetter(cube.White[0][a],cube.Green[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[a][c],cube.Orange[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[c][b],cube.Blue[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[b][0],cube.Red[0][b]);

                Wings = Wings + EdgeToLetter(cube.Blue[0][a],cube.White[c][a]);
                Wings = Wings + EdgeToLetter(cube.Blue[a][c],cube.Orange[a][0]);
                Wings = Wings + EdgeToLetter(cube.Blue[c][b],cube.Yellow[0][b]);
                Wings = Wings + EdgeToLetter(cube.Blue[b][0],cube.Red[b][c]);

                Wings = Wings + EdgeToLetter(cube.Orange[0][a],cube.White[b][c]);
                Wings = Wings + EdgeToLetter(cube.Orange[a][c],cube.Green[a][0]);
                Wings = Wings + EdgeToLetter(cube.Orange[c][b],cube.Yellow[b][c]);
                Wings = Wings + EdgeToLetter(cube.Orange[b][0],cube.Blue[b][c]);

                Wings = Wings + EdgeToLetter(cube.Green[0][a],cube.White[0][b]);
                Wings = Wings + EdgeToLetter(cube.Green[a][c],cube.Red[a][0]);
                Wings = Wings + EdgeToLetter(cube.Green[c][b],cube.Yellow[c][a]);
                Wings = Wings + EdgeToLetter(cube.Green[b][0],cube.Orange[b][c]);

                Wings = Wings + EdgeToLetter(cube.Red[0][a],cube.White[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[a][c],cube.Blue[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[c][b],cube.Yellow[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[b][0],cube.Green[b][c]);

                Wings = Wings + EdgeToLetter(cube.Yellow[0][a],cube.Blue[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[a][c],cube.Orange[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[c][b],cube.Green[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[b][0],cube.Red[c][a]); 

                string WingSolution = SolveWing(Wings);
                string tmp_wings = WingSolution;
                int len_wings = WingSolution.size();

                if(WingSolution.size()%2 == 1) WingSolution.push_back('E');
            
                for(int i=0;i<WingSolution.size()/2;i++)
                {
                    char* e1;
                    char* e2;

                    switch(WingSolution[2*i])

                    {
                        case 'A':  e1 = &(cube.White[0][a]); e2 = &(cube.Green[0][b]); break;
                        case 'B':  e1 = &(cube.White[a][c]); e2 = &(cube.Orange[0][b]); break;
                        case 'C':  e1 = &(cube.White[c][b]); e2 = &(cube.Blue[0][b]); break;
                        case 'D':  e1 = &(cube.White[b][0]); e2 = &(cube.Red[0][b]); break;

                        case 'E':  e1 = &(cube.Blue[0][a]); e2 = &(cube.White[c][a]); break;
                        case 'F':  e1 = &(cube.Blue[a][c]); e2 = &(cube.Orange[a][0]); break;
                        case 'G':  e1 = &(cube.Blue[c][b]); e2 = &(cube.Yellow[0][b]); break;
                        case 'H':  e1 = &(cube.Blue[b][0]); e2 = &(cube.Red[b][c]); break;

                        case 'I':  e1 = &(cube.Orange[0][a]); e2 = &(cube.White[b][c]); break;
                        case 'J':  e1 = &(cube.Orange[a][c]); e2 = &(cube.Green[a][0]); break;
                        case 'K':  e1 = &(cube.Orange[c][b]); e2 = &(cube.Yellow[b][c]); break;
                        case 'L':  e1 = &(cube.Orange[b][0]); e2 = &(cube.Blue[b][c]); break;

                        case 'M':  e1 = &(cube.Green[0][a]); e2 = &(cube.White[0][b]); break;
                        case 'N':  e1 = &(cube.Green[a][c]); e2 = &(cube.Red[a][0]); break;
                        case 'O':  e1 = &(cube.Green[c][b]); e2 = &(cube.Yellow[c][a]); break;
                        case 'P':  e1 = &(cube.Green[b][0]); e2 = &(cube.Orange[b][c]); break;

                        case 'Q':  e1 = &(cube.Red[0][a]); e2 = &(cube.White[a][0]); break;
                        case 'R':  e1 = &(cube.Red[a][c]); e2 = &(cube.Blue[a][0]); break;
                        case 'S':  e1 = &(cube.Red[c][b]); e2 = &(cube.Yellow[a][0]); break;
                        case 'T':  e1 = &(cube.Red[b][0]); e2 = &(cube.Green[b][c]); break;

                        case 'U':  e1 = &(cube.Yellow[0][a]); e2 = &(cube.Blue[c][a]); break;
                        case 'V':  e1 = &(cube.Yellow[a][c]); e2 = &(cube.Orange[c][a]); break;
                        case 'W':  e1 = &(cube.Yellow[c][b]); e2 = &(cube.Green[c][a]); break;
                        case 'X':  e1 = &(cube.Yellow[b][0]); e2 = &(cube.Red[c][a]); break;
                    }

                    char* e3;
                    char* e4;

                    switch(WingSolution[2*i+1])

                    {
                        case 'A':  e3 = &(cube.White[0][a]); e4 = &(cube.Green[0][b]); break;
                        case 'B':  e3 = &(cube.White[a][c]); e4 = &(cube.Orange[0][b]); break;
                        case 'C':  e3 = &(cube.White[c][b]); e4 = &(cube.Blue[0][b]); break;
                        case 'D':  e3 = &(cube.White[b][0]); e4 = &(cube.Red[0][b]); break;

                        case 'E':  e3 = &(cube.Blue[0][a]); e4 = &(cube.White[c][a]); break;
                        case 'F':  e3 = &(cube.Blue[a][c]); e4 = &(cube.Orange[a][0]); break;
                        case 'G':  e3 = &(cube.Blue[c][b]); e4 = &(cube.Yellow[0][b]); break;
                        case 'H':  e3 = &(cube.Blue[b][0]); e4 = &(cube.Red[b][c]); break;

                        case 'I':  e3 = &(cube.Orange[0][a]); e4 = &(cube.White[b][c]); break;
                        case 'J':  e3 = &(cube.Orange[a][c]); e4 = &(cube.Green[a][0]); break;
                        case 'K':  e3 = &(cube.Orange[c][b]); e4 = &(cube.Yellow[b][c]); break;
                        case 'L':  e3 = &(cube.Orange[b][0]); e4 = &(cube.Blue[b][c]); break;

                        case 'M':  e3 = &(cube.Green[0][a]); e4 = &(cube.White[0][b]); break;
                        case 'N':  e3 = &(cube.Green[a][c]); e4 = &(cube.Red[a][0]); break;
                        case 'O':  e3 = &(cube.Green[c][b]); e4 = &(cube.Yellow[c][a]); break;
                        case 'P':  e3 = &(cube.Green[b][0]); e4 = &(cube.Orange[b][c]); break;

                        case 'Q':  e3 = &(cube.Red[0][a]); e4 = &(cube.White[a][0]); break;
                        case 'R':  e3 = &(cube.Red[a][c]); e4 = &(cube.Blue[a][0]); break;
                        case 'S':  e3 = &(cube.Red[c][b]); e4 = &(cube.Yellow[a][0]); break;
                        case 'T':  e3 = &(cube.Red[b][0]); e4 = &(cube.Green[b][c]); break;

                        case 'U':  e3 = &(cube.Yellow[0][a]); e4 = &(cube.Blue[c][a]); break;
                        case 'V':  e3 = &(cube.Yellow[a][c]); e4 = &(cube.Orange[c][a]); break;
                        case 'W':  e3 = &(cube.Yellow[c][b]); e4 = &(cube.Green[c][a]); break;
                        case 'X':  e3 = &(cube.Yellow[b][0]); e4 = &(cube.Red[c][a]); break;
                    }

                    char* buffer1 = &(cube.Yellow[0][a]);
                    char* buffer2 = &(cube.Blue[c][a]);


                    swap(*buffer1,*e1);
                    swap(*buffer2,*e2);
                    swap(*buffer1,*e3);
                    swap(*buffer2,*e4);
                }

                if(tmp_wings.length()%2 == 1)
                {
                    char* buffer1 = &(cube.Yellow[0][a]);
                    char* buffer2 = &(cube.Blue[c][a]);
                    char* e1 = &(cube.Blue[0][a]);
                    char* e2 = &(cube.White[c][a]);

                    swap(*buffer1,*e1);
                    swap(*buffer2,*e2);
                }

                if(m-1 == charg*250)
                {
                    cout << (m-1)*100/(cube.size_cube/2) << " %\n";
                    charg++;
                }

                m++;
            }
        }

        if(size%2 == 1)
        {
            // Wings

            int lim;
            
            m = 1; lim = size/2;

            int charg = 0;

            while(m<lim)
            {
                Wings = "";

                int a = size/2+m;
                int b = (size-1)/2-m;
                int c = size-1;

                Wings = Wings + EdgeToLetter(cube.White[0][a],cube.Green[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[a][c],cube.Orange[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[c][b],cube.Blue[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[b][0],cube.Red[0][b]);

                Wings = Wings + EdgeToLetter(cube.Blue[0][a],cube.White[c][a]);
                Wings = Wings + EdgeToLetter(cube.Blue[a][c],cube.Orange[a][0]);
                Wings = Wings + EdgeToLetter(cube.Blue[c][b],cube.Yellow[0][b]);
                Wings = Wings + EdgeToLetter(cube.Blue[b][0],cube.Red[b][c]);

                Wings = Wings + EdgeToLetter(cube.Orange[0][a],cube.White[b][c]);
                Wings = Wings + EdgeToLetter(cube.Orange[a][c],cube.Green[a][0]);
                Wings = Wings + EdgeToLetter(cube.Orange[c][b],cube.Yellow[b][c]);
                Wings = Wings + EdgeToLetter(cube.Orange[b][0],cube.Blue[b][c]);

                Wings = Wings + EdgeToLetter(cube.Green[0][a],cube.White[0][b]);
                Wings = Wings + EdgeToLetter(cube.Green[a][c],cube.Red[a][0]);
                Wings = Wings + EdgeToLetter(cube.Green[c][b],cube.Yellow[c][a]);
                Wings = Wings + EdgeToLetter(cube.Green[b][0],cube.Orange[b][c]);

                Wings = Wings + EdgeToLetter(cube.Red[0][a],cube.White[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[a][c],cube.Blue[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[c][b],cube.Yellow[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[b][0],cube.Green[b][c]);

                Wings = Wings + EdgeToLetter(cube.Yellow[0][a],cube.Blue[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[a][c],cube.Orange[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[c][b],cube.Green[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[b][0],cube.Red[c][a]); 

                string WingSolution = SolveWing(Wings);
                string tmp_wings = WingSolution;
                int len_wings = WingSolution.size();

                if(WingSolution.size()%2 == 1) WingSolution.push_back('E');
            
                for(int i=0;i<WingSolution.size()/2;i++)
                {
                    char* e1;
                    char* e2;

                    switch(WingSolution[2*i])

                    {
                        case 'A':  e1 = &(cube.White[0][a]); e2 = &(cube.Green[0][b]); break;
                        case 'B':  e1 = &(cube.White[a][c]); e2 = &(cube.Orange[0][b]); break;
                        case 'C':  e1 = &(cube.White[c][b]); e2 = &(cube.Blue[0][b]); break;
                        case 'D':  e1 = &(cube.White[b][0]); e2 = &(cube.Red[0][b]); break;

                        case 'E':  e1 = &(cube.Blue[0][a]); e2 = &(cube.White[c][a]); break;
                        case 'F':  e1 = &(cube.Blue[a][c]); e2 = &(cube.Orange[a][0]); break;
                        case 'G':  e1 = &(cube.Blue[c][b]); e2 = &(cube.Yellow[0][b]); break;
                        case 'H':  e1 = &(cube.Blue[b][0]); e2 = &(cube.Red[b][c]); break;

                        case 'I':  e1 = &(cube.Orange[0][a]); e2 = &(cube.White[b][c]); break;
                        case 'J':  e1 = &(cube.Orange[a][c]); e2 = &(cube.Green[a][0]); break;
                        case 'K':  e1 = &(cube.Orange[c][b]); e2 = &(cube.Yellow[b][c]); break;
                        case 'L':  e1 = &(cube.Orange[b][0]); e2 = &(cube.Blue[b][c]); break;

                        case 'M':  e1 = &(cube.Green[0][a]); e2 = &(cube.White[0][b]); break;
                        case 'N':  e1 = &(cube.Green[a][c]); e2 = &(cube.Red[a][0]); break;
                        case 'O':  e1 = &(cube.Green[c][b]); e2 = &(cube.Yellow[c][a]); break;
                        case 'P':  e1 = &(cube.Green[b][0]); e2 = &(cube.Orange[b][c]); break;

                        case 'Q':  e1 = &(cube.Red[0][a]); e2 = &(cube.White[a][0]); break;
                        case 'R':  e1 = &(cube.Red[a][c]); e2 = &(cube.Blue[a][0]); break;
                        case 'S':  e1 = &(cube.Red[c][b]); e2 = &(cube.Yellow[a][0]); break;
                        case 'T':  e1 = &(cube.Red[b][0]); e2 = &(cube.Green[b][c]); break;

                        case 'U':  e1 = &(cube.Yellow[0][a]); e2 = &(cube.Blue[c][a]); break;
                        case 'V':  e1 = &(cube.Yellow[a][c]); e2 = &(cube.Orange[c][a]); break;
                        case 'W':  e1 = &(cube.Yellow[c][b]); e2 = &(cube.Green[c][a]); break;
                        case 'X':  e1 = &(cube.Yellow[b][0]); e2 = &(cube.Red[c][a]); break;
                    }

                    char* e3;
                    char* e4;

                    switch(WingSolution[2*i+1])

                    {
                        case 'A':  e3 = &(cube.White[0][a]); e4 = &(cube.Green[0][b]); break;
                        case 'B':  e3 = &(cube.White[a][c]); e4 = &(cube.Orange[0][b]); break;
                        case 'C':  e3 = &(cube.White[c][b]); e4 = &(cube.Blue[0][b]); break;
                        case 'D':  e3 = &(cube.White[b][0]); e4 = &(cube.Red[0][b]); break;

                        case 'E':  e3 = &(cube.Blue[0][a]); e4 = &(cube.White[c][a]); break;
                        case 'F':  e3 = &(cube.Blue[a][c]); e4 = &(cube.Orange[a][0]); break;
                        case 'G':  e3 = &(cube.Blue[c][b]); e4 = &(cube.Yellow[0][b]); break;
                        case 'H':  e3 = &(cube.Blue[b][0]); e4 = &(cube.Red[b][c]); break;

                        case 'I':  e3 = &(cube.Orange[0][a]); e4 = &(cube.White[b][c]); break;
                        case 'J':  e3 = &(cube.Orange[a][c]); e4 = &(cube.Green[a][0]); break;
                        case 'K':  e3 = &(cube.Orange[c][b]); e4 = &(cube.Yellow[b][c]); break;
                        case 'L':  e3 = &(cube.Orange[b][0]); e4 = &(cube.Blue[b][c]); break;

                        case 'M':  e3 = &(cube.Green[0][a]); e4 = &(cube.White[0][b]); break;
                        case 'N':  e3 = &(cube.Green[a][c]); e4 = &(cube.Red[a][0]); break;
                        case 'O':  e3 = &(cube.Green[c][b]); e4 = &(cube.Yellow[c][a]); break;
                        case 'P':  e3 = &(cube.Green[b][0]); e4 = &(cube.Orange[b][c]); break;

                        case 'Q':  e3 = &(cube.Red[0][a]); e4 = &(cube.White[a][0]); break;
                        case 'R':  e3 = &(cube.Red[a][c]); e4 = &(cube.Blue[a][0]); break;
                        case 'S':  e3 = &(cube.Red[c][b]); e4 = &(cube.Yellow[a][0]); break;
                        case 'T':  e3 = &(cube.Red[b][0]); e4 = &(cube.Green[b][c]); break;

                        case 'U':  e3 = &(cube.Yellow[0][a]); e4 = &(cube.Blue[c][a]); break;
                        case 'V':  e3 = &(cube.Yellow[a][c]); e4 = &(cube.Orange[c][a]); break;
                        case 'W':  e3 = &(cube.Yellow[c][b]); e4 = &(cube.Green[c][a]); break;
                        case 'X':  e3 = &(cube.Yellow[b][0]); e4 = &(cube.Red[c][a]); break;
                    }

                    char* buffer1 = &(cube.Yellow[0][a]);
                    char* buffer2 = &(cube.Blue[c][a]);


                    swap(*buffer1,*e1);
                    swap(*buffer2,*e2);
                    swap(*buffer1,*e3);
                    swap(*buffer2,*e4);
                }

                if(tmp_wings.length()%2 == 1)
                {
                    Alg = return_wing_parity(cube.size_cube,m);
                    cube.apply_alg(Alg);
                }

                m++;

                if(m-1 == charg*50)
                {
                    cout << k*100/NumberOfCentersType(size) << " %\n";
                    charg++;
                }

            }

            // Midges

            Edges = "";

            int mid = size/2;

            Edges = Edges + EdgeToLetter(cube.White[0][mid],cube.Green[0][mid]);
            Edges = Edges + EdgeToLetter(cube.White[mid][size-1],cube.Orange[0][mid]);
            Edges = Edges + EdgeToLetter(cube.White[size-1][mid],cube.Blue[0][mid]);
            Edges = Edges + EdgeToLetter(cube.White[mid][0],cube.Red[0][mid]);

            Edges = Edges + EdgeToLetter(cube.Blue[0][mid],cube.White[size-1][mid]);
            Edges = Edges + EdgeToLetter(cube.Blue[mid][size-1],cube.Orange[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Blue[size-1][mid],cube.Yellow[0][mid]);
            Edges = Edges + EdgeToLetter(cube.Blue[mid][0],cube.Red[mid][size-1]);

            Edges = Edges + EdgeToLetter(cube.Orange[0][mid],cube.White[mid][size-1]);
            Edges = Edges + EdgeToLetter(cube.Orange[mid][size-1],cube.Green[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Orange[size-1][mid],cube.Yellow[mid][size-1]);
            Edges = Edges + EdgeToLetter(cube.Orange[mid][0],cube.Blue[mid][size-1]);

            Edges = Edges + EdgeToLetter(cube.Green[0][mid],cube.White[0][mid]);
            Edges = Edges + EdgeToLetter(cube.Green[mid][size-1],cube.Red[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Green[size-1][mid],cube.Yellow[size-1][mid]);
            Edges = Edges + EdgeToLetter(cube.Green[mid][0],cube.Orange[mid][size-1]);

            Edges = Edges + EdgeToLetter(cube.Red[0][mid],cube.White[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Red[mid][size-1],cube.Blue[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Red[size-1][mid],cube.Yellow[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Red[mid][0],cube.Green[mid][size-1]);

            Edges = Edges + EdgeToLetter(cube.Yellow[0][mid],cube.Blue[size-1][mid]);
            Edges = Edges + EdgeToLetter(cube.Yellow[mid][size-1],cube.Orange[size-1][mid]);
            Edges = Edges + EdgeToLetter(cube.Yellow[size-1][mid],cube.Green[size-1][mid]);
            Edges = Edges + EdgeToLetter(cube.Yellow[mid][0],cube.Red[size-1][mid]); 


            string EdgeSolution = SolveEdge(Edges);
            int len_edges = EdgeSolution.size();
            string tmp_edges = EdgeSolution;
            tmp_edges.push_back('Z');

            i = 0;

            while(i<len_edges)
            {
                Alg = return_BHE_alg(tmp_edges[i],tmp_edges[i+1]);
                if(Alg.length() > 0 && i+1<len_edges)
                {
                    cube.apply_alg(Alg);
                    i = i+2;
                }
                else
                {
                    Alg = return_single_edge_alg(tmp_edges[i]);
                    cube.apply_alg(Alg);
                    i++;
                }
            }

            if(EdgeSolution.length()%2 == 1)
            {
                Alg = return_edge_parity();
                cube.apply_alg(Alg);
            }
        }

        //Coins

        Corners = "";

        Corners = Corners + CornerToLetter(cube.White[0][0],cube.Red[0][0]);
        Corners = Corners + CornerToLetter(cube.White[0][size-1],cube.Green[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][size-1],cube.Orange[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][0],cube.Blue[0][0]);

        Corners = Corners + CornerToLetter(cube.Blue[0][0],cube.Red[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[0][size-1],cube.White[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][size-1],cube.Orange[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][0],cube.Yellow[0][0]);

        Corners = Corners + CornerToLetter(cube.Orange[0][0],cube.Blue[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[0][size-1],cube.White[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][size-1],cube.Green[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][0],cube.Yellow[0][size-1]);

        Corners = Corners + CornerToLetter(cube.Green[0][0],cube.Orange[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Green[0][size-1],cube.White[0][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][size-1],cube.Red[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][0],cube.Yellow[size-1][size-1]);

        Corners = Corners + CornerToLetter(cube.Red[0][0],cube.Green[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Red[0][size-1],cube.White[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][size-1],cube.Blue[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][0],cube.Yellow[size-1][0]);

        Corners = Corners + CornerToLetter(cube.Yellow[0][0],cube.Red[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[0][size-1],cube.Blue[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][size-1],cube.Orange[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][0],cube.Green[size-1][size-1]);

        string CornerSolution = SolveCorner(Corners);

        int len_corners = CornerSolution.size();
        string tmp_corners = CornerSolution; 
        tmp_corners.push_back('A');

        i = 0;
        while(i<len_corners)
        {
            Alg = return_BHC_alg(tmp_corners[i],tmp_corners[i+1]);
            if(Alg.length() > 0 && i+1<len_corners)
            {
                cube.apply_alg(Alg);
                i = i+2;
            }
            else
            {
                Alg = return_single_corner_alg(tmp_corners[i]);
                cube.apply_alg(Alg);
                i++;
            }
        }

        if(CornerSolution.length()%2 == 1 && size >= 4)
        {
            Alg = return_corner_parity(cube.size_cube);
            cube.apply_alg(Alg);
        }
    }

    if(cube.is_solved()) cout << "Cube solved\n";
    else cout << "Cube not solved\n";
}

// Function to count total number of words in the string
int countMoves(string Algorithm)
{
  // Check if the string is null or empty then return zero
  if (Algorithm.size() == 0) {
    return 0;
  }
  // Splitting the string around matches of the given regular expression
  vector<string> words;
  string temp = "";
  for (int i = 0; i < Algorithm.size(); i++) {
    if (Algorithm[i] == ' ') {
      words.push_back(temp);
      temp = "";
    }
    else {
      temp += Algorithm[i];
    }
  }
 
  int count = 1;
 
  for (int i = 0; i < words.size(); i++) {
    if (words[i].size() != 0)
      count++;
  }
 
  // Return number of words in the given string
  return count;
}

size_t solution_length(Cube& cube)
{
    size_t len = 0;
    int size = cube.size_cube;
    string Corners, Edges, Centers, Wings;
    string Alg;
    int i,j,x,k,m;

    if(size == 2)
    {
        // Coins

        Corners = "";

        Corners = Corners + CornerToLetter(cube.White[0][0],cube.Red[0][0]);
        Corners = Corners + CornerToLetter(cube.White[0][size-1],cube.Green[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][size-1],cube.Orange[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][0],cube.Blue[0][0]);

        Corners = Corners + CornerToLetter(cube.Blue[0][0],cube.Red[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[0][size-1],cube.White[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][size-1],cube.Orange[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][0],cube.Yellow[0][0]);

        Corners = Corners + CornerToLetter(cube.Orange[0][0],cube.Blue[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[0][size-1],cube.White[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][size-1],cube.Green[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][0],cube.Yellow[0][size-1]);

        Corners = Corners + CornerToLetter(cube.Green[0][0],cube.Orange[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Green[0][size-1],cube.White[0][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][size-1],cube.Red[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][0],cube.Yellow[size-1][size-1]);

        Corners = Corners + CornerToLetter(cube.Red[0][0],cube.Green[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Red[0][size-1],cube.White[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][size-1],cube.Blue[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][0],cube.Yellow[size-1][0]);

        Corners = Corners + CornerToLetter(cube.Yellow[0][0],cube.Red[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[0][size-1],cube.Blue[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][size-1],cube.Orange[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][0],cube.Green[size-1][size-1]);

        string CornerSolution = SolveCorner(Corners);

        int len_corners = CornerSolution.size();
        string tmp_corners = CornerSolution; 
        tmp_corners.push_back('A');

        i = 0;
        while(i<len_corners)
        {
            Alg = return_BHC_alg(tmp_corners[i],tmp_corners[i+1]);
            if(Alg.length() > 0 && i+1<len_corners)
            {
                len = len+countMoves(Alg);
                i = i+2;
            }
            else
            {
                Alg = return_single_corner_alg(tmp_corners[i]);
                len = len+countMoves(Alg);
                i++;
            }
        }
    }

    else if(size == 3)
    {
        // Edges
  
        Edges = "";

        int mid = size/2;

        Edges = Edges + EdgeToLetter(cube.White[0][mid],cube.Green[0][mid]);
        Edges = Edges + EdgeToLetter(cube.White[mid][size-1],cube.Orange[0][mid]);
        Edges = Edges + EdgeToLetter(cube.White[size-1][mid],cube.Blue[0][mid]);
        Edges = Edges + EdgeToLetter(cube.White[mid][0],cube.Red[0][mid]);

        Edges = Edges + EdgeToLetter(cube.Blue[0][mid],cube.White[size-1][mid]);
        Edges = Edges + EdgeToLetter(cube.Blue[mid][size-1],cube.Orange[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Blue[size-1][mid],cube.Yellow[0][mid]);
        Edges = Edges + EdgeToLetter(cube.Blue[mid][0],cube.Red[mid][size-1]);

        Edges = Edges + EdgeToLetter(cube.Orange[0][mid],cube.White[mid][size-1]);
        Edges = Edges + EdgeToLetter(cube.Orange[mid][size-1],cube.Green[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Orange[size-1][mid],cube.Yellow[mid][size-1]);
        Edges = Edges + EdgeToLetter(cube.Orange[mid][0],cube.Blue[mid][size-1]);

        Edges = Edges + EdgeToLetter(cube.Green[0][mid],cube.White[0][mid]);
        Edges = Edges + EdgeToLetter(cube.Green[mid][size-1],cube.Red[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Green[size-1][mid],cube.Yellow[size-1][mid]);
        Edges = Edges + EdgeToLetter(cube.Green[mid][0],cube.Orange[mid][size-1]);

        Edges = Edges + EdgeToLetter(cube.Red[0][mid],cube.White[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Red[mid][size-1],cube.Blue[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Red[size-1][mid],cube.Yellow[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Red[mid][0],cube.Green[mid][size-1]);

        Edges = Edges + EdgeToLetter(cube.Yellow[0][mid],cube.Blue[size-1][mid]);
        Edges = Edges + EdgeToLetter(cube.Yellow[mid][size-1],cube.Orange[size-1][mid]);
        Edges = Edges + EdgeToLetter(cube.Yellow[size-1][mid],cube.Green[size-1][mid]);
        Edges = Edges + EdgeToLetter(cube.Yellow[mid][0],cube.Red[size-1][mid]); 


        string EdgeSolution = SolveEdge(Edges);
        int len_edges = EdgeSolution.size();
        string tmp_edges = EdgeSolution;
        tmp_edges.push_back('Z');

        i = 0;

        while(i<len_edges)
        {
            Alg = return_BHE_alg(tmp_edges[i],tmp_edges[i+1]);
            if(Alg.length() > 0 && i+1<len_edges)
            {
                len = len+countMoves(Alg);
                i = i+2;
            }
            else
            {
                Alg = return_single_edge_alg(tmp_edges[i]);
                len = len+countMoves(Alg);
                i++;
            }
        }

        if(EdgeSolution.length()%2 == 1)
        {
            Alg = return_edge_parity();
            len = len+countMoves(Alg);
        }

        // Coins

        Corners = "";

        Corners = Corners + CornerToLetter(cube.White[0][0],cube.Red[0][0]);
        Corners = Corners + CornerToLetter(cube.White[0][size-1],cube.Green[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][size-1],cube.Orange[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][0],cube.Blue[0][0]);

        Corners = Corners + CornerToLetter(cube.Blue[0][0],cube.Red[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[0][size-1],cube.White[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][size-1],cube.Orange[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][0],cube.Yellow[0][0]);

        Corners = Corners + CornerToLetter(cube.Orange[0][0],cube.Blue[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[0][size-1],cube.White[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][size-1],cube.Green[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][0],cube.Yellow[0][size-1]);

        Corners = Corners + CornerToLetter(cube.Green[0][0],cube.Orange[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Green[0][size-1],cube.White[0][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][size-1],cube.Red[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][0],cube.Yellow[size-1][size-1]);

        Corners = Corners + CornerToLetter(cube.Red[0][0],cube.Green[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Red[0][size-1],cube.White[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][size-1],cube.Blue[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][0],cube.Yellow[size-1][0]);

        Corners = Corners + CornerToLetter(cube.Yellow[0][0],cube.Red[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[0][size-1],cube.Blue[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][size-1],cube.Orange[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][0],cube.Green[size-1][size-1]);

        string CornerSolution = SolveCorner(Corners);

        int len_corners = CornerSolution.size();
        string tmp_corners = CornerSolution; 
        tmp_corners.push_back('A');

        i = 0;
        while(i<len_corners)
        {
            Alg = return_BHC_alg(tmp_corners[i],tmp_corners[i+1]);
            if(Alg.length() > 0 && i+1<len_corners)
            {
                len = len+countMoves(Alg);
                i = i+2;
            }
            else
            {
                Alg = return_single_corner_alg(tmp_corners[i]);
                len = len+countMoves(Alg);
                i++;
            }
        }
    }

    else 
    {
        int s = size-2;
        
        k = 0;
        x = s;
        int charg = 0;

        #pragma omp for
        for(int j=0;j<s/2;j=j+1)
        {
            for(int i=0;i<x-1;i=i+1)
            {
                Centers = "";

                Centers = Centers + cube.White[j+1][i+j+1];
                Centers = Centers + cube.White[i+j+1][s-j];
                Centers = Centers + cube.White[s-j][s-i-j];
                Centers = Centers + cube.White[s-i-j][j+1];

                Centers = Centers + cube.Blue[j+1][i+j+1];
                Centers = Centers + cube.Blue[i+j+1][s-j];
                Centers = Centers + cube.Blue[s-j][s-i-j];
                Centers = Centers + cube.Blue[s-i-j][j+1];

                Centers = Centers + cube.Orange[j+1][i+j+1];
                Centers = Centers + cube.Orange[i+j+1][s-j];
                Centers = Centers + cube.Orange[s-j][s-i-j];
                Centers = Centers + cube.Orange[s-i-j][j+1];

                Centers = Centers + cube.Green[j+1][i+j+1];
                Centers = Centers + cube.Green[i+j+1][s-j];
                Centers = Centers + cube.Green[s-j][s-i-j];
                Centers = Centers + cube.Green[s-i-j][j+1];

                Centers = Centers + cube.Red[j+1][i+j+1];
                Centers = Centers + cube.Red[i+j+1][s-j];
                Centers = Centers + cube.Red[s-j][s-i-j];
                Centers = Centers + cube.Red[s-i-j][j+1];

                Centers = Centers + cube.Yellow[j+1][i+j+1];
                Centers = Centers + cube.Yellow[i+j+1][s-j];
                Centers = Centers + cube.Yellow[s-j][s-i-j];
                Centers = Centers + cube.Yellow[s-i-j][j+1];
                
                string CenterSolution = SolveCenter(Centers);

                int len_centers = CenterSolution.size();
                if(len_centers%2 == 1) CenterSolution.push_back('A');

                m = 0;
                while(m<len_centers)
                {
                    Alg = return_3S_center_alg(CenterSolution[m],CenterSolution[m+1],size,j+1,i+j+1);
                    len = len+countMoves(Alg);
                    m = m+2;
                }
                k++;

                if(k%250000 == 0) cout << ++charg << endl;
            }
            x = x-2;
        }

        if(size%2 == 0)
        {
            // Wings

            int lim;
            
            m = 0; lim = size/2-1;
            k = 1;

            while(m<lim)
            {
                Wings = "";

                int a = size/2+m;
                int b = (size-1)/2-m;
                int c = size-1;

                Wings = Wings + EdgeToLetter(cube.White[0][a],cube.Green[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[a][c],cube.Orange[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[c][b],cube.Blue[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[b][0],cube.Red[0][b]);

                Wings = Wings + EdgeToLetter(cube.Blue[0][a],cube.White[c][a]);
                Wings = Wings + EdgeToLetter(cube.Blue[a][c],cube.Orange[a][0]);
                Wings = Wings + EdgeToLetter(cube.Blue[c][b],cube.Yellow[0][b]);
                Wings = Wings + EdgeToLetter(cube.Blue[b][0],cube.Red[b][c]);

                Wings = Wings + EdgeToLetter(cube.Orange[0][a],cube.White[b][c]);
                Wings = Wings + EdgeToLetter(cube.Orange[a][c],cube.Green[a][0]);
                Wings = Wings + EdgeToLetter(cube.Orange[c][b],cube.Yellow[b][c]);
                Wings = Wings + EdgeToLetter(cube.Orange[b][0],cube.Blue[b][c]);

                Wings = Wings + EdgeToLetter(cube.Green[0][a],cube.White[0][b]);
                Wings = Wings + EdgeToLetter(cube.Green[a][c],cube.Red[a][0]);
                Wings = Wings + EdgeToLetter(cube.Green[c][b],cube.Yellow[c][a]);
                Wings = Wings + EdgeToLetter(cube.Green[b][0],cube.Orange[b][c]);

                Wings = Wings + EdgeToLetter(cube.Red[0][a],cube.White[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[a][c],cube.Blue[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[c][b],cube.Yellow[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[b][0],cube.Green[b][c]);

                Wings = Wings + EdgeToLetter(cube.Yellow[0][a],cube.Blue[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[a][c],cube.Orange[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[c][b],cube.Green[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[b][0],cube.Red[c][a]); 

                string WingSolution = SolveWing(Wings);
                string tmp_wings = WingSolution;
                int len_wings = WingSolution.size();

                if(WingSolution.size()%2 == 1) WingSolution.push_back('E');
            
                for(int i=0;i<WingSolution.size()/2;i++)
                {
                    Alg = return_3S_wing_alg(WingSolution[2*i],WingSolution[2*i+1],m,cube.size_cube);
                    len = len+countMoves(Alg);
                }

                if(tmp_wings.length()%2 == 1)
                {
                    Alg = return_wing_parity(cube.size_cube,m);
                    len = len+countMoves(Alg);
                }

                m++;
                k++;
            }
        }

        if(size%2 == 1)
        {
            // Wings

            int lim;
            
            m = 1; lim = size/2;
            k = 1;

            while(m<lim)
            {
                Wings = "";

                int a = size/2+m;
                int b = (size-1)/2-m;
                int c = size-1;

                Wings = Wings + EdgeToLetter(cube.White[0][a],cube.Green[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[a][c],cube.Orange[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[c][b],cube.Blue[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[b][0],cube.Red[0][b]);

                Wings = Wings + EdgeToLetter(cube.Blue[0][a],cube.White[c][a]);
                Wings = Wings + EdgeToLetter(cube.Blue[a][c],cube.Orange[a][0]);
                Wings = Wings + EdgeToLetter(cube.Blue[c][b],cube.Yellow[0][b]);
                Wings = Wings + EdgeToLetter(cube.Blue[b][0],cube.Red[b][c]);

                Wings = Wings + EdgeToLetter(cube.Orange[0][a],cube.White[b][c]);
                Wings = Wings + EdgeToLetter(cube.Orange[a][c],cube.Green[a][0]);
                Wings = Wings + EdgeToLetter(cube.Orange[c][b],cube.Yellow[b][c]);
                Wings = Wings + EdgeToLetter(cube.Orange[b][0],cube.Blue[b][c]);

                Wings = Wings + EdgeToLetter(cube.Green[0][a],cube.White[0][b]);
                Wings = Wings + EdgeToLetter(cube.Green[a][c],cube.Red[a][0]);
                Wings = Wings + EdgeToLetter(cube.Green[c][b],cube.Yellow[c][a]);
                Wings = Wings + EdgeToLetter(cube.Green[b][0],cube.Orange[b][c]);

                Wings = Wings + EdgeToLetter(cube.Red[0][a],cube.White[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[a][c],cube.Blue[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[c][b],cube.Yellow[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[b][0],cube.Green[b][c]);

                Wings = Wings + EdgeToLetter(cube.Yellow[0][a],cube.Blue[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[a][c],cube.Orange[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[c][b],cube.Green[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[b][0],cube.Red[c][a]); 

                string WingSolution = SolveWing(Wings);
                string tmp_wings = WingSolution;
                int len_wings = WingSolution.size();

                if(WingSolution.size()%2 == 1) WingSolution.push_back('E');
            
                for(int i=0;i<WingSolution.size()/2;i++)
                {
                    Alg = return_3S_wing_alg(WingSolution[2*i],WingSolution[2*i+1],m,cube.size_cube);
                    len = len+countMoves(Alg);
                }

                if(tmp_wings.length()%2 == 1)
                {
                    Alg = return_wing_parity(cube.size_cube,m);
                    len = len+countMoves(Alg);
                }

                m++;
                k++;
            }

            // Midges

            Edges = "";

            int mid = size/2;

            Edges = Edges + EdgeToLetter(cube.White[0][mid],cube.Green[0][mid]);
            Edges = Edges + EdgeToLetter(cube.White[mid][size-1],cube.Orange[0][mid]);
            Edges = Edges + EdgeToLetter(cube.White[size-1][mid],cube.Blue[0][mid]);
            Edges = Edges + EdgeToLetter(cube.White[mid][0],cube.Red[0][mid]);

            Edges = Edges + EdgeToLetter(cube.Blue[0][mid],cube.White[size-1][mid]);
            Edges = Edges + EdgeToLetter(cube.Blue[mid][size-1],cube.Orange[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Blue[size-1][mid],cube.Yellow[0][mid]);
            Edges = Edges + EdgeToLetter(cube.Blue[mid][0],cube.Red[mid][size-1]);

            Edges = Edges + EdgeToLetter(cube.Orange[0][mid],cube.White[mid][size-1]);
            Edges = Edges + EdgeToLetter(cube.Orange[mid][size-1],cube.Green[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Orange[size-1][mid],cube.Yellow[mid][size-1]);
            Edges = Edges + EdgeToLetter(cube.Orange[mid][0],cube.Blue[mid][size-1]);

            Edges = Edges + EdgeToLetter(cube.Green[0][mid],cube.White[0][mid]);
            Edges = Edges + EdgeToLetter(cube.Green[mid][size-1],cube.Red[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Green[size-1][mid],cube.Yellow[size-1][mid]);
            Edges = Edges + EdgeToLetter(cube.Green[mid][0],cube.Orange[mid][size-1]);

            Edges = Edges + EdgeToLetter(cube.Red[0][mid],cube.White[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Red[mid][size-1],cube.Blue[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Red[size-1][mid],cube.Yellow[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Red[mid][0],cube.Green[mid][size-1]);

            Edges = Edges + EdgeToLetter(cube.Yellow[0][mid],cube.Blue[size-1][mid]);
            Edges = Edges + EdgeToLetter(cube.Yellow[mid][size-1],cube.Orange[size-1][mid]);
            Edges = Edges + EdgeToLetter(cube.Yellow[size-1][mid],cube.Green[size-1][mid]);
            Edges = Edges + EdgeToLetter(cube.Yellow[mid][0],cube.Red[size-1][mid]); 


            string EdgeSolution = SolveEdge(Edges);
            int len_edges = EdgeSolution.size();
            string tmp_edges = EdgeSolution;
            tmp_edges.push_back('Z');

            i = 0;

            while(i<len_edges)
            {
                Alg = return_BHE_alg(tmp_edges[i],tmp_edges[i+1]);
                if(Alg.length() > 0 && i+1<len_edges)
                {
                    len = len+countMoves(Alg);
                    i = i+2;
                }
                else
                {
                    Alg = return_single_edge_alg(tmp_edges[i]);
                    len = len+countMoves(Alg);
                    i++;
                }
            }

            if(EdgeSolution.length()%2 == 1)
            {
                Alg = return_edge_parity();
                len = len+countMoves(Alg);
            }
        }

        //Coins

        Corners = "";

        Corners = Corners + CornerToLetter(cube.White[0][0],cube.Red[0][0]);
        Corners = Corners + CornerToLetter(cube.White[0][size-1],cube.Green[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][size-1],cube.Orange[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][0],cube.Blue[0][0]);

        Corners = Corners + CornerToLetter(cube.Blue[0][0],cube.Red[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[0][size-1],cube.White[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][size-1],cube.Orange[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][0],cube.Yellow[0][0]);

        Corners = Corners + CornerToLetter(cube.Orange[0][0],cube.Blue[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[0][size-1],cube.White[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][size-1],cube.Green[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][0],cube.Yellow[0][size-1]);

        Corners = Corners + CornerToLetter(cube.Green[0][0],cube.Orange[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Green[0][size-1],cube.White[0][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][size-1],cube.Red[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][0],cube.Yellow[size-1][size-1]);

        Corners = Corners + CornerToLetter(cube.Red[0][0],cube.Green[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Red[0][size-1],cube.White[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][size-1],cube.Blue[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][0],cube.Yellow[size-1][0]);

        Corners = Corners + CornerToLetter(cube.Yellow[0][0],cube.Red[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[0][size-1],cube.Blue[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][size-1],cube.Orange[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][0],cube.Green[size-1][size-1]);

        string CornerSolution = SolveCorner(Corners);

        int len_corners = CornerSolution.size();
        string tmp_corners = CornerSolution; 
        tmp_corners.push_back('A');

        i = 0;
        while(i<len_corners)
        {
            Alg = return_BHC_alg(tmp_corners[i],tmp_corners[i+1]);
            if(Alg.length() > 0 && i+1<len_corners)
            {
                len = len+countMoves(Alg);
                i = i+2;
            }
            else
            {
                Alg = return_single_corner_alg(tmp_corners[i]);
                len = len+countMoves(Alg);
                i++;
            }
        }

        if(CornerSolution.length()%2 == 1 && size >= 4)
        {
            Alg = return_corner_parity(cube.size_cube);
            len = len+countMoves(Alg);
        }
    }

    return len;
}

void print_solution(Cube& cube)
{
    int size = cube.size_cube;

    ofstream myfile;
    myfile.open ("Solution.txt");

    string Corners, Edges, Centers, Wings;

    string Alg;
    int i,j,x,k,m;

    if(size == 2)
    {
        // Coins

        myfile << "// Coins\n\n";

        Corners = "";

        Corners = Corners + CornerToLetter(cube.White[0][0],cube.Red[0][0]);
        Corners = Corners + CornerToLetter(cube.White[0][size-1],cube.Green[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][size-1],cube.Orange[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][0],cube.Blue[0][0]);

        Corners = Corners + CornerToLetter(cube.Blue[0][0],cube.Red[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[0][size-1],cube.White[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][size-1],cube.Orange[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][0],cube.Yellow[0][0]);

        Corners = Corners + CornerToLetter(cube.Orange[0][0],cube.Blue[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[0][size-1],cube.White[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][size-1],cube.Green[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][0],cube.Yellow[0][size-1]);

        Corners = Corners + CornerToLetter(cube.Green[0][0],cube.Orange[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Green[0][size-1],cube.White[0][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][size-1],cube.Red[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][0],cube.Yellow[size-1][size-1]);

        Corners = Corners + CornerToLetter(cube.Red[0][0],cube.Green[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Red[0][size-1],cube.White[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][size-1],cube.Blue[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][0],cube.Yellow[size-1][0]);

        Corners = Corners + CornerToLetter(cube.Yellow[0][0],cube.Red[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[0][size-1],cube.Blue[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][size-1],cube.Orange[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][0],cube.Green[size-1][size-1]);

        string CornerSolution = SolveCorner(Corners);

        int len_corners = CornerSolution.size();
        string tmp_corners = CornerSolution; 
        tmp_corners.push_back('A');

        i = 0;
        while(i<len_corners)
        {
            Alg = return_BHC_alg(tmp_corners[i],tmp_corners[i+1]);
            if(Alg.length() > 0 && i+1<len_corners)
            {
                myfile << Alg << "\n";
                i = i+2;
            }
            else
            {
                Alg = return_single_corner_alg(tmp_corners[i]);
                myfile << Alg << "\n";
                i++;
            }
        }
    }

    else if(size == 3)
    {
        // Edges

        myfile << "// Edges\n\n";
  
        Edges = "";

        int mid = size/2;

        Edges = Edges + EdgeToLetter(cube.White[0][mid],cube.Green[0][mid]);
        Edges = Edges + EdgeToLetter(cube.White[mid][size-1],cube.Orange[0][mid]);
        Edges = Edges + EdgeToLetter(cube.White[size-1][mid],cube.Blue[0][mid]);
        Edges = Edges + EdgeToLetter(cube.White[mid][0],cube.Red[0][mid]);

        Edges = Edges + EdgeToLetter(cube.Blue[0][mid],cube.White[size-1][mid]);
        Edges = Edges + EdgeToLetter(cube.Blue[mid][size-1],cube.Orange[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Blue[size-1][mid],cube.Yellow[0][mid]);
        Edges = Edges + EdgeToLetter(cube.Blue[mid][0],cube.Red[mid][size-1]);

        Edges = Edges + EdgeToLetter(cube.Orange[0][mid],cube.White[mid][size-1]);
        Edges = Edges + EdgeToLetter(cube.Orange[mid][size-1],cube.Green[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Orange[size-1][mid],cube.Yellow[mid][size-1]);
        Edges = Edges + EdgeToLetter(cube.Orange[mid][0],cube.Blue[mid][size-1]);

        Edges = Edges + EdgeToLetter(cube.Green[0][mid],cube.White[0][mid]);
        Edges = Edges + EdgeToLetter(cube.Green[mid][size-1],cube.Red[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Green[size-1][mid],cube.Yellow[size-1][mid]);
        Edges = Edges + EdgeToLetter(cube.Green[mid][0],cube.Orange[mid][size-1]);

        Edges = Edges + EdgeToLetter(cube.Red[0][mid],cube.White[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Red[mid][size-1],cube.Blue[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Red[size-1][mid],cube.Yellow[mid][0]);
        Edges = Edges + EdgeToLetter(cube.Red[mid][0],cube.Green[mid][size-1]);

        Edges = Edges + EdgeToLetter(cube.Yellow[0][mid],cube.Blue[size-1][mid]);
        Edges = Edges + EdgeToLetter(cube.Yellow[mid][size-1],cube.Orange[size-1][mid]);
        Edges = Edges + EdgeToLetter(cube.Yellow[size-1][mid],cube.Green[size-1][mid]);
        Edges = Edges + EdgeToLetter(cube.Yellow[mid][0],cube.Red[size-1][mid]); 


        string EdgeSolution = SolveEdge(Edges);
        int len_edges = EdgeSolution.size();
        string tmp_edges = EdgeSolution;
        tmp_edges.push_back('Z');

        i = 0;

        while(i<len_edges)
        {
            Alg = return_BHE_alg(tmp_edges[i],tmp_edges[i+1]);
            if(Alg.length() > 0 && i+1<len_edges)
            {
                myfile << Alg << "\n";
                i = i+2;
            }
            else
            {
                Alg = return_single_edge_alg(tmp_edges[i]);
                myfile << Alg << "\n";
                i++;
            }
        }

        if(EdgeSolution.length()%2 == 1)
        {
            Alg = return_edge_parity();
            myfile << Alg << "\n";
        }

        myfile << "\n\n";
        

        // Coins

        myfile << "// Coins\n\n";

        Corners = "";

        Corners = Corners + CornerToLetter(cube.White[0][0],cube.Red[0][0]);
        Corners = Corners + CornerToLetter(cube.White[0][size-1],cube.Green[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][size-1],cube.Orange[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][0],cube.Blue[0][0]);

        Corners = Corners + CornerToLetter(cube.Blue[0][0],cube.Red[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[0][size-1],cube.White[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][size-1],cube.Orange[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][0],cube.Yellow[0][0]);

        Corners = Corners + CornerToLetter(cube.Orange[0][0],cube.Blue[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[0][size-1],cube.White[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][size-1],cube.Green[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][0],cube.Yellow[0][size-1]);

        Corners = Corners + CornerToLetter(cube.Green[0][0],cube.Orange[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Green[0][size-1],cube.White[0][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][size-1],cube.Red[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][0],cube.Yellow[size-1][size-1]);

        Corners = Corners + CornerToLetter(cube.Red[0][0],cube.Green[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Red[0][size-1],cube.White[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][size-1],cube.Blue[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][0],cube.Yellow[size-1][0]);

        Corners = Corners + CornerToLetter(cube.Yellow[0][0],cube.Red[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[0][size-1],cube.Blue[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][size-1],cube.Orange[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][0],cube.Green[size-1][size-1]);

        string CornerSolution = SolveCorner(Corners);

        int len_corners = CornerSolution.size();
        string tmp_corners = CornerSolution; 
        tmp_corners.push_back('A');

        i = 0;
        while(i<len_corners)
        {
            Alg = return_BHC_alg(tmp_corners[i],tmp_corners[i+1]);
            if(Alg.length() > 0 && i+1<len_corners)
            {
                myfile << Alg << "\n";
                i = i+2;
            }
            else
            {
                Alg = return_single_corner_alg(tmp_corners[i]);
                myfile << Alg << "\n";
                i++;
            }
        }
    }

    else 
    {
        int s = size-2;

        int charg = 0;
        
        k = 0;
        x = s;

        for(int j=0;j<s/2;j=j+1)
        {
            for(int i=0;i<x-1;i=i+1)
            {
                myfile << "// Centre de type " + to_string(k+1) << "\n\n";

                Centers = "";

                Centers = Centers + (cube.White[j+1][i+j+1]);
                Centers = Centers + (cube.White[i+j+1][s-j]);
                Centers = Centers + (cube.White[s-j][s-i-j]);
                Centers = Centers + (cube.White[s-i-j][j+1]);

                Centers = Centers + (cube.Blue[j+1][i+j+1]);
                Centers = Centers + (cube.Blue[i+j+1][s-j]);
                Centers = Centers + (cube.Blue[s-j][s-i-j]);
                Centers = Centers + (cube.Blue[s-i-j][j+1]);

                Centers = Centers + (cube.Orange[j+1][i+j+1]);
                Centers = Centers + (cube.Orange[i+j+1][s-j]);
                Centers = Centers + (cube.Orange[s-j][s-i-j]);
                Centers = Centers + (cube.Orange[s-i-j][j+1]);

                Centers = Centers + (cube.Green[j+1][i+j+1]);
                Centers = Centers + (cube.Green[i+j+1][s-j]);
                Centers = Centers + (cube.Green[s-j][s-i-j]);
                Centers = Centers + (cube.Green[s-i-j][j+1]);

                Centers = Centers + (cube.Red[j+1][i+j+1]);
                Centers = Centers + (cube.Red[i+j+1][s-j]);
                Centers = Centers + (cube.Red[s-j][s-i-j]);
                Centers = Centers + (cube.Red[s-i-j][j+1]);

                Centers = Centers + (cube.Yellow[j+1][i+j+1]);
                Centers = Centers + (cube.Yellow[i+j+1][s-j]);
                Centers = Centers + (cube.Yellow[s-j][s-i-j]);
                Centers = Centers + (cube.Yellow[s-i-j][j+1]);
                
                string CenterSolution = SolveCenter(Centers);

                int len_centers = CenterSolution.size();
                if(len_centers%2 == 1) CenterSolution.push_back('A');

                m = 0;
                while(m<len_centers)
                {
                    Alg = return_3S_center_alg(CenterSolution[m],CenterSolution[m+1],size,j+1,i+j+1);
                    myfile << Alg << "\n";
                    m = m+2;
                }

                myfile << "\n";

                if(k == charg*5000)
                {
                    cout << k*100/NumberOfCentersType(size) << " %\n";
                    charg++;
                }

                k++;
            }
            x = x-2;
        }

        if(size%2 == 0)
        {
            // Wings

            int lim;
            
            m = 0; lim = size/2-1;
            k = 1;

            while(m<lim)
            {
                myfile << "// Wing de type " + to_string(k) << "\n\n";

                Wings = "";

                int a = size/2+m;
                int b = (size-1)/2-m;
                int c = size-1;

                Wings = Wings + EdgeToLetter(cube.White[0][a],cube.Green[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[a][c],cube.Orange[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[c][b],cube.Blue[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[b][0],cube.Red[0][b]);

                Wings = Wings + EdgeToLetter(cube.Blue[0][a],cube.White[c][a]);
                Wings = Wings + EdgeToLetter(cube.Blue[a][c],cube.Orange[a][0]);
                Wings = Wings + EdgeToLetter(cube.Blue[c][b],cube.Yellow[0][b]);
                Wings = Wings + EdgeToLetter(cube.Blue[b][0],cube.Red[b][c]);

                Wings = Wings + EdgeToLetter(cube.Orange[0][a],cube.White[b][c]);
                Wings = Wings + EdgeToLetter(cube.Orange[a][c],cube.Green[a][0]);
                Wings = Wings + EdgeToLetter(cube.Orange[c][b],cube.Yellow[b][c]);
                Wings = Wings + EdgeToLetter(cube.Orange[b][0],cube.Blue[b][c]);

                Wings = Wings + EdgeToLetter(cube.Green[0][a],cube.White[0][b]);
                Wings = Wings + EdgeToLetter(cube.Green[a][c],cube.Red[a][0]);
                Wings = Wings + EdgeToLetter(cube.Green[c][b],cube.Yellow[c][a]);
                Wings = Wings + EdgeToLetter(cube.Green[b][0],cube.Orange[b][c]);

                Wings = Wings + EdgeToLetter(cube.Red[0][a],cube.White[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[a][c],cube.Blue[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[c][b],cube.Yellow[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[b][0],cube.Green[b][c]);

                Wings = Wings + EdgeToLetter(cube.Yellow[0][a],cube.Blue[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[a][c],cube.Orange[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[c][b],cube.Green[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[b][0],cube.Red[c][a]); 

                string WingSolution = SolveWing(Wings);
                string tmp_wings = WingSolution;
                int len_wings = WingSolution.size();

                if(WingSolution.size()%2 == 1) WingSolution.push_back('E');
            
                for(i=0;i<WingSolution.size()/2;i++)
                {
                    Alg = return_3S_wing_alg(WingSolution[2*i],WingSolution[2*i+1],m,cube.size_cube);
                    myfile << Alg << "\n";
                }

                if(tmp_wings.length()%2 == 1)
                {
                    Alg = return_wing_parity(cube.size_cube,m);
                    myfile << Alg << "\n";
                }

                myfile << "\n";

                m++;
                k++;
            }
        }

        if(size%2 == 1)
        {
            // Wings

            int lim;
            
            m = 1; lim = size/2;
            k = 1;

            while(m<lim)
            {
                myfile << "// Wing de type " + to_string(k) << "\n\n";

                Wings = "";

                int a = size/2+m;
                int b = (size-1)/2-m;
                int c = size-1;

                Wings = Wings + EdgeToLetter(cube.White[0][a],cube.Green[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[a][c],cube.Orange[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[c][b],cube.Blue[0][b]);
                Wings = Wings + EdgeToLetter(cube.White[b][0],cube.Red[0][b]);

                Wings = Wings + EdgeToLetter(cube.Blue[0][a],cube.White[c][a]);
                Wings = Wings + EdgeToLetter(cube.Blue[a][c],cube.Orange[a][0]);
                Wings = Wings + EdgeToLetter(cube.Blue[c][b],cube.Yellow[0][b]);
                Wings = Wings + EdgeToLetter(cube.Blue[b][0],cube.Red[b][c]);

                Wings = Wings + EdgeToLetter(cube.Orange[0][a],cube.White[b][c]);
                Wings = Wings + EdgeToLetter(cube.Orange[a][c],cube.Green[a][0]);
                Wings = Wings + EdgeToLetter(cube.Orange[c][b],cube.Yellow[b][c]);
                Wings = Wings + EdgeToLetter(cube.Orange[b][0],cube.Blue[b][c]);

                Wings = Wings + EdgeToLetter(cube.Green[0][a],cube.White[0][b]);
                Wings = Wings + EdgeToLetter(cube.Green[a][c],cube.Red[a][0]);
                Wings = Wings + EdgeToLetter(cube.Green[c][b],cube.Yellow[c][a]);
                Wings = Wings + EdgeToLetter(cube.Green[b][0],cube.Orange[b][c]);

                Wings = Wings + EdgeToLetter(cube.Red[0][a],cube.White[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[a][c],cube.Blue[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[c][b],cube.Yellow[a][0]);
                Wings = Wings + EdgeToLetter(cube.Red[b][0],cube.Green[b][c]);

                Wings = Wings + EdgeToLetter(cube.Yellow[0][a],cube.Blue[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[a][c],cube.Orange[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[c][b],cube.Green[c][a]);
                Wings = Wings + EdgeToLetter(cube.Yellow[b][0],cube.Red[c][a]); 

                string WingSolution = SolveWing(Wings);
                string tmp_wings = WingSolution;
                int len_wings = WingSolution.size();

                if(WingSolution.size()%2 == 1) WingSolution.push_back('E');
            
                for(int i=0;i<WingSolution.size()/2;i++)
                {
                    Alg = return_3S_wing_alg(WingSolution[2*i],WingSolution[2*i+1],m,cube.size_cube);
                    myfile << Alg << "\n";
                }

                if(tmp_wings.length()%2 == 1)
                {
                    Alg = return_wing_parity(cube.size_cube,m);
                    myfile << Alg << "\n";
                }

                myfile << "\n";

                m++;
                k++;
            }

            // Midges

            myfile << "// Midges\n\n";
  
            Edges = "";

            int mid = size/2;

            Edges = Edges + EdgeToLetter(cube.White[0][mid],cube.Green[0][mid]);
            Edges = Edges + EdgeToLetter(cube.White[mid][size-1],cube.Orange[0][mid]);
            Edges = Edges + EdgeToLetter(cube.White[size-1][mid],cube.Blue[0][mid]);
            Edges = Edges + EdgeToLetter(cube.White[mid][0],cube.Red[0][mid]);

            Edges = Edges + EdgeToLetter(cube.Blue[0][mid],cube.White[size-1][mid]);
            Edges = Edges + EdgeToLetter(cube.Blue[mid][size-1],cube.Orange[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Blue[size-1][mid],cube.Yellow[0][mid]);
            Edges = Edges + EdgeToLetter(cube.Blue[mid][0],cube.Red[mid][size-1]);

            Edges = Edges + EdgeToLetter(cube.Orange[0][mid],cube.White[mid][size-1]);
            Edges = Edges + EdgeToLetter(cube.Orange[mid][size-1],cube.Green[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Orange[size-1][mid],cube.Yellow[mid][size-1]);
            Edges = Edges + EdgeToLetter(cube.Orange[mid][0],cube.Blue[mid][size-1]);

            Edges = Edges + EdgeToLetter(cube.Green[0][mid],cube.White[0][mid]);
            Edges = Edges + EdgeToLetter(cube.Green[mid][size-1],cube.Red[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Green[size-1][mid],cube.Yellow[size-1][mid]);
            Edges = Edges + EdgeToLetter(cube.Green[mid][0],cube.Orange[mid][size-1]);

            Edges = Edges + EdgeToLetter(cube.Red[0][mid],cube.White[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Red[mid][size-1],cube.Blue[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Red[size-1][mid],cube.Yellow[mid][0]);
            Edges = Edges + EdgeToLetter(cube.Red[mid][0],cube.Green[mid][size-1]);

            Edges = Edges + EdgeToLetter(cube.Yellow[0][mid],cube.Blue[size-1][mid]);
            Edges = Edges + EdgeToLetter(cube.Yellow[mid][size-1],cube.Orange[size-1][mid]);
            Edges = Edges + EdgeToLetter(cube.Yellow[size-1][mid],cube.Green[size-1][mid]);
            Edges = Edges + EdgeToLetter(cube.Yellow[mid][0],cube.Red[size-1][mid]); 


            string EdgeSolution = SolveEdge(Edges);
            int len_edges = EdgeSolution.size();
            string tmp_edges = EdgeSolution;
            tmp_edges.push_back('Z');

            i = 0;

            while(i<len_edges)
            {
                Alg = return_BHE_alg(tmp_edges[i],tmp_edges[i+1]);
                if(Alg.length() > 0 && i+1<len_edges)
                {
                    myfile << Alg << "\n";
                    i = i+2;
                }
                else
                {
                    Alg = return_single_edge_alg(tmp_edges[i]);
                    myfile << Alg << "\n";
                    i++;
                }
            }

            if(EdgeSolution.length()%2 == 1)
            {
                Alg = return_edge_parity();
                myfile << Alg << "\n";
            }

            myfile << "\n\n";
        }

        //Coins
        
        myfile << "// Coins\n\n";

        Corners = "";

        Corners = Corners + CornerToLetter(cube.White[0][0],cube.Red[0][0]);
        Corners = Corners + CornerToLetter(cube.White[0][size-1],cube.Green[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][size-1],cube.Orange[0][0]);
        Corners = Corners + CornerToLetter(cube.White[size-1][0],cube.Blue[0][0]);

        Corners = Corners + CornerToLetter(cube.Blue[0][0],cube.Red[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[0][size-1],cube.White[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][size-1],cube.Orange[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Blue[size-1][0],cube.Yellow[0][0]);

        Corners = Corners + CornerToLetter(cube.Orange[0][0],cube.Blue[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[0][size-1],cube.White[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][size-1],cube.Green[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Orange[size-1][0],cube.Yellow[0][size-1]);

        Corners = Corners + CornerToLetter(cube.Green[0][0],cube.Orange[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Green[0][size-1],cube.White[0][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][size-1],cube.Red[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Green[size-1][0],cube.Yellow[size-1][size-1]);

        Corners = Corners + CornerToLetter(cube.Red[0][0],cube.Green[0][size-1]);
        Corners = Corners + CornerToLetter(cube.Red[0][size-1],cube.White[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][size-1],cube.Blue[size-1][0]);
        Corners = Corners + CornerToLetter(cube.Red[size-1][0],cube.Yellow[size-1][0]);

        Corners = Corners + CornerToLetter(cube.Yellow[0][0],cube.Red[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[0][size-1],cube.Blue[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][size-1],cube.Orange[size-1][size-1]);
        Corners = Corners + CornerToLetter(cube.Yellow[size-1][0],cube.Green[size-1][size-1]);

        string CornerSolution = SolveCorner(Corners);

        int len_corners = CornerSolution.size();
        string tmp_corners = CornerSolution; 
        tmp_corners.push_back('A');

        i = 0;
        while(i<len_corners)
        {
            Alg = return_BHC_alg(tmp_corners[i],tmp_corners[i+1]);
            if(Alg.length() > 0 && i+1<len_corners)
            {
                myfile << Alg << "\n";
                i = i+2;
            }
            else
            {
                Alg = return_single_corner_alg(tmp_corners[i]);
                myfile << Alg << "\n";
                i++;
            }
        }

        if(CornerSolution.length()%2 == 1 && size >= 4)
        {
            Alg = return_corner_parity(cube.size_cube);
            myfile << Alg << "\n";
        }
    }
}

