#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2,n0,n1,n,n2,n3,nn,f=1,f1=1,f2=0;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else {
		cout<<0000;
		return 0;
	}
	n0=s1[1]-'0';
	n1=s1[2]-'0';
	n=n0*10+n1;
	n2=s2[1]-'0';
	n3=s2[2]-'0';
	nn=n2*10+n3;
	if(nn==n) {
		f2=1;
		cout<<1;
	}
	else cout<<0;
	if(f2==1&&s1[3]=='D'||f2==1&&s1[3]=='F') f=1;
	else f=0;
	if(f2==1&&s2[3]=='D'||f2==1&&s2[3]=='F') f1=1;
	else f1=0;
	if(f==1&&f1==1){
		cout<<11;
		
	} 
	else if(f==0&&f1==0){
		if(s1[3]=='A'&&s2[3]=='B') cout<<11;
		else if(s1[3]=='B'&&s2[3]=='C') cout<<11;
		else if(s2[3]=='B'&&s1[3]=='C') cout<<11;
		else if(s1[3]=='B'&&s2[3]=='A') cout<<11;
		else cout<<10;
	}
	else cout<<00;
	return 0;
} 
