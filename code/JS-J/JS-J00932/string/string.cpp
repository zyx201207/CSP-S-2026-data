#include <bits/stdc++.h>
using namespace std;
string a;
char c;
long long ans,len;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,x;
    cin >> n;
    for(long long i = 1;i <= n;i++)
    {
        cin >> x >> c;
        len += x;
        for(int i = 1;i <= x;i++)
            a = a + c;
    }
    string b = a;
    reverse(a.begin(),a.end());
    for(long long i = 0;i < len;i++)
        if(a[i] != b[i])
            ans++;
    cout << ans / 2;
}
