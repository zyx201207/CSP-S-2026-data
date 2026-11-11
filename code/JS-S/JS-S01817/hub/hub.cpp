#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 510, maxm = 5e5 + 5;
int c, m, n, d, q, w[maxn], matrix[maxn][maxn];
struct node {
    int len;
    int sta[maxn], t[maxn];
}line[maxn];
vector<int> stl[maxn];
int main() {
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        line[i].len = k;
        for (int j = 1; j <= k; j++) {
            cin >> line[i].sta[j] >> line[i].t[j];
            stl[line[i].sta[j]].push_back(i);
        }
    }
    return 0;
}
