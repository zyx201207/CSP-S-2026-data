#include<bits/stdc++.h>
using namespace std;
struct seat{
	string roomL,sideL;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	seat R,X;
	cin>>R.roomL>>R.sideL>>X.roomL>>X.sideL;
	if(R.roomL!=X.roomL){
		cout<<"0000"<<endl;
		return 0;
	}
	if(R.sideL[0]!=X.sideL[0]||R.sideL[1]!=X.sideL[1]){
		cout<<"1000"<<endl;
		return 0;
	}
	if((R.sideL[2]=='D'&&X.sideL[2]=='F')||(R.sideL[2]=='F'&&X.sideL[2]=='D')||(R.sideL[2]=='A'&&X.sideL[2]=='B')||(R.sideL[2]=='A'&&X.sideL[2]=='C')||(R.sideL[2]=='B'&&X.sideL[2]=='C')||(R.sideL[2]=='B'&&X.sideL[2]=='A')||(R.sideL[2]=='C'&&X.sideL[2]=='A')||(R.sideL[2]=='C'&&X.sideL[2]=='B')){
		if((R.sideL[2]=='A'&&X.sideL[2]=='C')||(R.sideL[2]=='C'&&X.sideL[2]=='A')){
		cout<<"1110"<<endl;
		return 0;
		}
		cout<<"1111"<<endl;
		return 0;
	}
	cout<<"1100"<<endl;
	return 0;
} 
