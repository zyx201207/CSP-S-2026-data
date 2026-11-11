#include<bits/stdc++.h>
#define fi first
#define se second
#define lowbit(x) ((x) & (-(x)))
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
inline ll read(){
    ll x = 0, f = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-')
          f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
inline void write(ll x){
    if(x < 0){
        x = -x;
        putchar('-');
    }
    if(x > 9)
      write(x / 10);
    putchar(x % 10 + '0');
}
ll n, m, ans;
ll a[N];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    for(int i = 1; i <= n; ++i)
      a[i] = read();
    sort(a + 1, a + n + 1);
    ll head = 1, sum = 0;
    for(int i = 1; i <= n; ++i){
        while(sum > m && head < i){
            sum -= a[i] - a[head];
            ++head;
        }
        // cerr << i << ' ' << head << ' ' << sum << '\n';
        ans = max(ans, i - head + 1);
        sum += (i - head + 1) * (a[i + 1] - a[i]);
    }
    write(ans);
    return 0;
}
/*
./crystal < crystal1.in > crystal1.out
./crystal < crystal2.in > crystal2.out
./crystal < crystal3.in > crystal3.out
./crystal < crystal4.in > crystal4.out

./wan < crystal1.in > crystal1.out
./wan < crystal2.in > crystal2.out
./wan < crystal3.in > crystal3.out
./wan < crystal4.in > crystal4.out
*/