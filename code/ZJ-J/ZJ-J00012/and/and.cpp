#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+10;
const int all1 = 2147483647;
int n, m, a[MAXN], dp[2][MAXN];

int read(){
    int sum = 0, sign = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch == '-'){
            sign = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9'){
        sum = (sum << 1)+(sum << 3)+(ch ^ 48);
        ch = getchar();
    }
    return sum*sign;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    n = read();
    m = read();
    for (int i = 1; i <= n; i++){
        a[i] = read();
    }
    dp[0][0] = all1;
    dp[1][0] = all1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= min(i, m); j++){
            dp[i%2][j] = max(dp[(i-1)%2][j], dp[(i-1)%2][j-1]&a[i]);
        }
    }
    cout << dp[n%2][m];
}