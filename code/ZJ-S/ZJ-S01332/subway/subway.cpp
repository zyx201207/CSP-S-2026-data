#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e16;
const int M=5e5+10;
const int N=505;
const int D = 22;
int c,n,m,d,q;
int f[N][N],w[M],k[N];
vector<int> a[N], t[N];
vector<int> has1[M],has2[M];
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= n;j++){
            f[i][j] = inf;
        }
    }
    for (int i = 1; i <= n;i++)
        f[i][i] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> k[i];
            a[i].resize(k[i] + 1);
            t[i].resize(k[i] + 1);
            for (int j = 1; j <= k[i]; j++)
            {
                cin >> a[i][j] >> t[i][j];
                has1[a[i][j]].push_back(i);
                has2[a[i][j]].push_back(t[i][j]);
            }
        }
    for(int i=1;i<=m;i++){
        int len = has1[i].size();
        for (int jb1 = 0; jb1 < len; jb1++)
        {
           for (int jb2 = 0; jb2 < len; jb2++){
               int j = has1[i][jb1], k = has1[i][jb2];
               int val1 = has2[i][jb1], val2 = has2[i][jb2];
               if (j == k)
                   continue;
               f[j][k] = f[k][j] = val1 + val2;
            }
        }
    }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
    while(q--){
        int x, y; cin>>x>>y;
        int ans = inf;
        int len1 = has1[x].size(), len2 = has1[y].size();
        for (int jb1 = 0; jb1 < len1; jb1++)
        {
           for (int jb2 = 0; jb2 < len2; jb2++){
               int j = has1[x][jb1], k = has1[y][jb2];
               int val1 = has2[x][jb1], val2 = has2[y][jb2];
               ans = min(ans, val1 + val2 + w[x] + w[y] + f[j][k]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
f[i][j]表示从i号线路到j号线路的最小代价
只用考虑中间转移的代价，两边的查询的时候直接加上就可以了
O(n^2*d^2)
*/