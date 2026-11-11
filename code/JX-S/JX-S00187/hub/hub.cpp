#include<queue>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int c,t;
int anss=0;
int dep[1000006];
bool v[1000006];
int f[1000006];
vector<int> va[1000006];
void bfs(int s)
{
    v[s]=1;
    dep[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int y:va[x])
        {
            if(v[y])
            {
                continue;
            }
            v[y]=true;
            dep[y]=dep[x]+1;
            q.push(y);
        }
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int tt=1;tt<=t;tt++)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            va[u].push_back(v);
            va[v].push_back(u);
        }
        memset(dep,0x3f,sizeof(dep));
        memset(v,0,sizeof(v));
        bfs(1);
        int yu=dep[1],u=1;
        for(int i=min(2,n);i<=n;i++)
        {
            if(dep[i]>yu)
            {
                yu=dep[i];
                u=i;
            }
        }
        memset(dep,0x3f,sizeof(dep));
        memset(v,0,sizeof(v));
        bfs(u);
        yu=dep[1];u=1;
        for(int i=min(2,n);i<=n;i++)
        {
            if(dep[i]>yu)
            {
                yu=dep[i];
                u=i;
            }
        }
        cout<<yu/2<<endl;
    }
    return 0;
}
