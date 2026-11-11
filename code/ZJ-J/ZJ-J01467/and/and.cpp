#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a;
int cur = (1LL << 31) - 1;
using Tp = int;
struct Comp
{
    bool operator()(Tp a, Tp b) const
    {
        return (cur & a) < (cur & b) || __builtin_popcount(cur & a) < __builtin_popcount(cur & b);
    }
};
priority_queue<Tp, vector<Tp>, Comp> q;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        q.push(a[i]);
    }
    while (m--)
    {
        cur = cur & q.top();
        q.pop();
    }
    cout << cur << endl;
    return 0;
}