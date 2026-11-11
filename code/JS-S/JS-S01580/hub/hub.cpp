#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e6 + 5;
int c,t,n,k,used[N],dis[N],cnt = 0x3f3f3f3f3f3f;
vector<int> g[N];

bool check(int x) {
    int cnt = 0, num = 0;
    while(x) {
        num++;
        if(x & 1) {
            cnt++;
            used[num] = 1;
        }
        else used[num] = 0;
        x >>= 1;
    }
    if(cnt == k) return true;
    return false;
}
void dfs(int u,int v,int stp,int fa) {
    if(u == v) {
        cnt = min(cnt,stp);
        return;
    }
    for(int i = 0; i < g[u].size(); i++) {
        int to = g[u][i];
        if(to == fa) continue;
        dfs(to,v,stp + 1,u);
    }
}
signed main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 1;i < n; i++) {
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i = 0; i < (1ll << n); i++) {
            if(!check(i)) continue;
            vector<int> s;
            int d = 0;
            for(int j = 1; j <= n; j++) {
                dis[j] = 0x3f3f3f3f3f3f;
                if(used[j]) {
                    dis[j] = 0;
                    s.push_back(j);
                }
                else {  
                    for(int h = 0; h < s.size(); h++) {
                        cnt = 0x3f3f3f3f3f3f;
                        dfs(j,s[h],0,0);
                        dis[j] = min(dis[j],cnt);
                    }
                }
                d = max(d,dis[j]);
            }
            int ans = 0x3f3f3f3f3f3f;
            ans = min(ans,d);
            cout << ans << "\n";
        }
    }
    return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/