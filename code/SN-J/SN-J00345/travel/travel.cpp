#include<bits/stdc++.h>
using namespace std;
string C1,C2,S1,S2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>C1>>C2>>S1>>S2;
	if(C1==S1) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	} 
	if(C2[0]==S2[0]&&C2[1]==S2[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	} 
	if((C2[2]=='A'&&S2[2]=='B')||(C2[2]=='A'&&S2[2]=='C')||(C2[2]=='B'&&S2[2]=='A')||(C2[2]=='B'&&S2[2]=='C')||(C2[2]=='C'&&S2[2]=='A')||(C2[2]=='C'&&S2[2]=='B')||(C2[2]=='E'&&S2[2]=='F')||(C2[2]=='F'&&S2[2]=='E')){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	} 
	if(abs(C2[2]-S2[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
