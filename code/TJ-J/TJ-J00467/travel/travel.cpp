#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,a3,a4;
	cin>>a1>>a2>>a3>>a4;
	if(a1==a3){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(a2[0]==a4[0]&&a2[1]==a4[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((a2[2]>='A'&&a2[2]<='C')&&(a4[2]>='A'&&a4[2]<='C')){
		cout<<"1";
		if(a2[2]-a4[2]==-1||a2[2]-a4[2]==1){
			cout<<"1";
		}
		else cout<<"0";
	}
	else if((a2[2]>='D'&&a2[2]<='F')&&(a4[2]>='D'&&a4[2]<='F')){
		cout<<"11";
	}
	else cout<<"00";
	
	return 0;
}
