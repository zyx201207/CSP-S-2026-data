#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
bool flag1,flag2,flag3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	//q1
	if(c1[1]==c3[1]) {
		cout<<1;
	}
	else {
		cout<<0; flag1=true;
	}
	//q2
	if(!flag1){
		if(c2[1]==c4[1]) cout<<1;
		else {
			cout<<0; flag2=1;
		}
	}
	else{
		flag2=1; cout<<0;
 	}
 	//q3
 	if(!flag2){
		if((c2[2]>='A' && c2[2]<='C') && (c4[2]>='A' && c4[2]<='C')) cout<<1;
		else if ((c2[2]>='D' && c2[2]<='F') && (c4[2]>='D' && c4[2]<='F'))cout<<1;
		else {
			cout<<0; flag3=1;
		}
	}
	else{
		flag3=1; cout<<0;
 	}
 	//Q4
 	if(!flag3){
		if(c2[2]=='D'||c4[2]=='D') cout<<1;
		else if(abs(c2[2]-c4[2])==1) cout<<1;
		else {
			cout<<0;
		}
	}
	else{
		 cout<<0;
 	}
	return 0;
} 
