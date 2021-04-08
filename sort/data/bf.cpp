#include <cstdio>
#include <algorithm>
using namespace std;

const int P = 998244353;

int n, p[10], q[10], w[9][10];

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    for (int j = i; j <= n; ++j) {
      scanf("%d", w[i] + j);
    }
  }
  for (int i = 1; i <= n; ++i) p[i] = i;
  int ans = 0;
  do {
    copy(p + 1, p + 1 + n, q + 1);
    for (int i = 1; i < n; ++i) {
      int j = i;
      for (int k = i + 1; k <= n; ++k) {
        if (q[k] < q[j]) j = k;
      }
      ans = (ans + w[i][j]) % P;
      if (ans >= P) ans -= P;
      reverse(q + i, q + j + 1);
    }
  } while (next_permutation(p + 1, p + 1 + n));
  printf("%d\n", ans);
}
