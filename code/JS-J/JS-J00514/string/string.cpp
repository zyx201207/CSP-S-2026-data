#include <bits/stdc++.h>
using namespace std;
int n = 0,cnt = 0;
int a;
long long l;
char c;
string s = {'0'};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a >> c;
        l += a;
        for(int j = 1;j <= a;j++)
        {
            s += c;
        }
    }
    for(int i = 1;i <= l;i++)
    {
        for(int j = l;j >= 1;j--)
        {
            if(s[i] != s[j])
            {
                s[j] = s[i];
                cnt++;
            }
        }
    }
    if(l % 2 == 0)
    {
        cout << cnt;
    }
    else
    {
        cout << cnt-1;
    }
    return 0;
}
