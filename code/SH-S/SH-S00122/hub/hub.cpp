#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 500010;
int n,m,a[N];

struct Edge {
    int v,w;
    Edge() {}
    Edge(int v,int w):v(v),w() {}
};
vector<Edge> edge;

signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for (int i=1; i<=n; ++i) {
        scanf("%lld", &a[i]);
    } 
    return 0;
}