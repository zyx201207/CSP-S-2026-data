#include<bits/stdc++.h>
using namespace std;

int c1, c2;
string s1, s2;
int a1, a2;
char b1, b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2){
        cout <<"0000";
        return 0;
    }
    cout << "1";
    a1 = s1[0] - '0';
    a1 = a1 * 10 + (s1[1] - '0');
    a2 = s2[0] - '0';
    a2 = a2 * 10 + (s2[1] - '0');
    if(a1 != a2){
        cout << "000";
        return 0;
    }
    b1 = s1[2];
    b2 = s2[2];
    cout <<"1";
    if((b1 >= 'A' && b1 <= 'C' && b2 >= 'D' && b2 <= 'F') || (b2 >= 'A' && b2 <= 'C' && b1 >= 'D' && b1 <= 'F')){
        cout <<"00";
        return 0;
    }
    cout <<"1";
    if((b1 == 'A' && b2 == 'B') || (b1 == 'B' && (b2 == 'A' || b2 == 'C')) || (b1 == 'C' && b2 == 'B') || (b1 == 'D' && b2 == 'F') ||(b1 == 'F' && b2 == 'D'))
        cout <<"1";
    else
        cout << "0";
    return 0;
}