#include <iostream>
using namespace std;
typedef long long LL;
const int SIZE = 2e6;
LL x[SIZE + 5];
int dp[SIZE + 5];
LL read();
int main()
{
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    int c; cin >> c;
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        LL d = read();
        for (int i = 1 ; i <= n ; ++i)
            x[i] = read();
        if (n <= 5000)
        {
            int cnt = 0;
            for (int l = 1 ; l < n ; ++l)
            {
                for (int r = l + 1 ; r <= n ; ++r)
                {
                    for (int i = l ; i <= r ; ++i)
                        dp[i] = 0;
                    bool f = false;
                    for (int i = l + 1 ; i <= r ; ++i)
                    {
                        int ql = l , qr = i - 1;
                        while (ql < qr)
                        {
                            int mid = ql + qr >> 1;
                            if (x[i] - x[mid] <= d)
                            {
                                f = true;
                                r = mid;
                            }
                            else l = mid + 1;
                        }
                        if (f == false) break;
                        dp[i] = dp[l] + 1;
                    }
                    if (f == false) break;
                    int t = 0;
                    for (int i = r - 1 ; i >= l ; --i)
                    {
                        if (dp[i] == dp[r] - 1 && x[r] - x[i] <= d)
                            ++t;
                        else break;
                    }
                    if (t == 2) ++cnt;
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
LL read()
{
    LL res = 0;
    char ch = getchar();
    while (! isdigit(ch))
        ch = getchar();
    while (isdigit(ch))
    {
        res = res * 10 + ch - '0';
        ch = getchar();
    }
    return res;
}
