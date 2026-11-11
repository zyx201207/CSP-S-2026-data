#include<bits/stdc++.h>
using namespace std;
long long a[100010];
long long n,m;
int hhz(int x,y)
{
    int ans=0;
    for(int i=x;x<=n;x++)
    {
        for(int i=y;y<=n;y++)
        {
            a[i]=a[i-1];
        }
    }
    return x<by;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.in","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            sort(a,a+1+n);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int x=1;x<=n;x++)
            {
                if(a[i]==0)
                {
                    cout<<" ";
                }
                else if(a[i]==1)
                {
                    continue;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<a[i];
    }
    return 0;
}
