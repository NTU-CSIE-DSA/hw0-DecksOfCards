#include "testlib.h"
#include <assert.h>
using namespace std;

int main() {
  registerValidation();
  int n = inf.readInt(1, 100000);
  inf.readSpace();
  int m = inf.readInt(1, 100000);
  inf.readEoln();
  vector<int> sz(n + 1);
  for(int i = 0; i < m; i++){
    int op = inf.readInt(1, 3);
    if(op == 1) {
      inf.readSpace();
      int idx = inf.readInt(1, n);
      inf.readSpace();
      inf.readInt(1, 1000000000);
      sz[idx]++;
    }
    if(op == 2) {
      inf.readSpace();
      int idx = inf.readInt(1, n);
      assert(sz[idx] > 0);
    }
    if(op == 3) {
      inf.readSpace();
      int idx1 = inf.readInt(1, n);
      inf.readSpace();
      int idx2 = inf.readInt(1, n);
      assert(idx1 != idx2);
      sz[idx2] += sz[idx1];
      sz[idx1] = 0;
    }
    if(op == 4) {
      inf.readSpace();
      int idx1 = inf.readInt(1, n);
      inf.readSpace();
      int idx2 = inf.readInt(1, n);
      assert(idx1 != idx2);
      sz[idx2] += sz[idx1];
      sz[idx1] = 0;
    }
    inf.readEoln();
  }
  inf.readEof();
  return 0;
}
