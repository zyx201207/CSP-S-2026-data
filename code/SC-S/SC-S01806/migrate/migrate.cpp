#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
#define usd unsigned
#define AC return
#define AK return 0
#define el putchar('\n')
#define YS cout << "YES"
#define NO cout << "NO"
#define Ys cout << "Yes"
#define No cout << "No"
#define ys cout << "yes"
#define no cout << "no"
#define void inline void
#define il inline
#define lowbit(x) ((x) & (-(x)))
#define debug(x) cerr << #x << ' ' << x << '\n'
#define Mod(x) (((x) % mod + mod) % mod)
il char gc() { char c; while((c = getchar()) <= ' ') ; return c; }
il int rd() {
    int x, f = 1; char c;
    while(!isdigit(c = getchar())) if(c == '-') f = -f;
    x = c ^ 48;
    while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + (c ^ 48);
    return x * f;
}
void ACehomoxue();
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int t = 1, c;
    c = rd(), t = rd();
    while(t--) ACehomoxue();
    AK;
}
const int mod = 998244353, maxn = 2 * 1e6 + 18;

int n, d, x[maxn], l[maxn], r[maxn], sf[maxn], c[maxn], pr[maxn], ans = 0, s[maxn];

void ACehomoxue() {
    n = rd(), d = rd(), ans = 0;
    for(int i = 1; i <= n; i++) x[i] = rd();
    for(int i = 1, p = 1; i <= n; i++) {
        while(p < i && x[i] - x[p] > d) p++;
        l[i] = p; 
        c[p]++;
    }
    for(int i = n, p = n; i; i--) {
        while(p > i && x[p] - x[i] > d) p--;
        r[i] = p;
    }
    // for(int i = 1; i <= n; i++) cout << i << ": " << l[i] << ' ' << r[i], el;
    for(int i = n; i; i--) {
        sf[i] = 1; 
        if(i != r[i] && l[r[i]] == i) sf[i] += sf[r[i]] + c[i] - 1; 
        else if(i != r[i]) sf[i] += c[i];
    }
    for(int i = 1; i <= n; i++) c[i] = 0;
    for(int i = 1; i <= n; i++) c[r[i]]++;
    for(int i = 1; i <= n; i++) {
        pr[i] = 1;
        if(i != l[i] && r[l[i]] == i) pr[i] += pr[l[i]] + c[i] - 1;
        else if(i != l[i]) pr[i] += c[i];
        if(r[i] <= i + 1) continue;
        if(l[r[i] - 1] == i) s[r[i]] += pr[i];
        else s[r[i]]++;
    }
    for(int i = 1; i <= n; i++) {
        int p = l[i];
        if(p >= i - 1) continue;
        if(r[p + 1] == i) ans += sf[i] * s[p + 1];
        else ans += s[p + 1];
        // cout << i << ' ' << ans, el;
    }
    cout << ans;
    el;
    for(int i = 1; i <= n; i++) x[i] = l[i] = r[i] = pr[i] = sf[i] = s[i] = c[i] = 0;
}