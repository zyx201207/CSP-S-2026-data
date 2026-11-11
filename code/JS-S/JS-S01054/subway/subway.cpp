#include<bits/stdc++.h>
#define int long long
#define ls (p<<1)
#define rs (ls|1)
#define F first
#define S second
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
void fileopen(string s)
{
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
int w[500003],k[503];
vector<int> a[503],t[503];//如题且1-index
vector<pair<int,int> > g[500003];//g[i]表示站厅i可以到达的线路的编号与代价
int dis[503][503];
int n,m,d,q;
signed main()
{
    memset(dis,0x3f,sizeof(dis));
    fileopen("subway");
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testnode,i,j,x,y;
    cin>>testnode>>n>>m>>d>>q;
    for(i=1;i<=m;i++)cin>>w[i];
    for(i=1;i<=n;i++)
    {
        dis[i][i]=0;
        cin>>k[i];
        a[i].push_back(0);
        t[i].push_back(0);
        for(j=1;j<=k[i];j++)
        {
            cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
            g[x].push_back({i,y});
        }
    }
    for(i=1;i<=m;i++)
    {
        for(auto p:g[i])
        {
            for(auto q:g[i])
            {
                if(p==q)continue;
                dis[p.F][q.F]=min(dis[p.F][q.F],p.S+q.S);
            }
        }
    }
    /*
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)cout<<dis[i][j]<<' ';
        cout<<'\n';
    }
    */
    for(int k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            if(dis[i][k]>=inf)continue;
            for(j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    while(q--)
    {
        cin>>x>>y;
        int ans=inf;
        for(auto p:g[x])for(auto q:g[y])ans=min(ans,dis[p.F][q.F]+p.S+q.S);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
/*
15:44 疑似正确做法？
考虑只将线路视为点，对于每个站厅，直接将其连接的线路两两连边，可以令点的量级变为O(n)，边的量级为O(md^2)，又注意到边实际上仅有至多O(n^2)条，取min即可。
使用Floyd预处理最短路，询问时直接枚举两端各自连接的线路，复杂度O(md^2+n^3+qd^2)（68pts）
(?)
注意到其实所有站厅连出的总边数是O(∑ki)=O(m)的
若干个和为500000的自然数a1,a2,...,ap，且每一项都不大于20
它们的平方和的量级？似乎是O(md)的？
复杂度O(md+n^3+qd^2)？
我说实践出真知

16:05 飞快的通过了所有的大样例
虽然没有最大数据的一档但是我没有用样例6的特殊性质一样跑过去了是不是说明这理论上是对的（

不管了，期望100pts

Can you see the meaning inside yourself
Can you see the meaning in your darkness
Where are you now Have you gone away
Here now Is it just a lookalike
All of the world is slowly changing
In a way I cannot see from here

341799!!
*/
