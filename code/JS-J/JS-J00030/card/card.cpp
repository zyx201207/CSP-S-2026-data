#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;

const int N = 500005;
const int M = 300005;
int n, m, a[N], lst[N], cnt, val[N], d[N];
int ans[M];
pair<int,int> tod[N];
vector<array<int,2>> nd[N];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    memset(lst, 0x3f, sizeof lst);
    for(int i=n;i>=1;i--) {
        int x = a[i];
        if(lst[x] > i && lst[x] <= n) {
            ++cnt;
            tod[cnt] = {i, lst[x]-1};
            nd[i].push_back({1, cnt});
            nd[lst[x]-1].push_back({2, cnt});
        }
        lst[x] = i;
    }
    int sum = 0;
    for(int i=1;i<=n;i++) {
        for(auto ed: nd[i]) {
            int op = ed[0], id = ed[1];
            if(op == 1) {
                val[id] = i-sum;
                sum += val[id];
            } else {
                sum -= val[id];
            }
        }
    }
    for(int i=1;i<=cnt;i++) {
        int s = tod[i].first, t = tod[i].second;
        d[s] -= val[i], d[t+1] += val[i];
    }
    for(int i=1;i<=n;i++) {
        d[i] += d[i-1];
        ans[a[i]] += d[i]+i;
    }
    for(int i=1;i<=m;i++)
        cout << ans[i] << ' ';
    return 0;
}