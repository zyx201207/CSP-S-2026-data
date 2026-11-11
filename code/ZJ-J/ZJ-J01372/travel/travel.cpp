#include<bits/stdc++.h>
using namespace std;
string a[2], b[2];
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> a[0] >> a[1] >> b[0] >> b[1];
	
	if(a[0] != b[0]){
		cout << "0000";
	}else{
		if(a[1][0] + a[1][1] != b[1][0] + b[1][1])cout << "1000";
		else{
			if(a[1][2] + b[1][2] == 'D' + 'E' || a[1][2] + b[1][2] == 'A' + 'B' || a[1][2] + b[1][2] == 'B' + 'C')cout << "1111";
			else if( a[1][2] + b[1][2] == 'A' + 'C')cout << "1110";
			else cout << "1100";
		}
	}
	return 0;
}
