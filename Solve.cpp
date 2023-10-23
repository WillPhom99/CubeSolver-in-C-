using namespace std;
#include <iostream>
#include <string>
#include "Solve.h"
#include <vector>

// Centers

void print_s(vector<string> t)
{
    int i;
    for(i=0;i<6;i++)
    {
        cout << t[i] << ' ';
    }
    cout << endl;
}

vector<string> LetterCentersAvailable(string CentersList)
{
    vector<string> ListOfUnsolvedCenters;
    for(int i=0;i<6;i++)
    {
        string UnsolvedCenterColor = "";
        for(int j=0;j<4;j++)
        {
            if(CentersList[i*4+j] != char(i+48) && i*4+j != 1) UnsolvedCenterColor = UnsolvedCenterColor+char(i*4+j+65);
        }  
        ListOfUnsolvedCenters.push_back(UnsolvedCenterColor);
    }

    ListOfUnsolvedCenters[0] = 'B'+ListOfUnsolvedCenters[0];

    return ListOfUnsolvedCenters;  
}

bool AllCenterSolved(string CentersList)
{
    if(CentersList != "000011112222333344445555") return false;
    return true;
}

int NextColorAfterCycleBreak(vector<string> ListOfUnsolvedCenters, int ColorCenter)
{
    if(ListOfUnsolvedCenters[1] != "" && ColorCenter != 1) return 1;
    if(ListOfUnsolvedCenters[2] != "" && ColorCenter != 2) return 2;
    if(ListOfUnsolvedCenters[3] != "" && ColorCenter != 3) return 3;
    if(ListOfUnsolvedCenters[4] != "" && ColorCenter != 4) return 4;
    else return 5;
}


string SolveCenter(string CentersList)
{
    vector<string> ListOfUnsolvedCenters = LetterCentersAvailable(CentersList);
    string CenterSolution = "";
    int ColorBeforeCycleBreak,CenterColorOnBuffer;
    bool WhiteCenterAlreadySolved = true;
    char buffer, LetterSolution;

    if(CentersList.substr(0,4) != "0000")
    {
        do
        {
            CenterColorOnBuffer = int(CentersList[1]-48);
            LetterSolution = ListOfUnsolvedCenters[CenterColorOnBuffer].back();
            CenterSolution = CenterSolution + LetterSolution;
            ListOfUnsolvedCenters[CenterColorOnBuffer].pop_back();
            swap(CentersList[1],CentersList[int(LetterSolution)-65]);
            WhiteCenterAlreadySolved = false;
        }while(CentersList.substr(0,4) != "0000");
    }

    if(AllCenterSolved(CentersList)) 
    {
        return CenterSolution;
    }

    else 
    {
        if(!WhiteCenterAlreadySolved) ColorBeforeCycleBreak = CenterColorOnBuffer;
        else ColorBeforeCycleBreak = 0;
        do
        {
            buffer = ListOfUnsolvedCenters[NextColorAfterCycleBreak(ListOfUnsolvedCenters,ColorBeforeCycleBreak)].back();
            CenterSolution = CenterSolution + buffer;
            swap(CentersList[1],CentersList[int(buffer)-65]);
            do
            {
                CenterColorOnBuffer = int(CentersList[1]-48);
                LetterSolution = ListOfUnsolvedCenters[CenterColorOnBuffer].back();
                CenterSolution = CenterSolution + LetterSolution;
                ListOfUnsolvedCenters[CenterColorOnBuffer].pop_back();
                ColorBeforeCycleBreak = int(CentersList[1]-48);
                swap(CentersList[1],CentersList[int(LetterSolution)-65]);
            } while (CentersList[1] != '0');
            
        } while (!AllCenterSolved(CentersList));  
    }

    return CenterSolution;
}


// Corners

char CornerToLetter(char Corner1, char Corner2)
{
    if(Corner1 == '0')
    {
        if(Corner2 == '4') return 'A';
        else if(Corner2 == '3') return 'B';
        else if(Corner2 == '2') return 'C';
        else if(Corner2 == '1') return 'D';

    }
    
    else if(Corner1 == '1')
    {
        if(Corner2 == '4') return 'E';
        else if(Corner2 == '0') return 'F';
        else if(Corner2 == '2') return 'G';
        else if(Corner2 == '5') return 'H';
    }
    

    else if(Corner1 == '2')
    {
        if(Corner2 == '1') return 'I';
        else if(Corner2 == '0') return 'J';
        else if(Corner2 == '3') return 'K';
        else if(Corner2 == '5') return 'L';
    }
    

    else if(Corner1 == '3')
    {
        if(Corner2 == '2') return 'M';
        else if(Corner2 == '0') return 'N';
        else if(Corner2 == '4') return 'O';
        else if(Corner2 == '5') return 'P';
    }
    

    else if(Corner1 == '4')
    {
        if(Corner2 == '3') return 'Q';
        else if(Corner2 == '0') return 'R';
        else if(Corner2 == '1') return 'S';
        else if(Corner2 == '5') return 'T';
    }
    

    else if(Corner1 == '5')
    {
        if(Corner2 == '4') return 'U';
        else if(Corner2 == '1') return 'V';
        else if(Corner2 == '2') return 'W';
        else if(Corner2 == '3') return 'X';
    }
    
}

char AdjacentCornerLetter(char CornerLetter)
{
    if(CornerLetter == 'A') return 'Q';
    if(CornerLetter == 'B') return 'M';
    if(CornerLetter == 'C') return 'I';
    if(CornerLetter == 'D') return 'E';
    
    if(CornerLetter == 'E') return 'R';
    if(CornerLetter == 'F') return 'C';
    if(CornerLetter == 'G') return 'L';
    if(CornerLetter == 'H') return 'U';
    
    if(CornerLetter == 'I') return 'F';
    if(CornerLetter == 'J') return 'B';
    if(CornerLetter == 'K') return 'P';
    if(CornerLetter == 'L') return 'V';
    
    if(CornerLetter == 'M') return 'J';
    if(CornerLetter == 'N') return 'A';
    if(CornerLetter == 'O') return 'T';
    if(CornerLetter == 'P') return 'W';
    
    if(CornerLetter == 'Q') return 'N';
    if(CornerLetter == 'R') return 'D';
    if(CornerLetter == 'S') return 'H';
    if(CornerLetter == 'T') return 'X';
    
    if(CornerLetter == 'U') return 'S';
    if(CornerLetter == 'V') return 'G';
    if(CornerLetter == 'W') return 'K';
    if(CornerLetter == 'X') return 'O';
    
    else return 'Z';
}

void swap_corners(string& CornersList)
{
    int buffer = (int)CornersList[0] - 65;
    int AdjClockWiseBuffer = (int)AdjacentCornerLetter(CornersList[0]) - 65;
    int AdjCounterClockWiseBuffer = (int)AdjacentCornerLetter(AdjacentCornerLetter(CornersList[0])) - 65;
    
    swap(CornersList[0],CornersList[buffer]);
    swap(CornersList[16],CornersList[AdjClockWiseBuffer]);
    swap(CornersList[13],CornersList[AdjCounterClockWiseBuffer]);
}

bool AllCornersSolvedExceptTwist(string CornersList)
{
    for(int i=0;i<24;i++)
    {
        int buffer = (int)CornersList[i] - 65;
        int AdjClockWiseBuffer = (int)AdjacentCornerLetter(CornersList[i]) - 65;
        int AdjCounterClockWiseBuffer = (int)AdjacentCornerLetter(AdjacentCornerLetter(CornersList[i])) - 65;

        if(buffer != i && AdjClockWiseBuffer != i && AdjCounterClockWiseBuffer != i)
            return false;
    }

    return true;
}

bool AllCornersSolved(string CornersList)
{
    for(int i=0;i<24;i++)
    {
        int buffer = (int)CornersList[i] - 65;
        if(buffer != i)
            return false;
    }
    return true;
}

int UnsolvedCorner(string CornersList)
{
    for(int i=0;i<24;i++)
    {
        int buffer = (int)CornersList[i] - 65;
        int AdjClockWiseBuffer = (int)AdjacentCornerLetter(CornersList[i]) - 65;
        int AdjCounterClockWiseBuffer = (int)AdjacentCornerLetter(AdjacentCornerLetter(CornersList[i])) - 65;
        if(i != buffer && i != AdjClockWiseBuffer && i != AdjCounterClockWiseBuffer && i != 0  && i != 13  && i != 16)
            return i;
    }
    
    return -1;
}

int TwistedCorner(string CornersList)
{
    for(int i=0;i<24;i++)
    {
        int buffer = (int)CornersList[i] - 65;
        int AdjClockWiseBuffer = (int)AdjacentCornerLetter(CornersList[i]) - 65;
        int AdjCounterClockWiseBuffer = (int)AdjacentCornerLetter(AdjacentCornerLetter(CornersList[i])) - 65;
        if((i == AdjClockWiseBuffer || i == AdjCounterClockWiseBuffer) && i != 0  && i != 13  && i != 16)
            return i;
    }
    
    return -1;
}

string SolveCorner(string CornersList)
{
    string CornerSolution;
    while(CornersList[0] != 'A' && CornersList[0] != 'N' && CornersList[0] != 'Q')
    {
        CornerSolution = CornerSolution + CornersList[0];
        swap_corners(CornersList);
    }
    
    if(AllCornersSolved(CornersList)) return CornerSolution;
    
    if(!AllCornersSolvedExceptTwist(CornersList))
    {
        while(!AllCornersSolvedExceptTwist(CornersList))
        {
            int buffer = UnsolvedCorner(CornersList);
            int AdjClockWiseBuffer = (int)AdjacentCornerLetter(buffer+65) - 65;
            int AdjCounterClockWiseBuffer = (int)AdjacentCornerLetter(AdjacentCornerLetter(buffer+65)) - 65;
            
            swap(CornersList[0],CornersList[buffer]);
            swap(CornersList[16],CornersList[AdjClockWiseBuffer]);
            swap(CornersList[13],CornersList[AdjCounterClockWiseBuffer]);
                
            CornerSolution = CornerSolution + char(buffer+65);
                
            while(CornersList[0] != 'A' && CornersList[0] != 'N' && CornersList[0] != 'Q')
            {
                CornerSolution = CornerSolution + CornersList[0];
                swap_corners(CornersList);
            }
        }
    }
    
    if(AllCornersSolved(CornersList)) return CornerSolution;
        
    while(!AllCornersSolved(CornersList))
    {
        int buffer = TwistedCorner(CornersList);
        int AdjClockWiseBuffer = (int)AdjacentCornerLetter(buffer+65) - 65;
        int AdjCounterClockWiseBuffer = (int)AdjacentCornerLetter(AdjacentCornerLetter(buffer+65)) - 65;
        
        swap(CornersList[0],CornersList[buffer]);
        swap(CornersList[16],CornersList[AdjClockWiseBuffer]);
        swap(CornersList[13],CornersList[AdjCounterClockWiseBuffer]);
        
        CornerSolution = CornerSolution + char(buffer+65);
        CornerSolution = CornerSolution + CornersList[0];
        swap_corners(CornersList);
    }
        
    return CornerSolution;
}

// Edges

char EdgeToLetter(char Edge1, char Edge2)
{
    if(Edge1 == '0')
    {
        if(Edge2 == '3') return 'A';
        else if(Edge2 == '2') return 'B';
        else if(Edge2 == '1') return 'C';
        else if(Edge2 == '4') return 'D';
    }
    

    else if(Edge1 == '1')
    {
        if(Edge2 == '0') return 'E';
        else if(Edge2 == '2') return 'F';
        else if(Edge2 == '5') return 'G';
        else if(Edge2 == '4') return 'H';
    }
   

    else if(Edge1 == '2')
    {
        if(Edge2 == '0') return 'I';
        else if(Edge2 == '3') return 'J';
        else if(Edge2 == '5') return 'K';
        else if(Edge2 == '1') return 'L';
    }
    

    else if(Edge1 == '3')
    {
        if(Edge2 == '0') return 'M';
        else if(Edge2 == '4') return 'N';
        else if(Edge2 == '5') return 'O';
        else if(Edge2 == '2') return 'P';
    }
    

    else if(Edge1 == '4')
    {
        if(Edge2 == '0') return 'Q';
        else if(Edge2 == '1') return 'R';
        else if(Edge2 == '5') return 'S';
        else if(Edge2 == '3') return 'T';
    }
    

    else if(Edge1 == '5')
    {
        if(Edge2 == '1') return 'U';
        else if(Edge2 == '2') return 'V';
        else if(Edge2 == '3') return 'W';
        else if(Edge2 == '4') return 'X';
    }
}

char AdjacentEdgeLetter(char EdgeLetter)
{
    if(EdgeLetter == 'A') return 'M';
    if(EdgeLetter == 'B') return 'I';
    if(EdgeLetter == 'C') return 'E';
    if(EdgeLetter == 'D') return 'Q';
    
    if(EdgeLetter == 'E') return 'C';
    if(EdgeLetter == 'F') return 'L';
    if(EdgeLetter == 'G') return 'U';
    if(EdgeLetter == 'H') return 'R';
    
    if(EdgeLetter == 'I') return 'B';
    if(EdgeLetter == 'J') return 'P';
    if(EdgeLetter == 'K') return 'V';
    if(EdgeLetter == 'L') return 'F';
    
    if(EdgeLetter == 'M') return 'A';
    if(EdgeLetter == 'N') return 'T';
    if(EdgeLetter == 'O') return 'W';
    if(EdgeLetter == 'P') return 'J';
    
    if(EdgeLetter == 'Q') return 'D';
    if(EdgeLetter == 'R') return 'H';
    if(EdgeLetter == 'S') return 'X';
    if(EdgeLetter == 'T') return 'N';
    
    if(EdgeLetter == 'U') return 'G';
    if(EdgeLetter == 'V') return 'K';
    if(EdgeLetter == 'W') return 'O';
    if(EdgeLetter == 'X') return 'S';
    
    else return 'Z';
}

void swap_edges(string& EdgesList)
{
    int buffer = (int)EdgesList[20] - 65;
    int AdjEdgeBuffer = (int)AdjacentEdgeLetter(EdgesList[20]) - 65;
    
    swap(EdgesList[20],EdgesList[buffer]);
    swap(EdgesList[6],EdgesList[AdjEdgeBuffer]);
}

bool AllEdgesSolvedExceptFlip(string EdgesList)
{
    for(int i=0;i<24;i++)
    {
        int buffer = (int)EdgesList[i] - 65;
        int AdjEdgeBuffer = (int)AdjacentEdgeLetter(EdgesList[i]) - 65;
        if(buffer != i && AdjEdgeBuffer != i)
            return false;
    }
    return true;
}

bool AllEdgesSolved(string EdgesList)
{
    for(int i=0;i<24;i++)
    {
        int buffer = (int)EdgesList[i] - 65;
        if(buffer != i)
            return false;
    }
    return true;
}

int UnsolvedEdge(string EdgesList)
{
    for(int i=0;i<24;i++)
    {
        int buffer = (int)EdgesList[i] - 65;
        int AdjEdgeBuffer = (int)AdjacentEdgeLetter(EdgesList[i]) - 65;
        if(i != buffer && i != AdjEdgeBuffer && i != 6  && i != 20)
            return i;
    }
    
    return -1;
}

int FlippedEdge(string EdgesList)
{
    for(int i=0;i<24;i++)
    {
        int buffer = (int)EdgesList[i] - 65;
        int AdjEdgeBuffer = (int)AdjacentEdgeLetter(EdgesList[i]) - 65;
        if(i == AdjEdgeBuffer && i != 6  && i != 20)
            return i;
    }
    
    return -1;
}

string SolveEdge(string EdgesList)
{
    string EdgeSolution;
    while(EdgesList[20] != 'U' && EdgesList[20] != 'G')
    {
        EdgeSolution = EdgeSolution + EdgesList[20];
        swap_edges(EdgesList);
    }
    
    if(AllEdgesSolved(EdgesList)) return EdgeSolution;
    
    if(!AllEdgesSolvedExceptFlip(EdgesList))      
    {
        while(!AllEdgesSolvedExceptFlip(EdgesList))
        {
            int buffer = UnsolvedEdge(EdgesList);
            int AdjEdgeBuffer = (int)AdjacentEdgeLetter(buffer+65) - 65;
            
            swap(EdgesList[20],EdgesList[buffer]);
            swap(EdgesList[6],EdgesList[AdjEdgeBuffer]);
                
            EdgeSolution = EdgeSolution + char(buffer+65);
                
            while(EdgesList[20] != 'U' && EdgesList[20] != 'G')
            {
                EdgeSolution = EdgeSolution + EdgesList[20];
                swap_edges(EdgesList);
            }
        }
    }
    
    if(AllEdgesSolved(EdgesList)) return EdgeSolution;
        
    while(!AllEdgesSolved(EdgesList))
    {
        int buffer = FlippedEdge(EdgesList);
        int AdjEdgeBuffer = (int)AdjacentEdgeLetter(buffer+65) - 65;
        
        swap(EdgesList[20],EdgesList[buffer]);
        swap(EdgesList[6],EdgesList[AdjEdgeBuffer]);
        
        EdgeSolution = EdgeSolution + char(buffer+65);
        EdgeSolution = EdgeSolution + EdgesList[20];
        swap_edges(EdgesList);
    }
        
    return EdgeSolution;
}


// Wings

bool AllWingSolved(string WingsList)
{
    int i;
    for(i=0;i<24;i++)
    {
        int buffer = (int)WingsList[i] - 65;
        if(buffer != i)
        {
            return false;
        }
    }
    return true;
}

int UnsolvedWing(string WingsList)
{
    int i;
    for(i=0;i<24;i++)
    {
        int buffer = (int)WingsList[i] - 65;
        if(buffer != i)
        {
            return i;
        }
    }
    return -1;
}

string SolveWing(string WingsList)
{
    string WingSolution;
    char buffer = WingsList[20];
    if(WingsList[20] != 'U')
    {
        do
        {
            WingSolution = WingSolution + WingsList[20];
            swap(WingsList[(int)buffer - 65],WingsList[20]);
            buffer = WingsList[20];
        } while (WingsList[20] != 'U');
    }
    if(AllWingSolved(WingsList)) return WingSolution;
    else
    {
        do
        {
            int buf = UnsolvedWing(WingsList);
            buffer = char(buf + 65);
            WingSolution = WingSolution + buffer;
            swap(WingsList[buf],WingsList[20]);
            do
            {
                WingSolution = WingSolution + WingsList[20];
                buffer = WingsList[20];
                swap(WingsList[(int)buffer - 65],WingsList[20]);
            } while (WingsList[20] != 'U');
        } while (!AllWingSolved(WingsList));
        
    }
    return WingSolution;
}