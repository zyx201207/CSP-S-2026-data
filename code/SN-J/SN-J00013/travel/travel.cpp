#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, c2, z1, z2;
	cin >> c1 >> z1 >> c2 >> z2;
	
	if(c1 != c2){
		cout << "0000";
	}else{
		if(z1.substr(0, 2) != z2.substr(0, 2)){
			cout << "1000";
		}else{
			if(((z1[2] == 'A' || z1[2] == 'B' || z1[2] == 'C') && (z2[2] == 'A' || z2[2] == 'B' || z2[2] == 'C')) || ((z1[2] == 'D' || z1[2] == 'F') && (z2[2] == 'D' || z2[2] == 'F'))){
				if((z1[2] == z2[2] + 1 && z2[2] != 'C') || (z1[2] == z2[2] - 1 && z1[2] != 'C')){
					cout << "1111";
				}else if((z1[2] == 'D' && z2[2] == 'F') || (z2[2] == 'D' && z2[2] == 'F')){
					cout << "1111";
				}else{
					cout << "1110";
				}
			}else{
				cout << "1100";
			}
		}
	}
	
	return 0;
}
