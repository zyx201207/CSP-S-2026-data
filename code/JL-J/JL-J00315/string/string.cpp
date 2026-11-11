#include <bits/stdc++.h>
using namespace std;
string s;
long long n,cnt,sum;
long long a[200005];
char c1,c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i] >> c1;
        for (int j = sum;j <= sum + a[i];j++)
        {
            c[j] = c1;
            s += c[j];
        }
        sum += a[i];
        for (int j = sum;j <= sum + a[i];j++)
        {
            c[j] = 0;
        }
    }
    for (int i = 0;i < n;i++)
    {
        if (s[i] != s[n + 1 - i])
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
