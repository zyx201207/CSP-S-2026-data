#include<bits/stdc++.h>
using namespace std;

bool check(char x, char y) {
    return x =='A' && y == 'B' || x =='B' && y == 'A' || x =='B' && y == 'C' || x =='C' && y == 'B' || x =='D' && y == 'F' || x =='F' && y == 'D';
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    int a, b;
    string x, y;
    cin >> a >> x >> b >> y;
    bool f = 1;
    if (a == b){
        cout << 1;
    } else {
        f = 0;
        cout << 0;
    }

    if(x[0] == y[0] && x[1] == y[1] && f) cout << 1;
    else {
        f = 0;
        cout << 0;
    }

    if(f && ('A' <= x[2] && x[2] <= 'C' && 'A' <= y[2] && y[2] <= 'C' || 'D' == y[2] && x[2] == 'F' || 'D' == x[2] && y[2] == 'F') ) {
        cout << 1;
    }else {
        f = 0;
        cout << 0;
    }

    if(f && check(x[2],y[2])){
        cout << 1;
    }else cout << 0;

    return 0;
}
