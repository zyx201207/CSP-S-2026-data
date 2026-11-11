#include <bits/stdc++.h>

using namespace std;;

using ll = long long;
using ull = unsigned long long;

const int kMaxN = 5e5 + 50;

ll n, m, a[kMaxN], sum, ans;
priority_queue<ll, vector<ll>, greater<ll>> q;

int main() {
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++ i) {
    cin >> a[i]; 
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++ i) {
    q.push(a[i]), sum += a[i];
    for (; !q.empty() && q.size() * a[i] - sum > m; sum -= q.top(), q.pop());
    ans = max(ans, (ll)q.size());
  }
  cout << ans << '\n';
  return 0;
}

// I wish cute ZRR has 0pts, And I have AKed. (By Bc2_Ch1ckenPr1nce)
