#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int n=c1[0]-'0'+(c1[1]-'0'),m=c2[0]-'0'+(c2[1]-'0');
	int n1=n/10+n%10,n2=m/10+m%10;
	if(n1==n2)cout<<'1';
	else 
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<'1';
	if(s1[2]=='C'&&s2[2]=='D')
	{
		cout<<"00";
		return 0;
	}
	if((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F')||(s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))
	{
		cout<<'1';
		if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))
		{
			cout<<'0';
		}
		else cout<<'1';
	}
	else cout<<"00";
	
	return 0;
} 
