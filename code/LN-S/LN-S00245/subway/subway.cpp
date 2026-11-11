#include<bits/stdc++.h>
#define P pair<int,int>
#define F first
#define S second
using namespace std;

const int M=5e5+10;
struct node
{
    int u,l;
    bool operator > (node y)
    {
        return l>y.l;
    }
};
int c,n,m,d,qq;
vector<pair<int,int>> g[M];
vector<int> way[M];
map<int,int> mp[505];
int w[M];



int DIS[2005][2005];

int dij(int s,int de)
{
    if(DIS[s][de]) return DIS[s][de];
    int dis[600],vis[600];
    for(int i=1;i<=550;i++) dis[i]=1e9,vis[i]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(make_pair(0,s));
    dis[s]=0;
    while(q.size())
    {
        pair<int,int> t=q.top();
        q.pop();
        int u=t.S;
        vis[u]=1;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i].S;
            if(vis[v]) continue;
            if(dis[v]>dis[u]+g[u][i].F)
            {
                dis[v]=dis[u]+g[u][i].F;
                q.push(make_pair(dis[v],v));
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        DIS[s][i]=dis[i];
    }
    return dis[de];
}

void solveAA()
{


    for(int i=1;i<=n;i++)
    {
        int a1,a2,t1,t2,k;
        scanf("%d%d%d%d%d",&k,&a1,&t1,&a2,&t2);
        g[a1].push_back(make_pair(t1+t2,a2));
        g[a2].push_back(make_pair(t1+t2,a1));
    }

    for(int i=1;i<=qq;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",dij(x,y)+w[x]+w[y]);
    }

}

void solveB()
{

    return;
}

int way1[2005][2005];
int way2[2005][2005];
void solve()
{

    for(int i=1;i<=n;i++)
    {
        cout<<endl<<i<<endl;
        int k,pos,ti;
        scanf("%d",&k);
        int way1[2005];
        int way2[2005];
        for(int j=1;j<=k;i++)
        {
            scanf("%d%d",&pos,&ti);
            way2[j]=ti;
            way1[j]=pos;

        }
        for(int aa=1;aa<k;aa++)
        {

            for(int bb=aa+1;bb<=k;bb++)
            {
                g[way1[aa]].push_back(make_pair(way2[aa]+way2[bb],way1[bb]));
                g[way1[bb]].push_back(make_pair(way2[aa]+way2[bb],way1[aa]));
            }
        }


    }

    for(int i=1;i<=qq;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",dij(x,y)+w[x]+w[y]);
    }

    exit(0);
}

int main()
{

    //freopen("subway1.in","r",stdin);
   // freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&qq);
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    if(c>=7&&c<=11)
    {
        solveAA();
        return 0;
    }
    solve();

    /*
   for(int i=1;i<=n;i++)
    {
        int k,pos,ti;
        scanf("%d",&k);
        for(int j=1;j<=k;i++)
        {
            scanf("%d%d",&pos,&ti);
            mp[i][pos]=ti;
            way[i].push_back(pos);
        }

    }

    if(c>=12&&c<=19) solveB();
    */
    return 0;
}
