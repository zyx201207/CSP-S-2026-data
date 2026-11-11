#include <bits/stdc++.h>
using namespace std;

long long a[200003];
char c[200003];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    long long n;
    cin >> n;
    string s = "";
    bool same = true;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cin >> c[i];
    }
    char tmp = c[1];
    for(int i = 1; i <= n; i++)
    {
        if(tmp != c[i])
        {
            same = false;
            break;
        }
    }
    if(same)
    {
        cout << 0;
        return 0;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= a[i]; j++) s += c[i];
    }
    long long ans = 0;
    long long l = 0, r = s.size() - 1;
    while(l < r)
    {
        if(s[l] != s[r]) ans++;
        l++;
        r--;
    }
    cout << ans;



    return 0;
}
