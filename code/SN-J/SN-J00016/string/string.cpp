#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s,f;
    int n,cnt = 0;;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int ai;
        cin >> ai;
        s += ai;
    }
    for(int i = n;i >= 1;i--)
    {
        f += s[i];
    }
    for(int i = 1;i <= n/2+1;i++)
    {
        if(s[i] != f[1])
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
