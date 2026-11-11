#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s;
    for(int i = 1;i <= n;i++){
        int x;
        char ch;
        cin >> x >> ch;
        for(int j = 1;j <= x;j++){
            s += ch;
        }

    }
    bool flag = false;
    for(int i = 0;i < s.size() / 2;i++){
        if(s[i] == s[s.size() - i + 1]) continue;
        else flag = false;
    }
    if(flag) cout << 0;
    else{
        int ans = 0;
        for(int i = 0;i < s.size() / 2;i++){
            if(s[i] != s[s.size() - i + 1]) ans++;
        }
        cout << ans;
    }
}
