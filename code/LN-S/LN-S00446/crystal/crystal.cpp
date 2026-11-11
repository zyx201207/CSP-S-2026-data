#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

long long n,m;
long long a[N];

bool check(int u)
{
    int flag = 0;
    for (int i = u; i <= n; i ++ )
        flag |= (((a[i]-a[i-1])*u-a[i]+a[i-u])<=m);
    return flag;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n ;i ++ )
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i = 1; i <= n ;i ++ )
    {
        a[i] += a[i-1];
    }
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l+r>>1;
        if (!check(mid)) r = mid;
        else l = mid+1;
    }
    cout << l-1 << endl;
    return 0;
}
