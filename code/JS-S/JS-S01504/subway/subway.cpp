#include <iostream>
#include <vector>
#include <cstdio>
#define int long long
using namespace std;

struct node1
{
    int a,t;
};

struct node2
{
    int z,t;
};

vector <node1> line[505];
vector <node2> lll[500005];
int w[500005];
int k[505];
int c,n,m,d,q;
const int inf = 0x3f3f3f3f3f3f3f3f;
int dp[505][505];

int min_n(int a,int b)
{
    if(a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}


signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;

    for(int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    // cout << "tgt1\n";
    for(int i = 1;i <= n;i++)
    {
        int k[i];
        cin >> k[i];
        node1 tmp;
        for(int j = 1;j <= k[i];j++)
        {
            cin >> tmp.a >> tmp.t;
            line[i].push_back(tmp);
            lll[tmp.a].push_back({i,tmp.t});
        }
    }
    // cout << "tgt2\n";

    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            dp[i][j] = inf;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        dp[i][i] = 0;
    }

    for(int i = 1;i <= m;i++)
    {
        for(int j = 0;j < lll[i].size();j++)
        {
            for(int k = 0;k < lll[i].size();k++)
            {
                dp[lll[i][j].z][lll[i][k].z] = min(dp[lll[i][j].z][lll[i][k].z],lll[i][j].t + lll[i][k].t);
                dp[lll[i][k].z][lll[i][j].z] = min(dp[lll[i][k].z][lll[i][j].z],lll[i][k].t + lll[i][j].t);
            }
        }
    }
    for(int k = 1;k <= n;k++)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        int ans = inf;
        for(int i = 0;i < lll[x].size();i++)
        {
            for(int j = 0;j < lll[y].size();j++)
            {
                ans = min(ans,dp[lll[x][i].z][lll[y][j].z] + w[x] + w[y] + lll[x][i].t + lll[y][j].t);
            }
        }
        cout << ans << '\n';
    }

    // cout << "tgt3\n";
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
