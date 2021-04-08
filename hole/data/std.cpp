#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 200005, INF = 2e9 + 1;
int n, m, x[N], y[N], l[N], r[N], id[N];

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
  int ans = INF, suf_max = 0;
  for (int i = n; i >= 0; --i) {
    ans = min<ll>(ans, min(l[id[i]] + 2ll * suf_max, 2ll * l[id[i]] + suf_max));
    suf_max = max(suf_max, r[id[i]]);
  }
  printf("%d\n", ans);
  return 0;
}
