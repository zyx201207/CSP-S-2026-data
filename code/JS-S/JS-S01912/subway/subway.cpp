#define MAXN 500002
#define MAXM 502
#include <iostream>
#include <vector>
using namespace std;

int c, n, m, d ,q, ans = 1e9;
int w[MAXN], a[MAXN], tim[MAXM][MAXN];
struct node{
    int to, val, type;
};
vector<node> edge[MAXM];

void dfs(int s, int e, int cnt, int ty){
  //  cout << ty << " " << s << endl;
  //  cout << s << " " << vis[ty][s] << endl;
  //  cout << endl;
    if(s == e){
        cnt += w[e];
        cnt += tim[ty][e];
        ans = min(ans, cnt);
        return;
    }
    for(int i = 0; i < edge[s].size(); ++ i){
        int tmp = edge[s][i].to, pri = edge[s][i].val, t = edge[s][i].type;

        if(ty == 0){
            dfs(tmp, e, cnt + tim[t][s], t);
        }else{
            if(t == ty){
                dfs(tmp, e, cnt, ty);
            }else{
                dfs(tmp, e, cnt + tim[ty][s] + tim[t][s], t);
            }
        }
    }
    return;
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; ++ i)
        cin >> w[i];
    for(int i = 1; i <= n; ++ i){
        int k;
        cin >> k;
        for(int j = 1; j <= k; ++ j){
            node x;
            cin >> a[j] >> tim[i][a[j]];
            x.type = i;
            x.val = tim[i][a[j]];
            x.to = a[j];
            if(j != 1)
                edge[a[j - 1]].push_back(x);
        }
    }
    for(int t = 1; t <= q; ++ t){
        int s, e;
        cin >> s >> e;
        ans = 1e9;
        dfs(s, e, w[s], 0);
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
