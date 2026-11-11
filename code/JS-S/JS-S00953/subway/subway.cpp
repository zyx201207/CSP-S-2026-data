#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;

int w[500005];
vector <int> change;

map <pair<int,int>,int> toIndex;

int dis[505][100005];

int cost[505][100005];
vector <int> train[500005];
bool vis[505][500005];

void init()
{
    for(int i=0;i<505;i++)
    {
        for(int j=0;j<500005;j++)
        {
            dis[i][j]=2147483647;
            vis[i][j]=false;
        }
    }
}

void dijkstra(int nowtrain, int nowstation)
{
    bool flag=true;
    vis[nowtrain][nowstation]=true;
    vector <pair<int,int>> nextSearch;
    for(int i=0;i<train[nowstation].size();i++)
    {
        int nxt=train[nowstation][i];
        if(vis[nxt][nowstation]) continue;
        flag=false;
        dis[nxt][nowstation]=min(dis[nowtrain][nowstation]+cost[nowtrain][nowstation]+cost[next][nowstation],dis[nxt][nowstation]);
        nextSearch.push_back(make_pair(nxt,nowstation));
    }
    for(int i=0;i<change.size();i++)
    {
        int nxt=change[i];
        if(nxt==nowstation||find(train[nxt].begin(),train[nxt].end(),nowtrain)==train[nxt].end()) continue;
        dis[nowtrain][nxt]=dis[nowtrain][nowstation];
        nextSearch.push_back(make_pair(nowtrain,nowstation));
        flag=false;
    }
    if(flag) return;
    for(int i=0;i<nextSearch.size();i++)
    {
        dijkstra(nextSearch[i].first,nextSearch[i].second);
    }
    return;
}

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
        int stanum;
        cin>>stanum;
        for(int j=0;j<stanum;j++)
        {
            int staInd,inputTime;
            cin>>staInd>>inputTime;
            cost[i][staInd]=inputTime;
            train[staInd].push_back(i);
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(train[i].size()>=2) change.push_back(i);
    }
    int tmp=0;
    for(int i=0;i<change.size();i++)
    {
        for(int j=0;j<train[change[i]].size();j++)
        {
            toIndex.insert(make_pair(make_pair(change[i],train[change[i]][j]),tmp));
            tmp++;
        }
    }
    while(q--)
    {
        int from,to;
        cin>>from>>to;
        init();
        train[from].push_back(0);
        train[to].push_back(0);
        dis[0][from]=0;
        dijkstra(0,from);
        cout<<dis[0][to]<<endl;
    }
    return 0;
}
