#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  printf("%d\n", n);
  for (int i = 0; i < n; ++i) {
    printf("%.2f %d\n", (rng() % 9999 + 1) / 100.0, rng() % 10 + 1);
  }
}
