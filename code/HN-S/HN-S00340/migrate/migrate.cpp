#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e6 + 10;

int c, T, n, d, a[N], dp[N], s[N];

void clear(){
  for(int i = 1; i <= n; i++) dp[i] = s[i] = 0;
}

void solve2(){
  int w = a[2] - a[1], t = d / w, ans = 0;
  if(t <= 1){
    cout << 0 << '\n';
    return ;
  }
  for(int i = 2; i <= n; i++){
    int e = (i - 1) / t;
    if(e == 1 && (i - 1) % t == t - 1) ans += n - i + 1;
  }
  cout << ans << '\n';
}

void solve3(){
  cout << 0 << '\n';
}

void solve(){
  cin >> n >> d; clear();
  for(int i = 1; i <= n; i++) cin >> a[i];
  int fl = 0, fl2 = 0;
  for(int i = 2; i <= n; i++) fl |= (a[i] - a[i - 1] != a[2] - a[1]), fl2 |= (max(a[i] - a[1], a[n] - a[i]) <= d);
  if(!fl){
    solve2();
    return ;
  }
  if(fl2){
    solve3();
    return ;
  }
  int ans = 0;
  for(int i = 1; i <= n; i++){
    dp[i] = 0, s[i] = 1;
    unordered_map<int, int> sum; sum[0]++;
    deque<int> q; q.push_back(i);
    //cout << i << '\n';
    for(int j = i + 1, k = i; j <= n; j++){
      while(k <= j && a[j] - a[k] > d) sum[dp[k]] -= s[k], k++;
      while(q.size() && a[j] - a[q.front()] > d) q.pop_front();
      if(q.size()) dp[j] = dp[q.front()] + 1, s[j] = sum[dp[q.front()]], ans += s[j] == 2;
      //cout << j << ' ' << dp[j] << ' ' << q.front() <<  ' ' << s[j] << '\n';
      while(q.size() && dp[j] < dp[q.back()]) q.pop_back();
      q.push_back(j); sum[dp[j]] += s[j];
    }
  }
  cout << ans << '\n';
}

signed main(){
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> c >> T;
  while(T--) solve();
  return 0;
}
