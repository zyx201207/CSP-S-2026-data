#include <bits/stdc++.h>

using namespace std;

vector <vector <long long> > ans (100001, vector<long long>(0, 0));


void dp (int start, int end, vector<long long>& w, vector<vector<int>>& zhan, int total, int xian, int flag, vector <vector <int>> visit) {
    for (int i = 0; i < zhan.size(); i++){
    if (zhan[end][xian] != 0) {
        total += zhan[end][xian];
        total += w[end];
        ans[flag].push_back(total);
        return;
    }
    }
    if (xian != -1) {
        for (int i = 1; i < zhan.size(); i++) {
            if (zhan[i][xian] != 0 && visit[i][xian] == 0){
                visit[i][xian] = 1;
                for (int j = 0; j < zhan[0].size(); j++){
                    if (zhan[i][j] != 0 && visit[i][j] == 0) {
                        visit[i][j] = 1;
                        dp(i, end, w, zhan, total+zhan[i][xian]+zhan[i][j], j, flag, visit);
                    }
                }
            }
        }
    }
    for (int i = 0; i < zhan[0].size(); i++) {
        if (zhan[start][i] != 0) {
            dp(start, end, w, zhan, total+zhan[start][i], i, flag, visit);
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<long long> w (m);
    for (int i = 0; i < m; i ++) {
        cin >> w[i];
    }
    int g = 0;
    vector<vector<int>> zhan (m+1, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        cin >> g;
        for (int j = 0; j < g; j++){
            int temp;
            cin >> temp;
            cin >> zhan[temp][i];
        }
    }
    for (int i = 0; i < q; i++) {
        int start, end;
        cin >> start >> end;
        vector <vector <int>> visit (m+1, vector<int> (n, 0));
        dp (start, end, w, zhan, w[start-1], -1, i, visit);
        sort(ans[i].begin(), ans[i].end());
        for (int j = 0; j < ans[i].size(); j++) {
            if (ans[i][j] != 0) {
                cout << ans[i][j];
            }
        }
    }
    return 0;
}
