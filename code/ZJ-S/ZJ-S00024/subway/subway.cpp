#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int c, n, m, d, q, w[500005], k[505], dis[500005];
vector<int> a[505], t[505];
bitset<500005> bs[505];

void dij(int &s){
    for(int i = 1;i <= m;i++)
        dis[i] = 1e9;
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    dis[s] = 0;
    while(!q.empty()){
        pair<int, int> u = q.top();
        q.pop();
        if(-u.first != dis[u.second])
            continue;
        for(int i = 1, j;i <= n;i++){
            if(!bs[i][u.second])
                continue;
            for(j = 0;j < k[i];j++){
                if(a[i][j] == u.second)
                    break;
            }
            for(int l = 0;l < k[i];l++){
                if(l == j)
                    continue;
                if(t[i][j] + dis[u.second] + t[i][l] < dis[a[i][l]]){
                    dis[a[i][l]] = t[i][j] + dis[u.second] + t[i][l];
                    q.push({-dis[a[i][l]], a[i][l]});
                }
            }
        }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)
        cin >> w[i];
    for(int i = 1, x, y;i <= n;i++){
        cin >> k[i];
        for(int j = 1;j <= k[i];j++){
            cin >> x >> y;
            bs[i][x] = 1;
            a[i].push_back(x);
            t[i].push_back(y);
        }
    }
    int x, y;
    while(q--){
        cin >> x >> y;
        dij(x);
        cout << w[x] + w[y] + dis[y] << '\n';
    }
    return 0;
}

