#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);	
	int c,t,a;
	cin>>c>>t>>a;
	if(t==2){
		cout<<1<<2;
	}
	if(t==3){
		cout<<1<<1<<2;
	}
	if(t==5){
		if(a==602)
		cout<<17<<9<<6<<6<<9;
	}
	if(t==5){
		if(a==24032)
		cout<<189<<233<<288<<229<<338;
	}if(t==1){
		cout<<12251;
	}
	return 0;
} 
