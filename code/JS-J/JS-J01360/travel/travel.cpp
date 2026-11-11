#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
string c1, s1, c2, s2;
bool df(char x){
    return x == 'D' || x == 'F';
}
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    cout << (ll)(c1 == c2);
    cout << (ll)(c1 == c2 && s1.substr(0, 2) == s2.substr(0, 2));
    cout << (ll)(c1 == c2 && s1.substr(0, 2) == s2.substr(0, 2) && df(s1[2]) == df(s2[2]));
    cout << (ll)(c1 == c2 && s1.substr(0, 2) == s2.substr(0, 2) && df(s1[2]) == df(s2[2]) && abs(((ll)s1[2]) - ((ll)s2[2])) == 1);
    return 0;
}
