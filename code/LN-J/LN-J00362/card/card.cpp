#include<bits/stdc++.h>
using namespace std;
int a[5*100*100*10];
int b[5*100*100*10];
int p[5*100*100*10];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(a[j]==b[k])
                {
                    for(int l=k;l<=n;l++)
                    {
                        b[l]=0;
                    }
                    for(int l=1;l<j;l++)
                    {
                        b[(n+1)/2+l]=b[l];
                        b[l]=0;
                    }
                    break;
                }
            }
            for(int k=2;k<=n;k++)
            {
                b[k-1]=b[k];
                b[k]=0;
            }
            b[n]=a[j];
        }
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(b[k]==j)
                {
                    p[j]++;
                }
            }
        }
        for(int j=1;j<=n;j++)
        {
            b[j]=0;
        }
    }
    for(i=1;i<=m;i++)
    {
        cout<<p[i]<<" ";
    }
    return 0;
}
