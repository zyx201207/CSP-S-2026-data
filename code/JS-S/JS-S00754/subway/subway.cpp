/*
freopen!
freopen!
freopen!

long long!
long long!
long long!

pianfen!
*/

// S-VI-MT-T-34/85
// S-VII-MT-T-43
// S-VIII-MT-T-44
// S-IX-MT-T-54
// S-X-MT-Obj.140

// D-VI-HT-VK3001(P)
// D-VII-HT-Tiger(P)
// D-VIII-HT-VK10001(P)
// D-IX-HT-Maus(Pre)
// D-X-HT-Maus

//subway.cpp

#include <bits/stdc++.h>

#define MAX_N 550
#define MAX_M 500050

#define INF 1e18

using namespace std;

int c, n, m, d, q;

struct Subway
{
    int w;//ditiekou->zhanting
    int t[MAX_N], k;//zhanting->zhantan
};
Subway s[MAX_M];

int g[MAX_N][MAX_N];

void Floyd()
{
    int k, i, j;

    for(k=1;k<=n;++k)
    {
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {

            }
        }
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;
    int a, b;
    int x, y;

    cin>>c>>n>>m>>d>>q;

    for(i=1;i<=m;++i)
    {
        cin>>s[i].w;
    }

    for(i=1;i<=n;++i)
    {
        cin>>s[i].k;

        int last;
        for(j=1;j<=s[i].k;++j)
        {
            cin>>a>>b;
            s[i].t[a] = b;
            if(j!=1)
            {
                g[last][a] = i;
                g[a][last] = i;
            }
            last = a;
        }
    }

    for(i=1;i<=q;++i)
    {
        cin>>x>>y;
        int line = g[x][y];
        int ans = s[x].w+s[line].t[x]+s[y].w+s[line].t[y];

        cout<<ans<<'\n';
    }

    return 0;
}
