#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	string r,R,x,X;
	cin>>r>>R>>x>>X;
	string st="";
	if(r==x){
		st+='1';
	}
	else{
		st+='0';
	}
	if(R[0]==X[0]&&R[1]==X[1]&&st=="1"){
		st+='1';
	}
	else{
		st+='0';
	}
	if(st=="11"&&((X[2]=='A'&&R[2]=='B')||(X[2]=='A'&&R[2]=='C')||(X[2]=='B'&&R[2]=='A')||(X[2]=='B'&&R[2]=='C')||(X[2]=='C'&&R[2]=='A')||(X[2]=='C'&&R[2]=='B')||(X[2]=='D'&&R[2]=='F')||(X[2]=='F'&&R[2]=='D'))){
		st+='1';
		if((X[2]=='A'&&R[2]=='B')||(X[2]=='B'&&R[2]=='A')||(X[2]=='B'&&R[2]=='C')||(X[2]=='C'&&R[2]=='B')||(X[2]=='D'&&R[2]=='F')||(X[2]=='F'&&R[2]=='D')){
			st+='1';
		}
		else{
			st+='0';
		}
	}
	else{
		st+="00";
	}
	cout<<st<<endl;	
	
	
	return 0;
}
