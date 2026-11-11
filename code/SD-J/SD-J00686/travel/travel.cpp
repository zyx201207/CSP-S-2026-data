#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 0;
const int MOD = 0;

string a,b,c,d;

signed main(){

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> a >> b >> c >> d;
	if(a == c) {
		cout << "1";
		if(b[0] == d[0] && b[1] == d[1]) {
			cout << "1";
			int x = 0,y = 0;
			if(b[2] == 'A' || b[2] == 'B' || b[2] == 'C') x = 1;
			if(d[2] == 'A' || d[2] == 'B' || d[2] == 'C') y = 1;
			if(x == y) {
				cout << "1";
				if(x == 0 || abs((int)(b[2] - 'A') - (int)(d[2] - 'A')) == 1) cout << "1";
				else cout << "0";
			} else cout << "00";
		} else {
			cout << "000";
		}
	}
	else cout << "0000";

	return 0;
}

