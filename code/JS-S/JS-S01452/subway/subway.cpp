#include <iostream>
#include<vector>
using namespace std;
long long g[1001][1001];
long long c , n , m , d , q , l[1001] , x , y , s[500001] , f[1001][1001];
vector<int> a[500001] , t[500001] , p[500001];
int main()
{
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1 ; i <= m ; i ++){
        cin >> s[i];
    }
    for(int i = 1 ; i <= n ; i ++){
        cin >> l[i];
        for(int j = 1 ; j <= l[i] ; j ++){
            cin >> x >> y;
            a[x].push_back(i);
            t[x].push_back(y);
        }
    }
    for(int i = 1 ; i <= m ; i ++){
        for(int j = 0 ; j < a[i].size() ; j ++){
            for(int k = 0 ; k < a[i].size() ; k ++){
                if(j == k) continue;
                g[a[i][j]][a[i][k]] = t[i][j] + t[i][k];
            }
        }
    }
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= n ; j ++){
            if(i == j) f[i][j] = 0;
            else f[i][j] = (g[i][j] != 0 ? g[i][j] : 0x3f3f3f3f3f3f3f3f);
        }
    }
    for(int k = 1 ; k <= n ; k ++){
        for(int i = 1 ; i <= n ; i ++){
            for(int j = 1 ; j <= n ; j ++){
                f[i][j] = min(f[i][k] + f[j][k] , f[i][j]);
            }
        }
    }
    for(int i = 1 ; i <= q ; i ++){
        long long u , v , mas = 0x3f3f3f3f3f3f3f3f;
        cin >> u >> v;
        for(int i = 0 ; i < a[u].size() ; i ++){
            for(int j = 0 ; j < a[v].size() ; j ++){
                mas = min(mas , f[a[u][i]][a[v][j]] + s[u] + s[v] + t[u][i] + t[v][j]);
            }
        }
        cout << mas << '\n';
    }
    return 0;
}
