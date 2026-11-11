#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {

     freopen("travel.in", "r", stdin);
     freopen("travel.out", "w", stdout);
    cin.tie(0) -> ios::sync_with_stdio(0);

    int c1, c2;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;

    int x1 = (s1[0] - '0') * 10 + s1[1] - '0';
    int x2 = (s2[0] - '0') * 10 + s2[1] - '0';
    char k1 = s1[2], k2 = s2[2];


    if (c1 == c2)  {
        cout << 1;
        if (x1 == x2) {
            cout << 1;
            if ((k1 <= 'C' && k2 <= 'C') || (k2 >= 'D' && k1 >= 'D')) {
                cout << 1;
                if (abs(signed(k2 - k1)) == 1 ) {
                    cout << 1;
                } else {
                	cout << "0";
				}
            } else {
            	cout << "00";
			}
        } else {
        	cout << "000";
		}
    } else {
    	cout << "0000";
	}
    


    return 0;
}
