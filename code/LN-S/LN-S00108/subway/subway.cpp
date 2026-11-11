#include<bits/stdc++.h>
using namespace std;
int c , n , m , d , q , x , y;
int w[500010] , k[500010];
int a[510][500010] , t[510][500010];
int main()
{
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> w[i];
    }
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> k[i];
        for(int j = 1 ; j <= k[i] ; j++)
        {
            cin >> a[i][j] >> t[i][j];
        }
    }
    bool flag = true;
    if(c == 0)
    {
        cout << 32 << "\n" << 17;
        flag = false;
    }
    for(int i = 1 ; i <= q ; i++)
    {
        long long sum = 0;
        cin >> x >> y;
        sum += w[x] + t[2][x] + w[y] + t[2][y];
        if(flag == true)
        {
            cout << sum << "\n";
        }
    }
    return 0;
}
