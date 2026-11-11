#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
const int MAXD=25;
const long long INF=1e18;
int c,n,m,d,q,k[MAXN],a[MAXN][MAXN],cr[MAXN*MAXD][MAXN];
long long w[MAXN*MAXD],t[MAXN][MAXN],dist[MAXN];
//w[i]: Hall i <-> Exit i.
//a[i][j]: The j-th Station of Line i.
//t[i][j]: Hall in a[i][j] <-> Line i in a[i][j].
//cr[i][j]: cr[a[i][j]][i]=j.
struct node
{
    long long sp;int u;
    const bool operator<(node y)const{return sp>y.sp;}
    //Is this right? Oh, I do not know!
};
//sp: How much time we have spent in walking.
//u: Which Line we are taking.
inline int f(int x,int y)
{
    priority_queue<node> pq;
    for(int i=1;i<=n;i++)
    {
        if(cr[x][i]) pq.push({t[i][cr[x][i]],i}),dist[i]=t[i][cr[x][i]];
        else dist[i]=INF;
    }
    while(!pq.empty())
    {
        long long sp;int u;
        sp=pq.top().sp,u=pq.top().u,pq.pop();
        for(int i=1;i<=m;i++)
        {
            if(cr[i][u])
            {
                for(int v=1;v<=n;v++)
                {
                    if(u==v) continue;
                    if(cr[i][v])
                    {
                        if(sp+t[u][cr[i][u]]+t[v][cr[i][v]]<dist[v]) dist[v]=sp+t[u][cr[i][u]]+t[v][cr[i][v]],pq.push({dist[v],v});
                        //if(dist[v]!=INF)

                    }
                }
            }
        }

    }
    long long ans=INF;
    for(int i=1;i<=n;i++)
        if(cr[i][y]) ans=min(ans,dist[i]);
    return ans+w[x]+w[y];
}
//I forget Dijkstra!!!
//I am angry!!!
//In fact, I can take subway and use less time than walk to that Line in a station.
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway1.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j],cr[a[i][j]][i]=j;
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;cin>>x>>y;
        cout<<f(x,y)<<'\n';
    }
    return 0;
}
//It is too difficult and terrible for me to solve it!!!
//I must stop trying this problem for minutes.
//I want to [DATA REMOVED], but I never want to be not allowed to take part in CSP for 3 years.
// Maybe I should use DSU, but I have no time.
//
//I often recall the past.
//The life is taken a photo in my brain. I turn my memory into the clouds in the sky.
//Clouds are also different from each other, some are light, and some are heavy.
//I forget other passages nowadays. In fact, I never memorize them. However, I still remember this:
//Where should I stop? I ask myself.
//
//Emmm......I think that my English is not very well.
//
//Oh, is there anyone plays SCP:SL made by Northwood? It is free on Steam! Support it please miaowu~
