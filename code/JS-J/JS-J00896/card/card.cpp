#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int a[n+5];
    int b[300005];
    int d[m+5];
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
        b[a[i]] = 0;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = i;j <= n;j++)
        {
            b[a[j]]++;
            if(b[a[j]] != 1)
            {
                int k = j-1;
                while(a[k] != a[j])
                {
                    b[a[k]] = 0;
                    k--;
                }
                b[a[j]] = 1;
            }
        }
        for(int j = 1;j <= m;j++)
        {
            d[j] += b[j];
        }
        for(int j = i;j <= n;j++)
        {
            b[a[j]] = 0;
        }
    }
    for(int j = 1;j <= m;j++)
    {
        cout<<d[j]<<" ";
    }
    return 0;
}
