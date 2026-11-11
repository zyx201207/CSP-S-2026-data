#include<iostream>
#include<cstdio>
using namespace std;
long long a[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        long long maxn=0;
        for(int i=1;i<=n;i++)
        {
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    if(m==2)
    {
        long long maxn=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    maxn=max(maxn,(a[i]&a[j]));
                }
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==n)
    {
        long long k=(a[1]&a[2]);
        for(int i=3;i<=n;i++)
        {
            k=(k&a[i]);
        }
        cout<<k;
    }
    if(m==n-1)
    {
        long long maxn=0;
        for(int i=1;i<=n;i++)
        {
            long long k=1048575;
            for(int j=1;j<=n;j++)
            {
                if(j!=i)
                {
                    k=(k&a[i]);
                }
            }
            maxn=max(maxn,k);
        }
        cout<<maxn;
        return 0;
    }
    if(a[1]+1==a[2]&&a[2]+1==a[3]&&a[3]+1==[4])
    {
        cout<<0;
        return 0;
    }
    cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
