#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long dp[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+(a[i]-a[i-1])*(i-1);
    }
    //j-->k:  dp[k]-(dp[j]+(a[k]-a[j])*j)
    long long maxn=1;
    for(int i=2;i<=n;i++)
    {
        long long l=1;
        long long r=i;
        while(l<r)
        {
            long long mid=(l+r)/2;
            if(dp[i]-dp[mid]-(a[i]-a[mid])*(mid-1)>m)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        // cout<<l<<' '<<i<<endl;
        maxn=max(maxn,i-l+1);
    }
    cout<<maxn<<endl;
    return 0;
}
