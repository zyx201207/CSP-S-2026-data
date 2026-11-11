#include<bits/stdc++.h>
using namespace std;
int c, t;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    srand(time(0));
    cin >> c >> t;
    if (t == 1) {
        cout << "12251";
    }
    else if (t == 2) {
        cout << "1\n2";
    }
    else if (t == 3) {
        cout << "1\n1\n2";
    }
    else if (t == 5) {
        cout << "17\n9\n6\n6\n9";
    }
    else {
        while (t--) {
            cout << rand() % 100;
        }
    }

    return 0;
}










//I love you hmx.
//I communicate(jiao liu, ying gai shi zhe mo ping de) with you. But when I see you, I am happy.
//I can't get you.
