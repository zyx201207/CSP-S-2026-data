#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string a,b;
string x,y;
bool p=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	if(a==x){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a==x&&b[0]==y[0]&&b[1]==y[1]){
		cout<<1;
		p=true;
	}else{
		cout<<0;
	}
	if(p){
		if(b[2]=='A'&&y[2]=='B'){
			cout<<1;
		}else if(b[2]=='B'&&y[2]=='A'){
			cout<<1;
		}else if(b[2]=='B'&&y[2]=='C'){
			cout<<1;
		}else if(b[2]=='C'&&y[2]=='B'){
			cout<<1;
		}else if(b[2]=='D'&&y[2]=='F'){
			cout<<1;
		}else if(b[2]=='F'&&y[2]=='D'){
			cout<<1;
		}else if(b[2]=='A'&&y[2]=='C'){
			cout<<1;
		}else if(b[2]=='C'&&y[2]=='A'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(p){
		if(b[2]=='A'&&y[2]=='B'){
			cout<<1;
		}else if(b[2]=='B'&&y[2]=='A'){
			cout<<1;
		}else if(b[2]=='B'&&y[2]=='C'){
			cout<<1;
		}else if(b[2]=='C'&&y[2]=='B'){
			cout<<1;
		}else if(b[2]=='D'&&y[2]=='F'){
			cout<<1;
		}else if(b[2]=='F'&&y[2]=='D'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
}
