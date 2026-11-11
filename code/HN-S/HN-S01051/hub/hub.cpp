#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

vector<int> mp[MAX];

int c, t, n, k;

namespace WK1{
  int b[MAX];
  bool vis[MAX];
  int fd(int x){return (b[x] == x ? x : b[x] = fd(b[x]));};
  int ans, rt = 0;
  int g[MAX];
  queue<int> d;
  int len[MAX];
  void bfs(){
    for(int i = 1; i <= n; i++){
      if(vis[i]) d.push(i), len[i] = 0;
    }
    rt = 0;
    while(d.size()){
      int x = d.front();
      d.pop();
      for(int i : mp[x]){
        if(len[i] == -1){
          rt = max(rt, len[i] = len[x] + 1);
          d.push(i);
        }
      }
    }
    ans = min(ans, rt);
  }
  void f(int x){
    int h = 0, ux = 0;
    for(int i =1 ; i<= n; i++) vis[i] = 0, b[i] = i;
    for(int i = 1, j = 1; i <= n; i++, j <<= 1){
      if(x & j){
        vis[i] = 1;
        ux = i;
        ++h;
        for(int uj : mp[i]){
          if(x & (1 << (uj - 1))){
            // cout << i << ' ' << uj << ' ' << fd(i) << ' ' << fd(uj) << '\n';
            if(fd(i) != fd(uj)){
              b[fd(i)] = fd(uj);
            }
          }
        }
      }
    }
    if(h != k){return;};
    h = 0, rt = 0;
    
    // for(int i = 1; i <= n; i++){
    //   cout << b[i] << ' ';
    // }
    // cout << '\n';

    for(int i = 1; i <= n; i++) h += b[i] == i;
    if(h <= 2){
      bfs();
    }
  }
  void work(){
    ans = n;
    for(int i = 0; i < (1 << n); i++){
      f(i);
    }
    cout << ans << '\n';
    for(int i = 1; i <= n; i++) mp[i].clear();
  }
}

void solve(){
  cin >> n>> k;
  for(int i = 1, x, y; i < n; i++){
    cin >> x >> y;
    mp[x].push_back(y), mp[y].push_back(x);
  }
  if(n <= 10){
    WK1::work();
  }
}

int main(){
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> c >> t;
  while(t--){
    solve();
  }
  return 0;
}