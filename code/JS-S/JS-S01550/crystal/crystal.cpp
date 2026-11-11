#include<bits/stdc++.h>
using namespace std;
struct node{
    long long x,y;
};
node dp[500005];
long long a[500005];
long long f[500005];
long long sum[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i<n;i++)
    {
        f[i]=a[i+1]-a[i];
        sum[i]=sum[i-1]+f[i];
    }
    dp[1].x=1;
    dp[1].y=0;
    for(int i = 2;i<=n;i++)
    {
        long long num = dp[i-1].y+f[i-1]*dp[i-1].x;
        long long cnt = dp[i-1].x;
        while(num>m)
        {
            long long u = sum[i-1]-sum[i-cnt-1];
            num-=u;
            cnt--;
        }
        dp[i].x=cnt+1;dp[i].y=num;
    }
    long long ans = 0;
    for(int i = 1;i<=n;i++)
    {
        ans = max(dp[i].x,ans);
    }
    cout << ans << endl;
    return 0;
}
