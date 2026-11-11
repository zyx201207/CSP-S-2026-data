#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1e6+5;
int c,t,n,k,d,rt,mn[N*2],u[N],v[N],id[N];
int dep[N],mxd[N],cmxd[N],s[N],son[N],f[N];
struct node{
  int v,id;
};
vector<node>ve[N];
void cl(){
  for(int i=1;i<=n;i++) ve[i].clear();
  return ;
}
void dfs(int x,int fa){
  dep[x]=dep[fa]+1,mxd[x]=0,cmxd[x]=0,s[x]=0,son[x]=0;
  for(auto [y,id]:ve[x]){
    if(y==fa) continue;
    ::id[y]=id,dfs(y,x),s[x]+=s[y];
    if(mxd[y]+1>mxd[x]) mxd[x]=mxd[y]+1,son[x]=y;
  }
  for(auto [y,id]:ve[x]){
    if(y==fa || y==son[x]) continue;
    cmxd[x]=max(cmxd[x],mxd[y]+1);
  }
  if(x!=rt) s[x]+=(mxd[x]>=d);
  return ;
}
void dfs2(int x,int fa){
  int S=s[x],op=0;
  if(x!=rt && mxd[x]>=d) op=1;
  for(auto [y,id]:ve[x]){
    if(y==fa) continue;
    f[y]+=S-op-s[y];
    if(y!=son[x]) f[y]+=op;
    dfs2(y,x);
  }
  return ;
}
void dfs3(int x,int fa){
  for(auto [y,id]:ve[x]){
    if(y==fa) continue;
    f[y]+=f[x],dfs3(y,x);
  }
  return ;
}
void dfs4(int x,int tp,int fa,int mx){
  if(cmxd[x]>=d) mx=dep[x];
  if(son[x]){
    int up=mx;
    if(cmxd[x]<d) up=max(up,dep[x]-d+cmxd[x]);
    f[son[x]]+=max(0,up-dep[tp]-(tp==rt)+1); 
    dfs4(son[x],tp,x,mx);
  }
  for(auto [y,id]:ve[x]){
    if(y==fa || y==son[x]) continue;
    dfs4(y,y,x,0);
  }
  return ;
}
bool ck(){
  for(int i=1;i<=2*n;i++) mn[i]=k+1;
  for(int i=1;i<=n;i++){//钦定i选
    rt=i,dfs(i,0);
    if(s[i]+1<=k) return true;
    for(int j=1;j<=n;j++) f[j]=0;
    dfs2(i,0),dfs3(i,0),dfs4(i,i,0,0);
    // cout<<"rt "<<i<<'\n';
    // for(int j=1;j<=n;j++) cout<<f[j]<<" ";
    // cout<<'\n';
    for(int j=1;j<=n;j++){
      if(j==i) continue;
      if(f[j]<mn[id[j]]) mn[id[j]]=f[j];
    }
  }
  for(int i=1;i<n;i++){
    // cout<<u[i]<<" "<<v[i]<<" "<<mn[2*i-1]<<" "<<mn[2*i]<<'\n';
    if(mn[2*i]+mn[2*i-1]+2<=k) return true;
  }
  return false;
}
void solve(){
  cin>>n>>k;cl();
  for(int i=1;i<n;i++){
    cin>>u[i]>>v[i];
    ve[u[i]].pb({v[i],2*i-1}),ve[v[i]].pb({u[i],2*i});
  }
  int l=0,r=(n+1)/2;
  while(l<r){
    int mid=l+r>>1;
    d=mid;
    if(ck()) r=mid;
    else l=mid+1;
  }
  cout<<l<<'\n';
  return ;
}
int main(){
  freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>c>>t;
  while(t--) solve();
  return 0;
}