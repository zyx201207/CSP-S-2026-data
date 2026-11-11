#include <bits/stdc++.h>
using namespace std;
long long a[200005],n,m,k[200005];
long long  maxn = INT_MIN;
void dfs(long long x,long long c)
{
    if(x>m)
    {
        maxn = max(maxn,c);
    }
    else
    {
        for(long long i=1; i<=n; i++)
        {
            if(k[i]==0)
            {
                k[i]=1;
                long long d = c&a[i];
                dfs(x+1,d);
                k[i]=0;
            }
        }
    }
}
long long pd(long long x)
{
    for(int  i=1; i<=20; i++)
    {
        if(pow(2,i)-1==x)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    if(n<=20||m==2)
    {
        dfs(1,pow(2,21)-1);
        cout<<maxn;
        return 0;
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    if(m==n)
    {
        maxn = pow(2,21)-1;
        for(int i=1;i<=n;i++)
        {
            maxn=maxn&a[i];
        }
        cout<<maxn;
        return 0;
    }
    int f1=1,f2=1,x0,x1,x2,x3;
    for(int i=1; i<=n; i++)
    {
        if(!pd(a[i]))
        {
            f1=0;
        }
        if(f2>=4)
        {
            f2=0;
        }
        if(a[i]==0)
        {
            x0++;
        }
        if(a[i]==1)
        {
            x1++;
        }
        if(a[i]==2)
        {
            x2++;
        }
        if(a[i]==3)
        {
            x3++;
        }
    }
    if(f1==1)
    {
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
        return 0;
    }
    if(f2==1)
    {
        if(m<=x3)
        {
            cout<<3;
        }
        else if(m<=x3+x2)
        {
            cout<<2;
        }
        else if(m<=x3+x1)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
        return 0;
    }
    return 0;
}
