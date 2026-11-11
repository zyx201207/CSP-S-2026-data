#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<cstring>
using namespace std;
struct Edge
{
    int v,w;
};
int c,n,m,d,q,w[200005],k[200005],v,w1,ans,x,y;
vector<Edge>edge[200005];
bool flag[200005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=2;j++)
        {
            cin>>v>>w1;
            edge[i].push_back({v,w1});
            edge[v].push_back({i,w1});
        }
    }
    while(q--)
    {
        memset(flag,false,sizeof(flag));
        ans=INT_MAX;
        cin>>x>>y;
        queue<Edge>q;
        q.push({x,w[x]});
        flag[x]=true;
        while(!q.empty())
        {
            Edge u=q.front();
            q.pop();
            if(u.v==y)
            {
                ans=min(ans,u.w);
            }
            for(auto z:edge[u.v])
            {
                if(!flag[z.v])
                {
                    q.push({z.v,u.w+z.w+edge[z.v][z.v].w});
                    //cout<<z.v<<" "<<u.w+z.w+edge[z.v][z.v].w<<endl;
                    flag[z.v]=true;
                }
            }
        }
        cout<<ans+w[y]<<endl;
    }
    return 0;
}
