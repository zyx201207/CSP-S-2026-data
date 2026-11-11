#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn = 0,b;
    cin >> n >> m;
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    if(m == 3)
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                for (int l = 0;l < n;l++)
                {
                    if(j == i || j == l || i == l)
                    {
                        continue;
                    }
                b = a[i] & a[j] & a[l];
                maxn = max(maxn,b);
                }
            }
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(j == i)
            {
                continue;
            }
            b = a[i] & a[j];
            maxn = max(maxn,b);
        }
    }
    cout << maxn;

    return 0;
}
