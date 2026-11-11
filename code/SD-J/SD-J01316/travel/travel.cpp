#include<iostream> 
#include<cstring>
#include<string>
using namespace std;

string a,b,c,d;
bool f1=false,f2=false,f3=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		f1=true;	
	}else{
		cout<<0;
		f1=false; 
	}
	
	string p1="";
	p1+=b[0];
	p1+=b[1];
	string p2="";
	p2+=d[0];
	p2+=d[1];
	if(p1==p2&&f1)	{
		cout<<1;
		f2=true;
	}else{
		cout<<0;
		f2=false;
	}
	
	if(((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C') || ((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))) && f2){
		cout<<1;
		f3=true;
	}else{
		cout<<0;
		f3=false;
	}
	
	if(((b[2]=='A'&&d[2]=='B') || (b[2]=='B'&&(d[2]=='C'||d[2]=='A')) || (b[2]=='C'&&d[2]=='B') || (b[2]=='D'&&d[2]=='F') || (b[2]=='F'&&d[2]=='D')) &&f3){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
