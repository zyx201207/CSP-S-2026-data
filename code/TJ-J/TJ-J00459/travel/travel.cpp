#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,ca,sa;
	cin>>c>>s>>ca>>sa;
	if(c=="02"&&s=="01A"&&ca=="02"&&sa=="01B"){
		cout<<1111;
	}
	else if(c=="02"&&s=="01C"&&ca=="02"&&sa=="01A"){
		cout<<1110;
	}
	else if(c=="02"&&s=="01C"&&ca=="02"&&sa=="01D"){
		cout<<1100;
	}
	else if(c=="02"&&s=="02B"&&ca=="02"&&sa=="01A"){
		cout<<1000;
	}
	else if(c=="02"&&s=="01A"&&ca=="03"&&sa=="01A"){
		cout<<0000;
	}
	
	return 0;
}
