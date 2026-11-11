#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 4;
int n, k;
vector<int>bc[N];
set<int> ss[N];
int f[N], dep[N], siz[N];
void dfs(int x, int fx) {
    siz[x] = 0;
    for(int p : bc[x]) {
        if(p == fx) continue;
        dep[p] = dep[x] + 1;
        dfs(p,x);
        siz[x] = max(siz[x], siz[p]+1);
    }
    f[x] = fx;
}
bool chkrt(int rt, int mid) {
    memset(dep,0,sizeof dep);
    for(int i = 1; i <= n; ++i) {
        ss[i].clear();
    }
    dep[rt] = 1;
    dfs(rt, 0);
    for(int i = 1; i <= n; i++) {
        if(siz[i]>=mid)ss[dep[i]].insert(i);
    }
    int ans = 0;
    for(int i = n; i >= 1; --i) {
        ans += ss[i].size();
        if(ss[i].size()&&ss[i].size()<=2) {

            if(i<=mid+1) {if(ss[i].size()==1) {
                return ans < k;
            }
                if(bc[*ss[i].begin()].size()==3||bc[*next(ss[i].begin())].size()==3) {
                    ans--;
                }
                return ans <= k;
            }
        }
        for(int p : ss[i]) {
            ss[i-1].insert(f[p]);
        }
    }
}


bool chk(int mid) {
    if(!mid)return 0;
    for(int rt = 1; rt <= n; ++rt) {
        if(chkrt(rt, mid)) return 1;
    }
    return 0;
}
void solve() {
    cin >> n >> k;
    int u, v;
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        bc[u].push_back(v);
        bc[v].push_back(u);
    }
    if(k == n) {
        cout << 0 << '\n'; return ;
    }

    int L = 0, R = n;
    // (L,R]
    while(L + 1 < R) {
        int mid = ( L + R ) >> 1;
        if(chk(mid)) {
            R = mid;
        } else {
            L = mid;
        }
    }
    cout << R << '\n';
}
signed main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    int c, t;
    cin >> c >> t;
    while(t--) solve();

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
 9 10*/
