#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin >> n;
    int a[10005];
    string s;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i] >> s[i];
    }
    int minn=1024;
    for(int i = 0;i < n;i++)
    {
        if(a[i] < minn)
        {
            minn = a[i];
        }
        if(s[i] == s[i+1])
        {
            minn = 0;
            break;
        }
    }
    if(n == 1) cout << "0";
    else cout << minn;
    return 0;
}
