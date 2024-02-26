
/*
Copyright (c) 2023 Student Name

Adapted from original work by (c) 2023 Prof.  Jagadeesh Vasudevamurthy
*/


/*----------------------------------------------------------------
This file has intmatrix2 class definition
-----------------------------------------------------------------*/


#include "intmatrix2.h"


/*----------------------------------------------------------------
Definition of routines of intmatrix2 class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Space allocation of static must be in CPP file
-----------------------------------------------------------------*/

bool intmatrix2::_show = false ;

void intmatrix2::_release(){
  //do nothing
}

void intmatrix2::_alloc(){
  if(_r && _c){
    for(int i=0; i< _r;++i){
      vector<int> t(_c);
      _m.push_back(t);
    }
     _set(_v);
  }
}

void intmatrix2::_copy(const intmatrix2& r){
  if(r._r && r._c){
    _r = r._r;
    _c =r._c;
    _v = r._v;
    _alloc();
    for(int i =0; i< _r; ++i){
      for(int j =0; i< _c;++j){
        _m[i][j] = r._m[i][j];
      }
    }
  }
}

void intmatrix2::_alloc(const char* s) {
  int i= 0; //Running index 
  int j = 0; 
  int k = 0; 
  int no = 0;

  int num_col = 0;
  int num_row = 0;
  int t[1024] = { 0 };
  int tindex = 0;
  bool failed = false;
  char ch = 'a' ;
  do {  
    ch= s[i++]; 
    if ((ch == ' ') && (j == 0)) {
      //do nothing
    } else if (ch== '\0' || ch == '|' || ch == ' ') {
    if (j) {
      ++k; //Num of element in a row 
      t[tindex++] = no; 
      j = 0; 
    }
    no = 0; 
    if (ch== '\0' || ch == '|') {
      ++num_row; 
      if (num_col) { 
        if (num_col != k) { 
          failed= true; 
          break; 
        }
      }else{
        num_col = k;
      }
      k = 0;
    }
  } else if (ch >= '0' && ch <= '9'){
    no = 10 * no + (ch - '0');
    ++j;
  } else{
    failed = true;
    break;
  }
  } while(ch != '\0');

  if(!failed && num_row && num_col ){
    assert(tindex == num_row * num_col);
    _r = num_row;
    _c = num_col;
    _v = 0;
    _alloc();
    int i = 0;
    for( int r = 0; r< _r ;++r){
      for( int c= 0; c< _c;++c){
        _m[r][c] = t[i++];
      }
    }
    assert( i == tindex);
  }
}


intmatrix2 intmatrix2::add(const intmatrix2& b) const {
  intmatrix2 sum;
  const intmatrix2& a = *(this);
  if(a._r == b._r && a._c == b._c){
    sum._r = a._r;
    sum._c = a._c;
    sum._v = 0;
    sum.alloc();
    for(int r=0; r<_r; r++) {
      for(int c=0; c<_c; c++) {
        sum._m[r][c] = a._m[r][c] + b._m[r][c];
      }
    } 
  }
  return sum;
}

// add clear() functions


intmatrix2 intmatrix2::mult(const intmatrix2& b) const {

  intmatrix2 prod;

  const intmatrix2& a = *(this);
  if(a && other) {
    if(a._c == b._r){
      prod._r = a._r;
      prod._c = a._c;
      prod._v = b._c;
      prod._alloc();
      for( int i =0; i< a._r; i++){
        for(int j = 0; j<b._c;++j){
          prod._m[i][j] = 0;
          for( int k =0; k<a._c;++k){
            prod._m[i][j] = prod._m[i][j] + (a._m[i][k] * b._m[k][j]);
          }
        }
      }
    }else if(a._r == 1 && a._c == 1){
      prod._r = b._r;
      prod._c = b._c;
      prod._v = 0;
      prod._alloc();
      int v = a._m[0][0];
      for(int j = 0; j<b._r;++j){
          for( int k =0; k<b._c;++k){
            prod._m[j][k] = (v * b._m[j][k]);
          }
        }
    }else if(b._r == 1 && b._c == 1){
      prod._r = a._r;
      prod._c = a._c;
      prod._v = 0;
      prod._alloc();
      int v = b._m[0][0];
      for(int j = 0; j<a._r;++j){
          for( int k =0; k<a._c;++k){
            prod._m[j][k] = (v * a._m[j][k]);
          }
        }
    }
  }
  return prod;

}


void intmatrix2::_set(int v){
  for(int i=0; i< _r ; ++i){
    for(int j =0; j< _c; ++j){
      _m[i][j] = v;
    }
  }
}

ostream& operator<<(ostream& o, const intmatrix2& m) {
  // Implementation
  if(!m){
    o <<" Empty Matrix   \n";
  }else{
    for(int i=0; i<m._r; ++i) {
      for(int j=0; j<m._c; ++j) {
        o << m._m[i][j] << " ";
      }
      o << endl;
    }
  }
  return o;
}

bool intmatrix2::isEqual(const intmatrix2& other) const {
  // Compare this and other matrix
  // Return true if equal, false otherwise
  if(_r == 0._r && _c == o._c){
    for( int i =0; i< _r ; ++i){
      for(int j =0; j<_c;++j){
        if(_m[i][j] != o._m[i][j]){
          return false;
        }
      }
    }
    return true;
  } 
  return false;
}


//EOF

