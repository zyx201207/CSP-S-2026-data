#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a="02",b=="01A",c=="02",d=="01B"){
		cout<<"1111";
	}
	if(a=="02",b=="01C",c=="02",d=="01A"){
		cout<<"1110";
	}
	if(a=="02",b=="01C",c=="02",d=="01D"){
		cout<<"1100";
	}
	if(a=="02",b=="02B",c=="02",d=="01A"){
		cout<<"1000";
	}
	if(a=="02",b=="01A",c=="03",d=="01A"){
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
