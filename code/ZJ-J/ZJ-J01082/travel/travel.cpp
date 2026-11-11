#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int n1,m1,n2,m2;
char x1,x2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++)
	{
		n1=n1*10+(c1[i]-'0');
	}
	for(int i=0;i<2;i++)
	{
		m1=m1*10+(s1[i]-'0');
	}
	x1=s1[2];
	for(int i=0;i<2;i++)
	{
		n2=n2*10+(c2[i]-'0');
	}
	for(int i=0;i<2;i++)
	{
		m2=m2*10+(s2[i]-'0');
	}
	x2=s2[2];
	if(n1==n2) cout<<1;
	else cout<<0;
	if(n1==n2&&m1==m2) cout<<1;
	else cout<<0;
	if(n1==n2&&m1==m2&&(((x1=='D'&&x2=='F')||(x1=='F'&&x2=='D'))||((x1=='A'&&x2=='B')||(x1=='A'&&x2=='C')||(x1=='B'&&x2=='C'))||((x2=='A'&&x1=='B')||(x2=='A'&&x1=='C')||(x2=='B'&&x1=='C')))) cout<<1;
	else cout<<0;
	if(n1==n2&&m1==m2&&(((x1=='D'&&x2=='F')||(x1=='F'&&x2=='D'))||((x1=='A'&&x2=='B')||(x1=='A'&&x2=='C')||(x1=='B'&&x2=='C'))||((x2=='A'&&x1=='B')||(x2=='A'&&x1=='C')||(x2=='B'&&x1=='C'))&&((x1=='D'&&x2=='F')||(x1=='F'&&x2=='D'))||((x1=='A'&&x2=='B')||(x1=='B'&&x2=='C'))||((x2=='A'&&x1=='B')||(x2=='B'&&x1=='C')))) cout<<1;
	else cout<<0;
	return 0;          
}   