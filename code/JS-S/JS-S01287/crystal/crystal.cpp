#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long s[500005];
long long n,m;
bool check(int c)
{
    long long mini = 4e18;
    for (int i = c;i<=n;i++)
    {
        int j = i-c+1;
        mini = min(mini,(s[i]-s[j])-(j-1)*(a[i]-a[j]));
    }
    return mini<=m;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i = 2;i<=n;i++)
    {
        s[i] = s[i-1]+(a[i]-a[i-1])*(i-1);
    }
    int l = 1;
    int r = n;
    int ans = 0;
    while (l<=r)
    {
        int mid = (l+r)/2;
        if (check(mid))
        {
            ans = mid;
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    cout << ans << "\n";
    return 0;
}
