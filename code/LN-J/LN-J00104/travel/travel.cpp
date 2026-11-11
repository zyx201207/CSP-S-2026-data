#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1[3],s1[3],c2[3],s2[3];
    for (int i = 0;i < 2;i++){
        cin >> c1[i];
    }

    for (int i = 0;i < 3;i++){
        cin >> s1[i];
    }
    for (int i = 0;i < 2;i++){
        cin >> c2[i];
    }
    for (int i = 0;i < 3;i++){
        cin >> s2[i];
    }

    // chexiang?=
    if (c1[0] == c2[0] && c1[1] == c2[1]) {
        cout << "1";
    } else {
        cout << "0";
    }
    int flag1 = 0;
    if (s1[0] == s2[0] && s1[1] == s2[1] && s1[2] == s2[2]) {
            cout << "000";
            return 0;
    } else {
    // paishu?=
        if (s1[0] == s2[0] && s1[1] == s2[1]){
            cout << "1";
        } else {
            cout << "0";
            flag1 = 1;
        }
    }

    // juti zuowei? tongyice?
    if (flag1 == 1){
        cout << 0;
    } else {
        if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
            if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
                cout << "1";
            } else {
                cout << "0";
            }
        } else {
            if (s2[2] == 'D' || s2[2] == 'F'){
                cout << "1";
            } else {
                cout << "0";
            }
        }
    }


    // if zuoweixianglin?
    if (flag1 == 1){
        cout << 0;
    } else {
        if (s1[2] == 'A'){
        if (s2[2] == 'B'){
            cout << "1";
        } else {
            cout << "0";
        }
    } else if (s1[2] == 'B'){
        if (s2[2] == 'A' || s2[2] == 'C'){
            cout << "1";
        } else {
            cout << "0";
        }
    } else if (s1[2] == 'C') {
        if (s2[2] == 'B'){
            cout << "1";
        } else {
            cout << "0";
        }
    } else if (s1[2] == 'D') {
        if (s2[2] == 'F') {
            cout << "1";
        } else {
            cout << "0";
        }
    } else {
        if (s2[2] == 'F'){
            cout << "1";
        } else {
            cout << "0";
        }
    }
    }


    return 0;
}
