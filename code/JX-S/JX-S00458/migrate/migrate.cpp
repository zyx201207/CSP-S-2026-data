#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+3;
const ll inf=LONG_MAX;
int c,T;
int n,cnt,ans;
ll d,a[N],dp[N][N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dp[i][j]=inf;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
                dp[i][i]=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=i;k<=j;k++)
                    if((a[j]-a[k])<=d)
                        dp[i][j]=min(dp[i][j],dp[i][k]+1);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                cnt=0;
                if(dp[i][j]<=1)
                        continue;
                for(int k=i+1;k<j;k++)
                    if(dp[i][k]!=inf&&dp[k][j]!=inf)
                        if(dp[i][k]+dp[k][j]==dp[i][j])
                            cnt++;
                if(cnt==2)
                    ans++;
            }
        cout<<ans<<"\n";
    }
    return 0;
}
