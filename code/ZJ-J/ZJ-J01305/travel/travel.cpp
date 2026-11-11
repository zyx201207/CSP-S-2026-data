#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(sa[0]==sb[0] && sa[1]==sb[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((sa[2]<='C' && sb[2]<='C') || (sa[2]>'C' && sb[2]>'C')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(sa[2]>'C' && sb[2]>'C'){
		cout<<"1";
	}
	if(sa[2]<='C' && sb[2]<='C'){
		if((sa[2]<='B' && sb[2]<='B') || (sa[2]>='B' && sb[2]>='B')){
			cout<<"1";
		}else{
			cout<<"0";
			return 0;
		}
	}
	return 0;
}
