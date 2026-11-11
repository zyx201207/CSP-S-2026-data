#include<bits/stdc++.h>
#define bk(v, i) v[v.size() - (i)]
#define all(v) v.begin(), v.end()
#define rep(i, l, r) for(int i = (l);i <= (r);i++)
#define per(i, r, l) for(int i = (r);i >= (l);i--)
using namespace std;

const int INF = sizeof(int) == 4 ? (int)1e9 + 1 : (int)1e18 + 1;
template<typename T> inline void chkmin(T &x, T y){ ( x > y ) && ( x = y ); }
template<typename T> inline void chkmax(T &x, T y){ ( x < y ) && ( x = y ); }

int subtask;

namespace my 
{
    const int N = 1e6 + 5;
    int n, k;
    vector<int> e[N];
    int dfn[N], low[N], pos[N], now;
    int pa[N];
    inline void dfs(int x, int fa){
        pa[x] = fa;
        dfn[x] = ++ now, pos[now] = x;
        for(int i : e[x]) if(i ^ fa) dfs(i, x);
        low[x] = now;
    }

    int dep[N], mxdep[N];
    bool fl[N];
    int c[N];
    inline void dfs2(int x, int fa, int lim){
        // fl[x] = 1;
        mxdep[x] = !fl[x] ? dep[x] : -1;
        c[x] = 0;
        for(int i : e[x]) if(i ^ fa){
            dep[i] = dep[x] + 1;
            dfs2(i, x, lim);
            chkmax(mxdep[x], mxdep[i]);
            c[x] += c[i];
        }
        if(mxdep[x] - dep[x] >= lim) ++ c[x];
        // if(lim == 1) cerr << x << " " << mxdep[x] << " " << dep[x] << " " << c[x] << "\n";
    }
    inline void dfs3(int x, int fa, int lim, int dis){
        if(dis > lim) return ;
        fl[x] = 1;
        for(int i : e[x]) if(i ^ fa) dfs3(i, x, lim, dis + 1);
    }    

    int mx[N];
    inline void dfs1(int x, int fa){
        int mx1 = 0, mx2 = 0;
        for(int i : e[x]) if(i ^ fa){
            if(mxdep[i] > mxdep[mx1]) mx2 = mx1, mx1 = i;
            else if(mxdep[i] > mxdep[mx2]) mx2 = i;
        }
        for(int i : e[x]) if(i ^ fa){
            mx[i] = fl[i] ? -1 : 0;
            if(mx[x] != -1) chkmax(mx[i], mx[x] + 1);
            if(mx1 != i){
                if(mx1) chkmax(mx[i], mxdep[mx1] - dep[x] + 1);
            }
            else {
                if(mx2) chkmax(mx[i], mxdep[mx2] - dep[x] + 1);
            }
            dfs1(i, x);
        }
    }

    inline bool check(int mid){

        // cerr << mid << "\n";
        rep(y, 1, n){
            // if(mid == 1) cerr << y << "\n";
            rep(i, 1, n) fl[i] = 0;
            dfs2(1, 0, mid);

            // if(mid == 1) cerr << "----------------\n";
            int cnt = c[y];
            if(!cnt) cnt = 1;

            rep(i, dfn[y], low[y]) fl[pos[i]] = 1;
            
            dfs3(y, 0, mid, 0);
            dfs2(1, 0, mid);
            
            mx[1] = fl[1] ? -1 : 0, dfs1(1, 0);
            
            
            if(mx[y] <= mid && cnt <= k){
                // cerr << mid << " " << y << " " << mx[y] << "\n";
                return 1;
            }

            rep(x, 1, n) if(mx[x] <= mid){
                // if(mid == 1){
                //     cerr << x << " " << y << " " << cnt + max(1, c[x]) << "\n";
                // }
                if(cnt + max(1, c[x]) <= k){
                    // cerr << mid << " " << x << " " << y << "\n";
                    return 1;
                }
            }
        }
        return 0;
    }

    inline void main(){
        cin >> n >> k;
        // cerr << n << " " << k << "\n";
        rep(i, 1, n) e[i].clear();
        rep(i, 1, n - 1){
            int u, v; cin >> u >> v;
            e[u].push_back(v), e[v].push_back(u);
        }

        now = 0, dfs(1, 0);
        int l = 0, r = n, ans = n;
        while(l <= r){
            int mid = l + r >> 1;
            if(check(mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << ans << "\n";
        return ;
    }
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin >> subtask;
    int t; cin >> t; while(t --) my :: main();
    return 0;
}