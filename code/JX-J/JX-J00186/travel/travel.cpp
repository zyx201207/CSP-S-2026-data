#include<bits/stdc++.h>
using namespace std;
bool ch(char c){
	if(c=='A')return 1;
	if(c=='B')return 1;
	if(c=='C')return 1;
	return 0;
}
bool che(char x,char y){
	int d=x-y;
	if(d==1){
		if(x!='D')return 1;
	}
	else if(d==-1){
		if(y!='D')return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool b1=0,b2=0,b3=0,b4=0;
	if(a==c){
		b1=1;
		if(b.substr(0,2)==d.substr(0,2)){
			b2=1;
			if(ch(b[2])==ch(d[2])){
				b3=1;
				if(che(b[2],d[2]))b4=1;
			}
		}
	}
	cout<<b1<<b2<<b3<<b4;
	return 0;
}
