#include "testlib.h"
#include <climits>
#include <cassert>
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
  assert(argc > 4);
	int nl = atoi(argv[1]), nr = atoi(argv[2]);
	int ml = atoi(argv[3]), mr = atoi(argv[4]);
  int n = rnd.next(nl, nr);
  int m = rnd.next(ml, mr);
	cout << n << ' ' << m << '\n';
  map<int, int> mp;
  for(int i = 0; i < m; i++) {
    int op = rnd.next(1, 3);
    if(n == 1 && op > 2) {
      op = rnd.next(1, 2);
    }
    if(mp.size() == 0) {
      op = 1;
    }
    if(op == 1) {
      int idx = rnd.next(1, n);
      if(mp.size() == 0) {
        int type = rnd.next(0, 2);
        if(type == 0) {
          idx = 1;
        }
        else if(type == 1) {
          idx = n;
        }
      }
      mp[idx]++;
      int val = rnd.next(1, 1000000000);
      cout << op << ' ' << idx << ' ' << val;
    }
    else if(op == 2) {
      auto it = mp.lower_bound(rnd.next(1, n));
      if(it == mp.end()) it = mp.begin();
      int idx = (*it).first;
      mp[idx]--;
      if(mp[idx] == 0) {
        mp.erase(idx);
      }
      cout << op << ' ' << idx;
    }
    else if(op == 3) {
      auto it = mp.lower_bound(rnd.next(1, n));
      if(it == mp.end()) it = mp.begin();
      int idx1 = (*it).first;
      int idx2 = rnd.next(1, n);
      while(idx2 == idx1) {
        idx2 = rnd.next(1, n);
      }
      if(rnd.next(1, 2) == 1) swap(idx1, idx2);
      mp[idx2] += mp[idx1];
      mp[idx1] = 0;
      mp.erase(idx1);
      cout << op << ' ' << idx1 << ' ' << idx2;
    }
    cout << '\n';
  }
	return 0;
}
