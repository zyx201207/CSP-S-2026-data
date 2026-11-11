#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b,a1,b1,a2,b2;
	cin>>a>>a1>>b>>b1;
	if(a1[2]=='A' || a1[2]=='B' || a1[2]=='C'){
		a2="1";
	}
	else{
		a2="2";
	}
	if(b1[2]=='A' || b1[2]=='B' || b1[2]=='C'){
		b2="1";
	}
	else{
		b2="2";
	}
	if(a==b){
		cout<<"1";
		if(a1[1]==b1[1] && a1[0]==b1[0]){
			cout<<"1";
			if(a2==b2){
				cout<<"1";
				if(a2=="2"){
					cout<<"1";
				}
				else if(a1[2]+1==b1[2] || b1[2]+1==a1[2]){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
