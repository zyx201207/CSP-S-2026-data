#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[1000010],k[1000010],dis[510][510];
struct node { long long a,t; };
struct zb { long long x,y; };
bool cmp(node a,node b) { return a.a < b.a; }
vector <node> a[510];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= m;i++) cin>>w[i];
    for(int i = 1;i <= n;i++)
    {
        a[i].push_back({0,0});
        cin>>k[i];
        for(int j = 1,a1,t1;j <= k[i];j++) cin>>a1>>t1,a[i].push_back({a1,t1});
    }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            if(i == j) dis[i][j] = 0;
            else dis[i][j] = 1e9;
    for(int i = 1;i <= n;i++)
        for(int j = i + 1;j <= n;j++)
            for(int x = 1;x <= k[i];x++)
                for(int y = 1;y <= k[j];y++)
                    if(a[i][x].a == a[j][y].a)
                    {
                        dis[i][j] = min(dis[i][j],a[i][x].t + a[j][y].t);
                        dis[j][i] = min(dis[i][j],a[i][x].t + a[j][y].t);
                    }
    for(int x = 1;x <= n;x++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                dis[i][j] = min(dis[i][j],dis[i][x] + dis[x][j]);
    while(q--)
    {
        long long x,y,ans = 1e9;
        cin>>x>>y;
        vector <zb> s,e;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= k[i];j++)
                if(a[i][j].a == x) s.push_back({i,j});
                else if(a[i][j].a == y) e.push_back({i,j});
        for(int i = 0;i < s.size();i++)
            for(int j = 0;j < e.size();j++)
            {
                long long dx1 = s[i].x,dy1 = s[i].y,dx2 = e[j].x,dy2 = e[j].y;
                long long js = a[dx1][dy1].t + a[dx2][dy2].t;
                js += dis[dx1][dx2];
                ans = min(ans,js);
            }
        cout<<ans + w[x] + w[y]<<endl;
    }
    return 0;
}
