#include<bits/stdc++.h>

using namespace std;

long long a[500005], b[300005], c[500005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    long long n, m;
    cin >> n >> m;
    for(int i = 1;i<= n; i++)
    {
        cin >> c[i];
    }
    for(long long k = 1; k <= n; k++)
    {
        long long xb = k - 1;
        for(long long i = k; i<= n; i++)
        {
            bool bol = 1;
            for(int j = xb; j >= k; j--)
            {
                if(a[j] == c[i])
                {
                    xb = j;
                    a[xb] = c[i];
                    bol = 0;
                }
            }
            if(bol)
            {
                xb++;
                a[xb] = c[i];
            }

        }
        for(long long i = k; i <= xb; i++)
        {
            b[a[i]]++;
        }
    }


    for(int i =1;i<= m;i++)
    {
        cout << b[i] << ' ';
    }
    return 0;
}
