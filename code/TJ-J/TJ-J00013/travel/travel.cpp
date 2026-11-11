#include<bits/stdc++.h>
using namespace std;
string R,r,X,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>R>>r>>X>>x;
	if(R[0]==X[0] and R[1]==X[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;	
		return 0;
	}
	if(r[1]==x[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(r[1]==x[1]){
		if(r[2]=='A' and (x[2]=='B'or x[2]=='C')){
			cout<<1;
		}
		else if(r[2]=='B' and (x[2]=='A'or x[2]=='C')){
			cout<<1;
		}
		else if(r[2]=='C' and (x[2]=='A'or x[2]=='B')){
			cout<<1;
		}
		else if(r[2]=='D' and x[2]=='F'){
			cout<<1;
		}
		else if(r[2]=='F' and x[2]=='D'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(r[1]==x[1]){
		if(r[2]=='A' and x[2]=='B'){
			cout<<1;
		}
		else if(r[2]=='B'and x[2]=='A'){
			cout<<1;
		}
		else if(r[2]=='B'and x[2]=='C'){
			cout<<1;
		}
		else if(r[2]=='C'and x[2]=='B'){
			cout<<1;
		}
		else if(r[2]=='D'and x[2]=='F'){
			cout<<1;
		}
		else if(r[2]=='F'and x[2]=='D'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}else{
		cout<<0;
	}	

	return 0;
} 
