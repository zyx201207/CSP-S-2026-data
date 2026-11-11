#include<bits/stdc++.h>
#define int long long
#define fileIO(s) {freopen(s".in","r",stdin);freopen(s".out","w",stdout);}
using namespace std;
typedef pair<int,int> PII;
const int N=310,M=N*N,inf=0x3f3f3f3f3f3f3f3f;
int _,T,n,d,e[M],ne[M],h[N],idx;
const int A=2e6+10;
int a[A];
int dis[N],cnt[N],ans;
bool vis[N];
void add(int a,int b){
   e[idx]=b;ne[idx]=h[a];h[a]=idx++;
}
void dijkstra(int st){
   memset(dis,0x3f,sizeof dis);
   memset(vis,0,sizeof vis);
   memset(cnt,0,sizeof cnt);
   queue<int>q;
   q.push(st);dis[st]=0;cnt[st]=1;
   while(q.size()){
      int u=q.front();q.pop();
      if(vis[u])continue;
      vis[u]=1;
      for(int i=h[u];~i;i=ne[i]){
         int v=e[i];
         if(dis[v]>dis[u]+1){
            dis[v]=dis[u]+1;
            cnt[v]=cnt[u];
            q.push(v);
         }
         else if(dis[v]==dis[u]+1){
            cnt[v]+=cnt[u];
         }
      }
   }
}
signed main(){
   cin.tie(0)->sync_with_stdio(0);
   fileIO("migrate");
   cin>>_>>T;
   if(_==11||_==12){
      while(T--){
         cin>>n>>d;
         for(int i=1;i<=n;i++){
            cin>>a[i];
         }
         if(n==1){
            cout<<"0\n";
            continue;
         }
         int gongcha=a[2]-a[1];
         if(gongcha>=d){
            cout<<"0\n";
            continue;
         }
         int annss=n-2*(d/gongcha)+1;
         if(annss<0)cout<<"0\n";
         else cout<<n-2*(d/gongcha)+1<<"\n";
      }
      return 0;
   }
   while(T--){
      cin>>n>>d;
      memset(h,-1,sizeof h);idx=0;ans=0;
      for(int i=1;i<=n;i++){
         cin>>a[i];
      }
      if(n==1){
         cout<<"0\n";
         continue;
      }
      for(int i=2;i<=n;i++){
         for(int j=1;j<i;j++){
            if(abs(a[i]-a[j])<=d){
               add(i,j);
            }
         }
      }
      for(int i=1;i<=n;i++){
         dijkstra(i);
         for(int j=1;j<=n;j++){
//            cout<<"!!!"<<i<<" "<<j<<" "<<dis[j]<<" "<<cnt[j]<<"\n";
            if(cnt[j]==2&&dis[j]!=inf){
               ans++;
            }
         }
      }
      cout<<ans<<"\n";
   }
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
