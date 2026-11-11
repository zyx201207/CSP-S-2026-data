#include<bits/stdc++.h>
using namespace std;
string a, b, c, d;
int ans = 1;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> c >> d;
	if(a != c)
		ans = 0;
	cout << ans;
	if(b[0] != d[0] || b[1] != d[1])
		ans = 0;
	cout << ans;
	if(b[2] > d[2])
		swap(b, d);
	if(b[2] <= 'C' && d[2] >= 'D')
		ans = 0;
	cout << ans;
	if(b[2] == 'A' && d[2] == 'C')
		ans = 0;
	cout << ans;
	return 0;
}
