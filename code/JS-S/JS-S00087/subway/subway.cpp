#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll len=5e2+10,M=5e5+10;
int c,n,m,d,q;
ll bz,ans;
ll w[M];// time for stations
struct node{
    ll to,val;
};
int k[len];// route
bool vis[len];// route
vector<node>grap[len];// the stations that each route contain
vector<node>xl[M];// each route the stations can get to
ll dis[len][len];// dis between routes
vector<node>g[len];// route
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >, greater<pair<ll,ll> > >myque;

void dijkstra(int x){
    memset(vis,0,sizeof(vis));
    dis[x][x]=0;
    myque.push(make_pair(0,x));
    while(!myque.empty()){
        int to=myque.top().second;
        ll tmp=myque.top().first;
        myque.pop();
        if(vis[to])continue;
        vis[to]=1;
        for(int i=0;i<g[to].size();i++){
            ll eto=g[to][i].to;
            ll eval=g[to][i].val;
            if(eval+tmp<dis[x][eto]){
                dis[x][eto]=eval+tmp;
                myque.push(make_pair(dis[x][eto],eto));
            }
        }
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int sta;
            ll val;
            cin>>sta>>val;
            grap[i].push_back(node{sta,val});
            xl[sta].push_back(node{i,val});
        }
    }
    for(int i=0;i<=n;i++)memset(dis[i],0x3f,sizeof(dis[i]));
    bz=dis[0][0];
    for(int i=0;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<k[i];j++){//m
            ll tp=grap[i][j].to;//i can lead here
            ll tmpval=grap[i][j].val;
            for(int nw=0;nw<xl[tp].size();nw++){//use tp to get to other route
                ll y=xl[tp][nw].to;
                ll val2=xl[tp][nw].val;
                dis[i][y]=min(dis[i][y],val2+tmpval);
                dis[y][i]=min(dis[y][i],val2+tmpval);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(i!=j&&dis[i][j]<bz){
                g[i].push_back(node{j,dis[i][j]});
                g[j].push_back(node{i,dis[i][j]});
            }
        }
    }
    for(int i=0;i<=n;i++)memset(dis[i],0x3f,sizeof(dis[i]));
    for(int i=1;i<=n;i++){
        dijkstra(i);
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        ans=bz;
        for(int i=0;i<xl[x].size();i++){
            for(int j=0;j<xl[y].size();j++){
                ans=min(ans,w[x]+w[y]+xl[x][i].val+xl[y][j].val+dis[xl[x][i].to][xl[y][j].to]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//i forgot to write my diary again today...
//the last year.
//T1 is EASY, though i nearly get it wrong(forgot to consider it can be all turned into a number in the middle)
//if i can AC T2, i will write Time Machine in T1 or T3
//i can't possibly read T2 it is SO longgggggg 15:05
//if i can't get 100 out before 16:15 i'll give up
//ok we can see that d is incredibly small,15:16
//i think i have get the 100 way(?
//m*20 to get the best, a floyd for every route,then q*400(d^2) for max.
//20*5e5+5e2^3+1e5*4e2
//1e7+1.2e8+4e5=2e8
// still a bit risky to TLE actually...and it is mainly on n
//another way is n*dijkstra n*nlogn might help a bit
//i feel lucky that i decided to write the std of dij during testing time
// subway1 is right but 2...never mind 16:02
// i might spend a little more time on T2
//since i think 100+100+(T3orT4baoli)may be enough for 1= or for me to get to noip
// tested time for subway7 0.3s it definitely can work 16:40
