#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    int n;
    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        long long a;
        char c;
        cin >> a >> c;
        for(int j = 1; j <= a; j++) s += c;
    }
    int cnt = 0;
    for(int i = 0; i < ceil(n / 2.0); i++){
        if(s[i] == s[s.size() - 1 - i]) continue;
        s[s.size() - 1 - i] = s[i];
        cnt++;
    }
    cout << cnt;
    return 0;
}
