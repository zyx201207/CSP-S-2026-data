#include <bits/stdc++.h>

#define int long long
#define ull unsigned long long
#define up(i, a, b) for (int i = a; i <= b; i++)
#define down(i, a, b) for (int i = b; i >= a; i--)
#define unmap unordered_map 
#define pb push_back

using namespace std;

const int N = 2e5 + 101;

const int INF = LLONG_MAX;

int n, a[N], m, cha[N], ans, b[N], m1;
int center;

inline bool comp (int x, int y){
    return abs(b[center] - x) < abs(b[center] - y);
}
inline void solve (){
    cin >> n >> m;
    up (i, 1, n) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a + 1, a + n + 1);
    up (i, 1, n) {
        center = i;
        sort(a + 1, a + n + 1, comp);
        int j = 1, ans1 = 0;
        m1 = m;
        while (m1) {
            if (m1 <= a[j]) {
                break;
            }
            ans1 ++;
            m1 -= a[j++];
        }
        ans = max(ans1 , ans);
    }
    cout << ans << '\n';
}


signed main() {
    freopen ("crystal.in","r",stdin);
    freopen ("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}