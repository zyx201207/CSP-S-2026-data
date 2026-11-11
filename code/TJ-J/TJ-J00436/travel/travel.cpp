#include<bits/stdc++.h>
using namespace std;
bool xi = 0, p = 0, c = 0, l = 0;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r, x;
	string rr;
	string xx;
	cin >> r >> rr;
	cin >> x >> xx;
	if(r == x) {
		xi = 1;
		if(rr[0] == xx[0]&&rr[1] == xx[1]) {
			p = 1;
			char d = rr[2];
			char f = xx[2];
			if((d=='A'||d=='B'||d=='C')&&(f=='A'||f=='B'||f=='C')){
				c = 1;
				if(d=='B'||f=='B'){
					l = 1;
				}
			}
			if((d=='D'||d=='F')&&(f=='D'||f=='F')){
				c = 1;
				l = 1;
			}
		}
	}
	cout << xi << p << c << l;
	return 0;
}
