#include<bits/stdc++.h>
using namespace std;
int w[500005],k[505],ta[500005],tt[500005];
vector<pair<int,int>>e[500005];
vector<pair<int,int>>t[500005];
queue<pair<int,int>>qu;
int dis1[500005],dis2[500005];
int c,n,m,d,q;
int find(int u,int g)
{
    for(auto i:t[u])
        if(i.first==g)
            return i.second;
    return 0x3f3f3f3f;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
            cin>>ta[j]>>tt[j];
        for(int j=1;j<k[i];j++)
        {
            for(int l=j+1;l<=k[i];l++)
                e[ta[j]].push_back(make_pair(ta[l],i));
            for(int l=1;l<j;l++)
                e[ta[j]].push_back(make_pair(ta[l],i));
        }
        for(int j=1;j<=k[i];j++)
            t[ta[j]].push_back(make_pair(i,tt[j]));
    }
    while(q--)
    {
        memset(dis1,0x3f,sizeof(dis1));
        memset(dis2,0x3f,sizeof(dis2));
        int x,y;
        cin>>x>>y;
        qu.push(make_pair(x,w[x]));
        dis1[x]=w[x];
        while(!qu.empty())
        {
            pair<int,int> u=qu.front();
            qu.pop();
            for(auto i:e[u.first])
            {
                int ts=u.second+find(u.first,i.second)+find(i.first,i.second);
                if(ts<dis1[i.first])
                {
                    dis1[i.first]=ts;
                    qu.push(make_pair(i.first,dis1[i.first]));
                }
            }
        }
        qu.push(make_pair(y,w[y]));
        dis2[y]=w[y];
        while(!qu.empty())
        {
            pair<int,int> u=qu.front();
            qu.pop();
            for(auto i:e[u.first])
            {
                int ts=u.second+find(u.first,i.second)+find(i.first,i.second);
                if(ts<dis2[i.first])
                {
                    dis2[i.first]=ts;
                    qu.push(make_pair(i.first,dis2[i.first]));
                }
            }
        }
        cout<<min(dis1[y]+w[y],dis2[x]+w[x])<<endl;
    }
    return 0;
}