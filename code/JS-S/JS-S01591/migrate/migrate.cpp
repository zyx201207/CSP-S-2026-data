#include <bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
long long a[N],dp[N],cnt[N],n,d,ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        n=d=ans=0;
        cin>>n>>d;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)

            {
                memset(dp,0x3f,sizeof(dp));
                memset(cnt,0,sizeof(cnt));
//                cout<<i<<" "<<j<<endl;
                cnt[i]=1;dp[i]=0;
                for(int x=i+1;x<=n;x++)
                {
                    for(int y=x-1;a[x]-a[y]<=d&&y>=i;y--)
                    {
//                        cout<<x<<" "<<y<<" "<<114514<<endl;
                        if(dp[x]>dp[y]+1)
                        {
                            dp[x]=dp[y]+1;
                            cnt[x]=cnt[y];
                        }
                        else if(dp[x]==dp[y]+1)
                        {
                            cnt[x]+=cnt[y];
                        }
                    }
                    if(cnt[x]==2)
                        ans++;
                }
//                cout<<dp[j]<<":"<<cnt[j]<<endl;

            }
        cout<<ans<<endl;
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
