#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int w[N];
int c,n,m,d,q;
//vector <bool> b[505];
vector <int> G[N];//station to line
vector <pair<int,int>> L[505];//int name;int deep;
int t[505][N];
int k[505];
int dist[505];
int dijk(int u,int vv){
    int d1{0},d2{0};
    int d,v;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,u});
    dist[u]=0;
    while(!pq.empty()){
        pair<int,int> P=pq.top();
        pq.pop();
        dist[u]=min(dist[u],P.first);
        u=P.second;
        for(auto i:L[u]){
            //int i.first+d;
            d=i.first;
            v=i.second;
            if(dist[u]+d<dist[v]){
                dist[v]=dist[u]+d;
                pq.push({dist[v],v});
                if(v==vv) d2=G[v][v];
            }
        }
    }
    return dist[vv]+d1+d2;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        //cout<<w[i]<<endl;
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];//线路i的站点数
        for(int j=1;j<=k[i];j++){
            int stat,time;
            cin>>stat>>t[i][stat];//线路i 到 站点stat 的时间
            G[stat].push_back(i);
            //cout<<111;
        }
    }
    for(int stat=1;stat<=m;stat++){
        for(auto lu:G[stat]){
            for(auto lv:G[stat]){
                if(lv!=lu){
                    pair<int ,int> P;
                    P.first=t[lu][stat]+t[lv][stat];
                    P.second=lv;
                    L[lu].push_back(P);//lu->lv换乘时间
                    //cout<<lu<<" "<<lv<<" "<<t[lu][stat]+t[lv][stat]<<endl;
                    //for(auto PP:L[lu]) cout<<PP.first<<" "<<PP.second<<endl;
                    //cout<<L[lu][lv].first<<endl;
                }
            }
        }
    }
    while(q){
        int u,v,res;
        cin>>u>>v;
        //cout<<w[1]+w[2];
        if(u==v){
            cout<<0;
            continue;
        }
        //cout<<"["<<u<<v<<"]";
        for(int i=1;i<=n;i++) dist[i]=1e9+10;

        res=w[u]+w[v];
        res+=dijk(u,v)+G[u].front()+G[v].front();
        cout<<res<<endl;
        q--;
    }
    //cout<<L[1][2].first;
    return 0;
}
