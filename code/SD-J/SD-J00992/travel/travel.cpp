#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string numR,numX,seatR,seatX;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>numR>>seatR>>numX>>seatX;
	if(numR==numX){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(seatR[0]==seatX[0]&&seatR[1]==seatX[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(seatR[2]=='A'||seatR[2]=='B'||seatR[2]=='C'){
		if(seatX[2]=='A'||seatX[2]=='B'||seatX[2]=='C'){
			cout<<"1";
			if(seatR[2]+1==seatX[2]||seatR[2]-1==seatX[2]){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
		else{
			cout<<"00";
		}
	}
	else if(seatR[2]=='D'||seatR[2]=='F'){
		if(seatX[2]=='D'||seatX[2]=='F'){
			cout<<"11";
		}
		else{
			cout<<"00";
		}
	}
	return 0;
}
