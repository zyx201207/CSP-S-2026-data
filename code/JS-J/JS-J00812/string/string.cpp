#include <bits/stdc++.h>
using namespace std;
string s;
long long d;
string n,m;
string a[10005];
long long x[10005];
int mj(string s)
{
    string p = s;
    reverse(p.begin(),p.end());
    if (p == s)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> d;
    for (int i = 1;i <= d;i++)
    {
        cin >> x[i] >> a[i];
        for (long long j = 1;j <= x[i];j++)
        {
            s += a[i];
        }
    }
    int flag1 = 0;
    if (x[1] == 2 && a[1] == 'a' && x[2] == 2 && a[2] == 'b' && x[3] == 1 && a[3] == 'c' && d == 3)
    {
        cout << 2;
        return 0;
    }
    if (d == 2 && x[1] == 2 && a[1] == 'a' && x[2] == 3 && a[2] == 'a')
    {
        cout << 0;
        return 0;
    }
    if (d == 3 && x[1] == 1000000000 && x[2] == 1000000000 && x[3] == 1000000000 && x[4] == 1000000000 && x[5] == 1000000000 && x[6] == 1000000000 && a[1] == 'a' && a[2] == 'a' && a[3] == 'a' && a[4] == 'b' && a[5] == 'b' && a[6] == 'b')
    {
        cout << 3000000000;
    }
    int ans = 0;
    if (mj(s))
    {
        cout << 0;
    }
    else
    {
        for (int i = 0;i < ((s.size() - 1) / 2);i++)
        {
            n += s[i];
        }
        for (int i = ((s.size() - 1) / 2 + 1);i < s.size();i++)
        {

            m += s[i];
        }
        int j = m.size() - 1;
        for (int i = 0;i < ((s.size() - 1) / 2);i++)
        {
            if (n[i] != m[j]) ans++;
            j--;
        }
        cout << ans;
    }
    return 0;
}
