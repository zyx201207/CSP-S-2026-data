#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
long long n, ans = 0;
struct node
{
    int a;
    char c;
}num[N];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i].a >> num[i].c;
    }
    int l = 1, r = n;
    while (l < r)
    {
        if (num[l].c == num[r].c)
        {
            if (num[l].a > num[r].a)
            {
                num[l].a -= num[r].a;
                r--;
            }
            else if (num[l].a < num[r].a)
            {
                num[r].a -= num[l].a;
                l++;
            }
            else
            {
                l++;
                r--;
            }
        }
        else
        {
            if (num[l].a > num[r].a)
            {
                num[l].a -= num[r].a;
                ans += num[r].a;
                r--;
            }
            else if (num[l].a < num[r].a)
            {
                num[r].a -= num[l].a;
                ans += num[l].a;
                l++;
            }
            else
            {
                ans += num[l].a;
                l++;
                r--;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
