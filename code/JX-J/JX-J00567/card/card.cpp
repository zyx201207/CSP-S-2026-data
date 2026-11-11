#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 5005;

int n, m;
int ans[N];
int a[N];
vector<int> t;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) {
        t.clear();

        for (int j = i; j <= n; j++) {
            int x = a[j];
            int p = -1;

            for (int k = 0; k < t.size(); k++)
                if (t[k] == x) p = k;

            if (p != -1) {
                t.erase(t.begin() + p, t.end());
                // for (int j = p; j < t.size(); j++) t[j] = 0;
            }

            t.push_back(x);
        }

        for (int k : t) ans[k]++;
    }

    for (int i = 1; i <= m; i++) printf("%d ", ans[i]);

    return 0;
}
