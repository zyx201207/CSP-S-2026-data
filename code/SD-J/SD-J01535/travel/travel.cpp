#include <bits/stdc++.h>
using namespace std;
string cR,sR,cX,sX,sum; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cR >> sR >> cX >> sX;
	bool flag = true;
	if (cR == cX){
		sum += "1";
	}else{
		sum += "0";
		flag = false;
	}
	if (sR[0] == sX[0] && sR[1] == sX[1] && flag){
		sum += "1";
	}else{
		sum += "0";
		flag = false;
	}
	if ((sR[2] <= 'C' && sX[2] <= 'C' || sR[2] >= 'D' && sX[2] >= 'D') && flag){
		sum += "1";
	}else{
		sum += "0";
		flag = false;
	}
	if (flag){
		if (sR[2] <= 'C' && sX[2] <= 'C'){
			if(char(sR[2]) - char(sX[2]) == 1 || char(sX[2]) - char(sR[2]) == 1){
				sum += "1";
			}else{
				sum += "0";
			}
		}else{
			if (sR[2] == 'D' && sX[2] == 'F' || sR[2] == 'F' && sX[2] == 'D'){
				sum += "1";
			}else{
				sum += "0";
			}
		}
	}else{
		sum += "0";
	}
	cout << sum;
	return 0;
} 
