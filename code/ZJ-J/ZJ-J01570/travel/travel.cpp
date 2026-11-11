#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
string c1,c2,s1,s2;
int n,m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		printf("1");
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			printf("1");
			if('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'||'D'<=s1[2]&&s1[2]<='E'&&'D'<=s2[2]&&s2[2]<='E')
			{
				printf("1");
				if('D'<=s1[2]&&s1[2]<='E'&&'D'<=s2[2]&&s2[2]<='E')printf("1");
				else 
				{
					int x=abs(s1[2]-s2[2]);
					if(x==1)printf("1");
					else printf("0");
				}
			}
			else printf("00");
		}
		else printf("000");
	}
	else 
	{
		printf("0000");
	}
	return 0;
}
