#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string cc1,ss1,cc2,ss2;
	cin>>cc1>>ss1>>cc2>>ss2;
	bool samecc=0,samep=0,samec=0;
	int intss1=ss1[0]*10+ss1[1],intss2=ss2[0]*10+ss2[1];

	if(cc1==cc2)
	{
		cout<<1;
		samecc=1;
	}
	else
		cout<<0;

	if(intss1==intss2&&samecc)
	{
		cout<<1;
		samep=1;
	}
	else
		cout<<0;
	
	if((ss1[2]>='A'&&ss1[2]<='C')&&(ss2[2]>='A'&&ss2[2]<='C')&&samecc&&samep)
	{
		cout<<1;
		samec=1;
	}
	else if((ss1[2]>='D'&&ss1[2]<='F')&&(ss2[2]>='D'&&ss2[2]<='F')&&samecc&&samep)
	{
		cout<<1;
		samec=1;
	}
	else
		cout<<0;
		
	int x=abs(ss1[2]-ss2[2]);
	if(x==1&&samecc&&samep&&samec)
		cout<<1;
	else
		cout<<0;
	
	return 0;
} 
