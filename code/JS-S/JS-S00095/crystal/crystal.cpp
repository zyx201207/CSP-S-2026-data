#include <bits/stdc++.h>
using namespace std;

namespace FastRead
{
    constexpr int bufMAX = 1 << 20;
    char buf[bufMAX];
    int buf_len = 0, buf_pos = 0;
    inline char getchr()
    {
        return (buf_pos == buf_len && (buf_len = fread(buf, 1, bufMAX, stdin)) == (buf_pos = 0) ? 0 : buf[buf_pos++]);
    }
    inline long long readint()
    {
        char c;
        do c = getchr(); while (c != 0 && !(('0' <= c && c <= '9') || c == '-'));
        long long flag = ((c == '-') ? (c = getchr(), -1) : 1), num = 0;
        while ('0' <= c && c <= '9') num = num * 10 + c - '0', c = getchr();
        return flag * num;
    }
}
using FastRead::readint;

long long n, m, a[500010];

// int cnt = 0;

map<long long, long long> l;
long long check()
{
    long long maxn = 0;
    for (auto i : l)
        maxn = max(i.second, maxn);
    return maxn;
}
long long dfs(long long x, long long pos)
{
    // cout << ++cnt << ":\tdfs(" << x << ", " << pos << ")" << endl;
    if (x == 0)
    {
        // cout << "\t\t\t:" << check() << endl;
        return check();
    }
    long long maxn = check();
    for (long long i = pos; i < n; i++)
    {
        l[a[i]++]--;
        l[a[i]]++;
        maxn = max(maxn, dfs(x - 1, i));
        l[--a[i]]++;
        l[a[i] + 1]--;
    }
    return maxn;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    n = readint(), m = readint();
    for (long long i = 0; i < n; i++)
        l[a[i] = readint()]++;
    // for (auto i : l) cout << i.first << " " << i.second << endl;
    cout << dfs(m, 0) << '\n';

    return 0;
}
// 暴力，3.in、4.in TLE

// J组没考上的半天前连DFS都不会的初中生误闯天家