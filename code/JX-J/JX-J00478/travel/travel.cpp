#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int p1, p2;
    p1 = (s1[0]-'0')*10 + (s1[1] - '0');
    p2 = (s2[0]-'0')*10 + (s2[1] - '0');
    if(c1 == s1){
        cout << 1111;
    }
    else{
        cout << 0000;
    }
    fclose("travel.in");
    fclose("travel.out");
    return 0;
}
