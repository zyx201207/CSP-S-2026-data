#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int dp[200010];
int main()
{

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    dp[0]=0x7f7f;
    scanf("%d%d",&n,&m);
    int ans;
    memset(ans,0x7f,sizeof ans);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    if(m==1)
    {
        cout<<a[n];
        return 0;
    }
    if(m==2)
    {
        cout<<a[n]&a[n-1];
        return 0;
    }
    if(m==n)
    {
        for(int i=1;i<=n;i++)ans&=a[i];
        cout<<ans;
        return 0;
    }
    if(m==n-1)
    {
        for(int i=2;i<=n;i++)ans&=a[i];
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            dp[j]=max(dp[j],dp[j-1]&a[i]);
        }
    }
    cout<<dp[m];
}
