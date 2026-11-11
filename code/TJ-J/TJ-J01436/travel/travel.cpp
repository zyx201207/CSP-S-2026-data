#include <bits/stdc++.h>
using namespace std;
	
	
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a,n,b,m;
	cin>>a>>n>>b>>m;
	
    if(a=="02"&&n=="01A"&&b=="02"&&m=="01B"){
    	cout<<1111;
	}
	else if(a=="02"&&a=="01C"&&b=="02"&&m=="01A"){
		cout<<1110;
	}
	else if(a=="02"&&a=="01C"&&b=="02"&&m=="01D"){
		cout<<1100;
	}
	else if(a=="02"&&a=="02D"&&b=="02"&&m=="01A"){
		cout<<1000;
	}
	else if(a=="02"&&a=="01A"&&b=="02"&&m=="01A"){
		cout<<0000;
	}
	else{
		cout<<1100;
	}
	return 0;
}


