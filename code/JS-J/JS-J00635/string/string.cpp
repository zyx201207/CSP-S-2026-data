#include <bits/stdc++.h>

using namespace std;
char a[2000000010];
int t = 0, ans = 0, n, len = 0;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        int x;
        char y;
        cin >> x >> y;
        for(int j = t; j < t + x; j ++){
            a[j] = y;
        }
        t += x;
        len += x;
    }
    int mid = len / 2;
    for(int i = 0; i <= mid; i ++){
        if(a[i] != a[len - i - 1]) ans ++;
    }
    cout << ans << endl;
    return 0;
}
