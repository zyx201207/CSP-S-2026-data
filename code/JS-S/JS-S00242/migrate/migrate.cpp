#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e6+10;
const int INF = 0x3f3f3f3f;
ll n, d, x[N];

namespace SMALL{
int best[305][305];
int times[305];
void dfs(int t, int v, int from){
    //cout << "VIS " << t << " " << v << endl;
    if (t != from){
        if (best[from][t] == v){
            times[t]++;
        }
    }
    for(int i = t + 1; i <= n; i++){
        if (x[i] - x[t] <= d){
            dfs(i, v+1, from);
        }
    }
}
void main()
{
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            int has = 0, cnt = 0;
            for(int now = i; now < j; now++){
                if (has + x[now+1] - x[now] <= d){
                    has += x[now+1] - x[now];
                } else {
                    cnt++;
                    has = x[now+1] - x[now];
                    if (has > d){
                        best[i][j] = INF;
                        break;
                    }
                }
            }
            if (has > 0) cnt++;
            best[i][j] = cnt;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
            memset(times, 0, sizeof(times));
        //cout << "START " << i << endl;
        dfs(i, 0, i);
        for(int j = i+1; j <= n; j++){
            if (times[j] == 2){
                ans++;
    //cout << "GET " << i << " " << j << endl;
            }
        }
    }
    cout << ans << endl;
}
}

namespace CASEA{
void main()
{
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    d /= (x[2] - x[1]);
    //cout << "DBG " << d << endl;
    if (d == 1 || d == 0) {
        cout << 0 << endl;
        return;
    }
    if (d == 2){
        cout << n - 3 << endl;
        return;
    }
    ll c1 = 2*d-1;
    if (c1 > n){
        cout << 0 << endl;
        return;
    }
    cout << (n-1) - (c1-1) << endl;
}
}

namespace CASEB{
void main()
{
    int cnt;
    for(int i = 1; i <= n; i++){
        if (x[i] - d <= x[1] && x[i] + d >= x[n]){
            cnt++;
        }
    }
    if (cnt > 2){
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
    return;
}
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, c;
    cin >> c >> T;
    while(T--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
        }
        if (c <= 10){
            SMALL::main();
        }
        else if (c == 11 || c == 12){
            CASEA::main();
        }
        else if (c == 13 || c == 14){
            CASEB::main();
        }
    }
}
