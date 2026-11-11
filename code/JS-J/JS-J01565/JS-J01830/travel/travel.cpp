#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int side(char c){
    if (c - 'A' < 3){
        return 1;
    }
    else{
        return 2;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool b1 = 0, b2 = 0, b3 = 0, b4 = 0;
    if (c1 == c2){
        b1 = 1;
        if (s1[0] == s2[0] && s1[1] == s2[1]){
            b2 = 1;
            if (side(s1[2]) == side(s2[2])){
                b3 = 1;
                if (abs(s1[2] - s2[2]) == 1){
                    b4 = 1;
                }
            }
        }
    }
    cout << b1 << b2 << b3 << b4;

    return 0;
}
