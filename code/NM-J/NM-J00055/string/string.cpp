#include <bits/stdc++.h>
using namespace std;
int n,ans;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w".stdout);
    string s = "";
    cin >> n;
    for (int i =1;i<=n;i ++)  {
        int a;
        string c;
        cin >> a >>c;
        for (int i =1;i<=a;i++) {
            s += c;
        }
    }
    for (int i = 0;i<s.size()/2;i++) {
        if (s[s.size()-s[i]] == s[i]) {
            ans++;
        }
        s[s.size()-s[i]] = s[i];
        
    }
    
    cout << ans;
    return 0;
}