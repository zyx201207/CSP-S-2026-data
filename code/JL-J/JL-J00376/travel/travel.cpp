#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    int c = 0,a = 0,b = 0;
    string str,s;
    cin >> n >> str >> m >> s;
    if(n == m) {
        cout << 1;
        b++;
    }
    else cout << 0;
    if(b == 0) cout << 0;
    else if((s[0] == str[0]) && (s[1] == str[1])) {
        cout << 1;
        a++;
    }else cout << 0;
    if(a == 0) cout << 0;
    else if(str[2] <= 'C' && s[2] <= 'C') {
        cout << 1;
        c++;
    }else if(str[2] > 'C' && s[2] > 'C') {
        cout << 1;
        c++;
    }else cout << 0;
    if(c == 0) cout << 0;
    else if((((str[2] + 1) == s[2] ) || ((str[2] - 1) == s[2])) || ((str[2] == 'F') && (s[2] == 'D'))  || ((str[2] == 'D') && (s[2] == 'F'))) cout << 1;
    else cout << 0;
    return 0;
}
