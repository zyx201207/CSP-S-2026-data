#include <bits/stdc++.h>

using namespace std;
long long n,m,a[500005],b[500005],c[500005],maxn=INT_MIN,o;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool flag=1;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>=2) o=a[i]-a[i-1];
        if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) {flag=0;o=a[i]-a[i-1];}
        c[a[i]]++;
    }
    if(flag==1)
    {
        long long u=0;
        for(long long i=1;i<=n-1;i++)
        {
            if(m>=i*o)
            {
                m-=i*o;
                u++;
            }
        }
        cout<<u;
        return 0;
    }
    for(long long i=1;i<=n;i++)
    {
        long long s=c[a[i]],k=m,cnt=0;
        memset(b,0,sizeof(b));
        for(long long j=1;j<=n;j++)
        {
            if(a[i]>a[j])
            {
                b[++cnt]=a[i]-a[j];
            }
        }
        sort(b+1,b+cnt+1);
        for(long long j=1;j<=n;j++)
        {
            if(b[j]!=0&&k>=b[j])
            {
                k-=b[j];
                s+=1;
            }
        }
        maxn=max(maxn,s);
    }
    cout<<maxn;
    return 0;
}
