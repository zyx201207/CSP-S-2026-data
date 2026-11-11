#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n;
long long a[N],cf[N],c[N],m;
long long ans=-1;
long long num=0;
long long res=0;
bool jud=false;
long long k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long dp[n+5][n+5];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=0;
        }
    }
    long long x[n+5];
    if(n>=5001)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        sort(x+1,x+n+1);
        k=abs(x[2]-x[1]);
        //cout<<k<<"\n";
        long long res=0;
        for(int j=1;j<=n;j++)
        {
            res=(long long)j*(j-1)*k;
            //cout<<res<<"\n";
            if(res>m)
            {
                ans=(long long)j;
                break;
            }
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        //cout<<a[i]<<" ";
        c[i]=a[n]-a[i];
        dp[i][i]=0;
    }
 //   for(int i=n-1;i>=1;i--)
  //  {
  //      dp[n][i]=dp[n][n]+a[i]-a[i+1];
  //  }
    //cout<<"\n";
    ans=1;
    for(int i=n;i>=1;i--)
    {
        num=1;
        for(int j=i-1;j<=i,j>=1;j--)
        {
            dp[i][j]=dp[i][j+1]+c[j]-c[i];
            if(dp[i][j]<=m)
            {
                ans=max(ans,++num);
                //cout<<i<<" "<<j<<" "<<ans<<" "<<dp[i][j]<<"\n";
            }
            else
            {
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
//
//15 3 1 1 1 1 1 1 1 1 1 11 11 11 2  2 3
