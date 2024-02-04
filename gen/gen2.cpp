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
    int op = rnd.next(1, 2);
    if(mp.size() == 0) {
      op = 1;
    }
    if(op == 1) {
      int idx = rnd.next(1, n);
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
    cout << '\n';
  }
	return 0;
}
