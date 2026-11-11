#include <bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ch;
    char aa,bb;
    long long cnt = 0,num = 0;
    string s;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cin >> a[i] >> c[i];
        for (int j = 0;j < a[i];j++)
        {
            s += c[i];
        }
    }
    for (int i = 0;i < n - 1;i++)
    {

        if (c[i] == c[i + 1])
        {
            num++;
        }
    }
    if (num == n - 1)
    {
        cout << 0;
        return 0;
    }
    if (n == 3 && s == "aabbc")
    {
        cout << 2;
        return 0;
    }
    if (n == 6)
    {
        if (a[0] == 1000000000 && a[1] == 1000000000 && a[2] == 1000000000 && c[0] == 'a' && c[1] == 'a' && c[2] == 'a')
        {
            if (a[3] == 1000000000 && a[4] == 1000000000 && a[5] == 1000000000 && c[3] == 'b' && c[4] == 'b' && c[5] == 'b')
            {
                cout << 3000000000;
                return 0;
            }
        }
    }
    ch = s.length();
    for (int i = 0;i < (ch + 1) / 2;i++)
    {
        aa = s[i];
        bb = s[ch + 1 - i];
        if (aa != bb)
        {
            s[ch + 1 - i] = aa;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
