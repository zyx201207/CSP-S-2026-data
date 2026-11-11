#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int c,t,n,k,lim,vis[N],md[N],sz[N],od[N];
vector<int> e[N];
void dfs1(int x,int fa){
  vis[x] = md[x] = sz[x] = 0;
  for (auto &i : e[x]){
    if (i ^ fa){
      dfs1(i,x);
      vis[x] |= vis[i];
      sz[x] += sz[i];
      md[x] = max(md[x],md[i] + 1);
    }
  }
  if (md[x] == lim){
    vis[x] = 1;
  }
  sz[x] += vis[x];
}
int dfs2(int x,int fa){
  int mx = od[x],se = 0;
  for (auto &i : e[x]){
    if (i ^ fa){
      if (mx < md[i] + 1){
        se = mx,mx = md[i] + 1;
      }
      else{
        se = max(se,md[i] + 1);
      }
    }
  }
  int ans = 1e9;
 (od[x] <= lim) && (ans = min(ans,max(sz[x],1)),1);
  for (auto &i : e[x]){
    if (i ^ fa){
      od[i] = ((mx == md[i] + 1)?se:mx) + 1;
      ans = min(ans,dfs2(i,x));
    }
  }
  return ans;
}
int tx(int x,int fa){
  dfs1(x,fa);
  od[x] = 0;
  return dfs2(x,fa);
}
int cnt,nd[N];
void dfs3(int x,int fa){
  vis[x] = md[x] = sz[x] = 0;
  nd[x] = 1e9;
  for (auto &i : e[x]){
    if (i ^ fa){
      dfs3(i,x);
      md[x] = max(md[x],md[i] + 1);
      nd[x] = min(nd[x],nd[i] + 1);
      sz[x] += sz[i];
    } 
  }
  if (nd[x] + md[x] <= lim){
    md[x] = -1e9;
  }
  if (md[x] >= lim){
    vis[x] = 1;
    md[x] = -1e9;
    nd[x] = 0;
    cnt++;
  }
  sz[x] += vis[x];
}
bool chk(int x){
  lim = x;
  if (tx(1,0) <= k){
    return 1;
  }
  if (k == 2){
    cnt = 0;
    dfs3(1,0);
    if (md[1] >= 0){
      sz[1]++;
    }
    if (sz[1] <= 2){
      return 1;
    }
    return 0;
  }
  for (int i = 1;i <= n;i++){
    for (auto &j : e[i]){
      if ((i < j) && (tx(i,j) + tx(j,i) <= k)){
        return 1;
      }
    }
  }  
  return 0;
}
void solve(){
  cin >> n >> k;
  for (int i = 1;i <= n;i++){
    e[i].clear();
  }
  for (int i = 1,u,v;i < n;i++){
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  if (k == n){
    cout << "0\n";
    return;
  }
  int l= 1 ,r = n;
  while (l <= r){
    int mid = (l + r) >> 1;
    (chk(mid))?r = mid - 1:l = mid + 1;
  }
  cout << l << "\n";
}
signed main(){
  freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  for (cin >> c >> t;t--;){
    solve();
  }

}