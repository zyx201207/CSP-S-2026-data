#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200001],b;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if (m==1)
    {
        for (int i=1;i<=n;i++)
        {
            b=max(b,a[i]);
        }
    }
    else if (m==2)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                b=max(b,(a[i]&a[j]));
            }
        }
    }
    else if (m==3)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                for (int k=j+1;k<=n;k++)
                {
                    b=max(b,(a[i]&a[j]&a[k]));
                }
            }
        }
    }
    else if (m==4)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                for (int k=j+1;k<=n;k++)
                {
                    for (int l=k+1;l<=n;l++)
                    {
                        b=max(b,(a[i]&a[j]&a[k]&a[l]));
                    }
                }
            }
        }
    }
    else if (m==5)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                for (int k=j+1;k<=n;k++)
                {
                    for (int l=k+1;l<=n;l++)
                    {
                        for (int o=l+1;o<=n;o++)
                        {
                            b=max(b,(a[i]&a[j]&a[k]&a[l]&a[o]));
                        }
                    }
                }
            }
        }
    }
    cout<<b;
    fclose();
    fclose();
    return 0;
}
