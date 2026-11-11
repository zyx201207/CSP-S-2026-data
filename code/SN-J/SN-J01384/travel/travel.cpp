#include<bits/stdc++.h>
using namespace std;

string j1;
string j2;
string j5;
string j6;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>j1;
	cin>>j2;
	cin>>j5;
	cin>>j6;
	if(j1==j5){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(j2[0]==j6[0] &&j2[1]==j6[1]){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(j2[2]=='A'){
		if(j6[2]=='B'){
			cout<<1;
			cout<<1; 
		}else if(j6[2]=='C'){
			cout<<1;
			cout<<0;
		}else{
			cout<<0;
			cout<<0;
		}
	}
	if(j2[2]=='B'){
		if(j6[2]=='A'){
			cout<<1;
			cout<<1; 
		}
		else if(j6[2]=='C'){
			cout<<1;
			cout<<1;
		}else{
			cout<<0;
			cout<<0;
		}
	}
	if(j2[2]=='C'){
		if(j6[2]=='B'){
			cout<<1;
			cout<<1; 
		}
		else if(j6[2]=='A'){
			cout<<1;
			cout<<0;
		}else{
			cout<<0;
			cout<<0;
		}
	}
	if(j2[2]=='D'){
		if(j6[2]=='F'){
			cout<<1;
			cout<<1; 
		}else{
			cout<<0;
			cout<<0;
		}
	}
	if(j2[2]=='F'){
		if(j6[2]=='D'){
			cout<<1;
			cout<<1; 
		}else{
			cout<<0;
			cout<<0;
		}
	}
	return 0;
}
