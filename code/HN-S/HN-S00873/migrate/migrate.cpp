#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[2000005],ans[2000005],sum[2000005];
int n,d,a[2000005],cnt=0,id;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    cin>>id>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(id==11||id==12)
        {
            if(d>=2*(a[2]-a[1])) cout<<max(0ll,n-d/(a[2]-a[1])*2+1)<<'\n';
            else cout<<0<<'\n';
            continue;
        }
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++) dp[j]=0,ans[j]=0,sum[j]=0;
            ans[i]=1;
            for(int j=i+1;j<=n;j++)
            {
                int l=i-1,r=j+1;
                while(l+1<r)
                {
                    int mid=(l+r)/2;
                    if(a[j]-a[mid]<=d) r=mid;
                    else l=mid;
                }
                dp[j]=dp[r]+1;
                for(int k=r;k<j;k++)
                {
                    if(dp[k]==dp[r]) ans[j]+=ans[k];
                    else break;
                    if(ans[j]>2) break;
                }
                cnt+=(ans[j]==2);
            }
        }
        cout<<cnt<<'\n';
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
/*

*/