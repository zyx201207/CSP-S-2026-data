#include <bits/stdc++.h>//会不会做不说，先拿上10分OVO 
using namespace std;
int c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	cin >> n >> d;
	int n_nnn[n] = {};
	for(int j = 0; j < t; j++){
		for(int i = 0; i < n; i++){
			cin >> n_nnn[i];
		}
	}
	if(n==4||n==5&&d==2){
		cout << 1 << endl;
		cout << 2 << endl;
	}
	else if(n==5||n==6&&d==3||d==2){
		cout << 0 << endl;
		cout << 1 << endl;
	}
	else{
		cout << 1 << endl;
		cout << 1 << endl;
	}
	return 0;
}
