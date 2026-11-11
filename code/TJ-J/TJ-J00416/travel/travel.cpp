#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int tonum(string s) {
	int result=0;
	for (char c:s)	result=result*10+(c-'0');
	return result;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int c1=tonum(s1), c2=tonum(s3);
	int l1=tonum(s2.substr(0,2)), l2=tonum(s4.substr(0,2));
	int n1=tonum(s2.substr(2))+'0', n2=tonum(s4.substr(2))+'0';
	if (n1=='F')	n1--;
	if (n2=='F')	n2--;
	cout << (c1==c2);
 	cout << (c1==c2&&l1==l2);
 	cout << (c1==c2 && l1==l2 && ((n1<='C'&&n2<='C')||(n1>'C'&&n2>'C')));
 	cout << (c1==c2 && l1==l2 && ((n1<='C'&&n2<='C')||(n1>'C'&&n2>'C')) && abs(n1-n2)==1);
	return 0;
}
