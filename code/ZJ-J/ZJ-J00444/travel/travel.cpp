#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;
	if(a1 == b1){
		cout << "1";
		if(a2[0] == b2[0] && a2[1] == b2[1]){
			cout << "1";
			if(a2[2] >= 'A' && a2[2] <= 'C'){
				if(b2[2] >= 'A' && b2[2] <= 'C'){
					cout << "1";
					if(abs(int(a2[2] - b2[2])) == 1) cout << "1";
					else cout << "0";
				} else cout << "00";
			}else{
				if(b2[2] == 'D' || b2[2] == 'F'){
					cout << "1";
					if((a2[2] == 'D' && b2[2] == 'F') || (a2[2] == 'F' && b2[2] == 'D')) cout << "1";
					else cout << "0";
				} else cout << "00";
			} 
		} else cout << "000";
	} else cout << "0000";
	
	return 0;
}
