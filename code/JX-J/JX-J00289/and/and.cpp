#include <bits/stdc++.h>
#define buff ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
using namespace std;

const int MAXN = 2e5 + 5;

int n, m;
int maxx, cnt;
long long ans;
bool p[MAXN];

long long f(long long x)
{
    long long cnt = 0;
    while (x--)
    {
        cnt += (x % 2 == 1);
    }
    return cnt;
}

struct st {
    int x, fx = f(x);
} a[MAXN];

bool cmp(st a, st b)
{
    return a.fx > b.fx;
}

long long dfs(long long i, long long x)
{
    long long num = 0;
    if (num == m) return x;
    num++;
    dfs(i + 1, (a[i], x & a[i + 1].x));
}

int main(){
    //freopen("and.in", "r", stdin);
    //freopen("and.out", "w", stdout);
    buff;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x;
    }

    sort(a + 1, a + n + 1, cmp);
    ans = dfs(1, a[1].x);
    cout << ans;
    return 0;
}
