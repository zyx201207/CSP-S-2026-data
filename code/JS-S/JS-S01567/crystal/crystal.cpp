#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll rd(){
    ll num = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-'){
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        num = num * 10 + (ch - '0');
        ch = getchar();
    }
    return num * f;
}
constexpr ll N = 5e5;
ll n, m, a[N + 5], ans = 1;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = rd(), m = rd();
    for(ll i = 1; i <= n; i++){
        a[i] = rd();
    }
    sort(a + 1, a + n + 1);
    ll j = 1, cnt = 0;
    for(ll i = 2; i <= n; i++){
        cnt += (i - j) * (a[i] - a[i - 1]);
        while(cnt > m){
            cnt -= a[i] - a[j++];
        }
        ans = max(ans, i - j + 1);
    }
    printf("%lld\n", ans);
    return 0;
}