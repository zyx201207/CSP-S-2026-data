#include<bits/stdc++.h>

using namespace std;

const int MAX = 5e5 + 5;

long long a[MAX];
vector<long long> u;

int n, ans = 0;
long long m;

int main(){
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  u.push_back(0);
  for(int i = 1, j = 0; i <= n; i++){
    long long x = a[i], s;
    a[i] += a[i - 1];
    while(x * (i - j) - (a[i] - a[j]) > m) ++j;
    ans = max(ans, i - j);
  }
  cout << ans << '\n';
  return 0;
}
