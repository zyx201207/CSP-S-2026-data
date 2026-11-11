#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[505];
long long t[505][500005];
vector<int> g[500005];
int st,en;
int vis[505];
long long dfs(int line,int x){
    if(x==en){
        return 0;
    }
    if(vis[x]==1)return 0;
    vis[x] = 1;
    long long ans = LONG_LONG_MAX;
    for(int j = 1;j <= n;j++){
        for(int k = 0;k < g[j].size();k++){
            ans = min(ans,dfs(j,g[j][k])+t[x][line]+t[x][j]);
        }
    }
    for(int j = 0; j < g[x].size();j++){
        ans = min(dfs(line,g[x][j]),ans);
    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= m;i++){
        cin>>w[i];
    }
    for(int i = 1;i <= n;i++){
        int k;cin>>k;
        for(int j = 1;j <= k;j++){
            int idx;long long ti;
            cin>>idx>>ti;
            g[i].push_back(idx);
            t[i][idx] = ti;
        }
    }
    while(q--){
        cin>>st>>en;
        long long ans = LONG_LONG_MAX;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j < g[i].size();j++){
                if(g[i][j]==st){
                    memset(vis,0,sizeof(vis));
                    ans = min(ans,dfs(i,st))+w[st]+w[en];
                }
            }
        }
        cout<<ans<<' ';
    }
    return 0;
}
