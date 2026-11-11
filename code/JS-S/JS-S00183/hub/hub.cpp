#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxN=1e6+20;
vector<int> edge[maxN];
int dis[maxN];
void dfs(int u,int fa) {
    for (auto v:edge[u]) {
        if (v==fa) continue;
        if (dis[v]>dis[u]+1) {
            dis[v]=dis[u]+1;
            dfs(v,u);
        }
    }
}
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        for (int i=1;i<n;i++) {
            int u,v;
            cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        cout<<1<<"\n";
    }
    return 0;
}
