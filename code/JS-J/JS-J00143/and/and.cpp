#include <bits/stdc++.h>
using namespace std;

struct st
{
    long long num;
    long long cnt;
} a[200005];
bool cmp(st x, st y)
{
    if(x.cnt != y.cnt) return x.cnt > y.cnt;
    return x.num > y.num;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    long long INF = 1;
    for(int i = 1; i <= 31; i++) INF *= 2;

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i].num;
    for(int i = 1; i <= n; i++)
    {
        long long tmp = a[i].num;
        while(tmp)
        {
            if(tmp % 2 == 0) tmp /= 2;
            else
            {
                tmp--;
                a[i].cnt++;
            }
        }
    }

    sort(a + 1, a + 1 + n, cmp);
    long long ans = INF - 1;
    for(int i = 1; i <= m; i++)
    {
        ans = ans & a[i].num;
    }
    cout << ans;


    return 0;
}
