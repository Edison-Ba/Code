#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int t, n, m;
bool la = 0;
int main() {
  cin >> t;
  for (int T = 1; T <= t; T++) {
    cin >> m >> n;
    if (m < n) {
      swap(m, n);
    }
    if (n * 2 < m) {
      cout << m * m << endl;
    } else {
      cout << 4 * n * n << endl;
    }
  }
  return 0;
}
