#include <bits/stdc++.h>
using namespace std;

string ans = "0000", a, b, c, d;

int work(char k) {
    int i = k - 'A';
    if(0 <= i && i <= 2) {
        return 1;
    }
    else if(3 <= i && i <= 4) {
        return 2;
    }
    else {
        return -1;
    }
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if(a == c) {
        ans[0] = '1';
        if(b[0] == d[0] && b[1] == d[1]) {
            ans[1] = '1';
            if(work(b[2]) == work(d[2])) {
                ans[2] = '1';
                int i = b[2] - 'A', j = d[2] - 'A';
                if(abs(i - j) <= 1) {
                    ans[3] = '1';
                }
            }
        }
	}
	cout << ans << endl;
	return 0;
}
