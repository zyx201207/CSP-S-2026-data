#include <bits/stdc++.h>
using namespace std;
long long n,d;
long long dbx;
long long mp[200005];
long long r[2][200005];
const long long Full=1e19;
struct stu{
    long long x,step;
};
queue<stu> q;
void bfs(int x)
{
    q.push({x,1});
    while(!q.empty())
    {
        auto f=q.front();
        q.pop();
        if(f.step<r[1][f.x])
        {
            r[0][f.x]=0;
            r[1][f.x]=f.step;
        }
        if(f.step==r[1][f.x])
        {
            r[0][f.x]++;
        }
        int i=f.x+1;
        while(mp[i]-mp[f.x]<=d && i<=n)
        {
            q.push({i,f.step+1});
            i++;
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    if(c==11 || c==12)
    {
        for(int i=1;i<=t;i++)
        {
            cin>>n>>d;
            for(int j=1;j<=n;j++)cin>>mp[i];
            long long u=mp[2]-mp[1];
            if(d<2*u || d>=3*u) cout<<"0"<<"\n";
            else cout<<(n-3)<<"\n";
        }
        return 0;
    }
    if(c==13 || c==14)
    {
         for(int i=1;i<=t;i++)
        {
            cin>>n>>d;
            for(int j=1;j<=n;j++)cin>>mp[i];
            cout<<n-1<<"\n";
        }
        return 0;
    }
    for(int i=1;i<=t;i++)
    {
        dbx=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>mp[i];
        if(n==1)
        {
            cout<<0<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                r[0][j]=Full;
                r[1][j]=Full;
            }
            bfs(i);
            for(int j=1;j<=n;j++)
            {
                if(r[0][j]==2)dbx+=1;
            }
        }
        cout<<dbx<<"\n";
    }
    return 0;
}
