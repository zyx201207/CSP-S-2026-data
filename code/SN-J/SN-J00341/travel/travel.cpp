#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int cxR,cxX;
	string zwR,zwX;
	cin >> cxR >>  zwR >> cxX>>zwX;
	if(cxR!=cxX){
		cout << "0000";
		return 0;
	}
	else{
		cout << "1";
		
		if(zwR[0]!=zwX[0]||zwR[1]!=zwX[1]){
			cout << "000";
			return 0;
		}
		else{
			cout << "1";
			if(zwR[2]<='C'&&zwX[2]<='C'){
				cout <<1;
			}
			else if(zwR[2]>'C'&&zwX[2]>'C'){
				cout << 1;
			}
			else{
				cout << "00";
				return 0;
			}
			if(zwR[2]-zwX[2]!=1&&zwX[2]-zwR[2]!=1){
				cout << "0";
				return 0;
			}
			else{
				cout << "1";
				return 0;
			}
		}
	}
	return 0;
}
