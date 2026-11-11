#include<bits/stdc++.h>
using namespace std;
#define ll long long
int op,T;
ll a[2000005],n,d,dp[5005],c[5005];
ll g[5005][5005],t[5005][5005];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>op>>T;
    if(op<=10||op>=15)
    {
        for(;T--;)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            memset(g,0x3f,sizeof(g));
            memset(t,0,sizeof(t));
            for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(a[j]-a[i]<=d)t[i][j]=t[j][i]=g[j][i]=g[i][j]=1;else break;
            for(int i=1;i<=n;i++)g[i][i]=0,t[i][i]=1;
            for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            for(int k=i+1;k<j;k++)
            {
                int x=g[i][k]+g[k][j];
                if(x<g[i][j])t[i][j]=0,g[i][j]=x;
                if(x==g[i][j])t[i][j]+=t[i][k]*t[k][j];
            }
            int ans=0;
            for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans+=(t[i][j]==2);
            cout<<ans<<"\n";
        }
    }
    if(op==11||op==12)
    {
        for(;T--;)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            ll gap=a[2]-a[1];
            if(d<=gap)cout<<"0\n";
            else cout<<max(n+1-(d/gap)*2,0ll)<<"\n";
        }
    }
    if(op==13||op==14)
    {
        for(;T--;)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            int fi=0,lst=0;
            for(int i=1;i<=n;i++)
            {
                if(!fi&&a[i]>=a[n]-d&&a[1]+d>=a[i])fi=i;
                if(a[i]>=a[n]-d&&a[1]+d>=a[i])lst=i;
            }
            if(lst-fi!=1)cout<<"0\n";
            else cout<<(fi-1)*(n-lst)<<"\n";
        }
    }
    if(op>=15)for(;T--;)cout<<"0\n";
    return 0;
}