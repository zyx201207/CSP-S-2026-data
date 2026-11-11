#include<iostream>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],k,x,y,mmin=-0x7fffffff,aa,ac,ba,bc;
map<int,bool> vis[N];
//vector<at> sub[N];
struct node
{
    int v,w;
};
vector<node> graph[N];/*
int dfs(int step,int cttm)
{
    if(step==y)
    {
        if(mmin>cttm)
            mmin=cttm;
        return 0;
    }
    for(int i=1;)
}*/
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k>>aa>>ac>>ba>>bc;
        graph[aa].push_back({ba,ac+bc});
        graph[ba].push_back({aa,ac+bc});
    }
    //for(int i=1;i<=n;i++)
    //    cout<<graph[i][0].w<<' '<<graph[i][1].w<<'\n';
    while(q--)
    {
        cin>>x>>y;
        long long sumt=w[x]+w[y];
        while(x!=y)
        {
            if(graph[x][0].v==x)
            {
                sumt+=graph[x][1].w;
                x=graph[x][1].v;
            }else
            {
                sumt+=graph[x][0].w;
                x=graph[x][0].v;
            }
        }
        cout<<sumt<<'\n';
    }
    /*while(q--)
    {
        cin>>x>>y;
        dfs()
    }*/
    return 0;
}
