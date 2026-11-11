#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string R, X, c, s;
	
	cin >> c >> R >> s >> X;
	if(c == s) cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	if(R[1] == X[1]) cout << 1;
	else{
		cout << "000";
		return 0;
	}
	if((R[2] <= 'C' && X[2] <= 'C') || (R[2] > 'C' && X[2] > 'C')) cout << 1;
	else{
		cout << "00";
		return 0;
	}
	if((R[2] == X[2]+1 && R[2]!='D') || (R[2]+1 == X[2] && X[2]!='D'))cout << 1;
	else{
		cout << "0";
		return 0;
	}
	return 0;
} 
