#include<bits/stdc++.h>
using namespace std;
int n,dis;
int a[2000001];
int cnt;
struct tDot
{
    int x;
    int step;
};
int mins;
void bfs(int s,int t)
{
    queue <tDot> q;
    tDot d={s,0};
    q.push(d);
    while(!q.empty())
    {
        d = q.front();
        q.pop();
        if(d.x==t)
        {
            mins = min(mins,d.step);
            return ;
        }
        for(int i=d.x+1;i<=t;i++)
        {
            if(a[i]-a[d.x]<=dis)
            {
                q.push({i,d.step+1});
            }
        }
    }
}
void dfs(int dep,int x,int k)
{
    if(dep>mins)
    {
        return ;
    }
    if(x==k)
    {
        if(dep==mins)
        {
            cnt++;
        }
        return ;
    }
    for(int i=x+1;i<=k;i++)
    {
        if(a[i]-a[x]<=dis)
        {
            dfs(dep+1,i,k);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>dis;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                cnt = 0;
                mins = INT_MAX;
                bfs(i,j);
                dfs(0,i,j);
             //   cout<<i<<" "<<j<<" "<<cnt<<'\n';
                if(cnt==2)
                {
                    ans++;
                //    cout<<i<<" "<<j<<'\n';
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
