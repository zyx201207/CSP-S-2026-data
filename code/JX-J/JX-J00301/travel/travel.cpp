#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) cout << 1;
    else{
        cout << "0000";
        return 0;
    }
    //X28369788
    string a1 = "", a2 = "";
    a1 += s1[0];
    a1 += s1[1];
    a2 += s2[0];
    a2 += s2[1];
    int f = 0;
    if(a1 == a2) {
        cout << 1;
        f = 1;
    }
    else cout << 0;
    if(f == 0) {
        cout << "00";
        return 0;
    }
    bool f1 = 0, f2 = 0;
    if(s1[2] >= 'A' && s1[2] <= 'C') f1 = 1;
    if(s2[2] >= 'A' && s2[2] <= 'C') f2 = 1;
    //cout << "f1=" << f1 << " " << "f2=" << f2 << endl;
    if(f1 == f2) cout << 1;
    else cout << 0;
    if(f1 == f2 && f1 == 1){
        if(abs(s1[2] - s2[2]) == 1){
            cout << 1;
        }
        else{
            cout << 0;
        }

    }
    else if(f1 == f2 && f1 == 0){
        cout << 1;
    }
    else cout << 0;
	return 0;
}
