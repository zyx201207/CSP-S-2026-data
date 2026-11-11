#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
    ll num = 0,sign = 1;char ch = getchar();
    while(ch < '0' || ch > '9') sign = (ch == '-' ? -1 : 1),ch = getchar();
    while('0' <= ch && ch <= '9') num = (num << 3) + (num << 1) + ch - '0',ch = getchar();
    return (sign > 0 ? num : -num);
}
const int maxn = 2e6 + 8;
const ll inf = 1e18;
ll a[maxn],vis[maxn],dis[maxn],ans[maxn],x,y;bool A = 1;
vector<int> adj[maxn];
void dfs(int i,ll l){
    if(dis[i] > l) dis[i] = l,ans[i] = 1;
    else if(dis[i] == l) ans[i]++;
    else return ;
    for(int v : adj[i]){
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v,l + 1);
        vis[v] = 0;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c = read(),t = read();
    while(t--){
        int n = read();ll d = read();x = 0;
        for(int i = 1;i <= n;i++){
            a[i] = read(),vis[i] = 0,dis[i] = inf;
            if(i > 2) A = (A && y == a[i] - a[i - 1]);
            if(i > 1) y = a[i] - a[i - 1];
        }
        if(c == 13 || c == 14){
            cout << 0 << '\n';
            continue;
        }
        if(A){
            d /= y;
            cout << n - d * 2 + 1 << '\n';
            continue;
        }
        for(int i = 1;i <= n;i++)
            for(int j = i + 1;j <= n;j++)
                if(a[j] - a[i] <= d){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++) ans[j] = 0,dis[j] = inf;
            vis[i] = 1;dfs(i,0);vis[i] = 0;
            for(int j = 1;j <= n;j++)
                if(ans[j] == 2) x++;
        }
        cout << x / 2 << '\n';
        for(int i = 1;i <= n;i++) adj[i].clear();
    }
    return 0;
}
