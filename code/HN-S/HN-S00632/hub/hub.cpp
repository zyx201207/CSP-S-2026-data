#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void FileIO (string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e6 + 10, M = 4010;

int TestCase, TestID, n, m, k, mxdep, lft, l, r;
int stk[N], top, p[N], d[N];
vector<int> g[N];
bool flag[N];

void init (int x, int fa, int dep) {
  if (dep > mxdep) mxdep = dep, lft = x;
  for (int i : g[x])
    if (i != fa)
      init(i, x, dep + 1);
}

void init_ (int x, int fa, int dep) {
  stk[++top] = x;
  if (dep == mxdep && !m) {
    m = top;
    for (int i = 1; i <= top; i++) p[i] = stk[i], flag[p[i]] = 1;
    return ;
  }
  for (int i : g[x])
    if (i != fa)
      init_(i, x, dep + 1);
  top--;
}

/*void dfs (int x, int y, int fa) {
  if (x == y)
}

bool check (int dis) {
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      
    }
  return 0;
}*/

void Color (int x, int now) {
  if (now >= d[x]) return ;
  d[x] = now;
  for (int i : g[x]) Color(i, now + 1);
}

bool check_11 (int dis) {
  for (int i = 1; i <= n; i++) d[i] = dis + 10;
  Color(p[dis + 1], 0), Color(p[m - dis], 0);
  for (int i = 1; i <= n; i++)
    if (d[i] > dis)
      return 0;
  return 1;
}

void Solve () {
  cin >> n >> k;
  for (int i = 1, x, y; i < n; i++) 
    cin >> x >> y, g[x].push_back(y), g[y].push_back(x);
  if (n == k) {
    cout << 0;
    return ;
  }
  if (TestID == 13 || TestID == 14) {
    m = n / 2;
    if (k >= m) {
      cout << 1;
      return ;
    }
    cout << max({1, ((m + 1) / 2 + 2 - (k + 1) / 2 + 1) / 2, (m / 2 + 2 - k / 2 + 1) / 2});
  } else {
    top = mxdep = m = 0, init(1, 0, 1), mxdep = 0, init(lft, 0, 1), init_(lft, 0, 1), l = 1, r = m / 2;
    if (k == 2) {
      while (l < r) {
        int mid = (l + r) >> 1;
        if (check_11(mid)) r = mid;
        else l = mid + 1;
      }
    } else {
      /*while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
      }*/
    }
    cout << l;
  }
  // SolveClear
  for (int i = 1; i <= n; i++) g[i] = vector<int> (), flag[i] = 0;
}

signed main () {
  ios::sync_with_stdio(0), cin.tie(0);
  FileIO("hub");
  for (cin >> TestID >> TestCase; TestCase--; Solve(), cout << '\n') {}
  return 0;
}
