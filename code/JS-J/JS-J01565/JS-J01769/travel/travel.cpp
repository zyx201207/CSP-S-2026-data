#include <bits/stdc++.h>
using namespace std;



int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string a, b, c, d;
    cin >> a >> b >> c >> d;

    if(a != c) return cout << "0000", 0;

    cout << 1;

    if(b[0] != d[0] || b[1] != d[1]) return cout << "000", 0;

    cout << 1;

    if(b[2] == 'A' || b[2] == 'B' || b[2] == 'C'){
        if(!(d[2] == 'A' || d[2] == 'B' || d[2] == 'C')) return cout << "00", 0;
    }else if(d[2] == 'A' || d[2] == 'B' || d[2] == 'C')  return cout << "00", 0;

    cout << 1;

    if(abs(int(b[2] - d[2])) == 1) cout << 1;
    else cout << 0;

    return 0;
}

