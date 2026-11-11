#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio (0) , cin.tie (0) , cout.tie (0);
#define ll long long
#define endl '\n'
int c1 , s1n , c2 , s2n;
char s1s , s2s;
bool q1 , q2 , q3 , q4;
int main () {
    IOS
    freopen ("travel.in" , "r" , stdin);
    freopen ("travel.out" , "w" , stdout);
    cin >> c1 >> s1n >> s1s >> c2 >> s2n >> s2s;
    if (s1s > s2s) swap (s1s , s2s);
    q1 = (c1 == c2);
    q2 = (q1 && s1n == s2n);
    q3 = (q1 && q2 && !(s1s <= 'C' && s2s >= 'D'));
    q4 = (q1 && q2 && q3 && ((s1s == 'A' && s2s == 'B') || s1s == 'B' && s2s == 'C') || (s1s == 'D' && s2s == 'F'));
    cout << q1 << q2 << q3 << q4;
    return 0;
}
