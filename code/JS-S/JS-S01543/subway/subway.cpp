#include<bits/stdc++.h>
using namespace std;
int c,n,m,p,q;
int w[500001];
vector <int> a[500001];
int t[501][1001];
struct tDot
{
    int step;
    int l;
};
void bfs(int s,int e)
{
    queue <tDot> q;
    tDot d;
    for(int i=0;i<a[s].size();i++)
    {
        int v=a[s][i];
        d = {w[s]+t[v][s],v};
        q.push(d);
    }
    int mins=INT_MAX;
    while(!q.empty())
    {
        d = q.front();
        q.pop();
        bool f=false;
        for(int i=0;i<a[e].size();i++)
        {
            if(a[e][i]==d.l)
            {
                mins = min(mins,d.step);
                f = true;
            }
        }
        if(f)
        {
            continue;
        }
        for(int i=1;i<=m;i++)
        {
            bool f=false;
            for(int j=0;j<a[i].size();j++)
            {
                if(a[i][j]==d.l)
                {
                    f = true;
                }
            }
            if(f)
            {
                for(int j=0;j<a[i].size();j++)
                {
                    if(a[i][j]!=d.l)
                    {
                        q.push({d.step+t[j][i],j});
                    }
                }
            }
        }
    }
    cout<<mins;
    return ;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>p>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x;
            cin>>x;
            a[x].push_back(i);
            cin>>t[i][j];
        }
    }
    for(int i=1;i<=m;i++)
    {
        sort(a[i].begin(),a[i].end());
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        bfs(x,y);
    }
    return 0;
}
