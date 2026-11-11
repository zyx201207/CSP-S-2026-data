#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
class station;
class station{
public:
    int w;
    vector<int> a;
    vector<int> t;
    int size;
    station& operator = (const station& A) {
        a.clear();
        for (int i = 1; i <= A.size; i++) {
            a[i] = A.a[i];
        }
        t.clear();
        for (int i = 1; i <= A.size; i++) {
            a[i] = A.t[i];
        }
        size = A.size;
        return *this;
    }
    inline void pk(const int& x, const int& y) {
        if (a[x] == a[y]) {
            t[x] = max(t[x], t[y]);
            a[y] = 0;
        }
        return;
    }
};
station st[500001];
bool to[500001];
int x[500001];
int y[500001];
inline bool f(const station& A, const station& B) {
    return A.a < B.a;
}
inline void in1() {
    static int a[200001], t[200001];
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &st[i].w);
    }
    for (int i = 1; i <= n; i++) {
        int k;
        memset(a, 0, sizeof(a));
        memset(t, 0, sizeof(t));
        for (int j = 1; j <= k; j++){
            scanf("%d%d", &a[i], &t[i]);
            for (int x = 1; x < i; x++) {
                st[a[i]].a.push_back(a[x]);
                st[a[x]].a.push_back(a[i]);
                int sum = t[i] + t[x];
                st[a[i]].t.push_back(sum);
                st[a[x]].t.push_back(sum);
            }
        }
        for (int j = 1; j <= k; j++) {
            st[j].size += k - 1;
        }
    }
    for (int i = 1; i <= m; i++) {int j = 1;
        for (; j <= st[i].size;j++) {
            st[i].pk(j, a[st[i].a[j]]);
        }
        a[st[i].a[j]] = j;
        memset(a, 0, sizeof(a));
    }
    for (int i = 1; i <= q; i++) {
        scanf("%d%d", &x, &y);
    }
}
class train {
    vector<int> a;
    vector<int> t;
    int size;
};
inline void in2() {
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &st[i].w);
    }
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; j++) {

        }
    }
}
inline void bfs(int x, int y) {
    queue<int> qq;
    qq.push(x);
    long long sum = 0;
    while(!qq.empty()){
        for (int i = 1; i <= st[qq.front()].size; i++) {
            if (qq.front() == y) {

            }
            qq.push(st[qq.front()].a[i]);
        }

    }
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    in1();
    for(int i = 1; i <= q; i++) {
        bfs(x, y);
    }
    return 0;
}
