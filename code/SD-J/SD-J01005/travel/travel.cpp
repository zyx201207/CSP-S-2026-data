#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,z1,z2;
	cin>>c1>>z1>>c2>>z2;
	if(z1[2]=='F'){
		z1[2]='E';
	}
	if(z2[2]=='F'){
		z2[2]='E';
	}
	
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	
	if((c1==c2)&&(z1[0]==z2[0]&&z1[1]==z2[1])){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	
	if((c1==c2)&&(z1[0]==z2[0]&&z1[1]==z2[1])&&((z1[2]<='C'&&z2[2]<='C')||(z1[2]>'C'&&z2[2]>'C'))){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	
	if((c1==c2)&&(z1[0]==z2[0]&&z1[1]==z2[1])&&((z1[2]<='C'&&z2[2]<='C')||(z1[2]>'C'&&z2[2]>'C'))&&(abs(z1[2]-z2[2])==1)){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
