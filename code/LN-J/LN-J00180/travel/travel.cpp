#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    int x = 0, y = 0;
    for(int i = 0; i < b.size(); i++){
        if(b[i] >= 'A' && b[i] <= 'Z'){
            break;
        }
        x = x * 10 + b[i] - '0';
    }
    for(int i = 0; i < d.size(); i++){
        if(d[i] >= 'A' && d[i] <= 'Z'){
            break;
        }
        y = y * 10 + d[i] - '0';
    }
    if(a == c) cout << 1;
    else cout << 0;

    if(a == c && x == y)cout << 1;
    else cout << 0;

    char s = b[2], t = d[2];
    if(a == c && x == y && !( (s == 'A' && t == 'F') || (s == 'A' && t == 'F') ) && !( (s == 'C' && t == 'D') || (s == 'D' && t == 'C') )  )cout << 1;
    else cout << 0;

    if(a == c && x == y && !( (s == 'A' && t == 'F') || (s == 'A' && t == 'F') ) && !( (s == 'C' && t == 'D') || (s == 'D' && t == 'C') )  && abs(s - t) == 1)cout << 1;
    else cout << 0;
    return 0;
}
