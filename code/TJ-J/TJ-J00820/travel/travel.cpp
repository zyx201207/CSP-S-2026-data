#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c_1, c_2, s_1, s_2;
	cin >> c_1 >> c_2 >> s_1 >> s_2;
	if(c_1 == s_1){
		cout << "1";
	}else{
		cout << "0" << "0" << "0" << "0";
		return 0;
	}
	int a1, a2, b1, b2;
	a1 = c_2[0] - '0';
	a2 = c_2[1] - '0';
	b1 = s_2[0] - '0';
	b2 = s_2[1] - '0';
	int a, b;
	if(a1 == 0){
		a = a2;
	}else{
		a = a1 * 10 + a2;
	}
	if(b1 == 0){
		b = b2;
	}else{
		b = b1 * 10 + b2;
	}
	if(a == b){
		cout << "1"; 
	}else{
		cout << "0" << "0" << "0";
		return 0;
	}
	char x = c_2[2], y = s_2[2];
	if(x == 'C' && y == 'D' || x == 'D' && y == 'C'){
		cout << "0" << "0";
		return 0;
	}else{
		cout << "1";
	}
	if(x == 'A' && y == 'B' || x == 'B' && y == 'A' || x == 'B' && y == 'C' || x == 'C' && y == 'B' || x == 'D' && y == 'F' || x == 'F' && y == 'D'){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}
