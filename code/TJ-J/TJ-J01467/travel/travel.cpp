#include<bits/stdc++.h>
using namespace std;
string s1, s2;
string c1, c2; 
int pai1, pai2, i1, i2;
bool f[10];
bool check(){
	int k = f[1] + f[2] + f[3];
	return k == 0 || k == 2;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	pai1 = (s1[0] - '0') * 10 + s1[1] - '0', pai2 = (s2[0] - '0') * 10 + s2[1] - '0';
	if(s1[2] == 'D'){
		s1[2] == 'E';
	}
	if(s2[2] == 'D'){
		s2[2] = 'E';
	}
	i1 = s1[2] - 'A' + 1, i2 = s2[2] - 'A' + 1;
	f[i1] = 1, f[i2] = 1;
	if(c1 == c2){
		cout << 1;
		if(pai1 == pai2){
			cout << 1;
			if(check()){
				cout << 1;
				if(abs(i1 - i2) == 1){
					cout << 1;
				}else{
					cout << "0";
					return 0;
				}
			}else{
				cout << "00";
				return 0;
			}
		}else{
			cout << "000";
			return 0; 
		}
	}else{
		cout << "0000";
		return 0;
	}
	
	return 0;
} 
