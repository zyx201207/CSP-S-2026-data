#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
long long ans;
long long minn;

long long n,d;
void dfs(int now,int end,int cnt)
{
    if(x[now]==x[end])
    {
        if(cnt==minn)
        {
            ans++;
            //cout<<2;
            return;
        }
        if(cnt<minn)
        {
            ans=1;
            minn=cnt;
            //cout<<1;
            return;
        }
        return;
    }
    if(x[now]>x[end])
    {
        return;
    }
    for(int i=now+1;i<=end&&x[i]-x[now]<=d;i++)
    {
        dfs(i,end,cnt+1);
    }

}
void Solve()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    queue<long long> q;
    x[n+1]=1e18+1;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            minn=1e18+2;
            ans=0;
            dfs(i,j,0);
            if(ans==2)sum++;
            //cout<<i<<' '<<j<<' '<<ans<<' '<<minn<<endl;
        }
    }
    cout<<sum<<endl;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        Solve();
    }
    return 0;
}
