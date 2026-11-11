#include<bits/stdc++.h>
using namespace std;
const int MAXN=510;
const int MAXM=5e5+7;
int w[MAXM];
vector<pair<int,int> >e[MAXM];
long long dis_[MAXN][MAXN];
vector<pair<int,long long> > dis[MAXN];
int c,n,m,d,q;
long long D[MAXN][MAXN];
void dijk(int p)
{
    for(int i=1;i<=n;i++)D[p][i]=LONG_MAX;
    D[p][p]=0;
    queue<int>qu;
    qu.push(p);
    while(!qu.empty())
    {
        int u=qu.front();
        qu.pop();
        for(pair<int,long long> x:dis[u])
        {
            long long DIS=x.second+D[p][u];
            if(DIS<D[p][x.first])
            {
                qu.push(x.first);
                D[p][x.first]=DIS;
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            int v,t;
            cin>>v>>t;
            pair<int,int>ttt;
            ttt.first=i;
            ttt.second=t;
            e[v].push_back(ttt);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(pair<int,int> x:e[i])
        for(pair<int,int> y:e[i])
            if(x.first!=y.first)
            {
            long long DIS=x.second+y.second;
            dis_[x.first][y.first]=min(dis_[x.first][y.first],DIS);
                if(dis_[x.first][y.first]==0)dis_[x.first][y.first]=DIS;
            }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(dis_[i][j]>0)
            {
                pair<int,long long>na,nb;
                na.first=j;
                nb.first=i;
                na.second=dis_[i][j];
                nb.second=dis_[i][j];
                dis[i].push_back(na);
                dis[j].push_back(nb);
            }
    }
    for(int i=1;i<=n;i++)dijk(i);
    //for(int i=1;i<=n;i++)
    //{
    //for(int j=1;j<=n;j++)
    //    cout<<D[i][j]<<' ';
    //cout<<endl;
    //}
    //cout<<endl;
    for(int i=1;i<=q;i++)
    {
        int U,V;
        long long ans=LONG_MAX>>2;
        scanf("%d%d",&U,&V);
        for(pair<int,int> x:e[U])
        for(pair<int,int> y:e[V])
            ans=min(ans,D[x.first][y.first]+x.second+y.second);
        printf("%lld\n",ans+w[U]+w[V]);
    }
    return 0;
}
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3*/
