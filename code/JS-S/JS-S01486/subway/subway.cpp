#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[505];
long long G[505][505];
vector<pair<int,int>> sts[500005]; // <x,t>
int cnts[500005];

int main()
{
    freopen ("subway.in","r", stdin);
    freopen ("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i=1; i<=m; i++)
        cin >> w[i];
    memset(G,0x3f,sizeof(G));
    for (int i=1; i<=n; i++)
    { //500
        // line#i
        cin >> k[i];
        for (int j=1; j<=k[i]; j++) // 500000
        {
            int ta, tt;
            cin >> ta >> tt;
            sts[ta].push_back(make_pair(i,tt));
            cnts[ta]++;
        }
    }
    for (int i=1; i<=m; i++)
    { // 500000
        for (int u=0; u<cnts[i]; u++)
            for (int v=0; v<cnts[i];v++)
            { // 400
                G[sts[i][u].first][sts[i][v].first] = sts[i][u].second +sts[i][v].second;
                G[sts[i][v].first][sts[i][u].first] = sts[i][u].second +sts[i][v].second;
            }
    }
/*
    for (int i=1; i<=m; i++)
    {
        cout << i << ": ";
        for (int j=0; j<cnts[i]; j++)
            cout << sts[i][j].first << '-' << sts[i][j].second << " ";
        cout << endl;
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            cout << G[i][j] << " ";
        cout <<endl;
    }
*/

    for (int i=1; i<=n; i++) G[i][i] = 0;

    for (int K=1; K<=n; K++)
    {
        for (int u = 1; u<=n; u++)
        {
            for (int v = 1; v<=n; v++)
            {
                G[u][v] = min(G[u][K]+G[K][v],G[u][v]);
            }
        }
    }
/*
    cout << "floyd\n";
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            cout << G[i][j] << " ";
        cout <<endl;
    }
*/

    for (int i=1; i<=q; i++)
    {
        int x,y;
        cin >> x >> y;
        long long ans = LONG_MAX;
        for (int a=0; a<cnts[x]; a++)
            for (int b=0; b<cnts[y]; b++)
                    //cout << a << "-" << b << ":" << G[sts[x][a].first][sts[y][b].first]+sts[x][a].second+sts[y][b].second << endl;
                    ans = min(ans, G[sts[x][a].first][sts[y][b].first]+sts[x][a].second+sts[y][b].second);
        cout << ans +w[x]+w[y] << endl;

    }
    fclose (stdin);
    fclose (stdout);
    return 0;
}
