#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  int m = atoi(argv[2]);
  int mx = atoi(argv[3]);
  long long eps = atoi(argv[4]);
  vector<long long> d(n + 1);
  printf("%d %d\n", n, m);
  d[1] = 0;
  for (int i = 2; i <= n; ++i) {
    d[i] = d[i - 1] + rng() % mx + 1;
  }
  long long x = d[n] + rng() % mx + 1;
  auto segsum = [&](int s, int t) {
    if (s < t) return d[t] - d[s];
    return d[t] - d[s] + x;
  };
  for (int i = 1; i <= m; ++i) {
    int type = rng() % 2 + 1;
    int s, t;
    long long l;
    do {
      s = rng() % n + 1;
      t = rng() % n + 1;
      l = segsum(s, t);
    } while (s == t || l > 1e9);
    if (type == 1) l -= rng() % (min(l, eps));
    else l += rng() % (min((int)1e9 + 1 - l, eps));
    printf("%d %d %d %d\n", type, s, t, l);
  }
}
