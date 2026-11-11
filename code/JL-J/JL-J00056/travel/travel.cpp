#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char ce1,ce2,p1[2],p2[2];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	p1[0]=s1[0];
	p1[1]=s1[1];
	p2[0]=s2[0];
	p2[1]=s2[1];
	ce1=s1[2];
	ce2=s2[2];
	if(c1==c2)cout<<1;
	else 
	{cout<<"0000";return 0;}
	if(p1[0]==p2[0]&&p1[1]==p2[1])cout<<1;
	else {cout<<"000";return 0;}
	if(p1[0]==p2[0]&&p1[1]==p2[1]&&((ce1=='A'&&ce2=='B')||(ce1=='B'&&ce2=='A')||(ce1=='A'&&ce2=='C')||(ce1=='C'&&ce2=='A')||(ce1=='B'&&ce2=='C')||(ce1=='C'&&ce2=='B')||(ce1=='D'&&ce2=='F')||(ce1=='F'&&ce2=='D')))
	cout<<1;
	else {cout<<"00";return 0;}
	if((ce1=='A'&&ce2=='B')||(ce1=='B'&&ce2=='A')||(ce1=='B'&&ce2=='C')||(ce1=='C'&&ce2=='B')||(ce1=='D'&&ce2=='F')||(ce1=='F'&&ce2=='D'))
	cout<<1;
	else cout<<0;
	return 0;
	}
