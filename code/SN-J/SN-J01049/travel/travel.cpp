#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2;
char c,r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c;
	c1=c1*10+c-'0';
	cin>>c;
	c1=c1*10+c-'0';
	cin>>c;
	s1=s1*10+c-'0';
	cin>>c;
	s1=s1*10+c-'0';
	cin>>r;
	cin>>c;
	c2=c2*10+c-'0';
	cin>>c;
	c2=c2*10+c-'0';
	cin>>c;
	s2=s2*10+c-'0';
	cin>>c;
	s2=s2*10+c-'0';
	cin>>x;
	if(c1==c2)cout<<1;
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	if(s1==s2)cout<<1;
	else{
		cout<<"000"<<endl;
		return 0;
	}
	if(r>='A'&&x>='A'&&r<='C'&&x<='C')cout<<1;
	else if(r>='D'&&x>='D'&&r<='F'&&x<='F')cout<<1;
	else{
		cout<<"00"<<endl;
		return 0;
	}
	if(r-'A'>x-'A'){
		swap(r,x);
	}
	if((r=='A'&&x=='B')||(r=='B'&&x=='C')||(r=='D'&&x=='F')){
		cout<<1;
		return 0;
	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
}
