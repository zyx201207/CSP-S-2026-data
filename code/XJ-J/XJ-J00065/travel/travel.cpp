#include<bits/stdc++.h>
using namespace std;
int main(){
	/*freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);*/
	string carR,seatR,carX,seatX;
	cin >> carR >> seatR >> carX >> seatX;
	bool A=false,B=false,C=false,D=false;
	if(carR==carX){
		cout << 1;
		A=true;
	}
	else{
		cout << 0;
	}
	
	
	if(A&&seatR.substr(0,2)==seatX.substr(0,2)){
		cout << 1;
		B=true;
	}
	else{
		cout << 0;
	}
	
	
	if(A&&B&&(seatR[2]>='A'&&seatR[2]<='C'&&seatX[2]>='A'&&seatX[2]<='C')||(seatR[2]>='D'&&seatR[2]<='F'&&seatX[2]>='D'&&seatX[2]<='F')){
		if(seatR[2]!=seatX[2]){
			cout << 1;
			C=true;
		}
		else{
			cout << 0;
		}
	}
	else{
		cout << 0;
	}
	
	
	if(A&&B&&C&&(seatR[2]-1==seatX[2]||seatR[2]+1==seatX[2])){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
