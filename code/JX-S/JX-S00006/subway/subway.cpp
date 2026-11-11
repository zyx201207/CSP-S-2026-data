#include<bits/stdc++.h>
using namespace std;
const int N1 = 5e5 + 5;
const int N2 = 1e5 + 3;
int c, d, q;
long long n, m;
int way[505], a[505][N2];
int up_to_middle[N1], middle_to_down[505][N1], x[505], y[505], time2, maxn;
void dfs(int way_number, int point, int i){
    if (a[way_number][point] == 0) {
        return ;
    }
    if (point > a[way_number][way[way_number]] and point != y[i]) {
        return ;
    } else if (point == y[i]) {
        maxn = max(maxn, time2);
        return ;
    }

    time2 = time2 + middle_to_down[way_number][point];
    dfs(way_number, point + 1, i);
    dfs(way_number + 1, point, i);
    return ;
}
map<pair<int, int>, int> mp;
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> up_to_middle[i];
    }
    for(int i = 1; i <= n; i++) {;
        cin >> way[i];

        for (int j = 1; j <= way[i]; j++) {
            cin >> a[i][j] >> middle_to_down[i][a[i][j]];
        }
    }
    for (int i = 1; i <= q; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= q; i++) {

        int time = up_to_middle[x[i]] + up_to_middle[y[i]];
        dfs(1, x[i], i);
        cout << maxn;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
