#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+5;
int c,n,m,d,q;
vector<pair<long long,int>>e[N];
long long dis[N],w[N];
void dijikstra(int me,int to)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    memset(dis,0x3f,sizeof(dis));
    q.push({0,me});
    dis[me]=0;
    bool op=0;
    while(!q.empty())
    {

        if(q.top().first>dis[q.top().second])continue;
        for(auto it:e[q.top().second])
        {
            int u=it.first;
            int d=it.second;

            if(dis[u]>d+q.top().first)
            {
                dis[u]=d+q.top().first;
                q.push({dis[u],u});
                if(u==to)
                {
                    op=1;
                    break;
                }
            }
        }
        if(op==1)
        {
            break;
        }
        q.pop();
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }

    int k=0;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            e[a].push_back({i+m,t});
            e[i+m].push_back({a,t});

        }

    }


    for(int i=1;i<=q;i++)
    {

        int qu,ta;

        cin>>qu>>ta;


        dijikstra(qu,ta);
        cout<<dis[ta]+w[qu]+w[ta]<<"\n";
    }
    return 0;
}
