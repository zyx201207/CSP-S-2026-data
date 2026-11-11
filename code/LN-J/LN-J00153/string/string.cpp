#include <bits/stdc++.h>
using namespace std;
string s;
char c;
long long q,n,ans;
long long r,l;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (long long i = 1;i<=n;i++)
    {
        cin >> q >> c;
        for (long long j = 1;j<=q;j++)
        {
            s = s+c;
        }
    }
    for (long long i = 0;i<s.size();i++)
    {
        r = i;
        l = s.size()-i-1;
        if (r>=l) break;
        if (s[r] !=s[l]) ans++;
    }
    cout << ans;
    return 0;
}
