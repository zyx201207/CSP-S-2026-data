#include<bits/stdc++.h>
using namespace std;
char sa[5],ca[5],sb[5],cb[5];
int a,b;
bool f1;
bool f2;
bool f3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sa>>ca>>sb>>cb;
	if(sa[0]==sb[0]&&sa[1]==sb[1])
	{
		printf("1");
		f1=true;
	}
	else 
	{
		printf("0");
		f1=false;
	}
	if(ca[0]==cb[0]&&ca[1]==cb[1]&&f1)
	{
		printf("1");
		f2=true;
	}
	else 
	{
		printf("0");
		f2=false;
	}
	a=ca[2]-'A'+1;
	b=cb[2]-'A'+1;
	if((a<=3&&b<=3||a>3&&b>3)&&f2)
	{
		f3=true;
		printf("1");
	}
	else 
	{
		f3=false;
		printf("0");
	}
	if(abs(a-b)==1&&f3)
		printf("1");
	else printf("0");
	return 0;
}