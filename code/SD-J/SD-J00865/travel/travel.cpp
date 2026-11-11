#include<bits/stdc++.h>
using namespace std;
char ca[21],sa[21],cb[21],sb[21];
bool flag=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	for(int i=0;i<strlen(ca);i++){
		if(ca[i]-'0'==cb[i]-'0'){
			flag=1;
		}
		else{
			flag=0;
			break;
		}
	}
	if(flag==0){
		cout<<"0";
	}
	else{
		cout<<"1";
	}
	if(flag==0){
		cout<<"00";
	}
	else if(sa[0]-'0'==sb[0]-'0'&&sa[1]-'0'==sb[1]-'0'){
		cout<<"1";
		if((sa[2]<='C'&&sb[2]<='C')||(sa[2]>='D'&&sb[2]>='D')){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"00";
	}
	if(flag==0){
		cout<<"0";
	} 
	else if((sa[0]==sb[0]&&sa[1]==sb[1])&&(sa[2]+1==sb[2]||sa[2]-1==sb[2])&&(sa[2]<='C'&&sb[2]<='C')||(sa[2]>='D'&&sb[2]>='D')&&(sa[0]-'0'==sb[0]-'0'&&sa[1]-'0'==sb[1]-'0')){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
} 
