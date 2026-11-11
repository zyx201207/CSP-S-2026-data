/*
uid=305928 last fight

azayagana risouhatasutsurukiyo
konoyonoyume subetenosete
ima ima saa kirisaite
tashikana kotowariminna urayamu
mitasarenu sekainoitadakide!

For lovely Tenshi Hinanawi
 */


/*
Probably so do I.
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k;
vector<int> e[1000005];
int ff[1000005],dis[1000005];
void dfs(int u,int fa){
  ff[u]=fa;
  for (int v:e[u]){
    if (v==fa)continue;
    dis[v]=dis[u]+1;
    dfs(v,u);
  }
}
int getroot(){
  dis[1]=0;
  dfs(1,0);
  int rt=1;
  for (int i=2;i<=n;i++){
    if (dis[i]>dis[rt])rt=i;
  }
  dis[rt]=0;
  dfs(rt,0);
  int x=1;
  for (int i=2;i<=n;i++){
    if (dis[i]>dis[x])x=i;
  }
  int t=dis[x];
  for (int i=1;i*2<=t;i++){
    x=ff[x];
  }
  dis[x]=0;
  dfs(x,0);
  return x;
}
int height[1000005];
void init(int u){
  height[u]=0;
  for (int v:e[u]){
    if (v==ff[u])continue;
    init(v);
    height[u]=max(height[u],height[v]+1);
  }
}
int flag[1000005];
int siz[1000005],out[1000005];
void getsiz(int u){
  siz[u]=1;
  out[u]=0;
  for (int v:e[u]){
    if (v==ff[u])continue;
    if (flag[v]){
      getsiz(v);
      siz[u]+=siz[v];
    }
    else out[u]=max(out[u],height[v]+1);
  }
}
bool check(int rt,int mid){
  //cout<<"mid=="<<mid<<"\n";
  for (int i=1;i<=n;i++){
    if (height[i]>=mid)flag[i]=1;
    else flag[i]=0;
    siz[i]=out[i]=0;
  }
  getsiz(rt);
  if (siz[rt]<=k)return 1;
  int cnt=0,b1=0,b2=0;
  for (int v:e[rt]){
    if (flag[v]){
      ++cnt;
      if (cnt==3)return 0;
      else if (cnt==1)b1=v;
      else b2=v;
    }
  }
  //if (cnt!=2){
    //cout<<"warning!\ncnt!=2\n";
    //cout<<mid<<"\n";
    //cout<<rt<<" "<<cnt<<" "<<b1<<" "<<b2<<"\n";
    //for (int i=1;i<=n;i++)cout<<height[i]<<" "<<flag[i]<<"\n";
    //cout<<"\n";
    //exit(0);
  //}
  deque<int> dq;
  dq.push_back(b1);
  dq.push_back(rt);
  dq.push_back(b2);
  int len=2;
  while (1){
    int cnt=0,nxt=0;
    for (int v:e[b1]){
      if (flag[v]&&siz[v]<siz[b1]){
	++cnt;nxt=v;
      }
    }
    //cout<<"b1"<<b1<<" "<<cnt<<"\n";
    if (cnt==1)len++,b1=nxt;
    else break;
    dq.push_front(b1);
  }
  while (1){
    int cnt=0,nxt=0;
    for (int v:e[b2]){
      if (flag[v]&&siz[v]<siz[b2]){
	++cnt;nxt=v;
      }
    }
    //cout<<"b2"<<b2<<" "<<cnt<<"\n";
    if (cnt==1)len++,b2=nxt;
    else break;
    dq.push_back(b2);
  }
  int tot=siz[b1]+siz[b2];
  //calculate contributions from b1,b2 up
  vector<int> a,b;
  for (int i:dq){
    a.push_back(i);
    b.push_back(dq.size()-1);
  }
  int N=dq.size()-1;
  for (int i=0;i<=N;i++){
    int L=max(0LL,i+out[a[i]]-mid);
    int R=min(N,i+mid-out[a[i]]);
    if (L)b[L-1]=min(b[L-1],R);
  }
  int mn=N-1;
  for (int i=N-1;i>=0;i--){
    b[i]=min(b[i],b[i+1]);
    mn=min(mn,i+N-b[i]);
  }
  //cout<<n<<" "<<rt<<" "<<b1<<" "<<b2<<" "<<siz[b1]<<" "<<siz[b2]<<" "<<tot<<" "<<mn<<" "<<k<<"\n";
  //for (int i=0;i<=N;i++){
  //cout<<a[i]<<" "<<b[i]<<"\n";
  //}
  return tot+mn<=k;
  
}
void solve(int cid){
  cin>>n>>k;
  for (int i=1;i<=n;i++){
    e[i].clear();
  }
  for (int i=1;i<n;i++){
    int u,v;cin>>u>>v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  if (n==2){
    cout<<"0\n";
    return;
  }
  int rt=getroot();
  init(rt);
  int l=0,r=height[rt];
  while (l<r){
    int mid=(l+r)/2;
    if (check(rt,mid))r=mid;
    else l=mid+1;
  }
  cout<<r<<"\n";
}


signed main(){
  freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int c,t;cin>>c>>t;
  while (t--)solve(c);
  return 0;
}
