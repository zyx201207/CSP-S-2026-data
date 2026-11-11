#include<bits/stdc++.h>
using namespace std;
int main()
{
    	freopen("travel.in","r",stdin);
    	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int v1=0,v2=0,v3=0;
	if(c1==c2)v1=1;
	int g=(s1[0]-'0')*10+(s1[1]-'0');
	int h=(s2[0]-'0')*10+(s2[1]-'0');
	if(g==h&&v1==1)v2=1;
	char cv=s1[2],cb=s2[2];
	int jv,jb;
	if(cv=='F'||cv=='D')jv=1;
	else jv=0;
	if(cb=='F'||cb=='D')jb=1;
	else jb=0;
	if(jb==jv&&v2==1&&v1==1)v3=1;
	cout<<v1<<v2<<v3;
	int v4=0;
    if(v1==1&&v2==1&&v3==1)
	{
		  if(cv=='D'&&cb=='F')v4=1;
	      if(cv=='F'&&cb=='D')v4=1;
	   	  if(cv=='A'&&cb=='B')v4=1;
	   	  if(cv=='B'&&cb=='A')v4=1;
	   	  if(cv=='C'&&cb=='B')v4=1;
	   	  if(cv=='A'&&cb=='C')v4=1;
	} 
	cout<<v4;
	return 0;
}