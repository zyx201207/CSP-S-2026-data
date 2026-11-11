#include <bits/stdc++.h>
using namespace std;
int main(){
	int r,x;
	string R,X; 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>R>>x>>X;
	if(r==x){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(R[1]==X[1]&&R[0]==X[0]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(R[2]<='C'&&X[2]<='C'||R[2]>'C'&&X[2]>'C'){
		cout<<1;
		if(R[2]-1==X[2]||R[2]+1==X[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<"00";
	}
	
	return 0;
}
