#include<bits/stdc++.h>
using namespace std;

long long a[2000005],cnt[2000005];
int dis[2000005];
struct node
{
    int x;
    int w;
};
bool operator<(node a,node b)
{
    return a.w>b.w;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n;
        long long m;
        cin>>n>>m;
        for(int i = 1;i <= n;i++)
            cin>>a[i];
        int ans=0;
        for(int i = 1;i <= n;i++)
        {
            memset(cnt,0,sizeof cnt);
            memset(dis,0x3f,sizeof dis);
            priority_queue<node>pq;
            pq.push({i,0});
            dis[i]=0;
            cnt[i]=1;
            while(!pq.empty())
            {
                int x = pq.top().x;
                int w = pq.top().w;
                pq.pop();
                for(int j = x+1;j <= n;j++)
                {
                    if(a[j]-a[x]<=m)
                    {
                        if(dis[j]>w+1)
                        {
                            dis[j]=w+1;
                            cnt[j]=cnt[x];
                            pq.push({j,dis[j]});
                        }
                        else if(dis[j]==w+1)
                            cnt[j]+=cnt[x];
                    }
                    else
                        break;
                }
            }
            for(int j = i+1;j <= n;j++)
                if(cnt[j]==2)
                    ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
