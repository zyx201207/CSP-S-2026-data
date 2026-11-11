//All samples are accepted expect 100pts
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
string c1,s1,c2,s2,l1,l2;
char b1,b2;
bool f1=0,f2=0,f3=0,f4=0;
int main()
{
	// Îñ±ØÉ¾³ý×¢ÊÍ£¡£¡£¡
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	b1=s1[2],b2=s2[2];
	l1=s1[0]+s1[1],l2=s2[0]+s2[1];
	if(c1==c2)
	{
		f1=1;
		if(l1==l2)
		{
			f2=1;
			if('A'<=b1&&b1<='C'&&'A'<=b2&&b2<='C')
			{
				f3=1;
				if(b2-b1==1||b1-b2==1)  f4=1;
				else f4=0;
			}
			else if((b1=='D'||b1=='F')&&(b2=='D'||b2=='F'))
			{
				f3=1;
				if((b1=='D'&&b2=='F')||(b1=='F'&&b2=='D'))  f4=1;
				else f4=0;
			}
			else f3=0;
		}
		else  f2=0;
	}
	else  f1=0;
	
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
