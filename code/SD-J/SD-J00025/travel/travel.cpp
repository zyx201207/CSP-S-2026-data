#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string xa,xb,ra,rb;
	cin>>ra>>rb>>xa>>xb;
	if(xa==ra)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	
	
	if(rb[1]==xb[1]&&rb[0]==xb[0])cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	
	
	if(rb[2]=='D'){
		if(xb[2]=='F')cout<<11;
		else cout<<0<<0;
	}
	else if(rb[2]=='F'){
		if(xb[2]=='D')cout<<11;
		else cout<<0<<0;
	}
	else if(xb[2]=='D'){
		if(rb[2]=='F')cout<<11;
		else cout<<0<<0;
	}
	else if(xb[2]=='F'){
		if(rb[2]=='D')cout<<11;
		else cout<<0<<0;
	}
	else{
		if(rb[2]=='A'&&xb[2]=='C'||rb[2]=='C'&&xb[2]=='A')cout<<10;
		else cout<<11;
	}
	
	return 0;
} 
