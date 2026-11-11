#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2000010;
int C,T;
int n,d,x[N];

struct Edge {
    int v,w;
    Edge() {}
    Edge(int v,int w):v(v),w(w) {}
    bool operator<(const Edge &other) const {
        return w > other.w;
    }
};

void Dijkstra() {  // 请注意每次要重置
    priority_queue<Edge> heap;
    vector<int> dis(n+10,0x3f3f3f3f);
    vector<int> vis(n+10,0);
    for (int i=1; i<=n; ++i) {
        ;
    }
}

bool edgeEmpty(vector<Edge> edge[],int n) {
    for (int i=1; i<=n; ++i) {
        if (!edge[i].empty()) {
            return false;
        }
    }
    return true;
}

bool ifall(int a,int b) {  // 是否整除
    double aa = double(a), bb = double(b);
    return signed(ceil(aa/bb)) == a / b;
}

int solve() {
    scanf("%lld %lld", &n, &d);
    vector<Edge> edge[n+10];
    for (int lastIdx=1,i=1; i<=n; ++i) {
        scanf("%lld", &x[i]);
        if (i != lastIdx and x[i]-x[lastIdx] <= d) {
            edge[lastIdx].push_back({i,x[i]-x[lastIdx]});
            edge[i].push_back({lastIdx,x[i]-x[lastIdx]});
        } else {
            while (i >= lastIdx and x[i]-x[lastIdx] > d) {
                ++lastIdx;
            }
        }
    }
    if (edgeEmpty(edge,n)) {
        return 0LL;
    }
    if (C >= 1 and C <= 10) {
        ;
    } else if (C >= 11 and C <= 12) {  // A
        int dd = x[2] - x[1];  // 公差 dd <= d
        int cnt = 0;
        for (int i=1; i<=n; ++i) {
            for (int j=n; j>=i; --j) {
                if (x[j]-x[i] <= d) {
                    break;
                }
                cnt += ifall(x[j]-x[i],dd);
            }
        }
        return cnt;
    } else if (C >= 13 and C <= 14) {  // B
        for (int i=1; i<=n; ++i) {
            if (edge[i].size() != n - 1) {
                continue;
            }
            // 根
            ;
        }
    } else if (C >= 15 and C <= 18) {  // C
        ;
    }
}

signed main() {
    // freopen("migrate.in", "r", stdin);
    // freopen("migrate.out", "w", stdout);
    scanf("%lld %lld", &C, &T);
    while (T--) {
        printf("%lld\n",solve());
    }
    return 0;
}