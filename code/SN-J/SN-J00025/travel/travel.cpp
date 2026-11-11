#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[2],c2[2],s1[3],s2[3];
	int a,b,rum=0,sum=0;
	for(int d=0;d<2;d++)
	{
		cin>>c1[d];
	}
	for(int d=0;d<=2;d++)
	{
		cin>>s1[d];
	}
	for(int d=0;d<2;d++)
	{
		cin>>c2[d];
		if(c2[d]==c1[d])
		rum++;
	}
	if(rum==2)
	{
	cout<<"1";
	for(int d=0;d<2;d++)
	{
		cin>>s2[d];
		if(s1[d]==s2[d])
		sum++;
	}
	cin>>s2[2];
	if(sum==2)
	{
	cout<<"1";
	if(s1[2]=='D'&&s2[2]!='F'||s2[2]=='D'&&s1[2]!='F'||s1[2]=='F'&&s2[2]!='D'||s2[2]=='F'&&s1[2]=='D')
	cout<<"00";
	else
	{
		cout<<"1";	
		a=s1[2]; b=s2[2];
		if(a+1==b||a-1==b)
		cout<<"1";
		else
		cout<<"0"; 
	}
}
else
cout<<"000";
}
else
cout<<"0000";
	return 0;
}
