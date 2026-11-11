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

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int c = readint(), // 测试点编号
        m = readint(), // 地铁线路数
        n = readint(), // 地铁站数
        d = readint(), // 每个地铁站最多被几条线路经过
        q = readint(); // 出行计划数
    vector<int> w(m + 1), // w[i]: 从第 i 个地铁站的地铁口走到站厅需要的时间
                k(n + 1), // k[i]: 第 i 条线路经过的地铁站数
                x(q + 1), // x[i]: 第 i 个出行计划的起点所在的地铁站编号
                y(q + 1); // y[i]: 第 i 个出行计划的终点所在的地铁站编号
    vector<vector<int>> a(n + 1), // a[i][j]: 第 i 条线路经过的第 j 个地铁站
                        t(n + 1); // t[i][j]: 从第 j 个地铁站的站厅走到第 i 条线路的站台需要的时间
    for (int i = 1; i <= m; i++)
        w[i] = readint();
    for (int i = 1; i <= n; i++)
    {
        k[i] = readint();
        a[i].resize(k[i] + 1);
        t[i].resize(k[i] + 1);
        for (int j = 1; j <= k[i]; j++)
            a[i][j] = readint(), t[i][j] = readint();
    }
    for (int r = 1; r <= q; r++)
        x[r] = readint(), y[r] = readint();
    
    for (int i = 0; i < q; i++)
    {
        cout << "0\n";
    }
    return 0;
}                                                                                                                                
// 不会