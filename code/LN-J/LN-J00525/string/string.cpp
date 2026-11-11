#include<bits/stdc++.h>
using namespace std;
long long n,op,cnt,l,r;
string s = "",fs,po;
map <int,char> m;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> op >> po;
        for(int i = 1;i <= op;i++)
            s += po;
    }
    r = s.length() - 1;
    while(l < r)
    {
        if(s[l] != s[r])
            cnt++;
        l++;
        r--;
    }
    cout << cnt;
    return 0;
}
