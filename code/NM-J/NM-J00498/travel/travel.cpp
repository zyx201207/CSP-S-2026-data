#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	if(a!=b)
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0] or s1[1]!=s2[1])
	{
		cout<<"1000";
		return 0;
	}
	int a1,b1;
	a1=s1[2]-'A'+1;
	b1=s2[2]-'A'+1;
	if(a1/4 != b1/4)
	{
		cout<<"1100";
		return 0;
	}
	if(a1==1 and b1==3)
	{
		cout<<"1110";
		return 0;
	}
	if(a1==3 and b1==1)
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
