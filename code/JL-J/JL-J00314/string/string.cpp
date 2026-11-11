#include<bits/stdc++.h>
using namespace std;
int n , z = 0 , ans = 0;
long long a[200001];
char b[200001];
string s , sx;
int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    cin >> n;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i] >> b[i];
        z += a[i];
    }
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= a[i];j ++)
        {
            s = s + (char)(b[i]);
        }
    }
    for(int i = z - 1;i >= 0; i --)
    {
        sx = sx + s[i];
    }
    if(sx == s)
    {
        cout << "0";
        return 0;
    }
    if(z % 2 == 1)
    {
        z = z - 1;
    }
    for(int i = 0;i <= z / 2 - 1;i ++)
    {
        if(s[i] != sx[i])
        {
            ans ++;
        }
    }
    cout << ans;
    return 0;
}
