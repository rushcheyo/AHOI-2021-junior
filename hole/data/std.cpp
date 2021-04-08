#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 200005;
const ll INF = 1e10 + 1;
int n, m, x[N], y[N], id[N];
ll l[N], r[N];

struct cmp {
  bool operator()(int x, int y) {
    return l[x] < l[y];
  }
};

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", x + i);
    id[i] = i;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", y + i);
  }
  sort(x + 1, x + 1 + n);
  sort(y + 1, y + 1 + m);
  for (int i = 1, j = 0; i <= n; ++i) {
    while (j != m && y[j + 1] < x[i])
      ++j;
    if (j) l[i] = x[i] - y[j];
    else l[i] = INF;
  }
  for (int i = n, j = m + 1; i >= 1; --i) {
    while (j != 1 && y[j - 1] > x[i])
      --j;
    if (j <= m) r[i] = y[j] - x[i];
    else r[i] = INF;
  }
  sort(id + 1, id + 1 + n, cmp());
  ll ans = INF, suf_max = 0;
  for (int i = n; i >= 0; --i) {
    ans = min(ans, min(l[id[i]] + 2 * suf_max, 2 * l[id[i]] + suf_max));
    suf_max = max(suf_max, r[id[i]]);
  }
  printf("%lld\n", ans);
  return 0;
}
