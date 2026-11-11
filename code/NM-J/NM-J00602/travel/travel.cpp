#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << 1;
    }else{
        cout << "0000" << '\n';
        return 0;
    }
    string a = s1.substr(0, 2);
    string b = s2.substr(0, 2);
    if(a == b){
        cout << 1;
    }else{
        cout << "000" << '\n';
        return 0;
    }
    char c = s1[s1.size() - 1], d = s2[s2.size() - 1];
    if(((c == 'D' || c == 'F') && (d == 'D' || d == 'F')) || ((c == 'A' || c == 'B' || c == 'C') && (d == 'A' || d == 'B' || d == 'C'))){
        cout << 1;
    }else{
        cout << "00" << '\n';
        return 0;
    }
    if((c == 'A' && d == 'B') || (c == 'B' && d == 'A') ||
       (c == 'B' && d == 'C') || (c == 'C' && d == 'B') ||
       (c == 'D' && d == 'F') || (c == 'F' && d == 'D')){
            cout << 1 << '\n';
    }else{
        cout << 0 << '\n';
    }
    return 0;
}
