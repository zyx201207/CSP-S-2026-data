#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    string r1 = "A",r2 = "B",r3 = "C",r4 = "D",r5 = "F";
    char o1 = r1[0],o2 = r2[0],o3 = r3[0],o4 = r4[0],o5 = r5[0];
    cin >> c1 >> s1 >> c2 >> s2;
    char p1 = s1[2],p2 = s2[2];
    if(c1 == c2) {
        cout << "1";
        if(s1[0] == s2[0] && s1[1] == s2[1]) {
            cout << "1";
            if(p1 == o1 && p2 == o2 || p1 == o2 && p2 == o1 || p1 == o2 && p2 == o3 || p1 == o3 && p2 == o2 || p1 == o1 && p2 == o3 || p1 == o3 && p2 == o1 || p1 == o4 && p2 == o5 || p1 == o5 && p2 == o4) {
                cout << "1";
                if(p1 == o1 && p2 == o3 || p1 == o3 && p2 == o1) {
                    cout << "0";
                } else {
                    cout << "1";
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
