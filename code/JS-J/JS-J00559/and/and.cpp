#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],ans;
long long yu(long long x,long long y)
{
    bool h[1000010],k[1000001],huan[1000010];
    long long shu=1,wei=1,cnt=0;
    while(shu<x)
    {
        shu*=2;
    }
    shu/=2;
    while(shu>=1)
    {
        if(x>=shu)
        {
            x-=shu;
            shu/=2;
            h[wei]=1;
            wei++;
        }
        else
        {
            shu/=2;
            h[wei]=0;
            wei++;
        }
    }//turn it into the 2
    wei--;
    for(int i=1;i<=wei;i++)
    {
        huan[i]=h[i];
    }
    for(int i=1;i<=wei;i++)
    {
        h[i]=huan[wei-i+1];
    }
    for(int i=1;i<=wei;i++)
    {
        huan[i]=0;
    }
    wei=1;shu=1;
    while(shu<y)
    {
        shu*=2;
    }
    shu/=2;
    while(shu>=1)
    {
        if(y>=shu)
        {
            y-=shu;
            shu/=2;
            k[wei]=1;
            wei++;
        }
        else
        {
            shu/=2;
            k[wei]=0;
            wei++;
        }
    }//turn it into the 2
    wei--;
    for(int i=1;i<=wei;i++)
    {
        huan[i]=k[i];
    }
    for(int i=1;i<=wei;i++)
    {
        k[i]=huan[wei-i+1];
    }
    for(int i=1;i<=wei;i++)
    {
        huan[i]=0;
    }
    wei=1;shu=1;
    for(int i=1;i<=min(sizeof(h),sizeof(k));i++)
    {
        if(h[i]==1&&k[i]==1)
        {
            cnt+=shu;
        }
        shu*=2;
    }
    return cnt;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    if(m==1)
    {
        sort(a+1,a+n+1);
        {
            cout<<a[n];
            return 0;
        }
    }

    if(m==n)
    {
        ans=yu(a[1],a[2]);
        for(int i=2;i<=n;i++)
        {
            long long p=yu(ans,a[i]);
            ans=p;
        }
        sort(a+1,a+n+1);
        cout<<min(ans,yu(a[1],a[n]));
        return 0;
    }
    if(m==2)
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(i!=j)
                {
                    ans=max(ans,yu(a[i],a[j]));
                }
            }
        }
        printf("%lld",ans);
        return 0;
    }
    return 0;
}
