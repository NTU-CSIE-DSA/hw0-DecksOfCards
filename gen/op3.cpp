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
  vector<int> deck = rnd.perm(n, 1);
  for(int i = 0; i < m; i++) {
    int op = 1;
    if(i > m / 2) op = 3;
    if(op == 1) {
      int idx = deck[(2 * i + 1) % n];
      mp[idx]++;
      int val = rnd.next(1, 1000000000);
      cout << op << ' ' << idx << ' ' << val;
    }
    else if(op == 3) {
      int idx1 = deck[(i - 1 - m / 2) % n];
      int idx2 = deck[(i - m / 2) % n];
      mp[idx2] += mp[idx1];
      mp[idx1] = 0;
      mp.erase(idx1);
      cout << op << ' ' << idx1 << ' ' << idx2;
    }
    cout << '\n';
  }
	return 0;
}
