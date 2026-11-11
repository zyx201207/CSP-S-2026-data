#include<bits/stdc++.h>
using namespace std;

long long n, m, maxn = -10, maxx = -10, sum, a[200005], big;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    if(m == 1)
    {
        for(int i = 1; i <= n; i++)
        {
            long long x;
            cin >> x;
            maxn = max(maxn,x);
        }
        cout << maxn;
    }
    else if(m == n)
    {
        for(int i = 1; i <= n; i++)
        {
            long long x;
            cin >> x;
            sum = sum & x;
        }
        cout << sum;
    }
    else if(m == 2)
    {
        long long left = 1, right = left + 1;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                maxx = max(maxx,a[i]&a[j]);
            }
        }
        cout << maxx;
    }
    else if(m == n - 1)
    {
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++)
        {
            long long add = 0;
            for(int j = 1; j <= n; j++)
            {
                if(j != i)
                {
                    add = add & a[j];
                }
            }
            big = max(big,add);
        }
        cout << big;
    }
    return 0;
}


