#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a;
	cin>>a;
	string b;
	cin>>b;
	string c;
	cin>>c;
	string d;
	cin>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a==c&&(b[0]-'0')*10+(b[1]-'0')==(d[0]-'0')*10+(d[1]-'0')){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a==c&&(b[0]-'0')*10+(b[1]-'0')==(d[0]-'0')*10+(d[1]-'0')&&(b[2]<='C'||d[2]<='C')||(b[2]>'C'&&d[2]>'C')){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a==c&&(b[0]-'0')*10+(b[1]-'0')==(d[0]-'0')*10+(d[1]-'0')&&(b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')&&(b[2]-d[2]=='1')||(d[2]-b[2]=='1')){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
