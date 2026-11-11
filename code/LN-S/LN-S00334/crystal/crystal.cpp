#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n+5],sum[n+5],xy=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sum[1]=1;
    long long ma=m;

    sort(a+1,a+1+n);
    sum[1]=1;
    xy=a[2]-a[1];
    int q=0;
    for(int i=3;i<=n;i++)
    {
        if(a[i]-a[i-1]!=0)q=1;
    }
    if(q==0)
    {
        sum[n]=1;
        for(int i=n-1;i>=1;i--)
        {
            if(ma-(a[i+1]-a[i])>=0)
            {
                sum[n]++;
                ma-=(a[i+1]-a[i]);
            }
            else
            {
                break;
            }
        }
        cout<<sum[n];
        return 0;
    }
    else{
        for(int i=2;i<=n;i++)
        {
            sum[i]=1;
            for(int j=i-1;j>=1;j--)
            {
                if(ma-(a[i]-a[j])>=0)
                {
                    sum[i]++;
                    ma-=(a[i]-a[j]);
                }
                else
                {
                    break;
                }
            }
            ma=m;
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,sum[i]);
        }
        cout<<ans;
        return 0;
    }
}
