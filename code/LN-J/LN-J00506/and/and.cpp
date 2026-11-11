#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n,m,a[N], st[N];

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
    }
    int ans = 0 ;
    for (int i = 30; i >= 0; i -- )
    {
        int sum = 0;
        for (int j = 1 ; j <= n; j ++ )
            if (!st[j])sum += (a[j] >> i&1);
        //cout << sum;
        if (sum >= m)
        {
            for (int j = 1; j <= n; j ++ )
            if (!(a[j] >> i & 1)) st[j] = 1;
            ans += 1 << i;
        }//*/
    }
    cout << ans << endl;
    return 0;
}
