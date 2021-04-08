#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  while (true) {
    vector<int> a(n), b(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      a[i] = rng() % 9999 + 1;
      b[i] = rng() % 10 + 1;
      sum += a[i] * b[i];
    }
    if (sum % 200 == 0) {
      printf("%d\n", n);
      for (int i = 0; i < n; ++i) {
        printf("%.2f %d\n", a[i] / 100.0, b[i]);
      }
      break;
    }
  }
}
