#include<bits/stdc++.h>
using namespace std;
int main () {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    bool cx, pai, ceDF, ceABC, xl;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1==c2) {
        cx=true;
    } else {
        cx=false;
    }
    if (s1[0] == s2[0] && s1[1] == s2[1]) {
        pai=true;
    } else {
        pai=false;
    }
    if (s1[2] == 'D' && s2[2] == 'F') {
        ceDF=true;
    } else if (s1[2] == 'F' && s2[2] == 'D'){
        ceDF=true;
    }
    if (s1[2] == 'D' && s2[2] == 'F') {
        ceDF=true;
    } else if (s1[2] == 'F' && s2[2] == 'D'){
        ceDF=true;
    }
    if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') {
        if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') {
            ceABC=true;
        } else {
            ceABC=false;
        }
    }
    if (s1[2] == 'A' && s2[2] == 'C'){
        xl=false;
    } else if (s1[2] == 'C' && s2[2] == 'A'){
        xl=false;
    } else {
        xl=true;
    }
    if (cx == true) {
        cout << "1";
        if (pai==true) {
            cout << "1";
            if (ceDF || ceABC == true) {
                cout << "1";
                if (xl == true) {
                    cout << "1";
                } else {
                    cout << "0";
                }
            } else {
                cout << "00";
            }
        } else {
            cout << "000";
        }
    } else {
        cout << "0000";
    }
    return 0;
}
