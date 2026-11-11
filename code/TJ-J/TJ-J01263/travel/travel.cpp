#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int a,c,cx,p,gdc,xl,paib,paid;
char gdcb,gdcd;
string b,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	paib=(b[0]-'0')*10+(b[1]-'0');
	paid=(d[0]-'0')*10+(d[1]-'0');
	gdcb=b[2];
	gdcd=d[2];
	if(a==c&&a!=1&&a!=16)
	{
		cx=1;
		if(paib==paid)
		{
			p=1;
			if((gdcb=='A'&&gdcd=='B')||(gdcb=='B'&&(gdcd=='A'||gdcd=='C'))||(gdcb=='C'&&gdcd=='B'))
			{
				xl=1;
			}
			if((gdcb=='D'&&gdcd=='F')||(gdcb=='F'&&gdcd=='D'))
			{
				xl=1;
			}
			if(gdcb>='A'&&gdcb<='C'&&gdcd>='A'&&gdcd<='C')
			{
				gdc=1;
			}
			if((gdcb=='D'||gdcb=='F')&&(gdcd=='D'||gdcd=='F'))
			{
				gdc=1;
			}
		}
	}
	cout<<cx<<p<<gdc<<xl;
	return 0;
 } 
