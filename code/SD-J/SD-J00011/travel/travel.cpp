#include<iostream>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		printf("1");
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			printf("1");
			char t1=s1[2],t2=s2[2];
			if((t1=='A' || t1=='B' || t1=='C') && (t2=='A' || t2=='B' || t2=='C'))
			{
				printf("1");
				if((t1=='A' && t2=='B') || (t1=='B' && t2=='C'))
					printf("1");
				else
					printf("0");
			}
				
			else if((t1=='E' || t1=='F') && (t2=='E' || t2=='F'))
				printf("11");
			else
				printf("00");
		}
		else
			printf("000");
	}
	else
		printf("0000");
	return 0;
}
