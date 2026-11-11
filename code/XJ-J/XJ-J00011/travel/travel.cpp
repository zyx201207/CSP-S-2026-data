#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in",r,stdin);
	freopen("travel.out",w,stdout);
	string a,b;
	string A,B;
	cin>>a>>A>>b>>B;
	if(a!=b){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
	}
	
	if(A[0]==B[0]&&A[1]==B[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(A[2]<=2&&B[2]<=2||A[2]>2&&B[2]>2){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(A[2]-B[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
