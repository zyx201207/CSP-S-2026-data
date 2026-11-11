#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 5e5 + 10;
LL a[N], sum[N], m;
int n;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
    int l = 1, ans = 0;
    for(int r = 1; r <= n; r ++)
    {
        while(a[r] * (r - l + 1) - sum[r] + sum[l - 1] > m) l ++;
        ans = max(ans, r - l + 1);
    }
    printf("%d\n", ans);
    return 0;
}
// g++ -std=c++14 -O2 -fsanitize=address,leak,undefined -Wall -Wextra -Wshadow -Wconversion crystal.cpp -o crystal