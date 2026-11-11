#include<bits/stdc++.h>
using namespace std;
int n, cnt;
string s;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n ; i++){
        int a1;
        cin >> a1;
        string s1;
        cin >> s1;
        for(int j = 0; j < a1; j ++){
            s += s1;
        }
    }
    for(int i = 0; i <= floor(s.size() * 1.0 / 2); i ++){
        if(s[i] != s[s.size() - i - 1]) cnt ++;
    }
    cout << cnt;
    return 0;
}
