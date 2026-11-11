#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 510;
const int M = 500010;
const ll inf = (ll)1e18;

int c, n, m, d, q;
ll w[M];
int k[N];
//map<int, map<int, int> > a; 线路i与地铁站p之间的t的下标
vector<ll> t[N]; // 线路i从k站台（对应a[i][p]下标）到p站厅的时间
vector<pair<int, ll> > tr[N]; // 每条线路记成一个点，存线路之间的图，权重为t[i][p]+t[j][p]，p为换乘的这一站
vector<int> subways[N]; // 第i站下有哪些线路
set<int> subways_fid[N]; // 为了寻找是否有某一条线路，和subways类似
int len_subways[N];
ll ans;
bool vis[N];
ll T;

void dijestra(int strt, int x, int y, int curw) {
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
    q.push({w[x] + w[y] + curw * 2, strt});
    while (!q.empty()) {
        pair<ll, int> tmp = q.top();
        q.pop();
        int u = tmp.second;
        vis[u] = true;

        //printf("%d %lld\n", u, tmp.first);

        if (subways_fid[y].find(u) != subways_fid[y].end()) {
            ans = min(ans, tmp.first);
            break;
        }

        for (int i = 0; i < tr[u].size(); i++) {
            int v = tr[u][i].first;
            int tmpw = tr[u][i].second;
            //printf("v: %d %lld\n", v, tmpw);

            if (vis[v] != false) continue;

            //t[subways[x][i]][a[subways[x][i]][x]]
            q.push({tmp.first + tmpw, v});
        }
    }
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &w[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
        for (int j = 0; j < k[i]; j++) {
            int tmpa;
            ll tmpt;
            scanf("%d%lld", &tmpa, &tmpt);
            t[i].push_back(tmpt);
            T = tmpt;
            subways[tmpa].push_back(i);
            subways_fid[tmpa].insert(i);
            len_subways[tmpa]++;
        }
    }

    //枚举所有站
    for (int p = 1; p <= m; p++) {
        int len = len_subways[p];
        //枚举p这一站下所有线路，两个
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                tr[subways[p][i]].push_back({subways[p][j], T + T});
                tr[subways[p][j]].push_back({subways[p][i], T + T});
            }
        }
    }

    /*for (int i = 1; i <= n; i++) {
        for (int j = 0; j < tr[i].size(); j++) {
            int u = tr[i][j].first;
            int tmpw = tr[i][j].second;
            printf("%d %d %lld\n", i, u, tmpw);
        }
    }*/

    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int lenx = len_subways[x];
        int leny = len_subways[y];
        ans = inf;
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < lenx; i++) {
            //printf("%d ", subways[x][i]);
            dijestra(subways[x][i], x, y, T);
        }
        printf("%lld\n", ans);

        /*printf("kokodayo:\n");

        for (int i = 0; i < lenx; i++) {
            printf("%d ", subways[x][i]);
        }
        printf("\n");
        for (int i = 0; i < leny; i++) {
            printf("%d ", subways[y][i]);
        }
        printf("\n");

        //需要寻找现在所处的线路是否在y的线路之中
        for (int i = 0; i < lenx; i++) {
            if (subways_fid[y].find(subways[x][i]) == subways_fid[y].end()) {
                printf("no\n");
            }else {
                printf("yes\n");
            }
        }
        printf("\n");*/
    }
    return 0;
}

