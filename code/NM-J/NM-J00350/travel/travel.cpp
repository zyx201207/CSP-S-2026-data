#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0;
	cin>>a;
	char b[5]={};
	cin>>b;
	int c=0;
	cin>>c;
	char d[5]={};
	cin>>d;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(a==c&&(b[0]-'0')*10+(b[1]-'0')==(d[0]-'0')*10+(d[1]-'0')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(a==c&&(b[0]-'0')*10+(b[1]-'0')==(d[0]-'0')*10+(d[1]-'0')&&((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(a==c&&(b[0]-'0')*10+(b[1]-'0')==(d[0]-'0')*10+(d[1]-'0')&&((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))&&(b[2]-d[2]==1||d[2]-b[2]==1)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
