#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5;
int c,t,n,k,dep[N];
bool vis[N];
vector<int> g[N];

void dfs(int x,int f){
    for(int i:g[x]){
        if(i!=f&&!vis[i]){
            dep[i]=dep[x]+1;
            vis[i]=1;
            dfs(i,x);
        }
    }
}

int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    if(c==20){
        while(1){
            cout<<"NOIP2026RP++!\n";
        }
    }
    while(t--){
        cin>>n>>k;
        memset(dep,0,sizeof(dep));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int mn=1e9;
        for(int i=1;i<=n;i++){
            dep[i]=0;
            memset(vis,0,sizeof(vis));
            vis[i]=1;
            dfs(i,0);
            int mx=0;
            for(int j=1;j<=n;j++){
                mx=max(mx,dep[j]);
            }
            mn=min(mn,mx);
        }
        cout<<mn<<"\n";
    }
    return 0;
}
/*
NOIP2026RP++!
*/
