#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FRE freopen("travel.in","r",stdin),freopen("travel.out","w",stdout);
int read()
{
	int f=1;
	int k=0,c=getchar();
	for(;!isdigit(c);c=getchar())
		if(c=='-')
			f=-1;
	for(;isdigit(c);c=getchar())
		k=k*10+(c-'0');
	return k*f;
}
bool get(char x,char y)
{
	if((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C'))
		return true;
	if((x=='E'||x=='F')&&(y=='E'||y=='F'))
		return true;
	return false;
}
int main()
{
	FRE
	int c1=read(),s1;
	char z1,z2;
	s1=(getchar()-'0')*10+getchar()-'0';
	z1=getchar();
	int c2=read(),s2;
	s2=(getchar()-'0')*10+getchar()-'0';
	z2=getchar();
	if(c1==c2)
	{
		cout<<1;
		if(s1==s2)
		{
			cout<<1;
			if(get(z1,z2))
			{
				cout<<1;
				if(z1+1==z2||z1-1==z2)
					cout<<1;
				else
					cout<<0;
			}
			else
				cout<<0<<0;
		}
		else
			cout<<0<<0<<0;
	}
	else
		cout<<0<<0<<0<<0;
	return 0;
}
