#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
long long c , n , m , d , q , w[N] , k , dis[N][N] , cnt = 0;
int main()
{
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0) , cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1 ; i <= m ; i++) cin >> w[i];
    int v = m ;
    memset(dis , 0x3f , sizeof dis);
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> k;
        while(k--)
        {
            int u , w;
            cin >> u >> w;
            dis[u][v] = w;
            dis[v][u] = w;
        }
        v++;
    }
    for(int k = 1 ; k <= n + m ; k++)
    {
        for(int i = 1 ; i <= n + m ; i++)
        {
            for(int j = 1 ; j <= n + m ; j++)
            {
                if(dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    while(q--)
    {
        int u , v;
        cin >> u >> v;
        cout << dis[u][v] + w[u] + w[v] << endl;
    }
    return 0;
}
