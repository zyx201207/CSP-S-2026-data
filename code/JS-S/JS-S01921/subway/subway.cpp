#include<bits/stdc++.h>
using namespace std;
typedef pair<int,long long> PILL;
typedef pair<int,int> PII;
const int MAXN=505;
const int MAXM=5e5+10;
const int MAXQ=1e5+10;
const long long INF=1e18;
long long w[MAXM];
int c,n,m,d,q;
vector<PILL>e[MAXM];
vector<PILL>kk;
struct plans{
    int x;
    int y;
}p[MAXQ];
long long dist[MAXM];
bool vis[MAXM];
bool cmp(PILL x,PILL y){
    return x.second<y.second;
}
void dijkstra(int start){
    for(int i=0;i<=m;i++){
        dist[i]=INF;
        vis[i]=false;
    }
    priority_queue<PILL,vector<PILL>,greater<PILL>>heap;
    heap.push({start,0});
    while(!heap.empty()){
        PILL temp=heap.top();
        heap.pop();
        int u=temp.first;
        long long dis=temp.second;

        if(vis[u])continue;
        vis[u]=true;

        for(int i=0;i<e[u].size();i++){
            int to=e[u][i].first;
            int W=e[u][i].second;
            if(vis[to])continue;
            if(dist[to]<dis+W){
                dist[to]=dis+W;
                heap.push({to,dist[to]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a;
            long long t;
            cin>>a>>t;
            kk.push_back({a,t});
        }
    }
    for(int r=0;r<kk.size()-1;r++){
        for(int j=r+1;j<kk.size();j++){
            e[kk[r].first].push_back({kk[j].first,kk[r].first});
        }
    }
    for(int i=1;i<=q;i++){
        cin>>p[i].x>>p[i].y;
        long long ans=w[p[i].x]+w[p[i].y];
        dijkstra(p[i].x);
        ans+=dist[p[i].y];
        cout<<ans<<endl;
    }
    return 0;
}
