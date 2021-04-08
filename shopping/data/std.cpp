#include <cstdio>

int main() {
  int n;
  int sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a1, a2;
    int b;
    scanf("%d.%d%d", &a1, &a2, &b);
    sum += (a1 * 100 + a2) * b;
  }
  sum *= 85;
  printf("%d.%d\n", sum / 10000, sum / 1000 % 10);
}
