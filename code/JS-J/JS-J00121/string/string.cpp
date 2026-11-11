#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    long long n , ans = 0 , x , cnt =0;
    string s , s1 , s2;
    char c;
    cin >> n;
    for (int i = 0 ; i < n; i++)
    {
        cin >> x >> c;
        int h = x;
        while(h--)
        {
            s += c;
        }
        ans += x;
    }
    ans = ceil(ans / 2 * 1.0);
    for (int i = 0 ; i < ans; i++)
    {
        s1 += s[i];
    }
    for (int i = s.size() - 1 ; i >= ans ; i--)
    {
        s2 += s[i];
    }
    for (int i = 0 ; i < s1.size() ; i++)
    {
        if(s1[i] != s2[i]) cnt++;
    }
    cout << cnt;
    return 0;
}