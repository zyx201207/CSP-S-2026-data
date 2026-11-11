#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int SIZE = 5e5;
LL a[SIZE + 5];
LL diff[SIZE + 5];
LL rcd[SIZE + 5];
LL read();
bool cmp(LL x , LL y);
int main()
{
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    int n; cin >> n;
    LL m = read();
    for (int i = 1 ; i <= n ; ++i)
        a[i] = read();
    sort(a + 1 , a + 1 + n , cmp);
    if (n > 5000)
    {
        LL d = a[1] - a[2];
        LL sum = 0;
        for (int i = 2 ; i <= n ; ++i)
        {
            sum = sum + (i - 1) * d;
            if (sum > m)
            {
                cout << i - 1 << endl;
                return 0;
            }
        }
        cout << n << endl;
        return 0;
    }
    for (int i = 2 ; i <= n ; ++i)
        diff[i] = a[i - 1] - a[i];
    int ans = 1;
    for (int i = n - 1 ; i >= 1 ; --i)
    {
        int l = i;
        for (int j = i + 1 ; j <= n ; ++j)
            rcd[j] = rcd[j] + diff[i + 1] * LL(j - i);
        for ( ; l <= n ; ++l)
            if (rcd[l] > m)
                break;
        ans = max(ans , l - i);
    }
    cout << ans << endl;
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
bool cmp(LL x , LL y){return x > y;}
