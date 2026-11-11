#include <bits/stdc++.h>
using namespace std;
long long a[200001];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int x = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >>a[i];
        if(x < a[i])
        {
            x = a[i];
        }
    }
    if(m == 1)
    {
        cout << x;
    }
    if(m == 2)
    {
        int k = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                int m = a[i] & a[j];
                if(k < m)
                {
                    k = m;
                }
            }
        }
        cout << k;
    }
    if(m == n)
    {
        int s = a[1];
        for(int i = 2;i <= n;i++)
        {
            s &= a[i];
        }
        cout << s;
    }



    return 0;
}
