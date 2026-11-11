#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	int p1,p2;
	char z1,z2;
	cin>>s1>>c1>>s2>>c2;
	p1=(c1[0]-'0')*10+c1[1]-'0';
	p2=(c2[0]-'0')*10+c2[1]-'0';
	z1=c1[2];
	z2=c2[2];
	if(s1!=s2)cout<<"0000";
	else if(p1!=p2)cout<<"1000";
	else if(z1<='C'&&z2>='D'||z2<='C'&&z1>='D') cout<<"1100";
	else if(z1<='C'&&z2<='C'&&abs(z1-z2)!=1)cout<<"1110";
	else cout<<"1111";
}