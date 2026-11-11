#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","in",stdin);
    freopen("travel.out","out",stdout);
    int c1;
    int c2;
    string s1;
    string s2;
    cin >> c1;
    cin >> s1;
    cin >> c2;
    cin >> s2;
    if(c1 == c2){
        cout << 1;
    }
    else{
        cout << 0;
    }
    string l1;
    string l2;
    l1 = s1[0] + s1[1];
    l2 = s2[0] + s2[1];
    string m1;
    string m2;
    m1 = s1[2];
    m2 = s2[2];
    if(l1 == l2){
        cout << 1;
    }
    else{
        cout << 0;
    }
    if((m1 == "B" && m2 == "A") || (m1 == "A" && m2 == "B") || (m1 == "C" && m2 == "B") || (m1 == "B" && m2 == "C") || (m1 == "D" && m2 == "F") || (m1 == "F" && m2 == "D")){
        cout << 1;
    }
    else{
        cout << 0;
    }
    if(l1 == l2 && ((m1 == "B" && m2 == "A") || (m1 == "A" && m2 == "B") || (m1 == "C" && m2 == "B") || (m1 == "B" && m2 == "C") || (m1 == "D" && m2 == "F") || (m1 == "F" && m2 == "D"))){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}
