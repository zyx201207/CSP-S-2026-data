#include<bits/stdc++.h>
using namespace std;
string s = "0";
long long n, m, ans = 0;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        long long x;
        string s1;
        cin >> x >> s1;
        m += x;
        for(int j = 1; j <= x; j++) s += s1;
    }
    for(int i = 1; i < m/2+1; i++){
        if(s[i] != s[m+1-i]) ans++;
     }
     cout << ans;

    return 0;
}
