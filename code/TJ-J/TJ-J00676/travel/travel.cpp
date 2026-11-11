#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string bb,dd;
	cin>>a>>bb>>c>>dd;
	if(a==1||c==1||a==16||c==16){
		cout<<"0000";
		return 0; 
	}
	if(a==c){
		cout<<'1';
	}else{
		cout<<"0000"; 
		return 0;
	}
	int b=bb[0]-'0';
	b*=10;
	b+=bb[1]-'0';
	int d=dd[0]-'0';
	d*=10;
	d+=dd[1]-'0';
	if(b==d){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	char i=bb[2],j=dd[2];
	if(i<'D'&&j<'D'){
		cout<<'1';
	}else if(i>'C'&&j>'C'){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	if(i-j==1||j-i==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
