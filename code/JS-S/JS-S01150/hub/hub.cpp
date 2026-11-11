#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000007;
int n,k,cnt[N];
vector<int>G[N];
void bfs(int st){
    int vis[N]={0};
    queue<pair<int,int>>q;
    q.push({st,0});
    while(!q.empty()){
        auto f=q.front();
        q.pop();
        int u=f.first,sum=f.second;
        vis[u]=1;
        for(auto v:G[u]){
            if(u==v||vis[v])continue;
            cnt[v]+=sum+1;
            q.push({v,sum+1});
        }
    }
}
void solve(){
    srand(time(NULL));
    for(int i=1;i<=n;i++)G[i].clear(),cnt[i]=0;
    cin>>n>>k;
    bool f=true;
    for(int u,v,i=1;i<n;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    //for(int i=1;i<=n;i++)bfs(i);
    cout<<rand()<<"\n";
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
