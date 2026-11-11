#include <iostream>
using namespace std;
int main(){
	int m,n,x,z;
	cin >> m >> n >> x >> z;
	if(m == x){
		if(int(n[0]+n[1]) == int(z[0]+z[1])){
			if(n[-1] - z[-1] == 1 or z[-1] - n[-1] == 1 or (z[-1] == d and n[-1] == f) or (z[-1] == f and n[-1] == d)){
				cout << 1111;
			}
			else{
				cout << 1110;
			}
		}
		else{
			cout << 1000;
		}
	}
	else{
	cout << 0000;
	}
	return 0;
}
