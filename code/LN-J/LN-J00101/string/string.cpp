#include <bits/stdc++.h>
using namespace std;

int t,a,ans;
string s,k;
char b;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        for (int i = 1;i <= a;i++)
            s += b;
    }
    k = s;
    reverse(s.begin(),s.end());
    for (int i = 0;i < s.size() / 2;i++)
    {
        if (k[i] != s[i])
            ans++;
    }
    cout << ans;
}
