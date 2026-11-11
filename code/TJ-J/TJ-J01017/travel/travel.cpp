#include<bits/stdc++.h>
using namespace std;
long long arr[100][100]; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long rc,xc,rs1,xs1;
	char rs2,xs2;
	cin>>rc>>rs1>>rs2>>xc>>xs1>>xs2;
	if(rc==xc){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(rs1==xs1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(rs1==xs1){
		if(rs2=='A'||rs2=='B'||rs2=='C'&&xs2=='A'||xs2=='B'||xs2=='C'){
			cout<<"1";
			if(rs2=='B'||xs2=='B'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			if(rs2=='D'||rs2=='F'&&xs2=='D'||xs2=='F'){
				cout<<"11";
			}
		}
	}else{
		cout<<"00";
	}
	return 0;
} 
