#include <bits/stdc++.h>
using namespace std;
string a[2], b[2];
int main(){
	freopen("travel.in", "r" ,stdin);
	freopen("travel.out", "w" ,stdout);
	cin >> a[0] >> b[0] >> a[1] >> b[1];
	if(a[0] == a[1]){
		cout << "1";
		if(b[0][0] == b[1][0] && b[0][1] == b[1][1]){
			cout << "1";
			if((b[0][2] <= 'B' && b[1][2] <= 'B')
			 || (b[0][2] > 'B' && b[1][2] > 'B')){
				cout << "1";
				if(abs(b[0][2] - b[1][2]) == 1){
					cout << "1";
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
