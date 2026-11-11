#include<bits/stdc++.h>
#define rep(i, a, b) for (int i=(a),i##_E_=(b);i<=i##_E_;++i)
#define drep(i, a, b) for (int i=(a),i##_E_=(b);i>=i##_E_;--i)
using namespace std;
using ll = long long;
constexpr int inf=1e9;

void ofile(string s){
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

int caseid;

vector<int>G[1000010];
bool vis[1000010];
int n,k,w,rt,ans,mem[1000010],fa[1000010],to[1000010],dp[1000010][3],typ[1000010];
void dfs0(int u,int p){
  fa[u]=p;
  for (auto v:G[u])if (v^p)dfs0(v,u);
}
void dfs1(int u,int p,int z){
  typ[u]=z;
  for (auto v:G[u])if (v^p){
    dfs1(v,u,z);
    if (dp[u][0]<dp[v][0]+1){
      dp[u][1]=dp[u][0];
      dp[u][0]=dp[v][0]+1;
      to[u]=v;
    }else dp[u][1]=max(dp[u][1],dp[v][0]+1);
  }
}
void dfs2(int u,int p){
  for (auto v:G[u])if (v^p){
    dp[v][2]=max(dp[v][2],dp[u][2]+1);
    dp[v][2]=max(dp[v][2],(to[u]==v?dp[u][1]:dp[u][0])+1);
    dfs2(v,u);
  }
}

int sol(int x){
  int y=fa[x];
  if (!y)return inf;
  int ans=0;
  rep(i,0,n+1)dp[i][0]=dp[i][1]=dp[i][2]=to[i]=0;
  dfs1(x,y,1),dfs2(x,y);
  dfs1(y,x,2),dfs2(y,x);
  bool ok[3];
  ok[1]=ok[2]=0;
  rep(i,1,n){
    int cnt=0;
    rep(j,0,2)cnt+=dp[i][j]>=w;
    if (cnt>=2)ok[typ[i]]=1,++ans;
    if (ans>k)return ans;
  }
  // cout<<w<<' '<<x<<' '<<y<<' '<<ans<<'\n';
  return ans+!ok[1]+!ok[2];
}

int cal(int x){
  if (~mem[x])return mem[x];
  int lo=1,hi=min(ans,n/2),mi,ret=n+1;
  while (lo<=hi){
    w=mi=(lo+hi)>>1;
    if (sol(x)<=k){
      ret=mi;
      hi=mi-1;
    }else
      lo=mi+1;
  }
  return mem[x]=ret;
}

array<int,2>centre(int u){
  function<int(int,int)>dfs1=[&](int u,int p){
    int sz=1;
    for (auto v:G[u])if (v!=p&&!vis[v])sz+=dfs1(v,u);
    return sz;
  };
  int all=dfs1(u,0),pos=u,posf=0,szn=all;
  function<int(int,int)>dfs2=[&](int u,int p){
    int szu=1,szm=0;
    for (auto v:G[u])if (v!=p&&!vis[v]){
      int szv=dfs2(v,u);
      szu+=szv;
    }
    szm=max(szu,all-szu);
    if (szm<szn&&u!=rt)szn=szm,pos=u,posf=p;
    return szu;
  };
  dfs2(u,0);
  return{pos,posf};
}
void dfz(int u,int up){
  // cout<<rt<<' '<<u<<' '<<cal(u)<<endl;
  if (ans<cal(u))return ;
  ans=cal(u);
  auto [x,f]=centre(up);
  assert(x==u);
  if (vis[f])return ;
  vis[u]=1;
  int wf=min(cal(f),cal(centre(f)[0]));
  vis[u]=0,vis[f]=1;
  int wg=min(cal(u),cal(centre(u)[0]));
  vis[f]=0;
  if (f!=rt&&wf<wg)vis[u]=1,dfz(centre(f)[0],f);
  else vis[f]=1,dfz(centre(u)[0],u);
}

void solve(){
  scanf("%d%d",&n,&k);
  rep(i,0,n+1)G[i]={},mem[i]=-1;
  rep(i,1,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  if (k==n){
    puts("0");
    return ;
  }
  rt=1;
  dfs1(1,0,1),dfs2(1,0);
  rep(i,1,n)if (max(dp[i][0],dp[i][2])<max(dp[rt][0],dp[rt][2]))rt=i;
  dfs0(rt,0);
  if (caseid>10){
    rep(i,1,n)vis[i]=0;
    ans=n+1;
    dfz(centre(rt)[0],rt);
    printf("%d\n",ans);
    return ;
  }
  ans=n+1;
  rep(i,1,n)ans=min(ans,cal(i));
  printf("%d\n",ans);
}

int main(){
  ofile("hub");
  int tt;
  scanf("%d%d",&caseid,&tt);
  while (tt--)solve();
  return 0;
}

/*
#include<bits/stdc++.h>
#define rep(i, a, b) for (int i=(a),i##_E_=(b);i<=i##_E_;++i)
#define drep(i, a, b) for (int i=(a),i##_E_=(b);i>=i##_E_;--i)
using namespace std;
using ll = long long;
constexpr int inf=1e9;

void ofile(string s){
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

int caseid;

vector<int>G[1000010];
int n,k,w,rt,val,to[1000010],dp[1000010][3],typ[1000010];
void dfs1(int u,int p){
  dp[u][0]=dp[u][1]=dp[u][2]=to[u]=0;
  for (auto v:G[u])if (v^p){
    dfs1(v,u);
    if (dp[u][0]<dp[v][0]+1){
      dp[u][1]=dp[u][0];
      dp[u][0]=dp[v][0]+1;
      to[u]=v;
    }else dp[u][1]=max(dp[u][1],dp[v][0]+1);
  }
}
void dfs2(int u,int p){
  for (auto v:G[u])if (v^p){
    dp[v][2]=max(dp[v][2],dp[u][2]+1);
    dp[v][2]=max(dp[v][2],(to[u]==v?dp[u][1]:dp[u][0])+1);
    dfs2(v,u);
  }
}
namespace DFZ{
  int fa[1000010],dep[1000010];
  bool vis[1000010];
  int centre(int u){}
  void init(){
    rep(i,0,n+1)vis[i]=0;
  }
}
bool dfs(int u,int p){
  int nval=val;
  if (p){
    val-=typ[p]==2;
    if (typ[p]==1)DFZ::add(p,-1);
    int ntyp=typ[p];
    if (u==to[p])ntyp-=dp[p][0]>=w;
    ntyp+=dp[p][2]>=w;
    if (p==rt){
      ntyp=typ[p]-1;
      if ((int)G[p].size()>=3)ntyp=2;
    }
    if (ntyp==1)DFZ::add(p,1);
    val+=ntyp==2;
    if (p!=rt&&val<=k)return 1;
  }
  for (auto v:G[u])if (v^p)if (dfs(v,u))return 1;
  if (p){
    int ntyp=typ[p];
    if (u==to[p])ntyp-=dp[p][0]>=w;
    ntyp+=dp[p][2]>=w;
    if (p==rt){
      ntyp=typ[p]-1;
      if ((int)G[p].size()>=3)ntyp=2;
    }
    if (ntyp==1)DFZ::add(p,-1);
    if (typ[p]==1)DFZ::add(p,1);
  }
  val=nval;
}
bool chk(){
  rep(i,1,n)typ[i]=(dp[u][0]>=w)+(dp[u][1]>=w);
  val=0;
  rep(i,1,n)val+=typ[i]==2;
  if (val<=k-1)return 1;
  DFZ::init();
  rep(i,1,n)if (typ[i]==1)DFZ::add(i,1);
  return dfs(rt,0);
}
void solve(){
  scanf("%d%d",&n,&k);
  rep(i,0,n+1)G[i]={};
  rep(i,1,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  if (k==n){
    puts("0");
    return ;
  }
  rt=1;
  dfs1(1,0,1),dfs2(1,0);
  rep(i,1,n)if (max(dp[i][0],dp[i][2])<max(dp[rt][0],dp[rt][2]))rt=i;
  dfs1(rt,0,1),dfs2(rt,0);
  int lo=1,hi=n/2,mi,ret=n+1;
  while (lo<=hi){
    w=mi=(lo+hi)>>1;
    if (chk()){
      ret=mi;
      hi=mi-1;
    }else
      lo=mi+1;
  }
  printf("%d\n",ret);
}

int main(){
  ofile("hub");
  int tt;
  scanf("%d%d",&caseid,&tt);
  while (tt--)solve();
  return 0;
}
*/