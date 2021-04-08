#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  int m = atoi(argv[2]);
  int mx = atoi(argv[3]);
  int eps = atoi(argv[4]);
  vector<int> d(n + 1);
  assert(m >= n);
  printf("%d %d\n", n, m);
  d[1] = 0;
  for (int i = 2; i <= n; ++i) {
    d[i] = d[i - 1] + rng() % mx + 1;
  }
  int x = d[n] + rng() % mx + 1;
  auto segsum = [&](int s, int t) {
    if (s < t) return d[t] - d[s];
    return d[t] - d[s] + x;
  };
  bool vis[505][3] = {};
  for (int i = 1; i <= n; ++i) {
    int type = 2, s = i, t = (i % n + 1) % n + 1, l = segsum(s, t);
    l += rng() % (min((int)1e9 + 1 - l, eps));
    printf("%d %d %d %d\n", type, s, t, l);
  }
  for (int i = 1; i <= m - n; ++i) {
    int type, s, t, l;
    do {
      type = 1;
      s = rng() % n + 1;
      t = s % n + 1;
      t = t % n + 1;
      l = segsum(s, t);
    } while (vis[s][type] || s == t || l > 1e9);
    vis[s][type] = true;
    if (type == 1) l -= rng() % (min(l, eps));
    else l += rng() % (min((int)1e9 + 1 - l, eps));
    printf("%d %d %d %d\n", type, s, t, l);
  }
}
