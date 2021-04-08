#include <bits/stdc++.h>
using namespace std;

const int N = 505, P = 998244353;
int n, w[N][N], fact[N], dp[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    for (int j = i; j <= n; ++j) {
      scanf("%d", w[i] + j);
    }
  }
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = 1ll * fact[i - 1] * i % P;
  }
  for (int i = n - 1; i; --i) {
    for (int j = i; j <= n; ++j) {
      dp[i] = (dp[i] + dp[i + 1] + 1ll * w[i][j] * fact[n - i]) % P;
    }
  }
  printf("%d\n", dp[1]);
}
