#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[100005],mid,midmax = 100000,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i+=1)
    {
        cin >> a[i];
        mid += a[i];
    }
    sort(a + 1,a + 1 + n);
    mid /= n;
    for (int i = 1;i <= n;i += 1)
    {
        if (a[i] - mid < a[midmax])
        {
            midmax = i;
        }
    }
    for (int i = midmax;i >= 1;i -= 1)
    {
        if (m >= a[midmax] - a[i])
        {
            ans += 1;
            m -= a[midmax] - a[i];
        }
    }
    cout << ans;
}
