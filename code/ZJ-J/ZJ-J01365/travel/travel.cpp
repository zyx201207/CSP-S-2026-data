#include<bits/stdc++.h>
using namespace std;

string c1,z1;
string c2,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>z1>>c2>>z2;
	if(c1==c2)cout<<1;
	else cout<<0;
	string s,s1;
	s+=z1[0];
	s+=z1[1];
	s1+=z2[0];
	s1+=z2[1];
	if(c1==c2&&s==s1)cout<<1;
	else cout<<0;
	char ch1=z1[2],ch2=z2[2];
	if(c1==c2&&s==s1&&(ch1>='D'&&ch2>='D'||ch1<='C'&&ch2<='C'))cout<<1;
	else cout<<0;
	bool r=0;
	if(ch1=='A'&&ch2=='B')r=1;
	else if(ch1=='B'&&ch2=='C')r=1;
	else if(ch1=='D'&&ch2=='F')r=1;
	if(c1==c2&&s==s1&&(ch1>='D'&&ch2>='D'||ch1<='C'&&ch2<='C')&&r)cout<<1;
	else cout<<0;
	return 0;
}