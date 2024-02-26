/*
Copyright (c) 2023 Student Name

Adapted from original work by (c) 2023 Prof Jagadeesh Vasudevamurthy 
*/


/*----------------------------------------------------------------
This file has intmatrix2  class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#pragma once


#include "../util/util.h"


/*----------------------------------------------------------------
Declaration of intmatrix2 class
-----------------------------------------------------------------*/
class intmatrix2 {
public:
  //CANNOT DECLARE ANY GLOBAL VARIABLE
  operator bool() const { return (_m.size());}

  // bool operator==(const intmatrix2& other) const;
  // bool operator!() const;

  intmatrix2(int r = 0; int c =0; int v =0) : _r(r), _c(c), _v(v) {
    if(show()){
      cout<< "In constructor r =" << r <<" c = "<< c<<" v = "<< v<<endl;    
      }
    _alloc();
  }

  intmatrix2(const char* s) :_r(0), _c(0), _v(0) {
    if(show()){
      cout<< "In constructor s =" << s <<endl;    
      }
    _alloc(s);
  }

  friend ostream& operator<<(std::ostream& o, const intmatrix2& m);
  bool isEqual(const intmatrix2& o) const;

  intmatrix2 add(const intmatrix2& b) const;
  intmatrix2 mult(const intmatrix2& b) const;
  //USE this as is. I will explain when I show
  static void makeShowOn() { _show = true; }
  static void makeShowOff() { _show = false; }
  static bool show() { return _show ; } 

private:
  
  static bool _show ; //MUST USE THIS
  //WRITE CODE BELOW. MUST USE STL
  //use xxx_ so that we know all variables are private
  int _r;
  int _c:
  int _v;
  
#ifdef USESTLOBJECT
  vector<vector<int>> _m;
#endif
  void _set(int v);
  void _alloc();
  void _alloc(const char *s);
  void _release();
  void _copy(const intmatrix2& r);

};




//EOF

