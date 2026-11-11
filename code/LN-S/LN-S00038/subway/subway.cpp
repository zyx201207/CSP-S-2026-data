#include<bits/stdc++.h>
using namespace std;
const int maxm = 5e5 + 10;
const int maxn = 500 + 10;
int c, n, m, d, q;
int w[maxm], t[maxm][maxn];
//w[i]地铁站i的口到厅的时间，t[i][j]地铁站i厅到路线j站台的时间
vector<int> r[maxm], l[maxn];
bool viss[maxn], visl[maxm];
int ans = INT_MAX;
void bfs(int now, int aim, int line, int tim) {
    //now现在的所在地铁站的编号，aim目标地铁站，line当前所在线路，tim已经所用时间
    //cout << now << " " << aim << " " << line << " " << tim << "\n";
    if(now == aim) {
        ans = min(ans, tim + t[aim][line]);
        //cout << ans << "\n";
        return ;
    }
    viss[now] = true;
    for(auto i : l[now]) {//枚举经过now的线路i
        for(auto j : r[i]) {//枚举；线路i经过的地铁站j
            if(viss[j])//走过了就跳过
                continue;
            //没走过
            if(line == i) {//枚举的线路i恰好就是当前所在的线路
                viss[j] = true;
                bfs(j, aim, line, tim);
                viss[j] = false;
            }
            else {//如果不是当前所在的线路，需要换乘
                if(visl[i])
                    continue;
                viss[j] = true;
                visl[i] = true;
                bfs(j, aim, i, tim + t[now][line] + t[now][i]);
                viss[j] = false;
                visl[i] = false;
            }
        }
    }
    return ;
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++) {
            int sta;//station
            cin >> sta;
            r[i].push_back(sta);
            l[sta].push_back(i);
            cin >> t[sta][i];
        }
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        //cout << "------------------------------\n";
        for(int i = 1; i <= n; i++)
            viss[i] = false;
        for(int i = 1; i <= m; i++)
            visl[i] = false;
        int ansans = INT_MAX;
        //cout << "now aim line tim\n";
        for(auto  i : l[x]) {
            bfs(x, y, i, 0);
            //cout << "ans = " << ans << "\n";
            ansans = min(ansans, ans + w[x] + w[y] + t[x][i]);
        }
        cout << ansans << "\n";
    }
    return 0;
}
