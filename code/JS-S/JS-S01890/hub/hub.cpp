#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int c,t,n,k;
vector <int> g[N];
bool vis[N],viss[N];
int dep[N];
int maxl;
int cnt = 0;

void dfs(int root,int lgt){
    dep[root] = lgt;
    for (auto i:g[root]){
        if (!vis[i + cnt]){
            vis[i + cnt] = 1;
            dfs(i + cnt,lgt + 1);
        }
    }
}

void fd(int root,int l){
    maxl = max(maxl,l);
    for (auto i:g[root]){
        if (!viss[i + cnt]){
            viss[i + cnt] = 1;
            //cout << 1;
            fd(i,l + 1);
            viss[i + cnt] = 0;
        }
    }
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while (t--){
        cin >> n >> k;
        for (int i = 1;i < n;i++){
            int u,v;
            cin >> u >> v;
            g[u + cnt].push_back(v);
            g[v + cnt].push_back(u);
        }
        vis[1 + cnt] = 1;
        dfs(1 + cnt,1);
        int maxn = -1,idx = 0;
        for (int i = 1 + cnt;i <= n + cnt;i++){
            //cout << dep[i + cnt] << " ";
            if (dep[i + cnt] > maxn){
                maxn = dep[i + cnt];
                idx = i;
            }
        }
        viss[1 + cnt] = 1;
        fd(idx,1);
        //cout << maxl << " ";
        cout << maxl / k << endl;
        cnt += n;
    }
    return 0;
}
