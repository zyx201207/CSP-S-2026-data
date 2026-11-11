#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+10;

bool check1(string sr,string sx) {
	int a,b;
	if(sr[2] == 'A' || sr[2] == 'B' || sr[2] == 'C') {
		a = 0;
	} else {
		a = 1;
	}
	if(sx[2] == 'A' || sx[2] == 'B' || sx[2] == 'C') {
		b = 0;
	} else {
		b = 1;
	}
	if(a == b) return true;
	else return false;
}
bool check2(string sr,string sx) {
	int a,b;
	a = sr[2] - 'A';
	b = sx[2] - 'A';
	if(abs(a-b) == 1 && !((a == 3 && b == 4) || (b == 3 && a == 4))) {
		return true;
	} else if((a == 4 && b == 6) || (b == 4 && a == 6)) {
		return true;
	} else {
		return false;
	}
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin >> cr >> sr >> cx >> sx;
	int flag = 1;
	if(cr == cx) {
		cout << 1;
	} else {
		cout << 0;
		flag = 0;
	}
	if(flag && sr[0] == sx[0] && sr[1] == sx[1]) {
		cout << 1;
	} else {
		cout << 0;
		flag = 0;
	}
	if(flag && check1(sr,sx)) {
		cout << 1;
	} else {
		cout << 0;
		flag = 0;
	}
	if(flag && check2(sr,sx)) {
		cout << 1;
	} else {
		cout << 0;
		flag = 0;
	}
	return 0;
}
