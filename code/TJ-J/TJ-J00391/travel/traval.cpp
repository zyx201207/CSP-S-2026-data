#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin >> a1 >> b1 >> a2 >> b2;
	if (a1 == a2){
		cout << 1;
		if (b1[0] == b2[0] && b1[1] == b2[1]){
			cout << 1;
			if (a1 == a2 && b1[0] == b2[0] && b1[1] == b2[1] && (b1[2] >= 'D' && b2[2] >= 'D') || (b1[2] <= 'C' && b2[2] <= 'C')){
				cout << 1;
				if (((b1[2] >= 'D' && b2[2] >= 'D') || (b1[2] <= 'C' && b2[2] <= 'C')) && (b1[2] + 1 == b2[2] || b1[2] - 1 == b2[2])){
					cout << 1;
				} 
				else{
					cout << 0;
				} 
			} 
			else{
				cout << "00";
			} 
		} 
		else{
			cout << "000";
		} 
	} 
	else{
		cout << "0000";
	} 
	return 0;
} 
