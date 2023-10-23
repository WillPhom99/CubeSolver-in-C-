#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>

#include "Rubik.h"
#include "Solve.h"
#include "Solution.h"

using namespace std::chrono;
using namespace std;

int main()
{
    int size_rubik = 16;
    Cube c(size_rubik);
    cout << "Cube initialised\n";

    auto start = high_resolution_clock::now();

    {
        //AutomaticScramble(c, size_rubik);

        //string scr = "R Lw B' Uw Fw F2 B2 3Uw2 U Bw Rw2 Uw2 3Uw2 Rw' F' Dw U' Fw Dw' 3Fw2 Bw' L2 U2 3Rw Rw 3Uw 3Fw' F2 Uw Lw Bw Fw2 3Rw Rw L' Uw2 D' U' F Lw L' B' Bw' F2 U' D2 3Rw' D 3Rw' Uw2 Rw2 3Fw2 Rw2 U2 3Uw2 3Rw Lw' F2 Fw' Uw' Dw2 3Rw Uw' B2 U2 Rw' Bw R 3Uw Fw' 3Uw' B Rw2 L 3Rw D' Fw' Dw2 Rw Uw2";
        string scr = GenerateScramble(size_rubik);
        c.apply_alg(scr);
    }

    cout << "Cube scrambled\n";

    {
        print_solution(c);
        //solve_cube(c);
        //cout << solution_length(c) << " moves" << endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start)/1000000;
    cout << "Time taken by function : " << duration.count() << " sec" << endl;

}