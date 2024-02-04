#include "testlib.h"
#include <climits>
#include <cassert>
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
  assert(argc > 1);
  int n = atoi(argv[1]);
  int m = 100000;
	cout << n << ' ' << m << '\n';
  map<int, int> mp;
  int deck[2] = {rnd.next(1, n), rnd.next(1, n)};
  for(int i = 0; i < m; i++) {
    int op = 1;
    if(i > m / 2) op = rnd.next(1, 2);
    if(op == 1) {
      int idx = deck[rnd.next(0, 1)];
      mp[idx]++;
      int val = rnd.next(1, 1000000000);
      cout << op << ' ' << idx << ' ' << val;
    }
    else if(op == 2) {
      auto it = mp.lower_bound(deck[rnd.next(0, 1)]);
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
