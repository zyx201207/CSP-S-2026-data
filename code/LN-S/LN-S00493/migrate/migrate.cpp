#include <bits/stdc++.h>
using namespace std;
#define ll long long
int c,t;
int n,d;
ll a[10009];
ll dp[10009];
int num[10009];
int ans;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int x=1;x<n;x++)
        {
            memset(dp,0x3f3f3f3f,sizeof(dp));
            memset(num,0,sizeof(num));
            dp[x]=0;
            int k=x;
            for(int i=x;i<=n;i++)
            {
                while(a[i]-a[k]>d) k++;
                for(int j=k;j<i;j++)
                {
                    if(dp[i]>dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                        num[i]=1;
                    }else if(dp[i]==dp[j]+1)
                    {
                        num[i]++;
                    }
                }
            }
            for(int i=x;i<=n;i++)
            {
                if(num[i]==2) ans++;
            }

        }
        cout<<ans<<endl;
        ans=0;
    }


    return 0;
}
