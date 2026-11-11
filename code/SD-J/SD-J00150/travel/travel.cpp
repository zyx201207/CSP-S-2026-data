#include<bits/stdc++.h>
using namespace std;
string a, b, c, d;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	string ans = "";
	if(a == c) ans += "1";
	else {
		cout << "0000" << "\n";
		return 0;
	}
	bool flag = 0;
	if(b[0] == d[0] && b[1] == d[1]) ans += "1", flag = 1;
	else ans += "0";
	char x = b[2], y = d[2];
	bool flag1 = 0;
	if(x >= 'A' && x <= 'C' && y >= 'A' && y <= 'C' && flag == 1) ans += "1", flag1 = 1;
	else if(x >= 'D' && y >= 'D') ans += "1", flag1 = 1;
	else ans += "0";
	int diff = abs(int(x) - (int) y);
	if(diff <= 1 && flag1) ans += "1";
	else ans += "0";
	cout << ans << "\n";
	return 0;
}
