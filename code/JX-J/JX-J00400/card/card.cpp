#include <bits/stdc++.h>
using namespace std;
int a[500005],b[300005],c[10000005],d[300005];
int n,m,y;
int main ()
{
    freopen ("card.in","r",stdin);
    freopen ("card.out","w",stdout);
    cin >>n>>m;
    for (int i=1;i<=n;i++)
        cin >>a[i];
    if (n==m)
    {
        for (int i=m;i>=1;i--)
            cout <<i<<" ";
        return 0;
    }
    int s,x=0;
    for (int i=1;i<=n;i++)
    {
        x++;
        s=x;
        int sum=0,num=n;
        for (int j=x;j<=num;j++)
        {
            c[j]=a[s];
            if (d[a[s]]==1)
            {
                for (int k=1;k<=n;k++)
                {
                    if (c[k]==d[a[s]])
                    {
                        sum=k;
                        break;
                    }
                }
                for (int k=sum;k<=n;k++)
                    c[k]=0;
                c[sum]=a[s];
                d[a[s]]=0;
                j=sum+1;
            }
            d[a[s]]=1;
            s++;
        }
        for (int j=1;j<=m;j++)
        {
            for (int k=1;k<=num;k++)
            {
                if (c[k]==j)
                    b[j]++;
            }
        }
        for (int j=1;j<=n;j++)
        {
            c[j]=0;
            d[j]=0;
        }
    }
    for (int i=1;i<=m;i++)
        cout <<b[i]<<" ";
    return 0;
}
