#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M = 5e5 + 5,N = 505;
int w[M];
int dis[N][N];
vector <array <int,2>> e[M];

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n,m,d,_;
    cin >> c >> n >> m >> d >> _;
    for(int i = 1;i <= m;i++)
        cin >> w[i];
    memset(dis,127,sizeof dis);
    for(int i = 1;i <= n;i++)
        dis[i][i] = 0;
    for(int i = 1;i <= n;i++)
    {
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++)
        {
            int a,t;
            cin >> a >> t;
            e[a].push_back({t,i});
        }
    }
    for(int i = 1;i <= m;i++)
    {
        int lsa = 0,lst = 0;
        for(auto x : e[i])
        {
            if(lsa) dis[lsa][x[1]] = min(dis[lsa][x[1]],lst + x[0]);
            lst = x[0],lsa = x[1];
        }
    }
    for(int i = 1;i < n;i++)
        for(int j = i + 1;j <= n;j++)
            for(int k = i + 1;k < j;k++)
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
    while(_--)
    {
        int x,y;
        cin >> x >> y;
        int ans = 1e15;
        for(auto i : e[x])
            for(auto j : e[y])
                ans = min(ans,dis[min(i[1],j[1])][max(i[1],j[1])] + i[0] + j[0]);
        cout << w[x] + w[y] + ans << endl;
    }
    return 0;
}
