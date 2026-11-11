#include<bits/stdc++.h>
using namespace std;
bool f1,f2,f3,f4;
bool pd(char a, char b) {
	if (a=='A'&&(b=='B'||b=='C')||a=='B'&&b=='C'||a=='D'&&b=='F') return 1;
	return 0;
}
bool pd1(char a, char b) {
	if (a=='A'&&b=='B'||a=='B'&&b=='C'||a=='D'&&b=='E') return 1;
	return 0;
}
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if (a==c) f1=1;
	if (f1&&b[0]==d[0]&&d[1]==b[1]) f2=1;
	char c1=b[2],c2=d[2];
	if (c1>c2) swap(c1,c2);
	if (f1&&f2&&pd(c1,c2)) f3=1;
	if (f1&&f2&&f3&&pd1(c1,c2)) f4=1;
	cout<<int(f1)<<int(f2)<<int(f3)<<int(f4);
	return 0;
}

