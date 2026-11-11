#include<bits/stdc++.h>
using namespace std;
map<char, int> mp;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    mp['A'] = 1;
    mp['B'] = 1;
    mp['C'] = 1;
    mp['D'] = 2;
    mp['F'] = 2;
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool b1, b2, b3, b4;
    b1 = b2 = b3 = b4 = false;
    if( c1 == c2 ) b1 = true;
    if( b1 ){
        if( s1[0] == s2[0] && s1[1] == s2[1] ) b2 = true;
        if( b2 ){
            if( mp[s1[2]] == mp[s2[2]] ) b3 = true;
            if( b3 ){
                char c1 = s1[2], c2 = s2[2];
                if( c1 == 'A' && c2 == 'B' ) b4 = true;
                if( c1 == 'B' && c2 == 'A' ) b4 = true;
                if( c1 == 'B' && c2 == 'C' ) b4 = true;
                if( c1 == 'C' && c2 == 'B' ) b4 = true;
                if( c1 == 'D' && c2 == 'F' ) b4 = true;
                if( c1 == 'F' && c2 == 'D' ) b4 = true;
            }
        }
    }
    cout << b1 ? 1 : 0;
    cout << b2 ? 1 : 0;
    cout << b3 ? 1 : 0;
    cout << b4 ? 1 : 0;
    return 0;
}
