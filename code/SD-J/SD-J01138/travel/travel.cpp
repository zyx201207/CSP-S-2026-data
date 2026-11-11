#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
string a,b,c,d;
int x1,x2,x3,x4;
bool f(char a,char b){
	if(a=='A'){
		if(b=='B'||b=='C') return true;
		else return false;
	}
	else if(a=='B'){
		if(b=='A'||b=='C') return true;
		else return false;
	}
	else if(a=='C'){
		if(b=='A'||b=='B') return true;
		else return false;
	}
	else if(a=='D'){
		if(b=='F') return true;
		else return false;
	}
	else{
		if(b=='D') return true;
		else return false;
	}
}
bool f2(char a,char b){
	if(a=='A'){
		if(b=='B') return true;
		else return false;
	}
	else if(a=='B'){
		if(b=='A'||b=='C') return true;
		else return false;
	}
	else if(a=='C'){
		if(b=='B') return true;
		else return false;
	}
	else if(a=='D'){
		if(b=='F') return true;
		else return false;
	}
	else{
		if(b=='D') return true;
		else return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	for(int i=0;i<a.size();i++)x1=x1*10+(a[i]-48);
	for(int i=0;i<c.size();i++)x2=x2*10+(c[i]-48);
	if(x1==x2) cout<<1;
	else cout<<0;
	for(int i=0;i<2;i++)x3=x3*10+(b[i]-48);
	for(int i=0;i<2;i++)x4=x4*10+(d[i]-48);
	if((x3==x4)&&(x1==x2)) cout<<1;
	else cout<<0;
	if((x3==x4)&&f(b[2],d[2])&&(x1==x2)) cout<<1;
	else cout<<0;
	if((x3==x4)&&f2(b[2],d[2])&&(x1==x2)) cout<<1;
	else cout<<0;
	return 0;
}
