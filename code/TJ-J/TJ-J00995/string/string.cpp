#include <bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin >> n;
    for (long long i=1;i<=n;i++)
    {
        int q;
        cin >> q;
        string s;
        cin >> s;
        while(q--)
        {
            a+=s;
        }
    }
    for (int i=a.size()-1;i>=0;i--)
    {
        b+=a[i];
    }
    int ans=0;
    for (int i=0;i<a.size();i++)
    {
        if (a[i]!=b[i])     ans++;
    }
    cout << ans;
    return 0;
}
