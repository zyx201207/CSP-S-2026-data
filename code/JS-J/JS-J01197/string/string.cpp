#include <bits/stdc++.h>
using namespace std;

int n, cnt;
string s;

string add(int num, string b)
{
    if (num == 1) return b;
    string temp = add(num / 2, b);
    if (num % 2 == 0)
        return temp + temp;
    return temp + temp + b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num;
        string b;
        cin >> num >> b;
        s += add(num, b);
    }
    int l = 0, r = s.size() - 1;
    while (l <= r)
    {
        if (s[l] != s[r]) cnt += 1;
        l += 1;
        r -= 1;
    }
    cout << cnt << "\n";
    return 0;
}
