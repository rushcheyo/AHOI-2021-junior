#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]), m = atoi(argv[2]), vl = atoi(argv[3]), vr = atoi(argv[4]);
  printf("%d %d\n", n, m);
  set<int> s;
  while (s.size() < n + m) s.insert(rng() % (vr - vl + 1) + vl);
  vector<int> v;
  for (int x : s) v.push_back(x);
  shuffle(v.begin(), v.end(), rng);
  for (int i = 0; i < n + m; ++i) printf("%d%c", v[i], " \n"[i + 1 == n || i + 1 == n + m]);
}
