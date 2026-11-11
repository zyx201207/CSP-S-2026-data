#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int a[n];
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        for ( int j = 1;j <= m;j++)
        {
            cin >> a[n];
        }
    }
    for (int i = 1;i <= n;i++)
    {
        for ( int j = 1;j <= m;j++)
        {

            int t;
            if(a[n+1] > a[n])
            {
                t = a[n+1];
            }
            cout << t;
        }
    }

    return 0;
}
