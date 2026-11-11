#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

inline ll read(){
    ll x = 0, f = 1;
    char c = getchar();
    while(!isdigit(c)){
        if(c == '-') f = -1;
        c = getchar();
    }
    while(isdigit(c)){
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

const int N = 5e5 + 10;
int n;
ll m;
ll a[N], s[N];

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    for(int i = 0;i < n;i++) a[i] = read();
    sort(a, a + n);
    s[0] = a[0];
    for(int i = 1;i < n;i++){
        s[i] = s[i-1] + a[i];
    }
    int l = 0;
    ll ans = 0;
    for(int r = 1;r < n;r++){
        ll sum;
        if(l == 0) sum = s[r];
        else sum = s[r] - s[l-1];
        ll len = r - l + 1;
        while(l < r && sum + m < len * a[r]){
            l++;
            len = r - l + 1;
            sum -= a[l];
        }
        if(sum + m >= len * a[r]){
            ans = max(ans, len);
        }
    }
    cout << ans;
    return 0;
}
