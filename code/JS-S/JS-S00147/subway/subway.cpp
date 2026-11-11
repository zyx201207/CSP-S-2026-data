#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pll;
const int N=5e3+10;
const int M=5e5+10;
int c,n,m,d,q,w[N+M],vis[M+N],dis[M+N];
vector<pll> g[M];
void dij(int s,int e){
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    priority_queue<pll,vector<pll>,greater<pll>> q;
    q.push({0,s});
    dis[s]=0;
    while(!q.empty()){
        int f=q.top().second,w=q.top().first;
        q.pop();
        if(vis[f])continue;
        vis[f]=1;
        for(auto e:g[f]){
            int nf=e.second,nw=e.first;
            if(dis[nf]>dis[f]+nw){
                dis[nf]=dis[f]+nw;
            }
            q.push(e);
        }
    }
    //cout<<1;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            g[j+m].push_back({a,t});
            g[a].push_back({j+m,t});
        }
    }

    for(int i=1;i<=q;i++){
        int s,e;
        cin>>s>>e;
        dij(s,e);
        cout<<dis[e]+w[s]+w[e]<<"\n";
    }
    return 0;
}


