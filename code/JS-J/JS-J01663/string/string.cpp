#include <bits/stdc++.h>
using namespace std;

int main() {


    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; i++) {
        int x; char c;
        cin >> x >> c;
        for (int i = 0; i < x; i++) {
            s += c;
        }
    }
    int ans = 0;
    for (int i = 0; i <= (n+1)/2; i++) {
        if (s[i] != s[n+1-i]){
            ans++;
        }
    }
    cout << ans;

    return 0;
}
