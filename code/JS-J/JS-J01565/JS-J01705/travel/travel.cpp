#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;

string c1, s1, c2, s2;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> c1 >> s1 >> c2 >> s2;

    if(c1 == c2) {
        cout << 1;
        if(s1.substr(0, 2) == s2.substr(0, 2)) {
            cout << "1";
            if(s1[2] <= 'C' && s2[2] <= 'C') {
                cout << "1";
                if((int)s1[2] - (int)s2[2] == 1 || (int)s1[2] - (int)s2[2] == -1) {
                    cout << "1";
                }
                else {
                    cout << "0";
                }
            }
            else if(s1[2] > 'C' && s1[2] > 'C') {
                cout << "11";
            }
            else {
                cout << "00";
            }
        }
        else {
            cout << "000";
        }
    }
    else {
        cout << "0000";
    }
    cout << endl;
    return 0;
}
