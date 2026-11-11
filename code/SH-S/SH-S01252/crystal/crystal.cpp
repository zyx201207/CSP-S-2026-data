#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long s[500010],a[500010],t[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%lld",&a[i]);
    sort(a + 1,a + n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = a[i] - a[i - 1];

    int ans = 0,j = 1;
    for (int i = 2; i <= n; i++)
    {
        t[i] = t[i - 1] + s[i] * 1ll * (i - 1);
        if (j == 1 && t[i] > m) j++;
        while (t[i] - t[j] - 1ll *(a[i] - a[j]) * (j - 1) > m) j++;
        ans = max(ans,i - j + 1);
    }
    cout << ans;

    return 0;
}
