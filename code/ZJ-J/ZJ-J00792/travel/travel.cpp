#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//froepen
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if (a!=c) {
		cout <<"0000";
	}
	else {
		cout <<1;
		int x=b[0]*10+b[1],y=d[0]*10+d[1];
		if (x!=y) {
			cout <<"000";
		}
		else {
			cout <<1;
			if (b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D') {
				cout <<1;
				if (b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'||b[2]=='B'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||d[2]>='D'&&b[2]>='D') {
					cout <<1;
				}
				else {
					cout <<0;
				}
			}
			else {
				cout <<"00";
			}
		}
	}
	return 0;
}//rp++
//100+58+100+60=318 
