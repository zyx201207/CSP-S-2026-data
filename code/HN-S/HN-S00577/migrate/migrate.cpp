#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,t,n,nxt[N],kd[N];
//-1:只可作终点
//0:随意
//1:非终点恰好一个
ll d,x[N];
void solve(){
  cin>>n>>d;
  for(int i=1;i<=n;i++) cin>>x[i];
  for(int i=1;i<=n;i++){
    int l=i,r=n;
    while(l<r){
      int mid=(l+r+1)>>1;
      if(x[mid]-x[i]<=d) l=mid;
      else r=mid-1;
    }
    nxt[i]=l;
    kd[i]=0;
    if(nxt[i-1]==nxt[i]) kd[i]=1;
    if(i>=2 && nxt[i-2]==nxt[i]) kd[i]=-1;
  }
  ll ans=0;
  for(int i=1;i<=n;i++){
    if(nxt[i]==i) continue;
    //枚举连向终点的点,不为i
    int j=nxt[i],pr=0;
    bool fg=0;//是否有1
    while(1){
      if(fg && kd[j]==1) break;//>1个1
      if(kd[j]==-1) break;//>0个-1
      if(j==nxt[j]) break;
      if(fg){
        ans+=nxt[j]-nxt[j-1];
      }
      else if(kd[j-1]==0 && nxt[pr]<j-1){
        ans+=nxt[j-1]-max(j,nxt[j-2]);
      }
      fg|=(kd[j]==1);
      if(kd[j]==1 && nxt[pr]>=j-1) break;
      pr=j-1,j=nxt[j];
    }
    // cout<<"i "<<i<<" "<<nxt[i]<<" "<<kd[i]<<" "<<ans<<'\n';
  }
  cout<<ans<<'\n';
  return ;
}
int main(){
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>c>>t;
  while(t--) solve();
  return 0;
}