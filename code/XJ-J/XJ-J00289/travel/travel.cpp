#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int ce1,ce2,ce3;
	ce3=abs(int(s1[2])-int(s2[2]));
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') ce1=1;
	else ce1=2;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') ce2=1;
	else ce2=2;
	
	if(c1==c2)
		cout<<"1";
	else
	{	
		cout<<"0000";
		return 0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1])
		cout<<"1";
	else
	{	
		cout<<"000";
		return 0;
	}
	
	if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))
		cout<<"1";
	else
	{	
		cout<<"00";
		return 0;
	}
	
	if(ce3==1)
		cout<<"1";
	else
	{	
		cout<<"0";
		return 0;
	}
	return 0;
 } 
