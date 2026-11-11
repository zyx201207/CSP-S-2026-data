#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2)
	{
		cout<<1;
	}
	string R,X;
	for (int i=0;i<s1.length();i++)
	{
	
		R[i]=s1[i];
	}
	for (int i=0;i<s2.length();i++)
	{
		X[i]=s2[i];
	}
	if (R==X)cout<<1;
	R=s1[s1.length()];
	X=s2[s2.length()];
	if (R=="A" || R=="B" || R=="C" && X=="A" || X=="B" || X=="C")
	{
		cout<<1;
	}
	else if (R=="D" || R=="F" && X=="D" || X=="F")
	{
		cout<<1;
	}
	char a=s1[s1.length()];
	char b=s2[s2.length()];
	if (a-1==b || a+1==b)cout<<1;
	return 0;
}