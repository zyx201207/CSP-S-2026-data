#include<bits/stdc++.h>
using namespace std;
const int maxn=2000001;
int c,t,n,b[maxn],cnt[maxn],ans;
long long d,a[maxn],dis[maxn];
void bfs(int x,int sum)
{
    queue<int> q;   
    q.push(x);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=b[u];i>x;i--)
        {
            if(dis[i]==dis[u]+1)
            {
                cnt[i]+=cnt[u];
            }
            if(dis[i]>dis[u]+1)
            {
                cnt[i]=1;
                dis[i]=dis[u]+1;
                q.push(i);
            }
        }
    }
}
void solve()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) b[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
    ans=0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=n;j++) cnt[j]=0,dis[j]=2e18;
        cnt[i]=1;
        dis[i]=0;
        bfs(i,0);
        for(int j=i;j<=n;j++)
        {
            // cout<<cnt[j]<<" ";
            if(cnt[j]==2)
                ans++;
        }
        // cout<<'\n';
    }
    cout<<ans<<'\n';
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
        solve();
    return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/