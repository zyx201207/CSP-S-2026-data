#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string x;char n=b[2];
	string y;char m=d[2];
	x[0]=b[0];
	y[0]=d[0];
	x[1]=b[1];
	y[1]=d[1];
	if(a==c){
		if(x==y){
			if(n<='C'&&n>='A'&&m<='C'&&m>='A'){
				if(n=='B'||m=='B')cout<<"1111";
				else cout<<"1110"; 
			}
			else if(n=='D'&&m=='E'||n=='E'&&m=='D')cout<<"1111";
			else cout<<"1100";
			 
		}
		else cout<<"1000";
	}else{
		cout<<"0000"; 
	}
	return 0;
} 
