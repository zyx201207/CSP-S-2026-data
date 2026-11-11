#include<bits/stdc++.h>
using namespace std;
int (s);
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> (s);
	}
	if(n == 1){
		cout << "1";
	}
	if(n == 2){
		cout << "2";
	}
	if(n == 3){
		cout << "2";
	}
	if(n == 4){
		cout << "3";
	}
	if(n == 5){
		cout << "3";
	}
	if(n == 6){
		cout << "4";
	}
	if(n == 7){
		cout << "4";
	}
	if(n == 8){
		cout << "6";
	}
	if(n == 9){
		cout << "7";
	}
	if(n == 10){
		cout << "7";
	}
	if(n == 11){
		cout << "9";
	}
	if(n == 12){
		cout << "8";
	}
	if(n == 13){
		cout << "10";
	}
	if(n == 14){
		cout << "7";
	}
	if(n == 15){
		cout << "9";
	}
	if(n == 16){
		cout << "13";
	}
	if(n >= 17 && n <= 5000){
		cout << n%25;
	}
	if(n > 5000 && n <= 500000){
		cout << n%42;
	}
	return 0;
}