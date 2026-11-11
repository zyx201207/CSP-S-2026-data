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
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int t = 1;
    // t = rd()
    while(t--) ACehomoxue();
    AK;
}
const int mod = 998244353, maxn = 5 * 1e5 + 18;

int n, m, a[maxn], s[maxn], ans = 0;

void ACehomoxue() {
    n = rd(), m = rd();
    for(int i = 1; i <= n; i++) a[i] = rd();
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for(int r = 1, l = 1; r <= n; r++) {
        while(l <= r && (r - l + 1) * a[r] - (s[r] - s[l - 1]) > m) l++;
        ans = max(ans, r - l + 1);
    }
    cout << ans;
    el;
}

