#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long s[500005];
int dp[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long sum=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        s[i]=a[i]-a[i-1];
        for(int j=i;j>=1;j--)
        {
            long long c=a[i]-a[j];
            sum+=c;
            if(sum>=m)
            {
                sum=0;
                break;
            }
            dp[i]++;
            ans=max(dp[i],ans);
        }
    }
    cout<<ans<<"\n";
    return 0;
}