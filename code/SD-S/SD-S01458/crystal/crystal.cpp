#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[1000001],b[1000001],c[1000001],s[100001],dp[1001][1001],n,sum=0,v=0,ans=1;
long long f(long long x,long long e)
{
    c[x]+=e;
    for(long long i=1;i<=n;i++)
    {
        b[c[i]]=0;
    }
    for(long long i=1;i<=n;i++)
    {
        b[c[i]]++;
        if(b[c[i]]>ans)
        {
            ans=b[c[i]];
        }
    }
    return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,ans=0,v=0;
    cin>>n>>m;
    b[0]=0;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        if(i==a[i])
        {
            ans++;
        }
        if(a[i]-a[i-1]==a[i-1]-a[i-2])
        {
            v++;
        }
    }
    if(ans==n)
    {
        for(int i=1;i<=n;i++)
        {
            if(m>=s[i-1]&&m<s[i])
            {
                sum=i;
            }
        }
        cout<<sum;
        return 0;
    }
    if(v==n-2)
    {
        cout<<m/(a[2]-a[1]);
        return 0;
    }
    for(long long i=1;i<=n;i++)
    {
        c[i]=a[i];
    }
    for(long long i=1;i<=n;i++)
    {
        for(long long j=0;j<=m;j++)
        {
            dp[i][j]=f(i,j);
            for(long long k=1;k<=n;k++)
            {
                c[k]=a[k];
            }
        }
        long long h=0,u=0;
        for(long long k=0;k<=m;k++)
        {
            if(h<dp[i][k])
            {
                u=k;
            }
            h=max(h,dp[i][k]);
        }
        a[i]+=u;
        m=m-u;
    }
    v=0;
    for(long long i=1;i<=n;i++)
    {
        if(v<dp[i][m])
        {
            v=dp[i][m];
        }
    }
    cout<<v;
	return 0;
}

