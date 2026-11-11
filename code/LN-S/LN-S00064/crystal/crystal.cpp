#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 500010;

int n; LL m;
LL a[N];
__int128 cur;
int ans;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    int l = 1, r;
    cur = 0;
    for(r = 1; r <= n; r++){
        cur += (__int128)(r - l) * (a[r] - a[r - 1]);
        while(cur > m)
            cur -= (__int128)a[r] - a[l++];
        ans = max(ans, r - l + 1);
    }
    printf("%d\n", ans);
    return 0;
}
