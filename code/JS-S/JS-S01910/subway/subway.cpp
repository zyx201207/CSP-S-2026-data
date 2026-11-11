#include<bits/stdc++.h>
using namespace std;
int a[1005],g[1005];
vector<pair<int,int> >b[505],c[505];
bool f[1005];
priority_queue<pair<int,int> >d;
int qwer(int w,int e,int q)
{

    while(!d.empty())d.pop();
    int r;
    for(int i=1;i<=q;i++)f[i]=false;
    memset(g,0x3f,sizeof(g));
    g[w]=0;
    d.push(make_pair(0,w));
    for(int i=1;i<=q;i++)
    {
        if(d.empty())break;
        while(f[d.top().second]&&!d.empty())
        {
            d.pop();
        }
        if(!d.empty())r=d.top().second;
        else break;
        f[r]=true;
        for(int j=0;j<c[r].size();j++)if(g[c[r][j].first]>c[r][j].second+g[r]&&!f[c[r][j].first])
        {
            g[c[r][j].first]=c[r][j].second+g[r];
            d.push(make_pair(g[c[r][j].first],c[r][j].first));
        }
    }
    return g[e];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int q,w,e,r,t,y,u;
    cin>>q>>q>>w>>e>>r;
    for(int i=1;i<=w;i++)cin>>a[i];
    for(int i=1;i<=q;i++)
    {
        cin>>t;
        for(int j=1;j<=t;j++)
        {
            cin>>y>>u;
            b[i].push_back(make_pair(y,u));
        }
        for(int j=1;j<=t;j++)for(int k=j+1;k<=t;k++)
        {
            c[b[i][j].first].push_back(make_pair(b[i][k].first,b[i][j].second+b[i][k].second));
            c[b[i][k].first].push_back(make_pair(b[i][j].first,b[i][j].second+b[i][k].second));
        }
    }
    for(int i=1;i<=r;i++)
    {
        cin>>t>>y;
        cout<<qwer(t,y,w)+a[t]+a[y]<<"\n";
    }
}
