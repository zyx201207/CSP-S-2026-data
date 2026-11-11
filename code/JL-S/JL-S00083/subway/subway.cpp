#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define int long long
using namespace std;
const int M=5e5+5,N=505,MM=5e3+5;
int cccc,n,m,d,q,w[M],k[N],a[N][MM],t[N][MM];
bool vis[M];
vector<int>v[N];
struct nodel
{
    int x,t,p;
    friend bool operator !(nodel u)
    {
        printf("%lld:%lld--%lld\n",u.p,u.x,u.t);
    }
};
queue<nodel>Q;
void bfs(int x,int y)
{
    int ret=1e18;
    nodel Snode1,Snode2;
    Snode1.x=x;Snode1.t=w[x];
    memset(vis,0,sizeof(vis));
    vis[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        Snode1.p=v[x][i];Q.push(Snode1);
    }
    while(!Q.empty())
    {
        Snode1=Q.front();Q.pop();
        //!Snode1;
        if(Snode1.x==y)
        {
            ret=min(ret,Snode1.t+w[y]+t[Snode1.p][Snode1.x]);
            continue;
        }
        for(int i=0;i<v[Snode1.x].size();i++)
        {
            Snode2.p=v[Snode1.x][i];
            for(int j=1;j<=k[Snode2.p];j++)
            {
                Snode2.x=a[Snode2.p][j];
                if(vis[Snode2.x]) continue;
                Snode2.t=Snode1.t+t[Snode1.p][Snode1.x]+t[Snode2.p][Snode1.x];
                vis[Snode2.x]=1;
                Q.push(Snode2);
            }
        }
    }
    printf("%lld\n",ret);
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&cccc,&n,&m,&d,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];j++)
        {
            scanf("%lld%lld",&a[i][j],&t[i][j]);
            v[a[i][j]].push_back(i);
        }
    }
    while(q--)
    {
        int ss,tt;
        scanf("%lld%lld",&ss,&tt);
        bfs(ss,tt);
    }
}
