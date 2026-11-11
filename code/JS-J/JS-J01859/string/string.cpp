#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
char c[2000005];
long long ans;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s = "";
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        for(int j = 1; j <= a[i]; j++)
            s += c[i];
    }
    for(int i = 0; i < s.size() / 2; i++)
        if(s[i] != s[s.size() - 1 - i])
            ans++;
    cout << ans;
    return 0;
}
