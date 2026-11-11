#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	char r,x,R,X;
	cin>>r>>R>>x>>X;
	if(r[0]==x[0]&&r[1]==x[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(R[0]==X[0]&&R[1]==X[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(R[0]==X[0]&&R[1]==X[1]){
		if(abs(R[2]-X[2])<3){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	if(abs(R[2]-X[2])==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	return 0;
} 
