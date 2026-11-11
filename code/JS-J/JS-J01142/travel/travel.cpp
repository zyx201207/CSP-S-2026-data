#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,a1,c=0,c1=0,d,d1;
	cin>>a;
	string b,b1;
	cin>>b;
	cin>>a1>>b1;
	for(int i=0;i<3;i++)
	{
		if(b[i]>='0'&&b[i]<='9')
		{
			c*=10;
			c+=b[i]-'0';
		}
		else
		{
			d=b[i]-'A'+1;
		}
	}
	for(int i=0;i<3;i++)
	{
		if(b1[i]>='0'&&b1[i]<='9')
		{
			c1*=10;
			c1+=b1[i]-'0';
		}
		else
		{
			d1=b1[i]-'A'+1;
		}
	}
	if(a1==a)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(c==c1&&a1==a)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((c==c1)&&(a1==a)&&((d<4&&d1<4)or(d>3&&d1>3)))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((c==c1)&&(a1==a)&&(((d<4&&d1<4)or(d>3&&d1>3))&&((d-d1==1)or(d-d1==-1))))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
