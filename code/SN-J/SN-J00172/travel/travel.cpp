#include <bits/stdc++.h>
using namespace std;
int cy, cr;
char sy[5], sr[5];
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cy;
	for(int i = 1;i <= 3;i++){
		cin >> sy[i];
	}
	cin >> cr;
	for(int i = 1;i <= 3;i++){
		cin >> sr[i];
	}
	if(cy == cr){
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	if(sy[1] == sr[1] && sy[2] == sr[2]){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	if(sy[3] == 'D' && sr[3] == 'F' || sy[3] == 'F' && sr[3] == 'D' || sy[3] == 'C' && sr[3] == 'B' || sy[3] == 'B' && sr[3] == 'C' || sy[3] == 'B' && sr[3] == 'A' || sy[3] == 'A' && sr[3] == 'B'){
		cout << "11";
		return 0;
	}
	if(sy[3] == 'A' && sr[3] == 'C' || sy[3] == 'C' && sr[3] == 'A'){
		cout << "10";
		return 0;
	}
	cout << "00";
	return 0;
}

