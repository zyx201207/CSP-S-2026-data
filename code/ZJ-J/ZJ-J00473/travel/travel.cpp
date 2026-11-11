#include<bits/stdc++.h>
using namespace std;
int ac,bc;
string as,bs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ac>>as>>bc>>bs;
	if(ac==bc){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(as[0]==bs[0]&&as[1]==bs[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((as[2]<='C'&&bs[2]<='C')||(as[2]>='D'&&bs[2]>='D')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(as[2]-bs[2])==1){
		cout<<"1";
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}