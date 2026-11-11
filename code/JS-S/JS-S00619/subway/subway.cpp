#include<bits/stdc++.h>
#define int long long
constexpr int N=1e6+5;
using namespace std;
vector<array<int,2>> g[N];
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<int> w(m+5);
    for (int i=1;i<=m;i++) {
        cin>>w[i];
    }
    for (int i=1;i<=n;i++) {
        int k;
        cin>>k;
        for (int j=1;j<=k;j++) {
            int a,t;
            cin>>a>>t;
            g[a].push_back({m+i,t});
            g[m+i].push_back({a,t});
        }
    }
    while (q--) {
        int x,y;
        cin>>x>>y;
        queue<array<int,2>> que;
        que.push({x,0});
        vector<int> dist(m+n+5,LLONG_MAX);
        dist[x]=0;
        while (!que.empty()) {
            int now=que.front()[0];
            int d=que.front()[1];
            que.pop();
            if (d>dist[now]) {
                continue;
            }
            dist[now]=d;
            for (const auto &it:g[now]) {
                if (d+it[1]<dist[it[0]]) {
                    dist[it[0]]=d+it[1];
                    que.push({it[0],dist[it[0]]});
                }
            }
        }
        cout<<w[x]+dist[y]+w[y]<<"\n";
    }
    return 0;
}
