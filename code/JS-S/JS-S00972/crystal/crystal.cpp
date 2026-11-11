#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int n, ans;
long long m, a[N];
long long sum;
queue<int> q;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    //printf("1\n");
    for (int i = 1; i <= n; i++)
    {
        int t = i;
        //ans = 0, cnt = 0;
        while (a[i] == a[t] && i <= n)
        {
            i++;
            //ans++, cnt++;
        }
        if (!q.empty()) sum += q.size() * (a[t] - a[q.back()]);
        while (sum > m)
        {
            sum -= a[t] - a[q.front()];
            q.pop();
        }
        ans = max(ans, i - t + (int)q.size());
        for (int j = t; j < i; j++) q.push(j);
        i--;
    }
    printf("%d\n", ans);
    return 0;
}
