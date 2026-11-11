#include <bits/stdc++.h>
using namespace std;
const int N=1e6+3;
vector<int> mp[N];
bool sel[N],vis[N];
int dep[N],fa[N][22];
void dfs(int u,int fat) {
  for(int v:mp[u]) {
    if(v==fat) continue;
    if(vis[v]) continue;
    if(!sel[v]) continue;
    vis[v]=1;
    dfs(v,u);
  }
}
void predfs(int u,int fat) {
  fa[u][0]=fat;
  for(int v:mp[u]) {
    if(v==fat) continue;
    dep[v]=dep[u]+1;
    predfs(v,u);
  }
}
int calc(int n,int k) { //O(n)
  int cnt=0;
  for(int i=1;i<=n;i++) {
    if(vis[i]) continue;
    if(!sel[i]) continue;
    cnt++;
    vis[i]=1;
    dfs(i,0);
  }
  for(int i=1;i<=n;i++) vis[i]=0;
  return cnt;
}
int lca(int a,int b) {
  if(dep[a]<dep[b]) a^=b,b^=a,a^=b;
  int c=dep[a]-dep[b];
  for(int i=20;i>=0;i--) {
    if(c&(1<<i)) a=fa[a][i];
  }
  if(a==b) return a;
  for(int i=20;i>=0;i--) {
    if(fa[a][i]!=fa[b][i]) a=fa[a][i],b=fa[b][i];
  }
  return fa[a][0];
}
vector<int> sels;
int ans;
void func(int n,int alr,int k) {
  if(alr==k) {
    int res=calc(n,k);
    if(res>2||res==0) return;
    int mxx=0;
    for(int i=1;i<=n;i++) {
      int mii=1e9;
      for(int v:sels) {
        if(i==v) {
          mii=0;
          continue;
        }
        int lf=lca(i,v);
        int dist=dep[i]+dep[v]-dep[lf]*2;
        mii=min(mii,dist);
      }
      if(mii<1e9) mxx=max(mxx,mii);
    }
    if(mxx>0) ans=min(ans,mxx);
    return;
  }
  for(int i=1;i<=n;i++) {
    if(sel[i])continue;
    sel[i]=1;
    sels.push_back(i);
    func(n,alr+1,k);
    sels.pop_back();
    sel[i]=0;
  }
}
int main() {
  freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int c,t;
  cin>>c>>t;
  while(t--) {
    int n,k;
    cin>>n>>k;
    sels.clear();
    for(int i=1;i<=n;i++) {
      mp[i].clear();
      sel[i]=0;
    }
    for(int i=1;i<n;i++) {
      int u,v;
      cin>>u>>v;
      mp[u].push_back(v);
      mp[v].push_back(u);
      dep[i]=dep[i+1]=0;
    }
    for(int j=0;j<=20;j++) {
      for(int i=1;i<=n;i++) {
        fa[i][j]=0;
      }
    }
    predfs(1,0);
    for(int j=1;j<=20;j++) {
      for(int i=1;i<=n;i++) {
          fa[i][j]=fa[fa[i][j-1]][j-1];
      }
    }
    /*
    while(1) {
      int x;
      printf("input selected:");
      cin>>x;
      for(int i=1;i<=x;i++) {
        int u; cin>>u;
        sel[u]=1;
        sels.push_back(u);
      }
      cout<<calc(n,k)<<'\n';
      sels.clear();
      for(int i=1;i<=n;i++) sel[i]=0;
    }
    */
    ans=1e9;
    func(n,0,k);
    cout<<ans<<'\n';
  }
  return 0;
}
