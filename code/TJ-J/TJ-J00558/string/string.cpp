#include <iostream>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s = "";
    while (n--)
    {
        int x;
        string c;
        cin >> x >> c;
        for (int i = 1; i <= x; i++)
        {
            s += c;
        }
    }
    long long t = s.size();
    string s1 = "",s2 = "";
    for (int i = 0; i < t/2; i++)
    {
        s1 += s[i];
    }
    if (t % 2 == 0)
    {
        for (int i = t-1; i >= t/2; i--)
        {
            s2 += s[i];
        }
    }
    else
    {
        for (int i = t-1; i >= t/2+1; i--)
        {
            s2 += s[i];
        }
    }
    long long ans = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i]) ans++;
    }
    cout << ans;
    return 0;
}
