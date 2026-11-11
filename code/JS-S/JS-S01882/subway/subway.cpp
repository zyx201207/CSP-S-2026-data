#include<bits/stdc++.h>
using namespace std;
#define int long long
#define SZ(a) (int)(a.size())
#define pb push_back
#define mk make_pair
const int RD=505;
const int ST=5e5+1005;
int c,n,m,d;
struct node{
    int to,cos;
    bool operator <(node b)const{return cos>b.cos;}
};
vector<node>road[RD];
int getin[ST];
const int thinst=2005;
const int inf=1e12+7;
int dis[thinst][thinst];
bool vis[thinst];
priority_queue<node>pq;
int dij(int beg,int end){
    while(!pq.empty())pq.pop();
    for(int i=1;i<=n+m;i++)vis[i]=0;
    pq.push({beg,0});
    while(!pq.empty()){
        int pos=pq.top().to;
        int cost=pq.top().cos;
        pq.pop();
        if(vis[pos]&&dis[beg][pos]<=cost)continue;
        vis[pos]=1;
        // cout<<"i'm in "<<pos<<",with cost is {"<<cost<<'\n';
        dis[beg][pos]=min(dis[beg][pos],cost);
        for(int i=1;i<=n+m;i++){
            if(dis[pos][i]>=inf)continue;
            else{
                if(dis[beg][i]>cost+dis[pos][i]&&vis[i])continue;
                dis[beg][i]=min(dis[beg][i],dis[pos][i]+cost);
                // cout<<"from "<<pos<<", i can go to "<<i<<'\n';
                pq.push({i,dis[beg][i]});
            }
        }
        // cout<<"}\n";
    }
    return dis[beg][end];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int T;
    cin>>c>>n>>m>>d>>T;
    for(int i=1;i<=m;i++){
        cin>>getin[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            road[i].pb({x,y});
        }
    }
        for(int i=0;i<=n+m+1;i++){
            for(int j=0;j<=n+m+1;j++){
                dis[i][j]=inf;
            }
        }
        for(int i=1;i<=n;i++){
            int sz=SZ(road[i]);
            for(int u=0;u<sz;u++){
                int to=road[i][u].to;
                int cos=road[i][u].cos;
                dis[to][i+m]=cos;
                dis[i+m][to]=cos;
                // cout<<"from "<<i+m<<" to "<<to<<'\n';
            }
        }
        while(T--){
            int x,y;
            cin>>x>>y;
            cout<<getin[x]+getin[y]+dij(x,y)<<'\n';
        }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/