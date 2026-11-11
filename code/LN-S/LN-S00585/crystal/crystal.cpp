#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;

const int N = 500005;

LL a[N], df[N];
LL d[N];
LL s[N];

int n;
LL m;

int lowbit(int x) {
    return x & -x;
}

int check(int x, LL m) {
    LL cut = df[x];
    int l = 1, r = x;
    while (l < r) {
        int mid = l + r >> 1;
        if (s[x] - s[mid - 1] - cut * (x - mid + 1) <= m) r = mid;
        else l = mid + 1;
    }
    return x - l + 1;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%lld", &a[i]);
    
    sort(a + 1, a + n + 1);

    LL mx = a[n];
    for (int i = 1; i <= n; i ++ ) {
        df[i] = mx - a[i];
        s[i] = s[i - 1] + df[i];
    }

    int ans = 0;
    for (int i = n; i; i -- ) 
        ans = max(ans, check(i, m));
    
    printf("%d\n", ans);
}