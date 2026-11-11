#include <bits/stdc++.h>
using namespace std;
string s = "";
char c;
int n;
int a;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a >> c;
        for(int j = 1;j <= a;j++){
            s += c;
        }
    }
    int cnt = 0;
    for(long long i = 0;i < ceil(s.size() / 2 + 1);i++){
        if(s[i] != s[s.size() - i]) cnt++;
    }
    cout << cnt;
    return 0;
}

