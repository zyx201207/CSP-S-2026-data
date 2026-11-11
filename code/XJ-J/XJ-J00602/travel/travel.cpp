#include<bits/stdc++.h>
using namespace std;
long long int a[1005]={0},c1,c2,i;
string s1,s2,x,y;
int main()
{
	preopen("travel.in","r",stdin);
	preopen("travel.out","w",stdout);
	cin>>c1;
	cin>>s2;
	cin>>c2;
	cin>>s2;
	if(c1==c2)
	{
		a[1]=1;
		cout<<a[1];
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	
	if(s1[0]==s1[0]&&s1[1]==s1[1])
	a[2]=1;
	else
	a[2]=0;
	
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
	a[3]=1;
	if(s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F')
	a[3]=1;
	
	if(s1[2]=='A'&&s2[2]=='B')
	a[4]=1;
	else
	if(s1[2]=='B'&&s2[2]=='A')
	a[4]=1;
	else
	if(s1[2]=='B'&&s2[2]=='C')
	a[4]=1;
	else
	if(s1[2]=='C'&&s2[2]=='B')
	a[4]=1;
	else
	if(s1[2]=='D'&&s2[2]=='F')
	a[4]=1;
	else
	if(s1[2]=='F'&&s2[2]=='D')
	a[4]=1;
	else
	a[4]=0;
	cout<<a[2]<<a[3]<<a[4];
	return 0;
}