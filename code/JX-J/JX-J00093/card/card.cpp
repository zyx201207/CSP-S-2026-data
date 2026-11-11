#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500005;

int a[MAXN];
vector<int> v;
long long ans[MAXN];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int h = 1; h <= n; h++) {
        for (int i = h; i <= n; i++) {
            for (int j = 0; j < v.size(); j++) {
                if (v[j] == a[i]) {
                    for (int k = j; k < v.size(); k++) {
                        v[k] = 0;
                    }
                    break;
                }
            }
            v.push_back(a[i]);
        }
        for (int i = 0; i < v.size(); i++) {
            ans[v[i]]++;
        }
        v.clear();
    }
    for (int i = 1; i <= m; i++) {
        printf("%lld ", ans[i]);
    }
    return 0;
}
