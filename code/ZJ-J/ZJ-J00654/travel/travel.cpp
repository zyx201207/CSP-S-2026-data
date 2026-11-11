#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char st1[10],st2[10],p1,p2,fp1,fp2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%s%d%s",&c1,st1+1,&c2,st2+1);
	int s1,s2;
	s1=(st1[1]-'0')*10+(st1[2]-'0'),p1=st1[3];
	s2=(st2[1]-'0')*10+(st2[2]-'0'),p2=st2[3];
	if(p1>='A' && p1<='C') fp1=1;
	else fp1=2;
	if(p2>='A' && p2<='C') fp2=1;
	else fp2=2;
	if(c1!=c2) 
	{
		printf("0000");
		return 0;
	}
	else if(c1==c2 && s1!=s2)
	{
		printf("1000");
		return 0;
	}
	else if(fp1!=fp2)
	{
		printf("1100");
		return 0;
	}
	else if(fp1==fp2)
	{
		if(fp1==2 || abs(p1-p2)==1)
		{
			printf("1111");
			return 0;
		}
		else
		{
			printf("1110");
			return 0;
		}
	}
	return 0;
}
