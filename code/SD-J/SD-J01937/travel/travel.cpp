#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cc,ss,ac,ak,wz1,wz2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++)
		cc=cc*10+c1[i]-'0';
	for(int i=0;i<c2.size();i++)
		ac=ac*10+c2[i]-'0';
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')
			ss=ss*10+s1[i]-'0';
		else
			wz1=s1[i]-'A'+1;
	}
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]>='0'&&s2[i]<='9')
			ak=ak*10+s2[i]-'0';
		else
			wz2=s2[i]-'A'+1;
	}
	if(cc==ac&&cc!=1&&cc!=16)
	{
		printf("1");
		if(ss==ak)
		{
			printf("1");
			if(wz1>=4&&wz2>=4)
			{
				printf("11");
			}
			else if(wz1<=3&&wz2<=3)
			{
				printf("1");
				if(wz1==2||wz2==2)
				{
					printf("1");
				}
				else
				{
					printf("0");
				}
			}
			else
			{
				printf("00");
			}
		}
		else
		{
			printf("000");
		}
	}
	else
	{
		printf("0000");
	}
	return 0;
}
