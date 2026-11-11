#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define vi void
using namespace std;

int a,x;
string b,y;
bool fg=0;

inline vi one() {
	if(a==x) {
		cout<<'1';
	} else {
		cout<<'0';
	}
	return;
}

inline vi tow() {
	if(a==x) {
		if(b.substr(0,2)==y.substr(0,2)) {
			cout<<'1';
			return;
		}
	}
	cout<<'0';
	return;
}

inline vi three() {
	if(a==x) {
		if(b.substr(0,2)==y.substr(0,2)) {
			char m=b[2],n=y[2];
			if((m=='A'&&n=='B')||(m=='B'&&n=='A')||(m=='A'&&n=='C')||(m=='C'&&n=='A')||(m=='C'&&n=='B')||(m=='B'&&n=='C')||(m=='D'&&n=='F')||(m=='F'&&n=='D')) {
				cout<<'1';
				fg=1;
				return;
			}
		}
	}
	cout<<'0';
	return;
}

inline vi four() {
	char m=b[2],n=y[2];
	if(fg) {
		if((m=='A'&&n=='B')||(m=='B'&&n=='A')||(m=='B'&&n=='C')||(m=='C'&&n=='B')||(m=='D'&&n=='F')||(m=='F'&&n=='D')) {
			cout<<'1';
			return;
		}
	}
	cout<<'0';
	return;
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>a>>b>>x>>y;
	one();
	tow();
	three();
	four();
	return 0;
}
