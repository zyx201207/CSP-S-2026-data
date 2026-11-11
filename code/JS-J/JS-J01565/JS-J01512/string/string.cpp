#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n; cin >> n;
    string str = "";
    for(int i = 1; i <= n; i++) {
        int a; char c;
        cin >> a >> c;
        for(int j = 1; j <= a; j++) {
            str += c;
        } 
    }
    int cnt = 0;
    for(int i = 0;  i < str.size() / 2; i++) {
        if(str[i] != str[str.size() - 1 - i]) cnt++;
    }
    cout << cnt;
    return 0;
}