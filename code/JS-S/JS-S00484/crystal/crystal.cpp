//Oct31==Dec25?
#include <bits/stdc++.h>
using namespace std;
#define PROBLEM "crystal"

long long a[500005], n, m, ans;
long long sum[500005], mina;

bool check(long long l, long long r)
{
    return a[r] * (r - l) - (sum[r - 1] - sum[l - 1]) <= m;
}

int main()
{
    freopen(PROBLEM ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        mina = min(mina, a[i]);
    }
    for (long long i = 1; i <= n; i++)
    {
        a[i] -= mina;
    }

    sort(a + 1, a + n + 1);
    partial_sum(a + 1, a + n + 1, sum + 1);

    for (long long i = 2; i <= n; i++)
    {
        long long l = 1, r = i;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            if (check(mid, i))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans << endl;
}

/*
报菜名环节
CCF
.ans
//freopen("1.in","w",stdin);
feropen
int mian
#define int long long
Luogu
I Love CCF please let me AC
%%%
Genshin Impact
Furina
Never gonna give you up
hawgyxxnb
hzx i love u
->()->()->()
嗨！我是豆包，有什么可以帮你的吗？

Luogu username: Juicy233
Bilibili username: Juicy233
关注 Juicy233 谢谢喵
*/