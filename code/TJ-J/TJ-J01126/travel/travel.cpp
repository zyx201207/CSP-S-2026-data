#include<bits/stdc++.h>
using namespace std; 
string s1,c1,s2,c2;
int x=0,x1=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1!=s2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(c1[0]!=c2[0]||c1[1]!=c2[1])
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(c1[2]<'D') x+=1;
	if(c2[2]<'D') x1+=1;
	if(x!=x1)
	{
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(c1[2]-c2[2]==1||c2[2]-c1[2]==1)
	{
		cout<<"1";
		return 0;
	}
	cout<<"0";
	return 0;
}
