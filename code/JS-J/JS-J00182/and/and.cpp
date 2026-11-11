#include <bits/stdc++.h>
using namespace std;
int n , m;
long long a[200001] , dp[200001] = {1};
void f1(){
    long long Max = 0;
    for (int i = 1 ; i <= n ; i++)
        Max = max(Max , a[i]);
    cout << Max;return;
}
void f2(){
    long long Max = 0;
    for (int i = 1 ; i <= n ; i++)
        for (int j = i + 1 ; j <= n ; j++)
            Max = max(Max , (a[i] & a[j]));
    cout << Max;return;
}
void f3(){
    long long num = a[1];
    for (int i = 2 ; i <= n ; i++)
        num = (num & a[i]);
    cout << num;return;
}
void f4(){
    return;
}
void f5(){
    for (int i = 1 ; i <= 63 ; i++) dp[0] *= 2;
    dp[0] -= 1;
    for (int i = 1 ; i <= n ; i++)
        for (int j = m ; j >= 1 ; j--)
            dp[j] = max(dp[j] , (dp[j - 1] & a[i]));
    cout << dp[m];return;
}
void f6(){
    return;
}
void f7(){
    int x = 0 , y = 0 , z = 0;
    for (int i = 1 ; i <= n ; i++){
        if (a[i] == 1) x++;
        else if (a[i] == 2) y++;
        else if (a[i] == 3) z++;
    }
    if (z >= m) cout << 3;
    else if (z + y >= m) cout << 2;
    else cout << 1;
    return;
}
int main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    cout.tie(0) , cin.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
        cin >> a[i];
    if (m == 1){f1();return 0;}
    if (m == 2){f2();return 0;}
    if (m == n){f3();return 0;}
    if (n <= 2000){f5();return 0;}
    if (a[1] < 4 && a[2] < 4 && a[3] < 4 && a[4] < 4 && a[5] < 4 && a[6] < 4 && a[7] < 4 && a[8] < 4 && a[9] < 4){f7();return 0;}
    return 0;
}
