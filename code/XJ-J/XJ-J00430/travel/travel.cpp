#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int flag=0;
	if(a==c){
		cout<<1;
	}
	else {
		cout<<0;
		flag=1;
	}
	int x=0,y=0;
	if(b[0]-d[0]==0&&b[1]-d[1]==0&&flag==0){
		cout<<1;
	}
	else {
		cout<<0;
		flag=1;
	}
	if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'&&flag==0){
		cout<<1;
		x=1;
	}
	else if(b[2]>='D'&&b[2]<='E'&&d[2]>='D'&&d[2]<='E'&&flag==0){
		cout<<11;
		y=1;
	}
	else {
		cout<<00;
		flag=1;
	}
	if(x==1&&b[2]=='A'&&d[2]=='B'){
		cout<<1;
	}
	else if(x==1&&b[2]=='B'&&d[2]=='A'){
		cout<<1;
	}
	else if(x==1&&b[2]=='B'&&d[2]=='C'){
		cout<<1;
	}
	else if(x==1&&b[2]=='C'&&d[2]=='B'){
		cout<<1;
	}
	else if(y!=1)cout<<0;
	
	return 0;
}
