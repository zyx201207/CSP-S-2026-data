#include <bits/stdc++.h>
using namespace std;

#define int long long 

constexpr int maxn = 2e6 + 100;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;

int n, d;
int x[maxn];

constexpr int maxN = 5e3 + 100;

int mndis[maxN][maxN];
int cnt[maxN][maxN];

#define ls (p<<1)
#define rs (p<<1|1)
#define mid (l+((r-l)>>1))

struct SegmentTree
{
    int mn[maxN];
    int cnt[maxN];

    void push_up(int p)
    {
        mn[p] = min(mn[ls], mn[rs]);
        cnt[p] = 0;
        if(mn[p] == mn[ls])
        {
            cnt[p] += cnt[ls];
        }
        if(mn[p] == mn[rs])
        {
            cnt[p] += cnt[rs];
        }
    }

    void update(int p, int l, int r, int x, int k, int k2)
    {
        if(l == r)
        {
            mn[p] = k;
            cnt[p] = k2;
            return ;
        }
        
        if(x <= mid) update(ls, l, mid, x, k, k2);
        else         update(rs, mid+1, r, x, k, k2);

        push_up(p);
    }

    pair<int, int> query()
    {
        return make_pair(mn[1], cnt[1]);
    }
};

#undef ls
#undef rs
#undef mid 

vector<pair<int, int>> event[maxN];

SegmentTree seg;

void solve_nle300()
{
    for(int l = 1; l <= n; ++l)
    {
        for(int r = l; r <= n; ++r)
        {
            for(int nxt = r + 1; nxt <= n && x[nxt] - x[r] <= d; ++nxt)
            {
                if(mndis[l][nxt] > mndis[l][r] + 1)
                {
                    mndis[l][nxt] = mndis[l][r] + 1;
                    cnt[l][nxt] = cnt[l][r];
                }
                else if(mndis[l][nxt] == mndis[l][r] + 1)
                {
                    cnt[l][nxt] += cnt[l][r];
                }
            }
        }
    }
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    
    int c, t;
    scanf("%lld%lld", &c, &t);

    while(t--)
    {
        scanf("%lld%lld", &n, &d);

        for(int i = 1; i <= n; ++i)
        {
            scanf("%lld", &x[i]);
        }
        
        if(n == 1)
        {
            printf("0\n");
            continue;
        }
        
        if(c >= 11 && c <= 12)
        {
            int dist = x[2] - x[1];
            int cnt = d / dist;
            if(cnt <= 1)
            {
                printf("0\n");
            }
            else
            {
                int len = cnt * 2;
                int ans = max(n - len + 1, 0LL);
                printf("%lld\n", ans);
            }

            continue;
        }

        for(int i = 1; i <= n; ++i)
        {
            for(int j = i; j <= n; ++j)
            {
                mndis[i][j] = INF;
                cnt[i][j] = 0;
            }
        }

        for(int i = 1; i <= n; ++i)
        {
            mndis[i][i] = 0;
            cnt[i][i] = 1;
        }

        if(n <= 300)
        {
            solve_nle300();
        }
        else
        {
            for(int l = 1; l <= n; ++l)
            {
                for(int i = 1; i <= n; ++i)
                {
                    seg.update(1, 1, n, i, INF, 0);
                    event[i].clear();
                }
                for(int r = l; r <= n; ++r)
                {
                    int lower = r + 1;
                    int upper = upper_bound(x + 1, x + 1 + n, x[r] + d) - x - 1;
                    if(lower <= upper)
                    {
                        event[lower].emplace_back(1, r);
                        event[upper + 1].emplace_back(-1, r);
                    }
                    
                    if(r != l)
                    {
                        for(auto now : event[r])
                        {
                            int op = now.first;
                            int id = now.second;

                            if(op == 1)
                            {
                                seg.update(1, 1, n, id, mndis[l][id] + 1, cnt[l][id]);
                            }
                            else
                            {
                                seg.update(1, 1, n, id, INF, 0);
                            }
                        }

                        auto res = seg.query();
                        
                        mndis[l][r] = res.first;
                        cnt[l][r] = res.second;
                    }
                }
            }
        }

        int ans = 0;

        for(int l = 1; l <= n; ++l)
        {
            for(int r = l + 1; r <= n; ++r)
            {
                if(cnt[l][r] == 2) ++ans;
            }
        }

        printf("%lld\n", ans);
    }
}