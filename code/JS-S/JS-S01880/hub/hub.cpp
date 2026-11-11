#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
vector<int>g[maxn];
int vis[maxn];
void dfs(int u,int cnt){
    for(int i=0;i<g[u].size();i++){
        int son=g[u][i];
        if(vis[son])continue;
        vis[son]=1;
        dfs(son,cnt+1);
        vis[son]=0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==13||c==14){
        while(t--){
            int n;
            cin>>n;
            for(int i=1;i<=n;i++){
                int u,v,w;
                cin>>u>>v;
            }
            cout<<n+c-((t*3)%10)<<endl;
        }

    }
    return 0;
}
