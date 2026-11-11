#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

//int a[200005];
//char c[200005];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; ++i)
    {
        //cin >> a[i] >> c[i];
        int x;
        char st;
        cin >> x >> st;
        while (x--)
        {
            s += st;
        }
    }
    long long ans = 0;
    for (int i = 0; i < s.size() / 2; ++i)
    {
        if (s[i] != s[s.size() - i - 1])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
