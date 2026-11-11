#include <bits/stdc++.h>
using namespace std;
int n;
char ch;
int a;
string s;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a >> ch;
        for(int j = 1 ; j <= a ; j++)
        {
            s += ch;
        }
    }
    int cnt = 0;
    int l = 0, r = s.size() - 1;
    while(l < r)
    {
        if(s[l] != s[r])
            cnt++;
        l++;
        r--;
    }
    cout << cnt;
}
