#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[500010], ans = 1;

main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+1+n);
    int l = 1, r = 1, tm = 0;
    for (int i = 2; i <= n; i++)
    {
        int now = a[i], delta = a[i]-a[i-1];
        r = i;
        tm += (r-l)*delta;
        while(tm > m && l < r) tm -= now-a[l],l++;
        ans = max(ans, r-l+1);
    }
    cout << ans << endl;
    return 0;
}
