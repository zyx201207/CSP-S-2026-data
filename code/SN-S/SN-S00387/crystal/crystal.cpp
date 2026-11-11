#include <bits/stdc++.h>
using namespace std;

#define fir first
#define sec second
#define pb push_back
#define bs basic_string
#define sz(v) (LL)(v).size()
#define cir(x) rep(__tmp, 1, x)
#define rd(x) scanf("%lld", &(x))
#define all(v) (v).begin(), (v).end()
#define erg(i, pre, x) for(LL i = (pre)[x];i;i = a[i].next)
#define rep(i, l, r) for(LL i = (l), _tmp = (r);i <= _tmp;i++)
#define per(i, l, r) for(LL i = (l), _tmp = (r);i >= _tmp;i--)
typedef long long LL;
typedef pair<LL, LL> PII;
const LL INF = 0x3f3f3f3f3f3f3f3f, INF_BIT = 0x3f;

const LL N = 5e5 + 10;

LL n, m;
LL a[N];

LL s[N];

LL ans;

void solve(){
    rd(n), rd(m);
    rep(i, 1, n) rd(a[i]);
    
    sort(a + 1, a + n + 1);
    rep(i, 1, n) s[i] = s[i - 1] + a[i];
    
    rep(i, 1, n){
        LL l = 1, r = i;
        while(l <= r){
            LL mid = l + (r - l) / 2;
            if((i - mid + 1) * a[i] - s[i] + s[mid - 1] <= m) r = mid - 1;
            else l = mid + 1;
        }
        ans = max(ans, i - l + 1);
    }
    
    printf("%lld\n", ans);
}

int main(){
    // freopen("crystal4.in", "r", stdin);  //std=
    // freopen("crystal4.out", "w", stdout);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    
    solve();
    return 0;
}
