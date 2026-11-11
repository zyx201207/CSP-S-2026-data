#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1, s1, c2, s2;
	bool flag = true;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2 && flag){
		cout << 1;
	}
	else {
		flag = false;
		cout << 0;
	}
	
	if (s1[0] == s2[0] && s1[1] == s2[1] && flag) {
		cout << 1;
	}
	else {
		flag = false;
		cout << 0;
	}
	
	int a, b;
	if (s1[2] == 'A') a = 1;
	if (s1[2] == 'B') a = 2;
	if (s1[2] == 'C') a = 3;
	if (s1[2] == 'D') a = 4;
	if (s1[2] == 'F') a = 5;
	if (s2[2] == 'A') b = 1;
	if (s2[2] == 'B') b = 2;
	if (s2[2] == 'C') b = 3;
	if (s2[2] == 'D') b = 4;
	if (s2[2] == 'F') b = 5;
	
	if (flag && (a+b <= 4 || a+b == 9)){
		cout << 1;
	}
	else {
		flag = false;
		cout << 0;
	}
	
	if (flag && abs(a-b) == 1) {
		cout << 1;
	}
	else cout << 0;
	
	return 0;
}
