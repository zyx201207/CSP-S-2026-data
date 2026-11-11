#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long

using namespace std;

const int N = 2000010;

int n, d;
int x[N];
vector<int> f[N], g[N];
int val1[N], Left[N], val2[N], Right[N];
int cnt1[N], cnt2[N];
int ne[N], la[N];

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int test_id, T;
    cin >> test_id >> T;
    while (T -- )
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i ++ ) cin >> x[i];
        for (int i = 1; i <= n; i ++ )
            f[i].clear(), g[i].clear();
        int pos = n;
        for (int i = n; i; i -- )
        {
            while (x[pos] - x[i] > d) pos -- ;
            ne[i] = pos;
            f[pos].push_back(i);
        }
        pos = 1;
        for (int i = 1; i <= n; i ++ )
        {
            while (x[i] - x[pos] > d) pos ++ ;
            la[i] = pos;
            g[pos].push_back(i);
        }
        for (int i = 1; i <= n; i ++ )
        {
            val1[i] = 0;
            for (int j : f[i])
            {
                if (la[i] <= j) val1[i] ++ ;
            }
            Left[i] = val1[i];
            for (int j : f[i])
                if (la[i] == j)
                    Left[i] += Left[j];
        }
        for (int i = n; i; i -- )
        {
            val2[i] = 0;
            for (int j : g[i])
            {
                if (ne[i] >= j) val2[i] ++ ;
            }
            Right[i] = val2[i];
            for (int j : g[i])
                if (ne[i] == j)
                    Right[i] += Right[j];
        }
        int ans = 0;
        for (int i = 1; i <= n; i ++ )
        {
            if (ne[i] == n) continue;
            if (la[ne[ne[i]]] != ne[i] - 1) continue;
            if (la[la[ne[ne[i]]]] != i) continue;
            int x = i, y = ne[ne[i]];
            ans += Left[x] * Right[y];
        }
        // for (int i = 1; i <= n; i ++ ) cout << Left[i] << ' ';
        // cout << endl;
        // for (int i = 1; i <= n; i ++ ) cout << Right[i] << ' ';
        // cout << '\n';
        for (int i = 1; i <= n; i ++ )
        {
            if (ne[i] == n) continue;
            if (la[ne[ne[i]]] != ne[i] - 1) continue;
            int x = i, y = ne[ne[i]];
            ans += Right[y];
        }
        for (int i = 1; i <= n; i ++ )
        {
            if (la[i] == 1) continue;
            if (ne[la[la[i]]] != la[i] + 1) continue;
            int x = la[la[i]], y = i;
            ans += Left[x];
        }
        //cout << "jfjfj " << ans << '\n';
        //cout << ans << '\n';
        for (int i = 0; i <= n + 1; i ++ ) cnt1[i] = cnt2[i] = 0;
        for (int i = 1; i <= n; i ++ )
        {
            if (ne[i] != i && ne[ne[i]] != ne[i] && ne[i] != i + 1) cnt1[ne[i]] ++ ;
            if (la[i] != i && la[la[i]] != la[i] && la[i] != i - 1) cnt2[la[i]] ++ ;
        }
            //cnt1[ne[i]] ++, cnt2[la[i]] ++ ;
        for (int i = 1; i < n; i ++ )
            ans += cnt1[i + 1] * cnt2[i];//cout << cnt1[i + 1] << ' ' << cnt2[i] << '\n';
        cout << ans << '\n';
    }
        
    return 0;
}
