#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long a[N];

int dist(int x, int y)
{
    return abs(a[y] - a[x]);
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--)
    {
        int n, d;
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int ans = 0;
        for(int l = 1; l < n; l++)
        {
            
            for(int r = l + 1; r <= n; r++)
            {
                int cnt = 0;
                if(dist(l, r) <= d) continue ;
                for(int k = l + 1; k <= r - 1; k++)
                    if(dist(l, k) <= d && dist(k, r) <= d)
                        cnt++;
                if(cnt == 2) ans++;
            }
            
        }
        cout << ans << '\n';
    }
    return 0;
}