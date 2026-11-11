#include <bits/stdc++.h>
using namespace std;
int a[500010],b[500010],c[300010]={0};
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        b[i]=a[i];
    }
    for (int o=1; o<=n; o++)
    {
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                if(a[i]==b[j])
                {
                    for (int x=j; x>=1; x--)
                    {
                        b[x]=0;
                    }
                }
            }
        }

        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                if (b[i]==j)
                {
                    c[j]++;
                }
            }
            b[i]==a[i];
        }
    }
    for (int i=1; i<=m; i++)
    {
        cout << c[i] << " ";
    }
    return 0;
}
