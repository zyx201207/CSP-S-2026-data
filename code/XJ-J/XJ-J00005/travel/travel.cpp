#include<bits/stdc++.h>
using namespace std;
char s1[10],s2[10];
string c1,c2;
int a[10],b[10],i;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;cin>>s1;cin>>c2;cin>>s2;
	if(c1==c2)
	cout<<1;
	else
	{
	cout<<"0000";
	return 0;
}
	for(i=0;i<=3;i++)
	a[i]=s1[i];
	for(i=0;i<=3;i++)
	b[i]=s2[i];
	if(a[0]==b[0]&&a[1]==b[1])
	cout<<1;
	else
	{
	cout<<"000";
	return 0;
}
	if(s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A')
	cout<<1;
	else
	{
	cout<<"00";
	return 0;
}
	if(s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B')
	cout<<1;
	else
	cout<<0;
	return 0;
}