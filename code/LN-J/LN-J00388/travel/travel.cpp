#include<bits/stdc++.h>
using namespace std;
int cage1, cage2;
string seat1, seat2;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w". stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> cage1 >> seat1 >> cage2 >> seat2;
    if (cage1 == cage2) {
        cout << 1;
        string t1, t2;
        for (int i = 0; i < 2; i ++) t1 += seat1[i];
        for (int i = 0; i < 2; i ++) t2 += seat2[i];
        if (t1 == t2) {
            cout << 1;
            if ((seat1[2] >= 'A' && seat2[2] >= 'A' && seat1[2] <= 'C' &&
                 seat2[2] <= 'C' ) || (seat1[2] >= 'D' && seat2[2] >= 'D')) {
                cout << 1;
                if ((seat1[2] >= 'A' && seat2[2] >= 'A' && seat1[2] <= 'C' &&
                    seat2[2] <= 'C' && (seat1[2] + 1 == seat2[2] || seat2[2] + 1 == seat1[2]))
                    || (seat1[2] >= 'D' && seat2[2] >= 'D' && (seat1[2] == 'D' &&
                    seat2[2] == 'F' || seat1[2] == 'F' && seat2[2] == 'D'))) {
                    cout << 1;
                } else cout << 0;
            } else cout << "00";
        } else cout << "000";
    } else cout << "0000";
    return 0;
}
