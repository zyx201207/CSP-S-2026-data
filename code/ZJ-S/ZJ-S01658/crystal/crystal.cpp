// 最后一次参加 CSP，

// 14:52 Done.

// 我是文明有素质的学军人。。。

// 第一题还能有错吗，没时间检查了，看第二题

#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 500005;
int n, m;
int a[N];
int val;
int ans;
int cnt;
int op_cnt;
queue<int> q;
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    val = -1e13;
    ans = 0;
    cnt = 0;
    op_cnt = 0;
    for(int i = 1; i <= n; i ++) {
        int new_val = a[i];
        op_cnt += cnt * (new_val - val);
        q.push(a[i]);
        cnt ++;
        while(op_cnt > m) {
            op_cnt -= new_val - q.front();
            cnt --;
            q.pop();
        }
        val = new_val;
        ans = max(ans, (long long)(q.size()));
    }
    cout << ans << "\n";
    // cerr << clock() * 1.0 / CLOCKS_PER_SEC << "\n";
    return 0;
}