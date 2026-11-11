#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n,a[N];
char c[N];

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    long long ed = n,fr = 1;
    long long ee = 0,ff = 1;
    long long ans = 0;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i] >> c[i];
        ee += a[i];
    }
    while (fr != ed)
    {
        if(a[ed] < a[fr])
        {
            if (c[ed] != c[fr])
                ans += a[ed];
            ee -= a[ed];
            ff += a[ed];
            a[fr] -= a[ed];
            ed -- ;
        }
        else if (a[ed] == a[fr])
        {
            if (c[ed] != c[fr])
                ans += a[ed];
            ee -= a[ed];
            ff += a[ed];
            ed -- ;
            fr ++ ;
        }
        else
        {
            if (c[ed] != c[fr])
                ans += a[fr];
            ee -= a[fr];
            ff += a[fr];
            a[ed] -= a[fr];
            fr ++ ;
        }
    }
    cout << ans << endl;

    return 0;
}
