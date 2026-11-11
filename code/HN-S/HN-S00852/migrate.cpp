#include<bits/stdc++.h>
#define int long long
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
    const int N = 2e6 + 5;
    int n, d;
    int x[N];
    int pre[N], suf[N];
    int d1[N], d2[N]; // dsuf, dpre
    int l[N], r[N];
    int sl[N], sr[N];
    inline void main(){
        cin >> n >> d;
        rep(i, 1, n) cin >> x[i];
        pre[0] = pre[n + 1] = 0, suf[0] = suf[n + 1] = 0;
        rep(i, 0, n + 1) d1[i] = d2[i] = 0; 
        rep(i, 1, n){
            pre[i] = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
            if(x[i] - d < x[1]) pre[i] = 0;
            if(pre[i] == i) pre[i] = 0;
            suf[i] = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
            if(x[i] + d > x[n]) suf[i] = n + 1;
            if(suf[i] == i) suf[i] = n + 1;
            ++ d1[suf[i]], ++ d2[pre[i]];
        }

        // rep(i, 1, n) cerr << pre[i] << " "; cerr << "\n";
        // rep(i, 1, n) cerr << suf[i] << " "; cerr << "\n";

        rep(i, 1, n){
            l[i] = i, sl[i] = d1[i];
            if(suf[pre[i]] == i) l[i] = l[pre[i]], sl[i] += sl[pre[i]];
        }
        per(i, n, 1){
            r[i] = i, sr[i] = d2[i];
            if(pre[suf[i]] == i) r[i] = r[suf[i]], sr[i] += sr[suf[i]];
        }
        int ans = 0;
        rep(i, 2, n){
            if(!d1[i] || !d2[i - 1]) continue ;
            int suml = d1[i], sumr = d2[i - 1];
            if(suf[pre[i - 1]] == i) suml += sl[pre[i - 1]];
            if(pre[suf[i]] == i - 1) sumr += sr[suf[i]];

            if(suf[i - 1] == i) -- suml;
            if(pre[i] == i - 1) -- sumr;

            ans += suml * sumr;
            // cerr << i << " " << suml << " " << sumr << "\n";
        }
        cout << ans << "\n";
        return ;
    }
}

signed main(){
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> subtask;
    int t; cin >> t; while(t --) my :: main();

    return 0;
}
