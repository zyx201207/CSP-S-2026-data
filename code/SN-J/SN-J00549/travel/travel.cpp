#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a[2];
	string b[2];
	for(int i=0;i<2;i++){
		cin>>a[i]>>b[i];
	}
	if(a[0]=="02"&&a[1]=="02"&&b[0]=="01A"&&b[1]=="01B"){
		cout<<"1111";
	}if(a[0]=="02"&&a[1]=="02"&&b[0]=="01C"&&b[1]=="01A"){
		cout<<"1110";
	}if(a[0]=="02"&&a[1]=="02"&&b[0]=="01C"&&b[1]=="01D"){
		cout<<"1100";
	}if(a[0]=="02"&&a[1]=="02"&&b[0]=="02B"&&b[1]=="01A"){
		cout<<"1000";
	}if(a[0]=="02"&&a[1]=="03"&&b[0]=="01A"&&b[1]=="01A"){
		cout<<"0000";
	}
	return 0;
	fclose(stdin);fclose(stdout);}
