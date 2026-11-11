#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a1[20],a2[20];
int k1,k2;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else cout<<"0";
	if(c1==c2)
	{
		for(int i=0;i<s1.size();i++)
			a1[i+1]=s1[i];	
		for(int i=0;i<s2.size();i++)
			a2[i+1]=s2[i];
		if(a1[1]==a2[1]&&a1[2]==a2[2]) 
		{
			cout<<"1";
			if((a1[3]<='C'&&a1[3]>='A')&&(a2[3]<='C'&&a2[3]>='A')) cout<<"1";
			else if((a1[3]=='D'||a1[3]=='F')&&(a2[3]=='D'||a2[3]=='F')) cout<<"1";
			else cout<<"0";
			if(a1[3]=='A') k1=1;
			if(a1[3]=='B') k1=2;
			if(a1[3]=='C') k1=3;
			if(a2[3]=='A') k2=1;
			if(a2[3]=='B') k2=2;
			if(a2[3]=='C') k2=3;
			if(abs(k1-k2)==1&&k1!=k2) cout<<"1";
			else if(((a1[3]=='D'||a1[3]=='F')&&(a2[3]=='D'||a2[3]=='F'))&&a1[3]!=a2[3]) cout<<"1";
			else cout<<"0";
		}
		else
		{
			cout<<"0"<<"0"<<"0";
			return 0;
		}
	}
	else cout<<"0"<<"0"<<"0";
	return 0;
} 
