#include <cstdio>

int main() {
  freopen("shopping.in", "r", stdin);
  freopen("shopping.out", "w", stdout);
  int n;
  double sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    double a;
    int b;
    scanf("%lf%d", &a, &b);
    sum += a * b;
  }
  sum *= 0.85;
  printf("%.1f\n", int(sum * 10) / 10.0);
}
