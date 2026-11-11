#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string s="\n";
	if(c1!=c2) 
	{
		cout<<"0000";
		return 0;
	}
	int a1=(s1[0]-48)*10+s1[1]-48;
	int a2=(s2[0]-48)*10+s2[1]-48;
	char b1=s1[2],b2=s2[2];
	if(a1!=a2)
	{
		cout<<"1000";
		return 0;
	}
	if((b1>='D'||b2>='D')&&(b1<'D'||b2<'D'))
	{
		cout<<"1100";
		return 0;
	}
	if(abs(int(b1-b2))!=1)
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
 } 
