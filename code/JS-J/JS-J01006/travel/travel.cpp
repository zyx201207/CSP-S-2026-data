#include <bits/stdc++.h>
using namespace std;
void redir(const string &file) {
  freopen((file + ".in").c_str(), "r", stdin);
  freopen((file + ".out").c_str(), "w", stdout);
}
int main() {
  redir("travel");
  int eyea, eyeb, rowa, rowb;
  char cola, colb;
  scanf("%d %d%c %d %d%c",
    &eyea, &rowa, &cola,
    &eyeb, &rowb, &colb);
  if (cola > colb) swap(cola, colb);
  bool cona = (eyea == eyeb),
    conb = (cona && rowa == rowb),
    conc = (conb && !(cola <= 'C' && colb >= 'D')),
    cond = (conc && cola + 1 == colb);
  printf("%d%d%d%d\n", cona, conb, conc, cond);
  return 0;
}