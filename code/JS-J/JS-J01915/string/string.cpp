#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;
long long s[N], d[N];
char m[N];
long long sum, ans;
int main()
{
    freopen ("string.in", "r", stdin);
    freopen ("string.out", "w", stdout);
    int n;
    cin >> n;
    string str = "";
    for (int i = 1;i <= n;i++)
    {
        cin >> s[i] >> m[i];
        int x = s[i];
        char tmp = m[i];
        sum += x;
        for (int i = 1;i <= x;i++)
        {
            str += tmp;
        }
    }
    int mid = sum / 2;
    for (int i = mid;i <= sum;i++)
    {
        if (str[i] != str[sum - i - 1])
        {
            ++ans;
        }
    }
    cout << ans;
    return 0;
}
