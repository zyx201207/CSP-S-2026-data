#include <bits/stdc++.h>
using namespace std;

// see this !
// how to Calc memory cost ???
// ok it cost 459027344UL bytes staticly
// memory limit is 1GB. maybe ok?
// however, vector will cost another a lot..
// i think it's not so bad..


// The Code is too complex, I don't want to change it any more...
// RP ++.
// hope it can get more scores.
namespace Prog {
#define cin ifs
#define cout ofs
ifstream ifs;
ofstream ofs;

constexpr int MAX_M = 500010;
constexpr int MAX_N = 510;
constexpr int MAX_D = 25;
constexpr int MAX_Q = 100010;
constexpr int MAX_FIN = MAX_N + MAX_M + MAX_M * MAX_D;
typedef long long var;

struct Edge {
    var v, w;
    bool operator>(const Edge& rhs) const {
        return w > rhs.w;
    }
};

var c, n, m, d, q;

map<int, int> mpID[MAX_M];
inline var toID(const var typ, const var id, const var id2 = 1) {
    if(typ == 1) { // DiTieKou
        return id;
    } else if(typ == 2) { // ZhanTing
        return id + MAX_M;
    } else if(typ == 3) { // ZhanTai && Road
        const var d = MAX_N + MAX_M;
        const var d1 = id * MAX_D;
        if(mpID[id][id2] == 0) {
            mpID[id][id2] = mpID[id].size();
        }
        return d + d1 + mpID[id][id2];
    }
    return 0;
}

// bitset<MAX_M> vis;
bool vis[MAX_FIN];
var dis[MAX_FIN];
var ans[MAX_Q];

stack<int> vi;

void dijkstar(const int s, const vector<Edge> g[]) {
    while(!vi.empty()) {
        const int toc = vi.top();
        dis[toc] = 0x3f3f3f3f3f3f3f3f;
        vis[toc] = false;
        vi.pop();
    }
    priority_queue<Edge, vector<Edge>, greater<Edge>> q;
    dis[s] = 0;
    q.push((Edge){s, dis[s]});
    vi.push(s);
    while(!q.empty()) {
        const int u = q.top().v;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        vi.push(u);
        for(const auto v : g[u]) {
            if(dis[v.v] > dis[u] + v.w) {
                dis[v.v] = dis[u] + v.w;
                q.push({v.v, dis[v.v]});
            }
        }
    }
}


var w[MAX_M];

vector<Edge> edge[MAX_FIN];
// may be i need to do sth...
// edge[1 ~ MAX_N] => 地铁口
// edge[MAX_N+1 ~ 2*MAX_N] => 站厅
// edge[2*MAX_N+1 ~ 2*MAX_N+MAX_M] => 


void read_all() {
    cin >> c >> n >> m >> d >> q;

    for(int i=1;i<=m;i++) {
        cin >> w[i];
        // edge[toID(1, i)].push_back({toID(2, i), w[i]});
        // edge[toID(2, i)].push_back({toID(1, i), w[i]});
    }
    for(int i=1;i<=n;i++) {
        var k;
        cin >> k;
        var lst_ar = -1;
        for(int j=1;j<=k;j++) {
            var ar, tr;
            cin >> ar >> tr;
            if(lst_ar != -1) {
                edge[toID(3, ar, i)].push_back({toID(3, lst_ar, i), 0});
                edge[toID(3, lst_ar, i)].push_back({toID(3, ar, i), 0});
            }
            edge[toID(3, ar, i)].push_back({toID(2, ar), tr});
            edge[toID(2, ar)].push_back({toID(3, ar, i), tr});
            lst_ar = ar;
        }
    }
}

struct Questions {
    int u, v, id;
} Qs[MAX_Q];

int mian() {
    // freopen("subway.in", "r", stdin);
    // freopen("subway.out", "w", stdout);
    ifs.sync_with_stdio(false);
    ofs.sync_with_stdio(false);
    ifs.open("subway.in");
    ofs.open("subway.out");
    // i'll try sth new.
    // this maybe faster.

    read_all(); 
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    // why there are soooo many things to read?
    // i can't even understand how i can read them.


    for(int Q=1;Q<=q;Q++) {
        cin >> Qs[Q].u >> Qs[Q].v;
        Qs[Q].id = Q;
        // dijkstar(toID(2, u), edge);
        // cout << dis[toID(2, v)] + w[u] + w[v] << '\n';
    }
    sort(Qs+1, Qs+q+1, [](const Questions& x, const Questions& y) {
        return x.u < y.u;
    });
    int last_u = -1;
    for(int Q=1;Q<=q;Q++) {
        const int u = Qs[Q].u;
        const int v = Qs[Q].v;
        if (last_u == u) {
            ans[Qs[Q].id] = dis[toID(2, v)] + w[u] + w[v];
        } else {
            dijkstar(toID(2, u), edge);
            ans[Qs[Q].id] = dis[toID(2, v)] + w[u] + w[v];
        }
        last_u = u;
    }
    for(int Q=1;Q<=q;Q++) {
        cout << ans[Q] << '\n';
    }

    // fclose(stdin);
    // fclose(stdout);
    ifs.close();
    ofs.close();
    return 0;
}

}


int main() {
    return Prog::mian();
}