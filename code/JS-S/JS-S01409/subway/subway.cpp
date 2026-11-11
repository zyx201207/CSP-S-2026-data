#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N = 405 + 5;
int read(){
    int f = 1,x = 0;
    char c = getchar();
    while(!isdigit(c))
        f = c == '-' ? -1 : 1,c = getchar();
    while(isdigit(c))
        x = (x << 3) + (x << 1) + (c ^ 48),c = getchar();
    return f * x;
}
int c,d,n,m,q;
int a[N][N],t[N][N],w[N],k[N],dis[N][N];
vector<int> fl[N];
vector<pii> G[N][N];
void dfs(int u,int dep){
    for(auto i : G[dep][u]){
        int v = i.first,w = i.second;
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c = read(),n = read(),m = read(),d = read(),q = read();
    for(int i=1;i<=m;i++)
        w[i] = read();
    for(int i=1;i<=n;i++){
        k[i] = read();
        for(int j=1;j<=k[i];j++)
            a[i][j] = read(),t[i][j] = read(),fl[a[i][j]];
    }
    if(c >= 12 && c <= 19){
        for(int i=1;i<n;i++){
            for(int j=1;j<=k[i];j++)
                dis[a[i][j]][a[i][j+1]] = 0;
        }
        while(q--){
            int u = read(),v = read();
            int ans = w[u] + w[v];
            cout<<ans<<'\n';
        }
        return 0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<k[i];j++){
            G[i][a[i][j]].push_back({a[i][j+1],0});
        }
    }
    while(q--){
        int u = read(),v = read();
        int ans = w[u] + w[v];
        cout<<ans + t[1][v]<<'\n';
    }
    return 0;
}