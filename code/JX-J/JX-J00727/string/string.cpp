#include <bits/stdc++.h>
using namespace std;

int a[200010];

int main(){

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;  cin >> n;

    long long cnt = 0;
    string s;

    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        char c;  cin >> c;

        for(int j = 1; j <= a[i]; j ++)
        {
            cnt ++;
            s += c;
        }
    }

    long long t = cnt / 2;
    long long ans = 0;

    for(long long i = 1; i <= t; i ++)
    {
        if(s[cnt - i] != s[i - 1])  ans ++;
    }

    cout << ans;

    return 0;
}
