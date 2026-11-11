#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(sa[0]==sb[0]&&sa[1]==sb[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((sa[2]>='A'&&sa[2]<='C'&&sb[2]>='A'&&sb[2]<='C')||(sa[2]>='D'&&sa[2]<='E'&&sb[2]>='D'&&sb[2]<='E')){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(sa[2]+1==sb[2]||sa[2]-1==sb[2]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
