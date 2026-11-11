//1h 15min in a simple T1 greedy problem,hyw?
//However rp++!
//pray for everyone: AK CSPS
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=505;
int c,n,m,d,q,k;
int w[maxn];
struct node{
    int u;
    int val;
    bool operator<(const node T1)const{
        return val>T1.val;//small root pq
    }
};
int T[maxn][maxn];///di i tiao xianlu dao a zhan zhantai de shijian
vector<int>vis[maxn];
vector<node>edge[maxn];
array<int,maxn>visp;
array<int,maxn>dis;
pair <int,int>qr[maxn];
vector<node>vnow[maxn];
void dijkstra(int u){
    visp.fill(0);
    dis.fill(INT_MAX);
    dis[u]=0;
    priority_queue<node>pq;
    pq.push({u,0});
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        for(auto v:vnow[it.u]){
            if(visp[v.u])continue;
            visp[v.u]=1;
            if(dis[v.u]>dis[it.u]+v.val){
                dis[v.u]=dis[it.u]+v.val;
                pq.push({v.u,dis[v.u]});
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int a,t;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            vis[a].push_back(i);
            T[i][a]=t;
        }
    }
    for(int i=1;i<=m;i++){
        for(auto it:vis[i]){
            for(auto itn:vis[i]){
                if(it==itn)continue;
                edge[it].push_back({itn,T[it][i]+T[itn][i]});//zhelishi ditieA->zhantai->ditieB
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>qr[i].first>>qr[i].second;
    }
 //   int u=502;

    for(int i=1;i<=q;i++){
        for(int j=0;j<maxn;j++) vnow[j]=edge[j];
        for(auto it:vis[qr[i].first]){
            vnow[502].push_back({it,w[qr[i].first]+T[it][qr[i].first]});
        }
        dijkstra(502);
        int ans=INT_MAX;
        for(auto it:vis[qr[i].second]){
            ans=min(ans,dis[it]+w[qr[i].second]+T[it][qr[i].second]);
        }
        cout<<ans<<endl;
    }
}
