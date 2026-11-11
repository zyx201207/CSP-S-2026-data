#include <bits/stdc++.h>
using namespace std;
int n, a[200005], ln, ans;
char c[200005];
string s, r;
string rev(string s){
    string t;
    for (int i = 0; i < ln; i++){
        if (i < ceil(1.0*ln/2)){
            t += s[i];
        }else{
            t += s[ln-i-1];
        }
    }
    return t;
}
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= a[i]; j++){
            s += c[i];
        }
    }
    ln = s.size();
    r = rev(s);
    for (int i = n/2+1; i < ln; i++){
        if (s[i] != r[i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
