#include <iostream>
#include <string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a;
	string b;
	string c;
	string d;
	cin>>a>>b>>c>>d;
	bool f1=false;
	bool f2=false;
	bool f3=false;
	bool f4=false;
	if(a==c){
		f1=true;
	}
	if(f1==true){
		cout<<1;
	}else{
		cout<<0;
	}
	if(f1==true&&b[0]==d[0]&&b[1]==d[1]){
		f2=true;
	}
	if(f2==true){
		cout<<1;
	}else{
		cout<<0;
	}
	if(f2==true&&b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'){
		f3=true;
	}else if(f2==true&&b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'){
		f3=true;
	}
	if(f3==true){
		cout<<1;
	}else{
		cout<<0;
	}
	if(f3==true&&b[2]=='A'&&d[2]=='B'){
		f4=true;
	}else if(f3==true&&b[2]=='B'&&d[2]=='A'){
		f4=true;
	}else if(f3==true&&b[2]=='C'&&d[2]=='B'){
		f4=true;
	}else if(f3==true&&b[2]=='B'&&d[2]=='C'){
		f4=true;
	}else if(f3==true&&b[2]=='D'&&d[2]=='F'){
		f4=true;
	}else if(f3==true&&b[2]=='F'&&d[2]=='D'){
		
		f4=true;
	}
	if(f4==true){
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	
	
	
	return 0;
}
