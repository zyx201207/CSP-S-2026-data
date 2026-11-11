#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
string a1;
string b1;
string a2;
string b2;
string x;
string y;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a1 >> b1 >> a2 >> b2;
	if(a1 == a2){
		cout << 1;
	}else{
		cout << 0;
	}
	x = b1[0] + b1[1];
	y = b2[0] + b2[1];
	if(a1 == a2 && x == y){
		cout << 1;
	}else{
		cout << 0;
	}
	if(a1 == a2 && x == y && ((b1[2] == 'A' && b2[2] == 'B') || (b1[2] == 'A' && b2[2] == 'C') || (b1[2] == 'B' && b2[2] == 'C') || (b1[2] == 'B' && b2[2] == 'A') || (b1[2] == 'C' && b2[2] == 'A') || (b1[2] == 'C' && b2[2] == 'B') || (b1[2] == 'D' && b2[2] == 'F') || (b1[2] == 'F' && b2[2] == 'D'))){
		cout << 1;
	}else{
		cout << 0;
	}
	if(a1 == a2 && x == y && ((b1[2] == 'A' && b2[2] == 'B') || (b1[2] == 'B' && b2[2] == 'C') || (b1[2] == 'B' && b2[2] == 'A') || (b1[2] == 'C' && b2[2] == 'B') || (b1[2] == 'D' && b2[2] == 'F') || (b1[2] == 'F' && b2[2] == 'D'))){
		cout << 1;	
	}else{
		cout << 0;
	}
	return 0;
} 


