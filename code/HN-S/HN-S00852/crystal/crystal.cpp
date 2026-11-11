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

const int N = 5e5 + 5;
int n, m;
int a[N], s[N];

signed main(){
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    rep(i, 1, n) s[i] = s[i - 1] + a[i];
    int ans = 0;
    rep(i, 1, n){
        int l = 1, r = i, p = i;
        while(l <= r){
            int mid = l + r >> 1;
            if(a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) p = mid, r = mid - 1;
            else l = mid + 1;
        }
        chkmax(ans, i - p + 1);
    }
    cout << ans << "\n";

    return 0;
}