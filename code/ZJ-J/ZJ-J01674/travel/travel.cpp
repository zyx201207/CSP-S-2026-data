#include <bits/stdc++.h>
using namespace std;
char c1[3],s1[4],c2[3],s2[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1,s1,c2,s2);
	if(c1[0]!=c2[0]||c1[1]!=c2[1]) printf("0000");
	else
	{
		printf("1");
		if(s1[0]!=s2[0]||s1[1]!=s2[1]) printf("000");
		else
		{
			printf("1");
			if((s1[2]>'C')!=(s2[2]>'C')) printf("00");
			else
			{
				printf("1");
				if(max(s1[2],s2[2])-min(s1[2],s2[2])>1) printf("0");
				else printf("1");
			}
		}
	}
	return 0;
}
