#ifndef ALGS_H_
#define ALGS_H_

#include <string>
#include <stack>
using namespace std;

// Centers

string alg(int i,int s,string c);
string alg2(int i,char c);
string return_3S_center_alg(char c1,char c2,int s,int i,int j);

// Corners

string return_single_corner_alg(char n);
string return_BHC_alg(char c1,char c2);
string return_corner_parity(int size);

// Edges

string return_single_edge_alg(char n);
string return_BHE_alg(char c1,char c2);
string return_edge_parity();

// Wings

stack<string> split_inv(string scr);
string invert(string scr);
string r2(int i);
string l2(int i);
string f2(int i);
string b2(int i);
string u2(int i);
string d2(int i);
string return_3S_wing_alg(char c1,char c2,int t,int size);
string return_wing_parity(int size, int i);

#endif