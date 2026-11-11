#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MMAX = 5e5+5;
const int NMAX = 505;
const int MAXINT = 1e10+5;
int wl[MMAX] = {};
int kl[NMAX] = {};
vector<int> al[NMAX] = {};
vector<int> tl[NMAX] = {};

struct sdata {
    int i, j;
};
struct line {
    int from, to, w;
};

int dn = 0;
sdata data[MMAX] = {};
vector<line> ll[MMAX] = {};
map<string, int> ids;
map<string, int> dis;

/**
 * w[i] 依次表示从每个地铁站的地铁口走到站厅需要的时间
 * a[i,j] 表示第 i 条线路经过的第 j 个地铁站， t[i,j] 表示从该地铁站(j)的站厅走到第 i 条线路的站台需要的时间
 * crosssed[i, j] 表示第 i 个地铁站被第 j 线路穿过
 * data 存储站点信息 (i, j)
 * ll 存储线路信息 (id -> from, to, w)
 * ids 存储节点到 id (传入 "i,j")
**/

vector<int> crossed[NMAX] = {};

string serialN(int x, int y) {
    return x + "," + y;
}

string toString(int x) {
    string r = "";
    while(x) {
        r = char(x%10 + '0') + r;
        x /= 10;
    }
    if (r.size() == 0) r = "0";
    return r;
}

string serialN(line l) {
    sdata f = data[l.from], t = data[l.to];
    cout << l.from << "," << l.to << ": ";
    // return "";
    return "node: {value:" + toString(l.w) + ",from:{line=" + toString(f.i) + ",station=" + toString(f.j) + "},to:{line=" + toString(t.i) + ",station=" + toString(t.j) + "}}";
}

bool DEBUG = true;

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
        int ld = -1; // 上一个节点
        for (int j=1;j<=kl[i];j++) {
            int lamb1, lamb2;
            scanf("%lli", &lamb1); // 地铁站
            scanf("%lli", &lamb2); // 时间
            al[i].push_back(lamb1);
            tl[i].push_back(lamb2);
            crossed[lamb1].push_back(i);
            if (DEBUG) cout << "crossed push: {station=" << lamb1 << ", line=" << i << "}" << endl;
            
            data[dn] = (sdata) {i, lamb1};
            ids[serialN(i, lamb1)] = dn;
            if (ld != -1) {
                ll[dn].push_back((line) {dn, ld, 0});
                ll[ld].push_back((line) {ld, dn, 0});
            }

            ld = dn++;
        }
    }

    // 遍历站台
    for (int i=0;i<NMAX;i++) {
        int sze = crossed[i].size();
        if (sze < 2) continue;
        // 遍历经过的列车
        for (int j=0;j<sze;j++) {
            for (int k=0;k<sze;k++) {
                if (j==k) continue;
                // n1, n2 列车序号 d1, d2 Data 序号
                int n1 = crossed[i][j], n2 = crossed[i][k];
                int d1 = ids[serialN(i,j)], d2 = ids[serialN(i,k)];
                if (DEBUG) cout << n1 << "," << i << " | " << n2 << "," << i << endl;
                int n = tl[n1][i]+tl[n2][i];
                ll[n1].push_back((line) {d1, d2, n});
                ll[n2].push_back((line) {d2, d1, n});
            }
        }
    }

    if (DEBUG) {
        cout << "println DataList" << endl;
        for (int i=0;i<dn;i++) {
            cout << i << ": " << data[i].i << "," << data[i].j << endl;
        }

        cout << "printout ll:" << endl;
        for (int i=1;i<=n;i++) {
            cout << "get line: " << i << ": \n";
            for (int j=0;j<ll[i].size();j++) {
                cout << serialN(ll[i][j]) << endl;
            }
        }
    }

    int minn = MAXINT;
    for ()

    return 0;    
}
