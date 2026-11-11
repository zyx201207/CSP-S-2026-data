#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n;
    cin >> n;
    long long ans = 0;
    string str = "";
    for (long long i = 1; i <= n; i++)
    {
        long long a;
        char b;
        cin >> a >> b;
        for (long long j = 1; j <= a; j++)
        {
            str += b;
            ans++;
        }
    }
    long long k = 0;
    if (ans % 2 == 0)
    {
        long long a = ans / 2;
        for (long long i = 1; i <= a; i++)
        {
            if (str[a-i] != str[a-1+i])
            {
                str[a-1+i] = str[a-i];
                k++;
            }
        }
    }
    else
    {
        long long mid = (ans + 1) / 2;
        for (long long i = 1; i <= mid - 1; i++)
        {
            if (str[mid - 1 + i] != str[mid - 1 - i])
            {
                str[mid - 1 + i] = str[mid - 1 - i];
                k++;
            }
        }
    }
    cout << k;
    return 0;
}
