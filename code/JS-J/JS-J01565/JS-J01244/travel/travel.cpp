#include <bits/stdc++.h>

using namespace std;

int rc, xc;
string rs, xs;

void init(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> rc >> rs >> xc >> xs;
    return;
}

void solve(){
    bool a = 0, b = 0, c = 0, d = 0;
    if(rc == xc){
        a = 1;
        if((rs[0] == xs[0]) && (rs[1] == xs[1])){
            b = 1;
            char q = rs[2], w = xs[2];
            bool z = 0, x = 0;
            if(q == 'D' || q == 'F')
                z = 0;
            else
                z = 1;
            if(w == 'D' || w == 'F')
                x = 0;
            else
                x = 1;
            if(x == z){
                c = 1;
                if(q - w == 1 || q - w == -1)
                    d = 1;
            }
        }
    }
    cout << a << b << c << d;
    return;
}

int main(){
    init();
    solve();
    return 0;
}
