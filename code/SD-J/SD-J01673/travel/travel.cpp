#include<bits/stdc++.h>
using namespace std;
string c[20],s[20];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	for (int i = 1; i <= 2; i++){
		cin >> c[i] >> s[i];
	} 
	if (c[1] == c[2]){
		cout << "1";
		if (s[1][1] == s[2][1] && s[1][0] == s[2][0]){
			cout << "1";
			char x = (char)(s[1][2]);
			char y = (char)(s[2][2]);
			if (x == 'A' || x == 'B' || x == 'C'){
				if (y == 'D' || y == 'F'){
					cout << "00";
					return 0;
				}
				else{
					cout << 1;
					int cha = (int)(x-y);
					if ((x == 'D' && y == 'F') || (x == 'F' && y == 'D')){
						cout << "1";
						return 0;
					}
					else if (abs(cha) == 1){
						cout << "1";
						return 0;
					}
					else{
						cout << "0";
						return 0;
					}
				}
			}
			else if (x == 'D' || x == 'F'){
				if (y == 'A' || y == 'B' || y == 'C'){
					cout << "00";
					return 0;
				}
				else{
					cout << 1;
					int cha = (int)(x-y);
					if ((x == 'D' && y == 'F') || (x == 'F' && y == 'D')){
						cout << "1";
						return 0;
					}
					else if (abs(cha) == 1){
						cout << "1";
						return 0;
					}
					else{
						cout << "0";
						return 0;
					}
				}
			}
			
		}
		else{
			cout << "000";
			return 0;
		}
	}
	else{
		cout << "0000";
		return 0;
	}
	return 0;
} 
