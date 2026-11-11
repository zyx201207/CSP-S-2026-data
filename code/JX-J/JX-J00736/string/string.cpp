#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct t{
    int a;
    char b;
}s[200005];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ll ans = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i].a >> s[i].b;
    ll head = 1, tail = n;
    while (head <= tail)
    {
        int sum;
        bool tree = (s[head].b != s[tail].b);
        if (s[head].a < s[tail].a)
        {
            sum = s[head].a;
            s[tail].a -= s[head].a;
            head++;
        }
        else if (s[head].a > s[tail].a)
        {
            sum = s[tail].a;
            s[head].a -= s[tail].a;
            tail--;
        }
        else
        {
            sum = s[tail].a;
            tail--;
            head++;
        }
        if (tree) ans += sum;
    }
    cout << ans;
    return 0;
}
