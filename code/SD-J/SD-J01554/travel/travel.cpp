#include<bits/stdc++.h>
using namespace std;
char c1[5],c2[5],s1[5],s2[5];
int flag;

bool check(char a)
{
	if(a=='A'||a=='B'||a=='C')
		return 1;
	return 0;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%s%s%s%s",&c1,&s1,&c2,&s2);
	
	flag=1;
	for(int i=0;i<2;i++)
		if(c1[i]!=c2[i])
		{
			flag=0;
			break;
		}
	printf("%d",flag);
	if(flag==0)
	{
		printf("000");
		return 0;
	}
	
	flag=1;
	for(int i=0;i<2;i++)
		if(s1[i]!=s2[i])
		{
			flag=0;
			break;
		}
	printf("%d",flag);
	
	if(flag==0||check(s1[2])!=check(s2[2]))
	{
		printf("00");
		return 0;
	}
	printf("1");
	
	if(s1[2]==s2[2]+1||s1[2]==s2[2]-1)
		printf("1");
	else printf("0");
	return 0;
}
