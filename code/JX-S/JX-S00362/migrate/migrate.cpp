#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#define LCUR cur << 1
#define RCUR cur << 1 | 1
#define LSON l, mid, LCUR
#define RSON mid + 1, r, RCUR
#define QL ql, qr, LSON
#define QR ql, qr, RSON
#define MID ((l + r) >> 1)

template <typename T>
using vec = std::vector<T>;
template <typename T>
using vec2 = vec<vec<T>>;
using LL = long long;
using ULL = unsigned long long;

template <typename T>
using vec = std::vector<T>;
template <typename T>
using vec2 = vec<vec<T>>;

template <typename T>
class SegmentTree
{
   private:
    int size;
    vec<T> t, tag;
    void PushUp(int cur)
    {
        t[cur] = t[LCUR] + t[RCUR];
    }
    void ApplyTag(int l, int r, int cur, T fa)
    {
        t[cur] += fa * (r - l + 1);
        tag[cur] += fa;
    }
    void PushDown(int l, int r, int cur)
    {
        if (tag[cur] == 0) return;
        int mid = MID;
        ApplyTag(LSON, tag[cur]);
        ApplyTag(RSON, tag[cur]);
        tag[cur] = 0;
    }
    void Update(T val, int ql, int qr, int l, int r, int cur)
    {
        if (ql <= l && r <= qr)
        {
            ApplyTag(l, r, cur, val);
            return;
        }
        int mid = MID;
        PushDown(l, r, cur);
        if (ql <= mid) Update(val, QL);
        if (qr > mid) Update(val, QR);
        PushUp(cur);
    }
    T Query(int pos, int l, int r, int cur)
    {
        if (l == r)
        {
            return t[cur];
        }
        int mid = MID;
        PushDown(l, r, cur);
        if (pos <= mid) return Query(pos, LSON);
        if (pos > mid) return Query(pos, RSON);
    }
   public:
    SegmentTree(int _size) : size(_size), t((_size << 2) + 6), tag((_size << 2) + 6) {}
    void Update(int ql, int qr, T val) { Update(val, ql, qr, 1, size, 1); }
    T Query(int pos) { return Query(pos, 1, size, 1); }
};

const int MAXN = 2e6 + 5;
const LL INF = 3e18;
LL x[MAXN];
ULL n, d;

struct sg
{
    int l, r;
};
sg Find2Plus(LL pos)
{
    int idx = (std::upper_bound(x + 1, x + n + 1, pos + d) - x - 3);
    if (idx < pos) return {-1, -1};
    LL l = (idx == 0 ? -INF : x[idx]);
    LL r = x[idx + 1];
    int il = std::upper_bound(x + 1, x + n + 1, l + d) - x;
    int ir = std::upper_bound(x + 1, x + n + 1, r + d) - x - 1;
    if (ir < il) return {-1, -1};
    return {il, ir};
}
sg Find1Plus(LL pos)
{
    int idx = std::upper_bound(x + 1, x + n + 1, pos + d) - x - 2;
    if (idx < pos) return {-1, -1};
    LL l = (idx == 1 ? -INF : x[idx]);
    LL r = x[idx + 1];
    int il = std::upper_bound(x + 1, x + n + 1, l + d) - x;
    int ir = std::upper_bound(x + 1, x + n + 1, r + d) - x - 1;
    if (ir < il) return {-1, -1};
    return {il, ir};
}
void Solve()
{
    std::cin >> n >> d;
    for (int i = 1; i <= n; i++) std::cin >> x[i];

    SegmentTree<LL> f1(n), f2(n);
    f1.Update(1, n, 1);
    LL ans = 0;
    for (int i = 1; i <= n; i++)
    {
        sg s2 = Find2Plus(x[i]);
        sg s1 = Find1Plus(x[i]);
        if (s1.l != -1)
        {
            f1.Update(s1.l, s1.r, f1.Query(i));
            f2.Update(s1.l, s1.r, f2.Query(i));
        }
        if (s2.l != -1)
        {
            f2.Update(s2.l, s2.r, f1.Query(i));
        }
        ans += f2.Query(i);
    }
    std::cout << ans << '\n';
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    std::cin >> c >> T;
    while (T--) Solve();
    return 0;
}

