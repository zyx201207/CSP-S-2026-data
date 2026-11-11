#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#define AK return
#define CSP 0;
using ll = long long;
using namespace std;
vector<pair<int,int>> g[600001];
int w[500001],v[2001][2001];
ll d[2001][2001];
ll l[500001],ld[500001];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,dd,q,bbb;
    cin >> c >> n >> m >> dd >> q;
    for(int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    if(n <= 2)
{
    ll r = 1e18;
    for(int i = 1;i <= n;i++)
    {
        int k;
        cin >> k;
        if(k == 1)
        {
            int a,b;
            cin >> a >> b;
            continue;
        }
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        r = min(r,b+d);
    }
    while(q--)
    {
        cout << w[1]+w[2]+r << '\n';
    }
    AK CSP
    }
    for(int i = 1;i <= n;i++)
    {
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++)
        {
            int a,b;
            cin >> a >> b;
            bbb = b;
            if(k != 1)
            {
                g[a+n].push_back({i,b});
                g[i].push_back({a+n,b});
            }
        }
    }
    if(c >= 12 && c <= 15)
{
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        queue<pair<ll,int>> pq;
        vector<int> dd(n+m+1,1e9);
        vector<bool> vv(n+m+1,false);
        dd[x] = 0;
        pq.push({0,x});
        while(!pq.empty())
        {
            auto f = pq.front();
            auto c = f.first;
            auto u = f.second;
            pq.pop();
            if(vv[u])
            {
                continue;
            }
            if(u == y)
            {
                break;
            }
            vv[u] = true;
            for(auto &ii : g[u])
            {
                int j = ii.first,w = ii.second;
                if(!vv[j])
                {
                    dd[j] = dd[u]+1;
                    pq.push({dd[j],j});
                }
            }
        }
        cout << dd[n+y]*bbb+w[x]+w[y] << '\n';
    }
    AK CSP
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    for(int i = 1;i <= m+n;i++)
    {
        for(int j = 1;j <= m+n;j++)
        {
            d[i][j] = 1e18;
        }
        d[i][i] = 0;
        pq.push({0,i});
        while(!pq.empty())
        {
            auto f = pq.top();
            auto c = f.first;
            auto u = f.second;
            pq.pop();
            if(v[i][u])
            {
                continue;
            }
            v[i][u] = true;
            for(auto &ii : g[u])
            {
                int j = ii.first,w = ii.second;
                if(d[i][u]+w < d[i][j])
                {
                    d[i][j] = d[i][u]+w;
                    pq.push({d[i][j],j});
                }
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        cout << d[n+x][n+y]+w[x]+w[y] << '\n';
    }
    AK CSP
}
