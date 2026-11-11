#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
int a1,a2,b1,b2;
char aa1,bb1;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]=='1')
	a1+=10;
	a1+=c1[1]-'0';
	if(c2[0]=='1')
	b1+=10;
	b1+=c2[1]-'0';
	
	if(s1[0]=='1')
	a2+=10;
	a2+=s1[1]-'0';
	if(s2[0]=='1')
	b2+=10;
	b2+=s2[1]-'0';
	aa1=s1[2];
	bb1=s2[2];
	
	if(a1==b1)
	cout<<1;
	else 
	{
		cout<<"0000";
		return 0;
	}
	if(a2==b2)
	cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if(aa1>='A'&&aa1<='C'&&bb1>='A'&&bb1<='C')
	{
		cout<<1;
		if(abs(aa1-bb1)==1)
		cout<<1;
		else
		cout<<0;
	}
	else if(aa1>='D'&&aa1<='F'&&bb1>='D'&&bb1<='F')
	cout<<11;
	else
	cout<<"00";
	return 0;
}
