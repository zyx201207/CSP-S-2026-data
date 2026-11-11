#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string cr,cx;
string sr,sx;
string sr1,sx1;

int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cr >> sr >> cx >> sx;
	if (cr != cx) {
		printf("0000");
		return 0;
	}
	printf("1");
	int l = sr.size();
	char pr,px;
	for (int i = 0;i < l;i++) {
		char c1 = sr[i];
		char c2 = sx[i];
		if (c1 >= '0' && c1 <= '9') {
			sr1 += c1;
		}
		if (c2 >= '0' && c2 <= '9') {
			sx1 += c2;
		}
		if (c1 >= 'A' && c1 <= 'Z') {
			pr = c1;
		}
		if (c2 >= 'A' && c2 <= 'Z') {
			px = c2;
		}
	}
	if (sr1 == sx1) {
		printf("1");
	} else {
		printf("000");
		return 0;
	}
	if ((pr >= 'A' && pr <= 'C' && px >= 'A' && px <= 'C') || (pr >= 'D' && pr <= 'E' && px >= 'D' && px <= 'E')) {
		printf("1");
	} else {
		printf("00");
		return 0;
	}
	if (pr + 1 == px || pr - 1 == px || px + 1 == pr|| px - 1 == pr) {
		printf("1");
	} else {
		printf("0");
	}
	
	return 0;
} 
