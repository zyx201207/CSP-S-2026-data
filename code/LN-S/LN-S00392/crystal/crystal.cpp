#include <bits/stdc++.h>

using namespace std;
long long n,m,b[15005][15005],a[500005],dp[500005],ans,sum;
int main()
{
    freopen("crystal.cpp","r",stdin);
    freopen("crystal.cpp","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            b[i][j]=abs(a[i]-a[j]);

        }
    }

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            dp[i]+=b[i][j];
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(dp[i]<=m)
        {
            sum=min(dp[i]-m,dp[i-1]-m);
            ans=i;
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
