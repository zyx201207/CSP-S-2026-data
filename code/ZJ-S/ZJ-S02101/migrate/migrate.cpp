#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdio>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3f;
vector<int>edges[2000005];
int a[2000005];
int dis[2000005],path[2000005];
int n,d;
int bfs(int s)
{
    memset(dis,INF,sizeof(dis));
    memset(path,0,sizeof(path));
    int ans=0;
    queue<int>q;
    dis[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int v=u+1;
        while(a[v]-a[u]<=d&&v<=n)
        {
            if(dis[v]==INF)
            {
                dis[v]=dis[u]+1;
                q.push(v);
                path[v]++;
            }
            else if(dis[v]==dis[u]+1)
            {
                path[v]++;
            }
            v++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(path[i]==2)
        {
            ans++;
        }
    }
    return ans;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            ans+=bfs(i);
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


