#ifndef RUBIK_H_
#define RUBIK_H_

using Face = char**;
using namespace std;
#include <string>
#include <vector>


class Move
{
public:
  string m;

  Move(string m);
  bool is_wide();
  int NumberOfTurns();
  int nb_w();
  char ext_sgl_move();
  string return_move();
  void print_move();
};

class Cube
{
public:
  int size_cube;

  Face White;
  Face Blue;
  Face Orange;
  Face Green;
  Face Red;
  Face Yellow;

  Cube(int size);
  Cube();
  ~Cube();
  Cube(const Cube& c1);
  Cube& operator=(const Cube& c);

  void print_face(Face f);
  void print_cube();

  void swap_own(Face &f, int nb_t);
  void U(int slice, int nb_t);
  void D(int slice, int nb_t);
  void R(int slice, int nb_t);
  void L(int slice, int nb_t);
  void F(int slice, int nb_t);
  void B(int slice, int nb_t);

  void Uw(int slice, int nb_t);
  void Dw(int slice, int nb_t);
  void Rw(int slice, int nb_t);
  void Lw(int slice, int nb_t);
  void Fw(int slice, int nb_t);
  void Bw(int slice, int nb_t);

  void x(int nb_t);
  void y(int nb_t);
  void z(int nb_t);

  void apply_move(Move m);
  void apply_alg(string Algorithm);

  bool is_solved();
  //void good_orientation();
  //string find_best_orient();
  //void best_orientation();
  //int nb_centers_solved();
};

int NumberOfCentersType(int);
vector<string> split(string scr);

void AutomaticScramble(Cube& cube, int size);
string GenerateScramble(int size);

#endif