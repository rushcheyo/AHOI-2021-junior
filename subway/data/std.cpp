#include <cstdio>

typedef long long ll;

const int N = 505;
const int M = 505;
const int E = N + M;
const ll INF = 1e12;
const ll bigINF = 9e18;

int n, m, e, u[E], v[E], k[E], b[E], pre[N];
ll d[N];

void add(int a, int b, int c, int d) {
  u[++e] = b; v[e] = a; k[e] = c; ::b[e] = d;
}

int solve(ll mid) {
  for (int i = 1; i <= n; ++i) d[i] = bigINF;
  d[1] = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= e; ++j)
      if (d[v[j]] > d[u[j]] + k[j] * mid + b[j]) {
        d[v[j]] = d[u[j]] + k[j] * mid + b[j];
        pre[v[j]] = j;
      }
  for (int j = 1; j <= e; ++j)
    if (d[v[j]] > d[u[j]] + k[j] * mid + b[j]) {
      int x = u[j];
      for (int i = 0; i < n; ++i) x = u[pre[x]];
      int coef = k[pre[x]];
      for (int y = u[pre[x]]; y != x; y = u[pre[y]]) coef += k[pre[y]];
      return coef > 0 ? 1 : -1;
    }
  return 0;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; ++i) add(i, i + 1, 0, -1);
  add(n, 1, 1, -1);
  for (int i = 0; i < m; ++i) {
    int t, S, T, L;
    scanf("%d%d%d%d", &t, &S, &T, &L);
    if (t == 1) {
      if (S < T) add(S, T, 0, -L);
      else add(S, T, 1, -L);
    } else {
      if (S < T) add(T, S, 0, L);
      else add(T, S, -1, L);
    }
  }
  ll l = 0, r = INF;
  while (l < r) {
    ll mid = (l + r + 1) / 2;
    int t = solve(mid);
    if (t == 0) l = mid;
    else if (t == 1) l = mid + 1;
    else r = mid - 1;
  }
  ll ub = l;
  if (ub >= INF) return puts("-1"), 0;
  l = 0, r = INF;
  while (l < r) {
    ll mid = (l + r) / 2;
    int t = solve(mid);
    if (t == 0) r = mid;
    else if (t == 1) l = mid + 1;
    else r = mid - 1;
  }
  printf("%lld\n", ub - l + 1);
}
