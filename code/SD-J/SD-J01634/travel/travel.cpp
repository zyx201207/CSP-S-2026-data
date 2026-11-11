#include<bits/stdc++.h>
using namespace std;



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;

	
	if(a[1] == c[1]) {
		cout << '1';
	
	} else {
		cout << "0000";
		return 0;
	}
	
	if(b[0] == d[0] && b[1] == d[1]) {
		cout << '1';
	} else {
		cout << "000";
		return 0;
	}
	
	
	
	if(b[2] <= 'C' && d[2] <= 'C') {
		cout << 1;
		
	}else if(b[2] >= 'D' && d[2] >='D') {
		cout << 1;
	} else {
		cout <<"00";
		return 0;
	}
	
	if(b[2] - d[2] == 2) {
		if(b[2] == 'D' && d[2] == 'F' || b[2] == 'F' && d[2] == 'D') {
			cout << 1;
		} else {
			cout << "0";
			return 0;
		}
	}
	if((b[2] - d[2] == 1 || d[2] - b[2] == 1) && (b[2] == 'B' || d[2] == 'B')) {
		cout << 1;
		
	}else {
			cout << "0";
			return 0;
	}
	
	return 0;
}
