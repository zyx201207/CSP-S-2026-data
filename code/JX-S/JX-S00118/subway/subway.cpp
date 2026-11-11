#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int w[N],k[N],a[505][N],t[505][N];
vector<pair<int,int>> vec[N];
int dist[N];
void dijisktra(int s){
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({dist[s],s});
    while(q.size()){
        auto t=q.top();
        int u=t.second;
        //cout<<u<<' '<<dist[u]<<'\n';
        q.pop();
        for(auto x:vec[u]){
            int v=x.second,w=x.first;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            if(j!=1){
                vec[a[i][j-1]+m*(i-1)].push_back({0,a[i][j]+m*(i-1)});
                vec[a[i][j]+m*(i-1)].push_back({0,a[i][j-1]+m*(i-1)});
            }
            vec[m*d+a[i][j]].push_back({t[i][j],m*(i-1)+a[i][j]});
            vec[m*(i-1)+a[i][j]].push_back({t[i][j],m*d+a[i][j]});
        }
    }
    while(q--){
        int s,e;
        cin>>s>>e;
        dijisktra(s+m*d);
        cout<<w[s]+dist[e+m*d]+w[e]<<'\n';
    }
    return 0;
}
