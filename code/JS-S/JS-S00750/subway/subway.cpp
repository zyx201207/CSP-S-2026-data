#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 505;
const int M = 500010;
int c, n, m, d, q;
int w[M];
ll ans;
bool vis[M][N];
vector <int> line[N];
vector <pair<int, int> > trans[N];

// cur_station, cur_line(0 stands for zhanting), fa_station, fa_line, target_station
void dfs(int ui, int uj, ll dis, int tar, int depth){
    // for (int i=0; i<depth; i++){
    //     cout << "\t";
    // }
    // printf("%d-%d-%d\n", ui, uj, dis);
    if (ui == tar){
        for (pair <int, int> tmp : trans[ui]){
            if (tmp.first == uj){
                // cout << "--------------------OK:" << tmp.first << " " << tmp.second << endl;
                ans = min(ans, dis + tmp.second);
                return;
            }
        }
    }

    if (dis >= ans) return;

    // take the metro to other place
    for (int vi : line[uj]){
        if (vis[vi][uj]) continue;
        vis[vi][uj] = 1;
        dfs(vi, uj, dis, tar, depth+1);
        vis[vi][uj] = 0;
    }
    // take another metro
    if (uj == 0){ // at zhanting
        for (pair <int, int> tmp : trans[ui]){
            int vj = tmp.first;
            int vd = tmp.second;
            if (vis[ui][vj]) continue;
            vis[ui][vj] = 1;
            dfs(ui, vj, dis+vd, tar, depth+1);
            vis[ui][vj] = 0;
        }
    }else if (!vis[ui][0]){ // go to zhanting
        for (pair <int, int> tmp : trans[ui]){
            if (tmp.first == uj){
                vis[ui][0] = 1;
                dfs(ui, 0, dis+tmp.second, tar, depth+1);
                vis[ui][0] = 0;
            }
        }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> c >> n >> m >> d >> q;

    for (int i=1; i<=m; i++) cin >> w[i];
    for (int i=1; i<=n; i++){
        int k;
        cin >> k;
        for (int j=1; j<=k; j++){
            int a, t;
            cin >> a >> t;
            line[i].push_back(a);
            trans[a].push_back({i, t}); // t stands for the time from zhanting to metroI's zhantai
        }
    }

    while (q--){
        int s, e;
        cin >> s >> e;
        ans = 0x3f3f3f3f3f3f3f3f;
        for (pair <int, int> tmp : trans[s]){
            vis[s][tmp.first] = 1;
            dfs(s, tmp.first, w[s]+tmp.second, e, 0);
            vis[s][tmp.first] = 0;
        }
        cout << ans + w[e] << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

// 0 2 5 20 2
// 4 1 9 2 5
// 3 1 5 2 7 4 6
// 3 2 3 3 4 5 7
// 1 3
// 27
// 1 2
// 5