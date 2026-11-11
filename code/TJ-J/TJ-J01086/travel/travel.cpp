#include<bits/stdc++.h>
using namespace std;
string a0,a1,b0,b1; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a0>>a1>>b0>>b1;
	if(a0==b0){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a0==b0&&a1[0]==b1[0]&&a1[1]==b1[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a0==b0&&a1[0]==b1[0]&&a1[1]==b1[1]){
		if((a1[2]=='A'||a1[2]=='B'||a1[2]=='C')&&(b1[2]=='A'||b1[2]=='B'||b1[2]=='C')){
			cout<<"1";
		}else if((a1[2]=='D'||a1[2]=='E')&&(b1[2]=='D'||b1[2]=='E')){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	if(a0==b0&&a1[0]==b1[0]&&a1[1]==b1[1]){
		if(a1[2]=='A'&&b1[2]=='B'){
			cout<<"1";
		}else if(a1[2]=='B'&&(b1[2]=='A'||b1[2]=='C')){
			cout<<"1";
		}else if(a1[2]=='C'&&b1[2]=='B'){
			cout<<"1";
		}else if(a1[2]=='D'&&b1[2]=='E'){
			cout<<"1";
		}else if(a1[2]=='E'&&b1[2]=='D'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	return 0;
} 
