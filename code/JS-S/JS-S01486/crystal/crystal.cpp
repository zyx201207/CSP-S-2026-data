#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
int sum[500005];
int a[500005];
int l=1, r=1;
int ans = -1;
int main()
{
    freopen("crystal.in","r", stdin);
    freopen("crystal.out","w", stdout);

    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (int i=1; i<=n; i++)
        sum[i] = sum[i-1] +a[i];
    while (r<=n)
    {
        int cost = (r-l)*a[r] - (sum[r-1]-sum[l-1]);
        if (cost<=m)
        {
            ans = max(ans, r-l+1);
            r++;
        }
        else if (l<r) l++;
        else r++;
    }
    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
