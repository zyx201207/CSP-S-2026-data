#include<bits/stdc++.h>

using namespace std;
string a,b,c,d;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	cin >> a >> b >>c >> d;
	if(a == c) {
		cout <<'1';
	}else{
		cout << '0';
	}
	if((b[0] == d[0] && b[1] == d[1]) && (a == c)){
		cout << '1';
	}else{
		cout << '0';
	}
	if((b[2] == 'C' && d[2] == 'D') || (d[2] == 'C' && b[2] == 'D')){
		cout << '0';
	}else if((b[0] == d[0] && b[1] == d[1]) && (((b[2] == 'A' && d[2] == 'B') || (b[2] == 'A' && d[2] == 'C') || (b[2] == 'B' && d[2] == 'C') || (b[2] == 'B' && d[2] == 'A') || (b[2] == 'C' && d[2] == 'A') || (b[2] == 'C' && d[2] == 'B')) ||
	 ((b[2] == 'D' && d[2] == 'E') || (b[2] == 'E' && d[2] == 'D')))){
		cout <<'1';
	}else{
		cout <<'0';
	}
	if((b[2] == 'C' && d[2] == 'D') || (d[2] == 'C' && b[2] == 'D')){
		cout << '0';
	}else if((b[0] == d[0] && b[1] == d[1]) && ((int(b[2] - d[2] == 1)) || (int(d[2] - b[2] == 1)))){
		cout <<'1';
	}else{
		cout <<'0';
	}
	return 0;
}
