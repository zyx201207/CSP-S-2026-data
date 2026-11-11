#include<bits/stdc++.h>
using namespace std;
int num;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a=="01"||a=="16"||c=="01"||c=="16"){
		return 0;
	}
	if(a==c){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((b[2]<='C'&&d[2]<='C'&&b[2]>='A'&&d[2]>='A')||(b[2]>='D'&&d[2]>='D')){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	num=int(b[2]-d[2]);
	if(num<0){
		num=-num;
	} 
	if(num==1){
		cout<<"1";
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}
