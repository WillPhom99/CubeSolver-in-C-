#ifndef SOLVE_H_
#define SOLVE_H_

using namespace std;
#include <vector>
#include <string>

// Centers

vector<string> LetterCentersAvailable(string);
bool AllCenterSolved(string CentersList);
int NextColorAfterCycleBreak(vector<string> ListOfUnsolvedCenters, int ColorCenter);
string SolveCenter(string CentersList);

// Corners

char CornerToLetter(char Corner1,char Corner2);
char AdjacentCornerLetter(char CornerLetter);
void swap_corners(string& CornersList);
bool AllCornersSolvedExceptTwist(string CornersList);
bool AllCornersSolved(string CornersList);
int UnsolvedCorner(string CornersList);
int TwistedCorner(string CornersList);
string SolveCorner(string CornersList);

// Edges

char EdgeToLetter(char Edge1,char Edge2);
char AdjacentCornerLetter(char EdgeLetter);
void swap_edges(string& EdgesList);
bool AllEdgesSolvedExceptFlip(string EdgesList);
bool AllEdgesSolved(string EdgesList);
int UnsolvedEdge(string EdgesList);
int FlippedEdge(string EdgesList);
string SolveEdge(string EdgesList);

// Wings 

bool AllWingSolved(string WingsList);
int UnsolvedWing(string WingsList);
string SolveWing(string WingsList);

#endif