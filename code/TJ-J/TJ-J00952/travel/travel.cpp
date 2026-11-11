#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	int a, b, c, d;
	cin >> c1 >> s1 >> c2 >> s2;
	char n = s1[0], n2 = s1[1], n3 = s1[2], p = s2[0], p2 = s2[1], p3 = s2[2];
	if(c1 == c2){
		a = 1;
	}
	else{
		a = 0;
	}	
	if(s1[0] == s2[0] && s1[1] == s2[1] && a == 1){
		b = 1;
	}
	else{
		b = 0;
	}
	if(n3 + p3 == 'D' + 'F' && b == 1){
		c = 1;
	}
	else if(n3 + p3 == 'A' + 'B' && b == 1){
		c = 1;
	}
	else if(n3 + p3 == 'C' + 'B' && b == 1){
		c = 1;
	}
	else if(n3 + p3 == 'C' + 'A' && b == 1){
		c = 1;
	}
	else{
		c = 0;
	}
	if(n3 + p3 != 'A' + 'C' && c == 1){
		d = 1;
	}
	else{
		d = 0;
	}
	cout << a << b << c << d;
	return 0;
}
