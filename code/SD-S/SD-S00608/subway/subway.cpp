#include<bits/stdc++.h>
#define int long long
#define fileIO(s) {freopen(s".in","r",stdin);freopen(s".out","w",stdout);}
using namespace std;
typedef pair<int,int> PII;
const int L=220,N=1e3+10,M=5e5+10,inf=1e17;
int _,linecnt,n,trans_max,T;//n是地铁站的数量
int entrance[N];//每个地铁站的地铁口走到站厅需要的时间
int e[M],id[M],ne[M],h[N],idx;
int dis[N],vis[N];
struct node{
   int cnt;
   int t[N],a[N];
}line[L];
void add(int a,int b,int c){
   e[idx]=b;id[idx]=c;ne[idx]=h[a];h[a]=idx++;
}
struct NODE{
   int pos,dist,lastid;
   bool operator <(const NODE &x)const{
      return dist>x.dist;
   }
};
void dijkstra(int st){
   queue<NODE>q;
   memset(dis,0x3f,sizeof dis);
   memset(vis,0,sizeof vis);
   q.push({st,0,0});dis[st]=0;vis[st]=1;
   while(q.size()){
      int u=q.front().pos,lastid=q.front().lastid;q.pop();
      vis[u]=0;
//      cout<<"!!!"<<u<<" "<<lastid<<":\n";
      for(int i=h[u];~i;i=ne[i]){
         int v=e[i],nxtid=id[i];
//         cout<<"!!!"<<v<<" "<<nxtid<<"\n";
         if(nxtid==lastid){
            if(dis[v]>dis[u]){
               dis[v]=dis[u];
//               cout<<"upd1 "<<dis[v]<<"\n";
               if(!vis[v]){
                  q.push({v,dis[v],nxtid});
                  vis[v]=1;
               }
            }
         }
         else{
            int cost=0;
            if(lastid==0)cost=line[nxtid].t[u];
            else cost=line[lastid].t[u]+line[nxtid].t[u];
            if(dis[v]>dis[u]+cost){
               dis[v]=dis[u]+cost;
//               if(lastid!=0)cout<<"upd2 "<<dis[v]<<" "<<line[lastid].t[u]<<" "<<line[nxtid].t[u]<<"\n";
               if(!vis[v]){
                  q.push({v,dis[v],nxtid});
                  vis[v]=1;
               }
            }
         }
      }
//      for(int i=1;i<=n;i++){
//         cout<<dis[i]<<"\n";
//      }
//      cout<<"\n";
   }
}
void init(){
   for(int i=1;i<=linecnt;i++){
      int cnt=line[i].cnt;
      int last=line[i].a[1];
      for(int j=2;j<=cnt;j++){
         int nw=line[i].a[j];
         add(last,nw,i);add(nw,last,i);
//         cout<<last<<" "<<nw<<" "<<i<<"\n";
         last=nw;
      }
   }
}
signed main(){
   cin.tie(0)->sync_with_stdio(0);
   fileIO("subway");
   memset(h,-1,sizeof h);
   cin>>_>>linecnt>>n>>trans_max>>T;
   for(int i=1;i<=n;i++){
      cin>>entrance[N];
   }
   for(int i=1;i<=linecnt;i++){
      cin>>line[i].cnt;
      for(int j=1;j<=line[i].cnt;j++){
         int aa,tt;
         cin>>aa>>tt;
         line[i].a[j]=aa;
         line[i].t[j]=tt;
      }
   }
   init();
   while(T--){
      int u,v;
      cin>>u>>v;
      dijkstra(u);
      cout<<dis[v]+entrance[u]+entrance[v]<<"\n";
   }
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
