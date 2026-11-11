#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string qa,wa,qs,ws;
	cin>>qs>>qa>>ws>>wa;
	if(qs==ws){
		cout<<1;
		if(qa[0]==wa[0]&&qa[1]==wa[1]){
			cout<<1;
			if((qa[2]<='C'&&wa[2]<='C')||(qa[2]>'C'&&wa[2]>'C')){
				cout<<1;
				if(qa[2]+1==wa[2]||qa[2]-1==wa[2]||qa[2]+wa[2]=='D'+'F'){
					cout<<1;
				}else cout<<0;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	return 0;
}
