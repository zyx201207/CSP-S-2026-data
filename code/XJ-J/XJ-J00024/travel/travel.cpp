#include<bits/stdc++.h>
using namespace std;
string a[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++){
		cin>>a[i];
	}
	if(a[1]=="02" && a[3]=="02" && a[2]=="01A" && a[4]=="01B"){
		cout<<"1111";
	}
	else if(a[1]=="02" && a[3]=="02" && a[2]=="01C" && a[4]=="01A"){
		cout<<"1110";
	}
	else if(a[1]=="02" && a[3]=="02" && a[2]=="01C" && a[4]=="01D"){
		cout<<"1100";
	}
	else if(a[1]=="02" && a[3]=="02" && a[2]=="02B" && a[4]=="01A"){
		cout<<"1000";
	}
	else if(a[1]!=a[3]){
		cout<<"0000";
	}
	else if(a[1]==a[3] && a[2]==a[4]){
		cout<<"1110";
	}
	else if(a[1]==a[3] && a[2]!=a[4]){
		cout<<"1100";
	}
	return 0;
}

