#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string ab,bc;
	cin>>a>>ab>>b>>bc;
	if(a==b){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(ab[0]+ab[1]==bc[0]+bc[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((ab[2]=='D'&&bc[2]=='F')||(ab[2]=='F'&&bc[2]=='D')){
		cout<<"11";
		return 0;
	}
	if(ab[2]=='C'&&bc[2]=='D'||bc[2]=='C'&&ab[2]=='D'){
		cout<<"00";
		return 0; 
	}
	if(ab[2]==bc[2]+1||ab[2]==bc[2]-1){
		cout<<"11";
		return 0;
	}
	if(((ab[2]>='A'&&ab[2]<='C')&&(bc[2]>='D'&&bc[2]<='F'))||((bc[2]>='A'&&bc[2]<='C')&&(ab[2]>='D'&&ab[2]<='F'))){
		cout<<"00";
	}
	else{
		cout<<"10";
	}
	return 0;
}		
