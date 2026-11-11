#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, gcd, ans;
int a[N];
string s;
char c[N];
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> a[1] >> c[1];
    for(int i = 2;i <= n; i++){
        cin >> a[i] >> c[i];
        gcd = __gcd(a[i], gcd);
    }
    for(int i = 1;i <= n; i++)
        a[i] /= gcd;
    for(int i = 1;i <= n; i++){
        for(int j = 1;j <= a[i]; j++)
            s += c[i];
    }
    int i, j;
    if(s.size()%2 == 0)
        i = s.size() / 2, j = s.size() / 2 + 1;
    else
        i =  j = s.size() / 2;
    while(i >= 0 && j < s.size()){
        if(s[i] != s[j])
            ans ++;
        i--;
        j++;
    }
    cout << ans * gcd;
    return 0;
}
