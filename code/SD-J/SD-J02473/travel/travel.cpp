#include<iostream>
#include<cstdio>
using namespace std;
int main(){ 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,c,x,y;
	int b,d;
	cin>>a>>b>>x>>c>>d>>y;
	if(a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	if(b==d,'x'=='y'){
		cout<<0;
	}else if(b==d){
		cout<<1;
	}else{
		cout<<0;
	}
	if('x'=='D','y'=='F'){
		cout<<1;
	}else if('x'=='F','y'=='D'){
		cout<<1;
	}else if('x'=='A','y'=='B'&&'y'=='C'){
		cout<<1;
	}else if('x'=='B','y'=='C'&&'y'=='A'){
		cout<<1;
	}else if('x'=='C','y'=='B'&&'y'=='A'){
		cout<<1;
	}else if('y'=='A','x'=='B'&&'x'=='C'){
		cout<<1;
	}else if('y'=='B','x'=='C'&&'x'=='A'){
		cout<<1;
	}else if('y'=='C','x'=='B'&&'x'=='A'){
		cout<<1;
	}else{
		cout<<0;
	}
	if('x'=='A','y'=='B'){
		cout<<1;
	}else if('x'=='B','y'=='A'){
		cout<<1;
	}else if('x'=='B','y'=='C'){
		cout<<1;
	}else if('x'=='C','y'=='B'){
		cout<<1;
	}else if('x'=='C','y'=='D'){
		cout<<1;
	}else if('x'=='D','y'=='C'){
		cout<<1; 
	}else if('x'=='D','y'=='F'){
		cout<<1;
	}else if('x'=='F','y'=='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
