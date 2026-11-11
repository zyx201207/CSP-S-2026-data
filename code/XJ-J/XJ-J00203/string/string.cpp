#include<bits/stdc++.h>
using namespace std;
string s, a;
int n, ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    int x, j;
    for(int i = 1; i <= n; i++)
    {
        cin >> x >> a;
        for(int k = 1; k <= x; k++)
            s = s + a;
    }
    s = " " + s;
    for(int i = 1; i <= s.size() / 2; i++)
    {
        j = s.size() - i;
        if(s[i] != s[j])
            ans++;
    }
    cout << ans;
    return 0;
}