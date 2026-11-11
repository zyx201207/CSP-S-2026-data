#include <bits/stdc++.h>
using namespace std;
long long n,m,dp[200010],b[200010];
long long a,i,j,x,an;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    dp[1] = 0;
    m = n;
    while(1+n--)
    {
        cin >> b[m-n];
        an = max(b[m-n],an);
    }
    if (x == m)
    {
        i = 2;
        a = b[1];
        while (i <= m)
        {
            a = (a & b[i]);
            i += 1;
        }
        cout << a;
    }
    else if (x == 1)
    {
        cout << an;
    }
    else if (x == 2)
    {
        i = 2;
        j = 1;
        while(i <= m)
        {
            while (j < i)
            {
                if(dp[i] < (b[i]&b[j]))
                {
                    dp[i] = b[i]&b[j];
                }
                j += 1;
            }
            i += 1;
        }
        cout << dp[m];
    }
    return 0;
}
