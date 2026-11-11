#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a=0,b=0,c=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		a=1;
	}else cout<<0;
	if(a==1 && (s1[0]==s2[0] && s1[1]==s2[1]))
	{
		cout<<1;
		b=1;
	}else cout<<0;
	if(b==1 && (((s1[2]>='A' && s1[2]<='C') && (s2[2]>='A' && s2[2]<='C')) || ((s1[2]>='D' && s1[2]<='E') && (s2[2]>='D' && s2[2]<='E'))))
	{
		cout<<1;
		c=1;
	}else cout<<0;
	if(c==1 && abs(s1[2]-s2[2])==1)cout<<1;
	else cout<<0;
	return 0;
}