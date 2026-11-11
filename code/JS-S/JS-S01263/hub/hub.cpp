#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int N=1e6+5;
int n,k,dis[N];
bool is[N];
vector<int> g[N];
void dfs(int x){
    is[x]=0;
    for(int u:g[x]) if(is[u]) dfs(u);
}
void sol(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n<=10){
        int mxs=(1<<n)-1;
        int ans=INT_MAX;
        for(int s=0;s<=mxs;s++){
            if(__builtin_popcount(s)!=k) continue;
            for(int i=1;i<=n;i++) is[i]=(s>>(i-1))&1;
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(is[i]){
                    dfs(i);
                    cnt++;
                }
            }
            if(cnt!=2) continue;
            queue<int> q;
            for(int i=1;i<=n;i++) dis[i]=-1;
            for(int i=1;i<=n;i++){
                if((s>>(i-1))&1){
                    q.push(i);
                    dis[i]=0;
                }
            }
            int mx=0;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                mx=max(mx,dis[u]);
                for(int v:g[u]){
                    if(dis[v]!=-1) continue;
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
            ans=min(ans,mx);
        }
        printf("%d\n",ans);
        return;
    }
    printf("0\n");
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--) sol();
    return 0;
}
