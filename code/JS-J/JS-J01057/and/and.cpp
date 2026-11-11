#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10,NINF=0xc0c0c0c0;
int INF=1;
int n,m,a[N],dp[20005][2005];
int b[N],maxn=-1;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],b[i]=b[i-1]&a[i],maxn=max(maxn,a[i]);
    for(int i=1;i<=62;i++) INF=INF*2+1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=INF;
        }
    }
    if(m==1)
    {
        int ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,a[i]);
        cout<<ans;
        return 0;
    }
    if(m==2)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
        }
        cout<<ans;
        return 0;
    }
    if(m==n)
    {
        cout<<b[n];
        return 0;
    }
    bool f=1;
    for(int i=1;i<=n;i++)
    {
        int p=a[i];
        while(p!=0)
        {
            if(p%2==0)
            {
                f=0;
                break;
            }
            p=(p-1)/2;
        }
    }
    if(f)
    {
        sort(a+1,a+n+1);
        cout<<a[m];
        return 0;
    }
    dp[1][1]=a[1];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=min(i,m);j++)
        {
            dp[i][j]=dp[i-1][j-1]&a[i];
            if(i-1>=j) dp[i][j]=max(dp[i-1][j],dp[i][j]);
        }
    }
    cout<<dp[n][m];
    return 0;
}
