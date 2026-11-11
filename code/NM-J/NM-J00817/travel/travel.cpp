#include<bits/stdc++.h>
using namespace std;
string c1 ,c2,s1,s2 ;
int cc1,cc2,ss1,ss2,w,e;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]=='0')cc1=c1[1]-'0';
	else {
		cc1=c1[0]-'0';
		cc1*=10;
		cc1+=c1[1]-'0';
	}
	if(c2[0]=='0')cc2=c2[1]-'0';
	else {
		cc2=c2[0]-'0';
		cc2*=10;
		cc2+=c2[1]-'0';
	}
	if(s1[0]=='0')ss1=s1[1]-'0';
	else {
		ss1=s1[0]-'0';
		ss1*=10;
		ss1+=s1[1]-'0';
	}
	if(s2[0]=='0')ss2=s2[1]-'0';
	else {
		ss2=s2[0]-'0';
		ss2*=10;
		ss2+=s2[1]-'0';
	}
	w=s1[2];
	e=s2[2];
	int q=w-e;
	if(cc1==cc2&&cc1!=1&&cc1!=16) cout<<1;
	else {
		cout<<0<<0<<0<<0;	
		return 0;
	}
	if(ss1==ss2) cout<<1;
	else {	cout<<0<<0<<0;	
		return 0;}
	if(w<='C'&&e<='C'){
		cout<<1;
		if(q==1||q==-1) cout<<1;
		else cout<<0;
	}
	else if(w>='D'&&e>='D') {
		cout<<1<<1;
	}
	else cout<<0<<0;
	return 0;
}
