#include<bits/stdc++.h>
using namespace std;
string ac,as,bc,bs; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ac>>as>>bc>>bs;
	if(ac!=bc){
		cout<<"0000";
	}else{
		cout<<"1";
		if((as[0]-'0')*10+as[1]-'0'!=(bs[0]-'0')*10+bs[1]-'0'){
			cout<<"000";
		}else{
			cout<<"1";
			if((as[2]<='C'&&bs[2]>='D')||(bs[2]<='C'&&as[2]>='D')){
				cout<<"00";
			}else{
				cout<<"1";
				if(abs(as[2]-bs[2])!=1){
					cout<<"0";
				}else{
					cout<<"1";
				}
			}
		}
	}
	return 0;
} 
