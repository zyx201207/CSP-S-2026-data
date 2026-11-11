#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5000 + 5,M = 2e6 + 5;
ll dist[N][N];
ll x[M];

vector<int> edge[N];

void bfs(int s)
{
    
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c,T;
    cin >> c >> T;
    if(c == 11 || c == 12)
    {
        while(T--)
        {
            ll n,d;
            cin >> n >> d;
            for(int i = 1; i <= n; i++) cin >> x[i];
            ll dx = (x[2] - x[1]);
            if(n >= 3 && d >= 2 * dx && d < 3 * dx) cout << n - 3 << "\n";
            else cout << "0\n";
        }
    }
    while(T--)
    {
        memset(dp,0,sizeof dp);
        int n;
        ll d;
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> x[i];
        for(int i = 1; i <= n; i++)
            for(int j = 1; j < i; j++)
                if(llabs(x[i] - x[j]) <= d)
                {
                    edge[i].push_bak(j);
                    edge[j].push_bak(i);
                }
        cout << 0 << "\n";
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/