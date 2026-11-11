#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
string p1,p2;
map<char,int>mp;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char ch1=s1[2],ch2=s2[2];
	a=(c1==c2);
	p1=s1[0]+s1[1];
	p2=s2[0]+s2[1];
	b=(a&&(p1==p2));
	mp['A']=mp['B']=mp['C']=1,mp['D']=mp['F']=2;
	c=(b&&(mp[ch1]==mp[ch2]));
	d=((ch1=='A'&&ch2=='B')||(ch2=='A'&&ch1=='B')||(ch1=='B'&&ch2=='C')||(ch2=='B'&&ch1=='C')||(ch1=='D'&&ch2=='F')||(ch2=='D'&&ch1=='F'));
	d=(d&&c);
	cout<<a<<b<<c<<d;
	return 0;
}