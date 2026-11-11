#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, len, jsq = 0, zh = 0;
    string s = "";
    cin >> n;
    while(n--)
    {
        int a;
        char c;
        cin >> a >> c;
        for (int i = 1; i <= a; i++)
        {
            s += c;
        }
    }
    len = s.size();
    for (int i = 0; i <= (len - 1) / 2; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            jsq++;
        }
    }
    cout << jsq;
    return 0;
}
