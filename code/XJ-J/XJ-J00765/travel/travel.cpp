#include<bits/stdc++.h>
using namespace std;
int c1,c2,f1,f2,f3,f4,a1,a2,d1,d2;
string s1,s2;
char b1,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1;//a是排；b是字母
	b1=s1[2];
	for(int i=0;i<=1;i++)
	{
		a1+=s1[i]-'0';
		a1*=10;
	}
	cin>>c2>>s2;
	b2=s2[2];
	for(int i=0;i<=1;i++)
	{
		a2+=s2[i]-'0';
		a2*=10;
	}
	a1/=10,a2/=10;
	d1=a1,d2=a2;
	if(c1==c2)
	{
		f1=1;
		if(d1==d2)
		{
			f2=1;
			if(b1<='C'&&b2<='C'||b1>='D'&&b2>='D')
			{
				f3=1;
				if(b1-1==b2||b1+1==b2)
				{
					f4=1;
				} 
			} 
		} 
	}
	if(f1==1) cout<<1;
	else cout<<0;
	if(f2==1) cout<<1;
	else cout<<0;
	if(f3==1) cout<<1;
	else cout<<0;
	if(f4==1) cout<<1;
	else cout<<0;
	return 0;
}