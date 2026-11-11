/*
freopen!
freopen!
freopen!

long long!
long long!
long long!

pianfen!
*/

// C-VII-HT-BZ-58
// C-VIII-HT-BZ-166
// C-IX-HT-BZ-68
// C-X-HT-BZ-75
// C-XI-HT-BZ-79

//migrate.cpp

#include <bits/stdc++.h>

#define MAX_N 2000050
#define MAX_NN 5050

#define INF 1e18

using namespace std;

int c, t;
int n, d;
unsigned long long x[MAX_N];
unsigned long long g[MAX_NN][MAX_NN];
unsigned long long ans;

void Floyd()
{
    int k, i, j;

    for(k=1;k<=n;++k)
    {
        for(i=1;i<k;++i)
        {
            for(j=k+1;j<=n;++j)
            {
                if(g[i][j] > g[i][k]+g[k][j])
                {
                    g[i][j] = g[i][k]+g[k][j];
                    //ans = 0;
                }
                /*
                else if(g[i][j] == g[i][k]+g[k][j])
                {
                    ++ans;
                }
                */
            }
        }
    }

    return ;
}
void Solve()
{
    int i, j;
    int cnt = 1;

    unsigned long long tmin = INF;

    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            if(g[i][j] < tmin)
            {
                tmin = g[i][j];
                cnt = 1;
            }
            else if(g[i][j] == tmin)
            {
                ++cnt;
                if(cnt == 2)
                {
                    ++ans;
                }
                else
                {
                    --ans;
                }
            }
        }
    }

    return ;
}
void Init()
{
    int i, j;

    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            g[i][j] = INF;
        }
    }

    return ;
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int i, j;

    cin>>c>>t;

    while(t--)
    {
        cin>>n>>d;
        
        for(i=1;i<=n;++i)
        {
            cin>>x[i];
        }
        
        Init();
        for(i=1;i<=n;++i)
        {
            for(j=i+1;j<=n;++j)
            {
                if(x[j]-x[i] <= d)
                {
                    g[i][j] = (x[j]-x[i]);
                }
            }
        }
        ans = 0;
        Floyd();
        Solve();

        cout<<ans<<'\n';
    }

    return 0;
}
/*
5 5 
1 2 4 8 9
*/

/*
5 8
-3 -1 2 2 7
*/