#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005]={},ans=1<<30,maxn=0,maxon;
bool cmp(ll a,ll b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    if (m == n)
    {
        for (int i=1; i<=n; i++)
        {
            ans &= a[i];
        }
        cout << ans;
        return 0;
    }
    else if (m == 1)
    {
        cout << a[1];
    }
    while (a[1] > pow(2,maxn))
    {
        maxn++;
    }
    bool flag = 1;
    while (flag)
    {
        ll cnt = 0;
        for (int i=1; i<=n; i++)
        {
            if ((a[i] << (maxn-1)) %2 == 1) cnt++;
        }
        if (cnt >= m)
        {
            maxon = cnt;
            break;
        }
        if (maxn == 0)
        {
            cout << 0;
            return 0;
        }
        maxn--;
    }
    for (int i=1; i<=n; i++)
    {
        if ((a[i] << (maxn-1)) %2 == 0) a[i] = 0;
    }
    sort(a+1,a+n+1,cmp);
    for (int i=1; i<=m; i++)
    {
        ans &= a[i];
    }
    cout << ans;
    return 0;
}
