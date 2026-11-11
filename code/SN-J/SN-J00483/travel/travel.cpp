#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1[0]==c2[0])
	{
		if(c1[1]==c2[1])
			a[0]=1;
	}
	else
		a[0]=0;
	if(s1[0]==s2[0])
	{
		if(s1[1]==s2[1])
			a[1]=1;
		if(a[0]==0)
			a[1]=0;
	}
	else
		a[1]=0;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	{
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
			a[2]=1;
		if(a[1]==0||a[0]==0)
			a[2]=0;
	}
	else if(s1[2]=='D'||s1[2]=='F')
	{
		if(s2[2]=='D'||s2[2]=='F')
			a[2]=1;
		if(a[1]==0||a[0]==0)
			a[2]=0;
	}
	
	else
		a[2]=0;
	if(s1[2]==s2[2]+1||s2[2]==s1[2]+1)
	{
		if(a[2]==0||a[0]==0)
			a[3]=0;
		else
			a[3]=1;
	}
	for(int i=0;i<4;i++)
	{
		printf("%d",a[i]);
	}
		
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
