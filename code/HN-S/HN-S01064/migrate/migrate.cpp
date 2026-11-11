#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e6 + 5, N = 5005;

ll ans, limd, position[MAXN];
ll f[MAXN], g[MAXN];
int fl[MAXN], fr[MAXN], gl[MAXN], gr[MAXN];
ll leftcnt[MAXN], rightcnt[MAXN];
int Tid, T, n, limnxt[MAXN], limpre[MAXN];
int ppre[MAXN], nnxt[MAXN];

int F(int l1, int r1, int l2, int r2) {
  if (l1 > r1 || l2 > r2) return 0;
  return max(0, min(r1, r2) - max(l1, l2) + 1);
}

void Solve() {
  cin >> n >> limd;
  for (int i = 1; i <= n; i++) {
    cin >> position[i];
    fl[i] = n, fr[i] = 0, gl[i] = n, gr[i] = 0;
  }
  for (int i = 1, j = 1; i <= n; i++) {
    for (; j <= n && position[j] - position[i] <= limd; j++);
    limnxt[i] = j - 1;
    if (j - 1 > i) {
      f[j - 1]++;
      fl[j - 1] = min(fl[j - 1], i);
      fr[j - 1] = max(fr[j - 1], i);
    }
  }
  for (int i = n, j = n; i >= 1; i--) {
    for (; j >= 1 && position[i] - position[j] <= limd; j--);
    limpre[i] = j + 1;
    if (j + 1 < i) {
      g[j + 1]++;
      gl[j + 1] = min(gl[j + 1], i);
      gr[j + 1] = max(gr[j + 1], i);
    }
  }
  // leftcnt[i] 表示有多少个位置可以一直跳 limnxt 到 i 且路径唯一
  // for (int i = 1; i <= n; i++) {
  //   int x = i;
  //   for (; x == limnxt[limpre[x]] && x > 1; x = limpre[x]) {
  //     if (x == limpre[x]) break;
  //     leftcnt[i] += f[x];
  //   }
  // }
  // for (int i = 1; i <= n; i++) {
  //   int x = i;
  //   for (; x == limpre[limnxt[x]] && x < n; x = limnxt[x]) {
  //     if (x == limnxt[x]) break;
  //     rightcnt[i] += g[x];
  //   }
  // }

  for (int i = 1; i <= n; i++) {
    ppre[i] = nnxt[i] = -1;
    if (limnxt[limpre[i]] == i) ppre[i] = limpre[i];
    if (limpre[limnxt[i]] == i) nnxt[i] = limnxt[i];
  }
  for (int i = 1; i <= n; i++) {
    if (ppre[i] != -1) leftcnt[i] = leftcnt[ppre[i]] + f[i];
  }
  for (int i = n; i >= 1; i--) {
    if (nnxt[i] != -1) rightcnt[i] = rightcnt[nnxt[i]] + g[i];
  }

  for (int i = 1; i <= n; i++) {
    // cerr << i << ' ' <<  "lim: " << limpre[i] << ' ' << limnxt[i] << " | " << "f, g: " << f[i] << ' ' << g[i] << " | " << "cnt: " << leftcnt[i] << ' ' << rightcnt[i] << '\n';
  }

  for (int i = 2; i + 1 < n; i++) {
    if (limpre[i] == limpre[i + 1] && limnxt[i] == limnxt[i + 1]) {
      ans += 1ll * leftcnt[i + 1] * rightcnt[i];
    } else if (limnxt[i] == limnxt[i + 1]) {
      ans += 1ll * rightcnt[i] * F(limpre[i], i - 1, fl[i + 1], fr[i + 1]);
    } else if (limpre[i] == limpre[i + 1]) {
      ans += 1ll * leftcnt[i + 1] * F(i + 2, limnxt[i + 1], gl[i], gr[i]);
    } else {
      ans += 1ll * F(limpre[i], i - 1, fl[i + 1], fr[i + 1]) * F(i + 2, limnxt[i + 1], gl[i], gr[i]);
    }
    // cerr << i << ' ' << ans << '\n';
  }
  cout << ans << '\n';
}

void Clear() {
  ans = 0;
  for (int i = 1; i <= n; i++) {
    f[i] = g[i] = 0;
    leftcnt[i] = rightcnt[i] = 0;
  }
}

int main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  for (cin >> Tid >> T; T--; ) {
    Solve(), Clear();
  }
  return 0;
}