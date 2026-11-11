#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge
{
    int v,w;
};
int c,n,m,d,q,dis[502][502],staw[500002],subk[502];
vector<edge>subesta[502],staesub[500002];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>staw[i];
    for(int i=1;i<=n;i++)
    {
        cin>>subk[i];
        for(int j=1;j<=subk[i];j++)
        {
            int v,w;
            cin>>v>>w;
            subesta[i].push_back({v,w});
            staesub[v].push_back({i,w});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    //cout<<"subway graph creation\n";
    for(int a=1;a<=n;a++)
    {
        for(int i=0;i<subesta[a].size();i++)
        {
            int b=subesta[a][i].v,abw=subesta[a][i].w;
            for(int j=0;j<staesub[b].size();j++)
            {
                int c=staesub[b][j].v,bcw=staesub[b][j].w;
                //cout<<a<<' '<<b<<' '<<c<<' '<<dis[a][c]<<' '<<abw<<' '<<bcw<<'\n';
                dis[a][c]=min(dis[a][c],abw+bcw);
                dis[c][a]=min(dis[c][a],abw+bcw);
            }
        }
    }
    /*
    cout<<"subway graph before floyd\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<dis[i][j]<<' ';
        cout<<'\n';
    }
    //*/
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    /*
    cout<<"subway graph before floyd\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<dis[i][j]<<' ';
        cout<<'\n';
    }
    //*/
    for(int i=1;i<=q;i++)
    {
        int x,y,tans=1e18;
        cin>>x>>y;
        for(int j=0;j<staesub[x].size();j++)
        {
            for(int k=0;k<staesub[y].size();k++)
                tans=min(tans,dis[staesub[x][j].v][staesub[y][k].v]+staesub[x][j].w+staesub[y][k].w);
        }
        cout<<staw[x]+staw[y]+tans<<'\n';
    }
    return 0;
}
/*
0 3 7 20 1
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
*/
