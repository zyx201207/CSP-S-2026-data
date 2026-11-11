#include<bits/stdc++.h>
using namespace std;

bool hw(string s){
    for(int i=0;i<s.size();i++){
        int j = s.size() - i - 1;
        if(s[i] != s[j]) return false;
    }
    return true;
}

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    for(int i=1;i<=n;i++){
        int a;
        char ch;
        cin >> a >> ch;
        for(int j=1;j<=a;j++) s += ch;
    }
    if(hw(s)){
        cout << '0';
        return 0;
    }
    int ans = 0, i = 0;
    for(int i=0;i<s.size()/2;i++){
        int j = s.size() - i - 1;
        if(s[i] != s[j]) ans++;
    }
    cout << ans;
    return 0;
}
