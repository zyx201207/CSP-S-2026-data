#include<bits/stdc++.h>
using namespace std;
string num1,num2,pos1,pos2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>num1>>pos1;
	cin>>num2>>pos2;
	bool check=true;
	if(num1[0]==num2[0]&&num1[1]==num2[1]){
		cout<<1;
	}else{
		cout<<0;check=false;
	}
	
	if(check){
		if(pos1[0]==pos2[0]&&pos1[1]==pos2[1]){
			cout<<1;check=true;
		}else{
			cout<<0;check=false;
		}
	}else{
		cout<<0;
	}
	
	if(check){
		if(pos1[2]=='A'||pos1[2]=='B'||pos1[2]=='C'){
			if(pos2[2]=='A'||pos2[2]=='B'||pos2[2]=='C'){
				cout<<1;
			}else{
				cout<<0;check=false;
			}
		}else if(pos1[2]=='D'||pos1[2]=='F'){
			if(pos2[2]=='D'||pos2[2]=='F'){
				cout<<1;
			}else{
				cout<<0;check=false;
			}
		}
	}else cout<<0;
	
	bool b=0;
	if(check){
		if(pos1[2]=='A'&&pos2[2]=='B'){
			cout<<1;b=1;
		}
		if(pos1[2]=='B'&&(pos2[2]=='A'||pos2[2]=='C')){
			cout<<1;b=1;
		}
		if(pos1[2]=='C'&&pos2[2]=='B'){
			cout<<1;b=1;
		}
		if(pos1[2]=='D'&&pos2[2]=='F'){
			cout<<1;b=1;
		}
		if(pos1[2]=='F'&&pos2[2]=='D'){
			cout<<1;b=1;
		}
		if(b==0) cout<<0;
	}else{
		cout<<0;
	}
	return 0;
}
	
