#include <bits/stdc++.h>
using namespace std;

bool p(char x, char y){
	if (x==y){
		return 1;
	}
	if (x=='A'||x=='B'||x=='C'){
		if (y=='A'||y=='B'||y=='C'){
			return 1;
		}
	}
	if (x=='D'||x=='F'){
		if (y=='D'||y=='F'){
			return 1;
		}
	}
	return 0;
}

bool o(char x,char y){
	if (x=='A'){
		if (y=='B'){
			return 1;
		}
	}
	if (x=='B'){
		if (y=='A'||y=='C'){
			return 1;
		}
	}
	if (x=='C'){
		if (y=='B'||y=='D'){
			return 1;
		}
	}
	if (x=='D'){
		if (y=='F'){
			return 1;
		}
	}
	if (x=='F'){
		if (y=='D'){
			return 1;
		}
	}
	return 0;
	
}

int main(){
	string r,r1,x,x1;
	freopen("traver.in","r",stdin);
	freopen("traver.out","w",stdout);
	cin>>r>>r1>>x>>x1; 
	
	
	
	if (r==x){
		cout<<1;
		if (r[0]==x[0]&&r[1]==x[1]){
			cout<<1;
			if (p(r1[2],x1[2])){
				cout<<1;
				
			}
			else {
				cout<<0;
			}
		}
		else {
			cout<<0;
		}
		if (o(r1[2],r1[2])){
			cout<<1;
		}
		else {
			cout<<0;
		} 
		
	}
	else {
		cout<<0<<0<<0<<0;
	}
	
	
	return 0;
}
