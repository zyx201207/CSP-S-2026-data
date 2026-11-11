#include<bits/stdc++.h>
using namespace std;
ifstream fin("subway.in");
ofstream fout("subway.out");
#define int long long
#define cin fin
#define cout fout
int n,m,D,q;
vector<pair<int,int>> adj[500555];
int w[500555];
vector<vector<int>> res(20555,vector<int>(20555));
void dijsktra(int s){
    vector<char> vis(20555);
    for(int i=1;i<=n+m;++i) res[s][i]=1145141919810ll;
    res[s][s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,s});
    while(!q.empty()){
        auto [c,u]=q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        res[s][u]=c;
        for(auto [v,t]:adj[u])
            if(!vis[v]) q.push({c+t,v});
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin>>_>>n>>m>>D>>q;
    if(_<=11){
        for(int i=1;i<=m;++i) cin>>w[i];
        for(int i=1;i<=n;++i){
            int k;
            cin>>k;
            for(int j=1;j<=k;++j){
                int a,vvw;
                cin>>a>>vvw;
                adj[a].push_back({m+i,vvw});
                adj[m+i].push_back({a,vvw});
            }
        }
        for(int i=1;i<=m;++i) dijsktra(i);
        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<res[x][y]+w[x]+w[y]<<"\n";
        }
    }
    else if(_<=15){
        for(int i=1;i<=m;++i) cin>>w[i];
        for(int i=1;i<=n;++i){
            int k;
            cin>>k;
            for(int j=1;j<=k;++j){
                int a,vvw;
                cin>>a>>vvw;
                adj[a].push_back({m+i,vvw});
                adj[m+i].push_back({a,vvw});
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            vector<char> vis(n+m+5);
            queue<pair<int,int>> qq;
            qq.push({x,0});
            vis[x]=1;
            while(!qq.empty()){
                auto [u,c]=qq.front();
                qq.pop();
                if(u==y){
                    cout<<c+w[x]+w[y]<<"\n";
                    break;
                }
                for(auto [v,t]:adj[u])
                    if(!vis[v]){
                        vis[v]=1;
                        qq.push({v,c+t});
                    }
            }
        }
    }
    return 0;
}
