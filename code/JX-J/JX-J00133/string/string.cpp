#include<bits/stdc++.h>
using namespace std;
bool ishui(string s){
    string a = s,b;
    for(int i = s.size() - 1;i >= 0;i--){
        b += s[i];
    }
    if(a == b) return 1;
    else return 0;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt = 0;
    string s;
    cin >> n;
    for(int i = 1;i <= n;i++){
        long long x;
        string a;
        cin >> x >> a;
        for(int j = 1;j <= x;j++){
            s += a;
        }
    }
    if(ishui(s)) cout << cnt;
    else{
        char b = s[0];
        for(int i = 0;i <= s.size() - 1;i++){
            if(s[i] != b) cnt++;
        }
        cout << cnt;
    }
    return 0;
}
