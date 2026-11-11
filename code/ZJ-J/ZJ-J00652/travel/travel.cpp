#include <bits/stdc++.h>
using namespace std;
string R,R1,X,X1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>R>>R1>>X>>X1;
	if(R==X){
	 	cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(R1[0]==X1[0]&&R1[1]==X1[1]){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(R1[2]>='D'&&X1[2]>='D'){
		cout<<1;
		cout<<1;
		return 0;
	}
	
	else if(R1[2]<='C'&&X1[2]<='C'){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		return 0;
	}
	if(R1[2]-X1[2]==1||R1[2]-X1[2]==-1){
		cout<<1;
	}
	else{
		cout<<0;
	}
		
		return 0;
	 
}
