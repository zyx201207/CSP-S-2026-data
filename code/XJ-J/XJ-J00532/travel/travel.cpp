#include <bits/stdc++.h>
using namespace std;
int a[28];
int b[28];
int c[28];
int d[28];
int f[28];
int main() {
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i = 1;i<=18;i++) {
		cin >> a[i];
	}
	for(int i = 1;i<=18;i++) {
		cin >> b[i];
	}
	for(int i = 1;i<=18;i++) {
		cin >> c[i];
	}
	for(int i = 1;i<=18;i++) {
		cin >> d[i];
	}
	for(int i = 1;i<=18;i++) {
		cin >> f[i];
	}
	if(c1 == c2) {
		cout << "1";
	} else {
		cout << "0";
	}

	
	return 0;
}