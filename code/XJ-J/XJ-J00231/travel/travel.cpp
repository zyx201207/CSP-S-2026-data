#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int a1=0,b1=0,c1=0,e=0;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		a1+=1;
	}
	else{
		cout<<0;
	}
	if(b[0]==d[0] and b[1]==d[1] and a1==1){
		cout<<1;
		b1+=1;
	}
	else{
		cout<<0;
	}
	if(a1==1 and b1==1 and b1==1){
		if(b[2]=='C' and d[2]=='D'){
			cout<<0;
			e+=1;
		}
		if(b[2]=='D' and d[2]=='C'){
			cout<<0;
			e+=2;
		}
		if(e==0){
			cout<<1;
			c1+=1;
		}
		
	}
	else{
		cout<<0;
	}
	if(a1==1 and b1==1 and c1==1){
		if(b[2]+1==d[2] or b[2]-1==d[2]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
} 
