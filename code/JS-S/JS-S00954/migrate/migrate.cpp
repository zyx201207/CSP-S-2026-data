#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
#define int long long 
int c,t;
int n,d,x[N],f[N],deg[N],cnt,dis[N],gra[N];
vector<int> g[N];
void start()
{
    for (int i=1;i<=n;i++) {f[i]=deg[i]=0;g[i].clear();}
    cnt=0;
}
void clean() 
{
    for (int i=1;i<=n;i++) {f[i]=0;dis[i]=1e18;gra[i]=deg[i];}
}
void toposort(int s)
{
    queue<int> q;
    q.push(s);
    clean();
    dis[s]=0;f[s]=1;
    while(!q.empty())
    {
        int b=q.front();q.pop();
        int u=b;
        for (int i=0;i<(int)g[b].size();i++)
        {
            int y=g[b][i];
            gra[y]--;
            //u->y
            if (dis[y]>dis[u]+1) 
            {
                dis[y]=dis[u]+1;
                f[y]=f[u];
            }
            else if (dis[y]==dis[u]+1)
            {
                f[y]+=f[u];
            }
            if (gra[y]==0)
            {
                q.push(y);
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (f[i]==2) cnt++;
    }
}
void del(int s)
{
    for (int i=0;i<(int)g[s].size();i++)
    {
        int y=g[s][i];deg[y]--;
    }
}
signed main()
{
    //very important
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for (int kkk=1;kkk<=t;kkk++)//easy to gdb
    {
        cin>>n>>d;
        start();
        for (int i=1;i<=n;i++) cin>>x[i];
        //add_edge and sao miao xian 
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                if (x[j]-x[i]<=d) {g[i].push_back(j);deg[j]++;}
            }
        }
        for (int i=1;i<=n;i++)
        {
            toposort(i);
            del(i);
        }
        cout<<cnt<<"\n";
    }
    return 0;
}