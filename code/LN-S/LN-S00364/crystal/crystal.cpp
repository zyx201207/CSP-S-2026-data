#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n, m;
int a[maxn], pre[maxn], d[maxn];
int c[maxn];

int calc(int mid, int k)
{
    if(mid <= k + 1) return 0;
    return c[mid] - k * a[mid] + pre[k];
}

int binary(int x, int k)
{
    int l = 1, r = n;
    while(l < r)
    {
        int mid = (l + r + 1) / 2;
        if(calc(mid, k) > x) r = mid - 1;
        else l = mid;
    }
    //printf("l = %lld\n", l);
    return l - k;
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i], d[i] = a[i] - a[i - 1];

    for(int i = 2; i <= n; i++)
        c[i] = c[i - 1] + (i - 1) * d[i];


    int ans = 1;
    for(int k = 2; k <= n; k++)
    {
        /*
        for(int i = 2; i <= n; i++)
            printf("%lld ", calc(i, k - 2));
        printf("\n");

        printf("k = %lld, binary = %lld\n", k - 2, binary(m, k - 2));
        */

        ans = max(ans, binary(m, k - 2));
        //printf("\n");
    }
    printf("%lld", ans);



    return 0;
}
