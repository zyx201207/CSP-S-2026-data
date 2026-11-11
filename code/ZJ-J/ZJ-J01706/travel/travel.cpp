#include<bits/stdc++.h>
using namespace std;
string cR,sR,cX,sX;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cR>>sR>>cX>>sX;
	if(cR==cX) printf("1");
	else{
		printf("0000");
		return 0;
	}
	if(sR[0]==sX[0]&&sR[1]==sX[1]) printf("1");
	else{
		printf("000");
		return 0;
	}
	if(sR[2]<='C'&&sX[2]<='C'||sR[2]>'C'&&sX[2]>'C') printf("1");
	else{
		printf("00");
		return 0;
	}
	if(abs(sR[2]-sX[2])==1||sR[2]>'C'&&sX[2]>'C') printf("1");
	else printf("0");
	return 0;
}