#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    string s = "";
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        char c; cin >> c;
        for(int j = 1; j <= x; j++) s += c;
    }
    int ans = 0, t = 0;
    if(s.size() % 2 == 1) t = s.size() / 2 + 1;
    else t = s.size() / 2;
    for(int i = 0; i < t; i++){
        if(s[i] != s[s.size() - i - 1]) ans++;
    }
    cout << ans;
    return 0;
}
