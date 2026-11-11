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

const LL N = 2e6 + 10;

LL id, t;
LL n, d;
LL a[N];

LL nxt[N];
LL ch[N];

LL ans;

void solve(){
    rd(id), rd(t);
    cir(t){
        ans = 0;
        
        rd(n), rd(d);
        rep(i, 1, n) rd(a[i]);
        
        // if(n == 197) continue;
        
        // LL g = d;
        // per(i, n, 1) a[i] -= a[1], g = __gcd(g, a[i]);
        // d /= g;
        // rep(i, 2, n) a[i] /= g;
        // printf("d=%lld | ", d);
        // rep(i, 1, n) printf("%lld ", a[i] /* - a[1] */);
        // rep(i, 2, n) printf("%lld ", a[i] - a[i - 1]);
        // puts("");
        
        LL j = n;
        nxt[n] = nxt[n + 1] = n + 1;
        per(i, n - 1, 1){
            while(j >= i && a[j] - a[i] > d) j--;
            nxt[i] = j;
        }
        
        rep(i, 1, n){
            LL j = nxt[i], k = nxt[j];
            if(j == i || k == j || k == n + 1){ ch[i] = 0; continue; }
            auto l = lower_bound(a + i, a + n + 1, a[k] - d), r = upper_bound(a + i, a + n + 1, a[i] + d);
            ch[i] = r - l;
        }
        
        // rep(i, 1, n) printf("%lld:%lld,%lld ", i, nxt[i], ch[i]);
        // puts("");
        
        rep(i, 1, n){
            LL x = i;
            bs<LL> v;
            while(x <= n){
                v += x;
                if(x == nxt[x]) break;
                x = nxt[x];
            }
            // v += n + 1;
            LL c2 = 0;
            rep(j, 1, sz(v) - 1){
                LL l = 0, r = 0;
                if(c2 /* && v[j - 1] < v[j] - 1 */){
                    l = upper_bound(a + v[j] + 1, a + n + 1, max(a[v[j - 1]], a[v[j] - 1]) + d) - a, r = upper_bound(a + v[j] + 1, a + n + 1, a[v[j]] + d) - a;
                }else{
                    if(v[j - 1] < v[j] - 1)
                    l = upper_bound(a + v[j] + 1, a + n + 1, max(a[v[j - 1]], a[v[j] - 2]) + d) - a, r = upper_bound(a + v[j] + 1, a + n + 1, a[v[j] - 1] + d) - a;
                }
                ans += r - l;
                // printf("from i=%lld at i'=%lld [c2=%lld]: +[%lld,%lld) %lld\n", i, v[j], c2, l, r, r - l);
                {
                    LL t = ch[v[j - 1]];
                    if(t > 2) break;
                    c2 += t == 2;
                    if(c2 > 1) break;
                }
            }
            // printf("from i=%lld: %lld\n", i, ans);
        }
        
        printf("%lld\n", ans);
        // if(__tmp == 5) break;
    }
}

int main(){
    // freopen("migrate4.in", "r", stdin);  //std=0
    // freopen("1.in", "r", stdin);  //std=9
    // freopen("1.out", "w", stdout);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    
    solve();
    return 0;
}

/*
8129 - 4160
16 - 4
9 - 3
7 - 4
12 - 10
0
0
0
2
1
0
2
3
6
0
2
0
*/
