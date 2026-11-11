#include<bits/stdc++.h>
#define int long long

int C,_;

namespace baoli{
    int N,D;
    int arr[2000005];
    std::vector<int> g[2000005];
    int dis[2000005];
    bool vis[2000005];
    std::queue<int> q;
    void bfs(int st){
        for(int i=0;i<2000005;i++)dis[i] = INT_MAX;
        memset(vis,0,sizeof vis);
        dis[st] = 0; q.push(st); vis[st] = 1;
        while(!q.empty()){
            int x = q.front(); q.pop();
            for(auto v:g[x]){
                if(vis[v])continue;
                dis[v] = dis[x]+1; vis[v] = 1; q.push(v);
            }
        }
    }
    int dfs(int x,int step,int ed){
        if(x == ed && step == 0)return 1;
        else if(step == 0)return 0;
        int tmp = 0;
        for(auto v:g[x])tmp += dfs(v,step-1,ed);
        return tmp;
    }
    void solve(){
        for(int i=0;i<2000005;i++)g[i].clear();
        scanf("%lld %lld",&N,&D);
        bool flag = 1;
        for(int i=1;i<=N;i++){
            scanf("%lld",arr+i);
            if(i >= 3)flag &= (arr[i]-arr[i-1] == arr[2]-arr[1]);
        }
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                if(abs(arr[j]-arr[i]) <= D){
                    g[i].push_back(j); g[j].push_back(i);
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=N;i++){
            bfs(i);
            for(int j=i+1;j<=N;j++){
                if(dis[j] == INT_MAX)continue;
                if(dfs(i,dis[j],j) == 2)ans++;
            }
        }
        printf("%lld\n",ans);
    }
}

signed main(){
    freopen("migrate.in","r",stdin); freopen("migrate.out","w",stdout);
    scanf("%lld %lld",&C,&_);
    while(_--)baoli::solve();
    return 0;
}
