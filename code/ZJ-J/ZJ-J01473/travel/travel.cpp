#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a="";
	string b="";
	string c="";
	string d="";
	int c1=0;
	int s1=0;
	int c2=0;
	int s2=0;
	cin>>a>>b>>c>>d;
	if(a==c){
		c1=1;
	}
	if(c1==1 && b[0]==d[0] && b[1]==d[1]){
		s1=1;
	}
	if(s1==1){
		if(b[2]>='A' && b[2]<='C' && d[2]>='A' && d[2]<='C'){
			c2=1;
		}
		else if(b[2]>='D' && b[2]<='E' && d[2]>='D' && d[2]<='E'){
			c2=1;
		}
	}
	if(c2==1 && abs(b[2]-d[2])==1){
		s2=1;
	}
	cout<<c1<<s1<<c2<<s2;
	return 0;
}