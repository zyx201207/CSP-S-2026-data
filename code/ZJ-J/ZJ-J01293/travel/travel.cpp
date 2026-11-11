#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const bool F=0,T=1;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;//x
	bool a,b,c,d;
	string s1,s2;//w
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		a=T;
	} else {
		a=F;
	}
	if((s1[0]==s2[0]&&s1[1]==s2[1])&&a) {
		b=T;
	} else {
		b=F;
	}
	if(((s1[2]<='C'&&s2[2]<='C')||
	        (s1[2]>='D'&&s2[2]>='D'))&&b) {
		c=T;
	} else {
		c=F;
	}
	if((abs(s1[2]-s2[2])==1)&&c) {
		d=T;
	} else {
		d=F;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
