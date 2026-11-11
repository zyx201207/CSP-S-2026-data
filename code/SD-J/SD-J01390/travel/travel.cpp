#include<bits/stdc++.h>
using namespace std;
int fa[100010];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string pos1,pos2,pos3,pos4;
	cin>>pos1>>pos2>>pos3>>pos4;
	if(pos1==pos3) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	
//	cout<<"sdsds\n";
	if(pos2.substr(0,2)	==pos4.substr(0,2)){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
//	cout<<"sdsds\n";return 0;
	if((pos2[2]>='A'&&pos2[2]<='C'&&pos4[2]>='A'&&pos4[2]<='C' ) ||( pos2[2]>='D'&&pos2[2]<='E'&&pos4[2]>='D'&&pos4[2]<='E')){
		cout<<"1";
	}else{
		cout<<"00";
//		cout<<"sdsds\n";
		return 0;
	}
//	cout<<"dddd\n";
//	cout<<"sdsds\n";
	if(abs(pos2[2]-pos4[2])==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
//	cout<<"sdsds\n";
	return 0;
}
