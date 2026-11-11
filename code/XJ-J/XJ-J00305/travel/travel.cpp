#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string a1,b1;
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int x=int(a1[0]-'0')*10+int(a1[1]-'0');
	int y=int(b1[0]-'0')*10+int(b1[1]-'0');
	if(x==y){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(a1[2]>='A'&&a1[2]<='C'){
		if(b1[2]>='A'&&b1[2]<='C'){
			cout<<1; 
		}else{
			cout<<0<<0;
			return 0;
		}
	}
	else if(a1[2]=='D'||a1[2]=='F'){
		if(b1[2]=='D'||b1[2]=='F'){
			cout<<1;
		}else{
			cout<<0<<0;
			return 0;
		}
	}
	char n=a1[2]+1;
	char m=b1[2]+1;
	if(n==b1[2]||m==a1[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
