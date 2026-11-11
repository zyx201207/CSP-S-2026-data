#include<bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int maxm = 5e5 + 5;

struct node{
    int y;
    long long p, d;
    bool operator<(const node i)const{
        return d < i.d;
    }
};

int c, n, m, dis, Q, k[maxm];
bool f[1005][1005];
long long w[maxm], d[maxm], t[1005][1005];
vector<pii> e[maxm]; //点，线路bianhao
priority_queue<node> q;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
   freopen("subway.in", "r", stdin);
   freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> dis >> Q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        for(int j = 1, a0, t0, a1, t1; j <= k[i]; j++){
            cin >> a1 >> t1;
            t[i][a1] = t1, f[i][a1] = 1;
            if(j != 1){
                e[a0].push_back({a1, i});
            }
            a0 = a1;
        }
    }
    for(int i = 1, x, y; i <= Q; i++){
        cin >> x >> y;
        fill(d + 1, d + m + 1, 1e15);
        for(int j = 1; j <= n; j++){
            if(!f[j][x]) continue;
            q.push({x, j, t[j][x]});
        }
        while(!q.empty()){
            node k = q.top();
            q.pop();
            if(d[k.y] > k.d){
                d[k.y] = k.d;
                for(pii g : e[k.y]){
                    long long v = (k.p == g.second ? 0 : t[k.p][k.y] + t[g.second][k.y]);
                    if(g.first == y) v += t[g.second][g.first];
                    q.push({g.first, g.second, k.d + v});
                }
            }
        }
        cout << (d[y] == 1e15 ? 0 : d[y]) + w[x] + w[y] << '\n';
    }
    return 0;
}
