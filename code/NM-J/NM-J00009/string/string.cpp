#include <bits/stdc++.h>
using namespace std;
long long n, a;
long long mn = 1e9;
char c;
string s, s1="000000000000000000";
int check(string x){
    bool flag = true;
    for(int i = 0;i<s.length();i++){
        if(s[i]!=s[s.length()-i-1]) flag = false;
    }
    return flag;
}
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a >> c;
        for(int j = 1;j <= a;j++){
            s+=c;
        }
    }
    if(check(s)){
        cout << 0;
        return 0;
    }
    for(int i = 0;i < s.length();i++){
        s1[i] = s[s.length()-i-1];
    }
    while(!check(s)){
        long long cnt = 0;
        for(int i = 0;i < s.length();i++){
            if(s1[i]!=s[i]){
                s1[i] = s[i];
                s[s.length()-1-i] = s1[i];
                cnt++;
            }
        }
        mn = min(mn, cnt);
    }
    cout << mn;
    return 0;
}
