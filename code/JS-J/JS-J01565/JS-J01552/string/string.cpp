#include <bits/stdc++.h>
using namespace std;

bool ishw(string s){
    string t = "";
    for(int i = s.size()-1;i >= 0;i--){
        t += s[i];
    }
    return t == s;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s = "";
    for(int i = 1;i <= n;i++){
        int a;
        char c;
        cin >> a >> c;
        for(int j = 1;j <= a;j++){
            s += c;
        }
    }
    int cnt = 0;
    if(ishw(s)){
        cout << 0;
    }
    else{
        int len = s.size();
        if(len % 2 == 0){
            for(int i = 0;i < len/2;i++){
                if(s[i] != s[len - 1 - i]){
                    cnt++;
                }
            }
        }
        else{
            for(int i = 0;i <= len/2;i++){
                if(s[i] != s[len - 1 - i]){
                    cnt++;
                }
            }
        }
        cout << cnt;
    }
    return 0;
}
