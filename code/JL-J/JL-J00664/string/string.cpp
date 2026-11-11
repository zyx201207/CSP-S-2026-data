#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++)
    {
        int a;
        char c;
        cin >> a >>c;
        for (int i = 1; i <= a; i++)
            s.push_back(c);
    }
    int l = s.size();
    long long sum = 0;
    bool f = 1;
    for (int i = 0; i < l / 2; i++)
    {

        if (s[i] != s[l-i-1])
            f = 0, sum++;
    }
    if (f)  cout << 0;
    else
    {
        cout << sum;
    }
    return 0;
}
