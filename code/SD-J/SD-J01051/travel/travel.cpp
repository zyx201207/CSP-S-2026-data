#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	string c1 , s1 , c2 , s2;
	cin >> c1 >> s1 >>c2 >>s2;
	if(c1 != c2){
		cout << "0000";
		return 0;
	}
	cout << 1;
	int k = (s1[0] - '0') * 10 + (s1[1] - '0');
	int k1 = (s2[0] - '0') * 10 + (s2[1] - '0');
	if(k != k1){
		cout << "000";
		return 0;
	}
	cout << 1;
	char a = s1[2] , b = s2[2];
	if(a < 'D' && b >= 'D'){
		cout << "00";
		return 0;
	}
	if(a >= 'D' && b < 'D'){
		cout << "00";
		return 0;
	}
	cout << 1;
	if(a == 'A' && b == 'B' || a == 'B' && b == 'A'){
		cout << 1;
		return 0;
	}
	if(a == 'B' && b == 'C' ||a == 'C' && b == 'B'){
		cout << 1;
		return 0;
	}
	if(a == 'D' && b == 'F' || a == 'F' && b == 'D'){
		cout << 1;
		return 0;
	}
	cout << 0;

	return 0;
}

