#include<bits/stdc++.h>
using namespace std;
int type[128];
string c1,s1,c2,s2;
bool flag;
char tmp[11];
void read(string &s)
{
	scanf("%s",tmp);
	s=tmp;
	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	type['A']=type['B']=type['C']=1;
	type['D']=type['F']=2;
	read(c1); read(s1); read(c2); read(s2);
	if(c1==c2)
	{
		flag=1;
		putchar('1');
	}
	else
		putchar('0');
	if(flag&&s1.substr(0,2)==s2.substr(0,2))
		putchar('1');
	else
	{
		flag=0;
		putchar('0');
	}
	if(flag&&type[s1[2]]==type[s2[2]])
		putchar('1');
	else
	{
		flag=0;
		putchar('0');
	}
	if(flag&&((type[s1[2]]==1&&abs(s1[2]-s2[2])==1)||type[s1[2]]==2))
		putchar('1');
	else
		putchar('0');
	return 0;
}
