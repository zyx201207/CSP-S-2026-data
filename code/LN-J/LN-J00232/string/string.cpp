#include<bits/stdc++.h>
using namespace std;
int n;
long long suml = 0 , cnt = 0;
int a[200010];
string c[200010] , s;
int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i] >> c[i];
        suml += a[i];
        for(int j = 1 ; j <= a[i] ; j++)
        {
            s += c[i];
        }
    }
    for(int i = 1 ; i <= suml / 2 ; i++)
    {
        if(s[i - 1] != s[suml - i])
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
