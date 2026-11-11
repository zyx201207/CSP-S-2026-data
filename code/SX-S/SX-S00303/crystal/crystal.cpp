#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

constexpr int N = 5e5 + 5;

LL read(){
    LL x = 0, f = 1; char c = getchar_unlocked();
    while(c < '0' || c > '9'){if(c == '-') f = -1; c = getchar_unlocked();}
    while(c >= '0' && c <= '9'){x = (x << 1) + (x << 3) + (c ^ 48); c = getchar_unlocked();}
    return x * f;
}

int n, ans;
LL m, a[N], s[N];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for(int i = 1; i <= n; i++){
        int l = 1, r = i;
        while(l < r){
            const int mid = l + r >> 1;
            if((LL)a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) r = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - l + 1);
    }
    printf("%d", ans);
    return 0;
}