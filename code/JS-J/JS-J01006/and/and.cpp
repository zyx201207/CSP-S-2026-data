#include <bits/stdc++.h>
using namespace std;
void redir(const string &file) {
  freopen((file + ".in").c_str(), "r", stdin);
  freopen((file + ".out").c_str(), "w", stdout);
}
const int Maxn = 2e5 + 10, Maxl = 31;
typedef vector<int> vi;
int seq[Maxn], n, m;
vi bit[Maxl], tk, mrg, res;
int main() {
  redir("and");
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &seq[i]);
    for (int j = 0; j < Maxl; j++) {
      if ((seq[i] >> j) & 1) bit[j].push_back(i);
    }
  }
  for (int i = Maxl - 1; ~i; i--) {
    if (bit[i].size() >= m) tk.push_back(i);
  }
  if (tk.empty()) { puts("0"); return 0; }
  res = bit[tk[0]];
  for (int i : tk) {
    mrg.clear();
    set_intersection(
      res.begin(), res.end(),
      bit[i].begin(), bit[i].end(),
      back_inserter(mrg)
    );
    if (mrg.size() >= m) res = mrg;
  }
  int ans = seq[res[0]];
  for (int x : res) ans &= seq[x];
  printf("%d\n", ans);
  return 0;
}