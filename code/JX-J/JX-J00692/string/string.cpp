#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
string s;
int n;
long long a[N];
long long l;
char c[N];
long long ans;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    s = " ";
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> a[i] >> c[i];
        for(int j = 1;j <= a[i];j ++){
            s += c[i];
        }
    }
    l = s.size();
    for(int i = 1;i <= (l + 1) / 2;i++){
        if(s[i] == s[l - i + 1]) continue;
        ans ++;
        s[i] = s[l - i + 1];
    }
    cout << ans << '\n';
    return 0;
}
//?