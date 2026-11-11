#include <bits/stdc++.h>
using namespace std;
void redir(const string &file) {
  freopen((file + ".in").c_str(), "r", stdin);
  freopen((file + ".out").c_str(), "w", stdout);
}
const int Maxn = 5e5 + 10;
int seq[Maxn], appr[Maxn], nxt[Maxn], res[Maxn], n, m;
int main() {
  redir("card");
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &seq[i]);
  for (int start = 1; start <= n; start++) {
    memset(appr, 0, sizeof(appr));
    memset(nxt, 0, sizeof(nxt));
    for (int i = start; i <= n; i++) {
      if (appr[seq[i]]) nxt[appr[seq[i]]] = i;
      else appr[seq[i]] = i;
    }
    for (int i = start; i <= n; i++) {
      if (nxt[i]) i = nxt[i];
      res[seq[i]]++;
    }
  }
  for (int i = 1; i <= m; i++) {
    printf("%d", res[i]);
    if (i < m) putchar(' ');
    else putchar('\n');
  }
  return 0;
}