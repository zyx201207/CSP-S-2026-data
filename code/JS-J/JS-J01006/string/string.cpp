#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void redir(const string &file) {
  freopen((file + ".in").c_str(), "r", stdin);
  freopen((file + ".out").c_str(), "w", stdout);
}
const int Maxn = 2e5 + 10;
int seq[Maxn], n;
char ch[Maxn];
int main() {
  redir("string");
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d %c", &seq[i], &ch[i]);
  int l = 1, r = n;
  ll res = 0;
  while (l < r) {
    if (seq[l] > seq[r]) {
      if (ch[l] != ch[r]) res += seq[r];
      seq[l] -= seq[r];
      r--;
    } else {
      if (ch[l] != ch[r]) res += seq[l];
      seq[r] -= seq[l];
      l++;
    }
  }
  printf("%lld\n", res);
  return 0;
}