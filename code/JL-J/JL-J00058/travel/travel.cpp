#include<bits/stdc++.h>
using namespace std;
char a1[5],a2[5],b1[5],b2[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",a1+1,a2+1,b1+1,b2
		+1);
	if(a1[1]!=b1[1]||a1[2]!=b1[2])
	{
		puts("0000");
		return 0;
	}
	if(a2[1]!=b2[1]||a2[2]!=b2[2])
	{
		puts("1000");
		return 0;
	}
	if(a2[3]<='C'&&b2[3]>='D'||a2[3]<='D'&&b2[3]>='C')
	{
		puts("1100");
		return 0;
	}
	if(abs(a2[3]-b2[3])!=1)
		puts("1110");
	else
		puts("1111");
	return 0;
}