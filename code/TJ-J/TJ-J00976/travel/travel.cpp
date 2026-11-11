#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int x=0,y=0;
int a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	} 
	for(int i=0;i<2;i++)
	{
		x+=(s1[i]-'0');
		y+=(s2[i]-'0');
		x*=10;
		y*=10;
	}
	if(x==y) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	} 
	a=int(s1[s1.size()-1]-'A');
	b=int(s2[s2.size()-1]-'A');
	if(a==5) a--;
	if(b==5) b--;
	if(!((a<=2&&b<=2)||(a>2&&b>2)))
	{
		cout<<"00";
		return 0;
	}
	else
	{
		cout<<1;
		if(abs(a-b)==1) cout<<1;
		else cout<<0;
		
	}
	return 0;
} 
