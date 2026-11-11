#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,st;
int as,bs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	st+='1';
	else st+='0';
	as=s1[0]*10+s1[1];
	bs=s2[0]*10+s2[1];
	if(as==bs)
	st+='1';
	else st+='0';
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
	st+='1';
	else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')
		st+='1';
	else{st+='0';st+='0';cout<<st;return 0;
	}
	
	if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
	st+='1';
	else if((s1[2]+1)==s2[2]||(s2[2]+1)==s1[2])
	st+='1';
	else st+='0';
	cout<<st;
	return 0;
}