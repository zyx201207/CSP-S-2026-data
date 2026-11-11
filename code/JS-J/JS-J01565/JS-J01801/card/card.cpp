#include <bits/stdc++.h>
using namespace std;
int n,m,a[5005],dp[5005][5005],pc[5005],qz[5005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(pc[a[i]]==0) pc[a[i]]=i;
        else
        {
            qz[i]=pc[a[i]];
        }
    }
    int lock=0,f=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=n-i+1;j--)
        {
            if(f==1)
            {
                dp[a[j]][i]=dp[a[j]][i-1]+1;
            }
            else dp[a[j]][i]=max(dp[a[j]][i],dp[a[j]][i-1]);
            if(lock==j)
            {

                f=1;
                lock=0;
            }
            if(qz[j]>=n-i+1&&qz[j]!=0)
            {
                lock=qz[j]-1;
                f=0;
            }

        }
    }

    for(int i=1;i<=m;i++)
    {
        cout<<dp[i][n]<<' ';
    }
    return 0;
}
