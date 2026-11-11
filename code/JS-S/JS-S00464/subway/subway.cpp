#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,k,x,y,mi,w[500005];
bool st[505][500005];
vector<vector<pair<int,int> > > a(505);
string S;

void dfs(int now,string s,int sum)
{
    if(now == y)
    {
        mi = min(mi,sum);
        return;
    }
    for(int i=1 ; i<=n ; i++)
    {
        if(st[i][now] && s[i]=='0')
        {
            int p = -1;
            for(int j=0 ; j<a[i].size() ; j++)
            {
                if(a[i][j].first == now)
                    p = j;
                if(p>=0 && j>p)
                {
                    s[i] = '1';
                    dfs(a[i][j].first,s,sum+a[i][p].second+a[i][j].second);
                    s[i] = '0';
                }
            }
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(int i=0 ; i<=505 ; i++)
        S += "0";
    cin >> c >> n >> m >> d >> q;
    for(int i=1 ; i<=m ; i++)
        cin >> w[i];
    for(int i=1 ; i<=n ; i++)
    {
        cin >> k;
        for(int j=1 ; j<=k ; j++)
        {
            int u,v;
            cin >> u >> v;
            a[i].push_back({u,v});
            st[i][u] = 1;
        }
    }
    while(q--)
    {
        cin >> x >> y;
        mi = 1e9;
        dfs(x,S,0);
        cout << mi+w[x]+w[y] << endl;
    }
    return 0;
}
