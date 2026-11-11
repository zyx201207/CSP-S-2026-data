#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MMAX = 5e5+5;
const int NMAX = 505;
const int MAXINT = 1e10+5;
const int SEPARATE = 1e10;
int wl[MMAX] = {};
int kl[NMAX] = {};

struct node
{
    int to, v;
};

vector<node> line[MMAX] = {};
int dis[100] = {};

map<string, int> trans; // 交汇点
string serial(int x, int y) {
    if (x>y) swap(x, y);
    return x + "," + y;
}

struct station
{
    vector<int> belong; // 所属线路
    map<int, int> val; // 线路交汇的增量 (line, station)
    
    bool isTrans() {
        return belong.size() > 1;
    }
    bool mergeVal(int line, int t) {
        belong.push_back(line);
        val[line] = t;
        if (isTrans()) {
            for (int i=0;i<belong.size();i++) {
                for (int j=0;j<belong.size();j++) {
                    if (i == j) continue;
                    int n1 = belong[i], n2 = belong[j];
                    if (trans.find(serial(n1, n2)) == trans.end()) trans[serial(n1, n2)] = val[n1]+val[n2];
                    else trans[serial(n1, n2)] = min(trans[serial(n1, n2)], val[n1]+val[n2]);
                }
            }
        }
    }
};



vector<int> al[NMAX] = {};
vector<int> tl[NMAX] = {};

station stal[NMAX];
int minS[MMAX] = {};

int dn = 0;
/**
 * w[i] 依次表示从每个地铁站的地铁口走到站厅需要的时间
 * a[i,j] 表示第 i 条线路经过的第 j 个地铁站， t[i,j] 表示从该地铁站(j)的站厅走到第 i 条线路的站台需要的时间
**/

bool DEBUG = false;

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int c, n, m, d, q; 
    scanf("%lli", &c);
    scanf("%lli", &n);
    scanf("%lli", &m);
    scanf("%lli", &d);
    scanf("%lli", &q);

    // 测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
    for (int i=1;i<=m;i++) scanf("%lli", &wl[i]);
    for (int i=1;i<=n;i++) { // 线路
        scanf("%lli", &kl[i]);
        if (DEBUG) cout << "kl[" << i << "]=" << kl[i] << endl;
        for (int j=1;j<=kl[i];j++) {
            int sta, time;
            scanf("%lli", &sta); // 节点
            scanf("%lli", &time); // 时间
            if (minS[sta] == 0) minS[sta] = time;
            else minS[sta] = min(minS[sta], time);

            stal[sta].mergeVal(i, time);
        }
    }

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (trans.find(serial(i, j)) == trans.end()) continue;
            line[i].push_back( (node) {j, trans[serial(i, j)]});
            // cout << i << "," << j << ": " << trans[serial(i, j)] << endl;
        }
    }

    while(q--) {
        int fr, to;
        scanf("%lli", &fr);
        scanf("%lli", &to);
        for (int i=1;i<=n;i++) dis[i] = 0;
        queue<node> q; 
        for (int i=0;i<stal[fr].belong.size();i++) {
            q.push((node) {stal[fr].belong[i], 0});
        }
        while(!q.empty()) {
            node cur = q.front(); q.pop();
            if (dis[cur.to] <= cur.v) continue;
            dis[cur.to] = cur.v;
            for (int i=0;i<line[cur.to].size();i++) {
                if (dis[cur.to] <= cur.v) continue;
                q.push((node){cur.v+line[cur.to][i].v, line[cur.to][i].to});
            }
        }
        cout << dis[to] << endl;
        cout << wl[fr] + wl[to] + minS[fr] + minS[to] + dis[to] << endl;
    }

    return 0;    
}
