#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int pd1=0;
	string str1,str2,str3,str4;
	cin>>str1>>str2>>str3>>str4;
	if(str1==str3){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	
	if(str2[0]==str4[0] && str2[1]==str4[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	
	if(str2[2]<=67 && str2[2]>=65 && str4[2]<=67 && str4[2]>=65){
		cout<<1;
		pd1=1;
	}else if(str2[2]<=70 && str2[2]>=68 && str4[2]<=70 && str4[2]>=68){
		cout<<1;
		pd1=2;
	}else{
		cout<<"00";
		return 0;
	}
	
	if(pd1==1){
		if(str2[2]=='A' && str4[2]=='C'){
			cout<<0;
			return 0;
		}else if(str2[2]=='C' && str4[2]=='A'){
			cout<<0;
			return 0;
		}else{
			cout<<1;
			return 0;
		}
	}else if(pd1==2){
			cout<<1;
			return 0;
	}
	return 0;
}
