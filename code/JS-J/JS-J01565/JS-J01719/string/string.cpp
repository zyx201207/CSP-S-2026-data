#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int c[200005] , s[100000005];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    int n;
    char x; cin >> n;
    long long mx = -1 , sum = 0 , _i = 1 , cnt = 0;
    if (n == 1) cout << 0;
    for (int i = 1;i <= n;i++){
        cin >> a[i] >> x;
        c[i] = int(x) - 96;
        mx = max(mx , a[i]);
        sum += a[i];
    }
    if (sum <= 1e8){
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= a[i];j++) s[_i] = c[i] , _i++;
        }
        _i--;
        for (int i = 1;i <= (_i + 1) / 2;i++) cnt += (s[i] != s[_i - i + 1]);
        cout << cnt;
    }else cout << 0;
    return 0;
}
