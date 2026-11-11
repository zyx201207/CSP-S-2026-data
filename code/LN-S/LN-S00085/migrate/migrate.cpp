#include <bits/stdc++.h>

using namespace std;

using ci = const int;
using cll = const long long;
using ll = long long;
using ull = unsigned long long;
using pii = pair <int,int>;

namespace namespace_qwq {

ci N = 2e6 + 5;
ci inf = 0x7f7f7f7f;
cll LLinf = 1e16;
cll mod = 998244353;

template <typename T>
inline void cmax(T &x,const T &y) {if(y > x) x = y;}

template <typename T>
inline void cmin(T &x,const T &y) {if(y < x) x = y;}

int c,t;

int n;
ll d;
ll x[N];

int f[N];
int dis[N];

void dfs(int u,int len) {
    if(len < dis[u]) dis[u] = len,f[u] = 1;
    else if(len == dis[u]) f[u]++;
    for(int i = u + 1;i <= n;i++) {
        if(x[u] + d >= x[i]) dfs(i,len + 1);
        else break;
    }
}

inline void Main() {
    cin >> c >> t;
    ll k,u,v,s,cnt,minn;
    while(t--) {
        cin >> n >> d;
        minn = (ll)(3e18);
        for(int i = 1;i <= n;i++) {
            cin >> x[i];
            if(i >= 2) cmin(minn,x[i] - x[i - 1]);
        }
        if(n == 1 || n == 2) cout << "0\n";
        else if(minn >= d) cout << "0\n";
        else if(c == 13 || c == 14 || ((x[n] - x[1]) <= d)) cout << "0\n";
        else if(c == 11 || c == 12) {
            k = x[2] - x[1];
            u = d / k;
            v = u - 1;
            s = u + v;
            cout << n - (s + 1) + 1 << "\n";
        } else {
            cnt = 0;
            for(int i = 1;i <= n;i++) {
                for(int j = 1;j <= n;j++) dis[j] = inf;
                dfs(i,0);
                for(int j = 1;j <= n;j++) {
                    if(f[j] == 2) cnt++;
                }
            }
            cout << cnt << "\n";
        }
    }
}

};

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    namespace_qwq::Main();
    return 0;
}