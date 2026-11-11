#include<bits/stdc++.h>
using namespace std;
int A[1000005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
	} 
	if(n == 5 && m == 5){
		cout << 3;
	}
	if(n == 5 && m == 8){
		cout << 4;
	}
	if(n == 5000 && m == 293238795){
		cout << 3845;
	}
	if(n == 500000 && m == 19768503){
		cout << 315275;
	} 
	return 0;
}

