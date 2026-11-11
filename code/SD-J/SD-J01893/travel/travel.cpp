#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char rc[5],xc[5];
	char r[5],x[5];
	cin>>rc[1]>>rc[2];
	for(int i=1;i<=3;i++){
		cin>>r[i];
	}
	cin>>xc[1]>>xc[2];
	for(int i=1;i<=3;i++){
		cin>>x[i];
	}
	if(rc[1]==xc[1]&&rc[2]==xc[2]){
		cout<<"1";
	}else{
		cout<<"0";
		return 0;
	}
	if(r[1]==x[1]&&r[2]==x[2]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if((r[3]=='F'&&x[3]=='D')||(x[3]=='D'&&r[3]=='F')||(r[3]=='C'&&x[3]=='B')||(r[3]=='B'&&x[3]=='C')||(r[3]=='B'&&x[3]=='A')||(r[3]=='A'&&x[3]=='B')||(r[3]=='A'&&x[3]=='C')||(r[3]=='C'&&x[3]=='A')){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if((r[3]=='F'&&x[3]=='D')||(x[3]=='D'&&r[3]=='F')||(r[3]=='C'&&x[3]=='B')||(r[3]=='B'&&x[3]=='C')||(r[3]=='B'&&x[3]=='A')||(r[3]=='A'&&x[3]=='B')){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0; 
}
