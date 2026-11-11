#include<bits/stdc++.h>
using namespace std;

int x, y;
int c1, c2;
string s1, s2;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> c1 >> s1 >> c2 >> s2;

    if(c1 != c2){
        cout << "0000";
        return 0;
    }

    x = (s1[0] - '0') * 10 + (s1[1] - '0');
    y = (s2[0] - '0') * 10 + (s2[1] - '0');

    if(x != y){
        cout << "1000";
        return 0;
    }

    if((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C')){
        cout << "1100";
        return 0;
    }

    if((s1[2] + 1 == s2[2]) || (s2[2] + 1 == s1[2]))
        cout << "1111";
    else
        cout << "1110";
    return 0;
}
