#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll readf() {
    ll x = 0, f = 1; char c = getchar_unlocked();
    for(; !isdigit(c); c = getchar_unlocked()) if(c == '-') f = -1;
    for(; isdigit(c); c = getchar_unlocked()) x = x * 10 + (c ^ 48);
    return x * f;
}

int tcs, t, n; ll m, ans; int rnxt[2000009], lnxt[2000009], lsz[2000009], rsz[2000009], sp[2000009], spl[2000009]; ll a[2000009];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    tcs = readf(), t = readf(); for(int cs = 1; cs <= t; cs++) {
        n = readf(), m = readf(); for(int i = 1; i <= n; i++) a[i] = readf();
        for(int i = 1, j = 1; i <= n; i++) { rnxt[i] = j - 1; while(j <= n && a[j] <= a[i] + m) rnxt[i] = j++; }
        for(int i = n, j = n; i >= 1; i--) { lnxt[i] = j + 1; while(j >= 1 && a[j] >= a[i] - m) lnxt[i] = j--; }
        for(int i = 1; i <= n; i++) lsz[i] = rsz[i] = sp[i] = spl[i] = 0;
        for(int i = 1; i <= n; i++) {
            if(rnxt[i] != i) lsz[rnxt[i]]++;
            if(lnxt[i] != i) rsz[lnxt[i]]++;
            if(lnxt[rnxt[i]] < i && rnxt[i] != i + 1) spl[rnxt[i]]++;   
            if(rnxt[lnxt[i]] > i && lnxt[i] != i - 1) sp[lnxt[i] + 1]++;   
        }
        for(int i = 1; i <= n; i++) if(rnxt[lnxt[i]] == i && lnxt[i] != i) lsz[i] += lsz[lnxt[i]];
        for(int i = n; i >= 1; i--) if(lnxt[rnxt[i]] == i && rnxt[i] != i) rsz[i] += rsz[rnxt[i]];
        ans = 0; for(int i = 2; i <= n; i++) if(lnxt[rnxt[i]] == i - 1 && rnxt[i - 1] == rnxt[i] && rnxt[i] != i && lsz[i]) ans += (ll)(1 + spl[i] + (lnxt[i - 1] == lnxt[i]) * lsz[lnxt[i]]) * (rsz[rnxt[i]] + sp[i] + 1); else if(lnxt[rnxt[i - 1]] == i - 1 && rnxt[i - 1] > i && lsz[i]) ans += (ll)(1 + spl[i] + (lnxt[i - 1] == lnxt[i]) * lsz[lnxt[i]]) * (sp[i] + 1); 
        printf("%lld\n", ans);
    }
    return 0;
}