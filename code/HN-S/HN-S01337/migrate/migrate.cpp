#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, t;
int n;
ll d;
vector<ll> x;
ll ans = 0;
static inline void solve()
{
    cin >> n >> d;
    x.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> x[i];
    ans = 0;
    cout << ans << '\n'; // 不可以，小白鸟
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    #endif
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> c >> t;
    while (t--) solve();
    return 0;
}
/*
白鸟～我的白鸟～
一去不复还～
白鸟过河滩～（无端联想）
后面不会唱了致歉（x）
沙子比最短。。路？！
这倒是提醒我了
请什么都没用了
CSP-S 2026 已升级为图论专场
打出“又是图论”之后，后面忘了
往下看一眼 T4 怎么也是
呼吸困难，可能是有人开 O2 了，，，要长出触手和复眼了。。。
图论可能只是建模用？
也算作是计数
对于固定右端点左端点应该是它左边的一个连续区间？
不会。。。先换 T3
关注 luogu clx201022 552688 喵，关注 clx201022 谢谢喵
*/