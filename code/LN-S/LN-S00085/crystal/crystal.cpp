#include <bits/stdc++.h>

using namespace std;

using ci = const int;
using cll = const long long;
using ll = long long;
using ull = unsigned long long;
using pii = pair <int,int>;

namespace namespace_qwq {

ci N = 5e5 + 5;
ci inf = 0x7f7f7f7f;
cll LLinf = 1e16;
cll mod = 998244353;

template <typename T>
inline void cmax(T &x,const T &y) {if(y > x) x = y;}

template <typename T>
inline void cmin(T &x,const T &y) {if(y < x) x = y;}

int n;
ll m;
ll a[N];

ll t[N];
ll sum[N];

ll val;

inline bool check(ci &mid,ci &idx) {
    val = sum[idx] - sum[mid - 1] - (ll)(1e12) * (0LL + idx - mid + 1LL) + a[idx] * (0LL + idx - mid + 1LL);
    return val <= m;
}

inline void Main() {
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++) t[i] = (ll)(1e12) - a[i];
    for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + t[i];
    int ans = 1;
    for(int i = 1,l,r,mid;i <= n;i++) {
        l = 1,r = i;
        while(l < r) {
            mid = (l + r) >> 1;
            if(check(mid,i)) r = mid;
            else l = mid + 1;
        }
        cmax(ans,i - l + 1);
    }
    cout << ans;
}

};

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    namespace_qwq::Main();
    return 0;
}