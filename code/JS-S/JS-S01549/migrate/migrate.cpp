#include <bits/stdc++.h>
using namespace std;

const int N=5e3+10;

int a[N];
int dp[N][N];
int num[N][N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,T;
    cin>>c>>T;

    while(T--)
    {
        memset(num,0,sizeof(num));
        int n,m;
        cin>>n>>m;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        memset(dp,0x3f3f3f,sizeof(dp));
        for(int i=1; i<=n; i++)
        {
            dp[i][i]=0;
            for(int j=i+1; j<=n; j++)
            {
                for(int k=j-1; k>=i; k--)
                {
                    if(a[j]-a[k]<=m)
                    {
                        if(dp[i][j]==dp[i][k]+1)
                        {
                            num[i][j]++;
                        }
                        else if(dp[i][j]>dp[i][k]+1)
                        {
                            dp[i][j]=dp[i][k]+1;
                            num[i][j]=1;
                        }
                    }
                }
            }
        }

        int ans=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(num[i][j]==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
