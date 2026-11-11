#include<bits/stdc++.h>

using namespace std;
using LL = long long;

string c1, s1, c2, s2;

int isnear(char x, char y){
	if(x == 'A'){
		if(y == 'B') return 2;
		else if(y == 'C') return 1;
		else return 0;
	}
	else if(x == 'B'){
		if(y == 'A' || y == 'C') return 2;
		else return 0;
	}
	else if(x == 'C'){
		if(y == 'B') return 2;
		else if(y == 'A') return 1;
		else return 0;
	}
	else if(x == 'D' && y == 'F' || x == 'F' && y == 'D') return 2;
	else return 0;
}

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2){
		cout << '1';
		if(s1[1] == s2[1]){
			if(isdigit(s1[2]) && isdigit(s2[2])){
				if(s1[2] == s2[2]){
					cout << '1';
					int i = isnear(s1[3], s2[3]);
					if(i == 1){
						cout << "10";
					}
					else if(i == 2){
						cout << "11";
					}
					else cout << "00";
				}
				else{
					cout << "000";
				}
			}
			else{
				cout << '1';
				int i = isnear(s1[2], s2[2]);
				if(i == 1){
					cout << "10";
				}
				else if(i == 2){
					cout << "11";
				}
				else cout << "00";
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
