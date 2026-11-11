#include <bits/stdc++.h>
#include <cstdio>
#define int long long
using namespace std;
const int N=2e6+10;
int c,T;
int n,d;
int arr[N],dp[N],cnt[N],sum_cnt[N];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>T;
    while(T--)
    {
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>arr[i];

        for(int k=1;k<=n;k++)
        {
            for(int i=k-1;i<=n;i++)
            {
                dp[i]=N;
                cnt[i]=0;
                sum_cnt[i]=0;
            }
            dp[k]=0,cnt[k]=1,sum_cnt[k]=1;
            for(int i=k+1;i<=n;i++)
            {
                int x=lower_bound(arr+k,arr+1+i,arr[i]-d)-arr;
                dp[i]=dp[x]+1;
                int y=upper_bound(dp+k,dp+i,dp[x])-dp-1;
                cnt[i]=sum_cnt[y]-sum_cnt[x-1];
                sum_cnt[i]=sum_cnt[i-1]+cnt[i];
                }

            for(int i=k;i<=n;i++)
            {
                if(cnt[i]==2)
                {
                    ans++;
                    //cout<<"("<<k<<","<<i<<")";
                }
            }
        }
        cout<<ans;
        cout<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
