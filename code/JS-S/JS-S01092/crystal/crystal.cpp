#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll read();
inline void wt(ll);
ll n,m,a[500005] = {},sum;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n = read(),sum = m = read();
    for(register int i = 1;i <= n;i++) a[i] = read(),sum += a[i];
    sort(a + 1,a + n + 1);
    for(register int i = n + 1;i >= 2;--i){
        sum -= a[i];
        ll x = abs(sum - sum / (i - 1) * (i - 1));
        if(sum < 0) x = i - 1 - x;
        if(x <= m){
            if(sum/(i-1) >= a[i - 1]){
                wt(i - 1);
                fclose(stdin);
                fclose(stdout);
                return 0;
            }
        }
    }
    return 0;
}
inline ll read(){
    register ll r;register bool f = 1;register char c;
    while((c = getchar()) && !isdigit(c)) if(c == '-') f ^= 1;
    r = (c ^ 48);
    while((c = getchar()) && isdigit(c)) r = (r << 3) + (r << 1) + (c ^ 48);
    return r * (f ? 1 : -1);
}
inline void wt(ll n){
    if(n < 0) putchar('-'),n = -n;
    if(n > 9) wt(n / 10);
    putchar(n % 10 + 48);
}
