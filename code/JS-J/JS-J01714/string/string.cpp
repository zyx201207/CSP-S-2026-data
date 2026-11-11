#include <bits/stdc++.h>

using namespace std;

char c[200005];
int a[200005];

int read()
{
    int x = 0, f = 1, ch = getchar();
    while(!isdigit(ch))
    {
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(isdigit(ch))
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x * f;
}

void solve(int n)
{
    string s;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= a[i]; j++)
            s += c[i];

    int cnt = 0;
    for(int i = 0; i < s.size() / 2; i++)
        if(s[i] != s[s.size() - i - 1])
            cnt++;

    cout << cnt;
}

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n = read();
    for(int i = 1; i <= n; i++)
        a[i] = read(), cin >> c[i];

    solve(n);

    return 0;
}