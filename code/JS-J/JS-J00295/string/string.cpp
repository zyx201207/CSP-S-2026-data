#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    string s = "";
    for(int i = 1; i <= n; i++)
    {
        long long t;
        char a;
        cin >> t >> a;
        for(long long j = 1; j <= t; j++)
            s += a;
    }
    long long ans = 0;
    for(long long i = 0; i < s.size() / 2; i++)
    {
        if(s[i] != s[s.size() - i - 1]) ans++;
    }
    cout << ans << endl;
    return 0;
}
