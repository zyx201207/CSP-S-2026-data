#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long vis[5000005];
long long a[5000005];
long long w[5000005];
long long cnt = 0;
void qk()
{
    for(int i = 1;i<=n;i++)
    {
        vis[i]=0;
        w[i]=0;
    }
}
void dfs(long long x,long long len)
{
    for(int i = x+1;i<=n;i++)
    {
        if(vis[i]<len&&vis[i]!=0)continue;
        for(int j = i-1;j>=x;j--)
        {
            if(vis[j]!=len-1)continue;
            if(a[i]-a[j]>d)break;
            w[i]++;
            vis[i]=len;
        }
    }
}
void solve()
{
    cin >> n >> d;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    for(int i = 1;i<=n;i++)
    {
        qk();
        cnt = 1;
        long long len = 1;
        vis[i]=1;
        while(len<=n-i+1)
        {
            //cout << cnt << endl;
            len++;
            if(len>n)break;
            dfs(i,len);
            //cout << len << endl;
        }
        for(int j = i+1;j<=n;j++)
        {
            //cout << w[j] << endl;
           // cout << w[i] << " ";
            if(w[j]==2)ans++;
        }
        //cout << endl;
    }
    cout << ans << endl;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin >> c >> t;
    while(t--)solve();
    return 0;
}
