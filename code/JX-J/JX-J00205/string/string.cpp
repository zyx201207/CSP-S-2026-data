#include<bits/stdc++.h>
using namespace std;
long long n , tot = 0 ;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1 ;i <= n ; i++)
    {
        long long x;char c;
        cin >> x >> c;
        for(int j = 1; j <= x ; j++)
        {
            s += c;
        }
    }
    long long l = s.length();
    for(int i = 0 ; i < l / 2; i++)
    {
        if(s[i] != s[l - i - 1]) tot++;
    }
    cout << tot ;
    return 0;
}
