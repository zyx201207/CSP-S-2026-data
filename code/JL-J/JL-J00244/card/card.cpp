#include <bits/stdc++.h>
using namespace std;
long long a[500100],b[500100],c[500100];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i<=n;i++)
    {
        long long x = 0;
        for(int j = 1;j<=n-x;j++)
        {
            long long y = x+1;
            for(int l = 1;l<=n-x;l++)
            {
                if(a[y] == b[l])
                {
                    for(int o = l;o<=y-1;o++)
                    {
                        b[o] = 0;
                    }
                }
            }
            b[j] = a[y];
            y++;
        }
        sort(b+1,b+1+n);
        for(int j = 1;j<=n;j++)
        {
            c[b[j]]++;
        }
        x++;
    }
    sort(c+1,c+1+n);
    for(int i = 1;i<=m;i++)
    {
        cout << c[i] << " ";
        if(c == 0)
        {
            break;
        }
    }
    return 0;
}
