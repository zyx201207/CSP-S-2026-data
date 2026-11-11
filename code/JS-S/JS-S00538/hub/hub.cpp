#include<bits/stdc++.h>
using namespace std;
const int N=20;
vector < int > G[N];
bool vis[N];
int dep[N],mx;
inline void dfs(int x,int fa){
    if (vis[x]) mx=min(mx,dep[x]);
    for (auto v:G[x]){
        if (v==fa) continue;
        dep[v]=dep[x]+1;
        dfs(v,x);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;cin>>c>>t;
    while (t--){
        int n,k;cin>>n>>k;
        for (int i=0;i<n;i++) G[i].clear();
        for (int i=1;i<n;i++){
            int x,y;cin>>x>>y;x--,y--;
            G[x].push_back(y),G[y].push_back(x);
        }
        int ans=n;
        for (int i=0;i<(1<<n);i++){
            int cnt=0;
            for (int j=0;j<n;j++) if (i&(1<<j)) cnt++;
            if (cnt!=k) continue;
            memset(vis,0,sizeof(vis));
            cnt=0;
            for (int j=0;j<n;j++){
                if (i&(1<<j)){
                    for (auto v:G[j]) if (vis[v]) cnt--;
                    vis[j]=1;
                    cnt++;
                }
            }
            if (cnt<=2){
                int qwq=0;
                for (int j=0;j<n;j++){
                    mx=0x3f3f3f3f;
                    memset(dep,0,sizeof(dep));
                    dfs(j,0);qwq=max(qwq,mx);
                }
                ans=min(ans,qwq);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}