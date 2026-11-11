#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
bool f1=1,f2=1,f3=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){//1
		cout<<1;
		f2=1;
	}
	else{
		cout<<0;
		f2=0;
	}
	ll a=s1[0]-'0';
	ll b=s1[1]-'0';
	ll c=s2[0]-'0';
	ll d=s2[1]-'0';
	ll p=a*10+b;
	ll q=c*10+d;
	if(p==q&&f2){//2
		cout<<1;
		f1=1;
	}
	else{
		cout<<0;
		f1=0;
	}
	if(((s1[2]>='A'&&s2[2]>='A'&&s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))&&f1&&f2){//3
		cout<<1;
		f3=1;
	}
	else{
		cout<<0;
		f3=0;
	}
	if(((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))&&f1&&f2&&f3){//4
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
