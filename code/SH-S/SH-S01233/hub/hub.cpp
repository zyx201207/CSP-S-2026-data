#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,dep[100005],a,b,maxdep,maxid;
vector<int> e[1000005];
void dfs(int u,int f) {
    dep[u] = dep[f] + 1;
    for(int v : e[u])
        if(v != f) dfs(v,u);
}
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
	cin.tie(nullptr); 
    cin >> c >> t;
    while(t--) {
        cin >> n >> k;
        maxdep = maxid = 0;
        for(int i = 1;i <= n;i++) e[i].clear();
        for(int i = 1;i < n;i++) {
            int u,v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1,0);
        for(int i = 1;i <= n;i++)
            if(dep[i] > maxdep) {
                maxdep = dep[i];
                maxid = i;
            }
        memset(dep,0,sizeof(dep));
        maxdep = 0;
        dfs(maxid,0);
        for(int i = 1;i <= n;i++)
            if(dep[i] > maxdep) {
                maxdep = dep[i];
                maxid = i;
            }
        cout << max((maxdep - k) / 2,1) << endl;
        memset(dep,0,sizeof(dep));
    }
    return 0;
}
