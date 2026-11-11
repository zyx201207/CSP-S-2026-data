#include <bits/stdc++.h>
using namespace std;
int trainR,trainX,quastion1,quastion2,quastion3,quastion4;
string seatR,seatX;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>trainR>>seatR>>trainX>>seatX;
	if(trainR==trainX){
		quastion1=1;
		if(seatR[0]==seatX[0] && seatR[1]==seatX[1]){
			quastion2=1;
			if(seatR[1]==seatX[1] && ((seatR[2]<'D' && seatX[2]<'D') || (seatR[2]>='D' && seatX[2]>='D'))){
				quastion3=1;
				if((seatR[2]=='A' && seatX[2]=='B') || (seatR[2]=='B' && seatX[2]=='A') || (seatR[2]=='B' && seatX[2]=='C') || (seatR[2]=='C' && seatX[2]=='B') || (seatR[2]=='D' && seatX[2]=='F') || (seatR[2]=='F' && seatX[2]=='D'))
					quastion4=1;
			}
		}
	}
	cout<<quastion1<<quastion2<<quastion3<<quastion4;
	return 0;
}
