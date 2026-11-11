#include<bits\stdc++.h>
using namespace std;
string a,b,a1,b1,x,y;
int c,d;
bool f=true,f1=true,f2=true;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	cin>>a>>a1>>b>>b1;
	x=a1[2];
	y=b1[2];
	for(int i=0;i<2;i++)
	{
		c*=10;
		c+=a1[i]-'0';
	}
	for(int i=0;i<2;i++)
	{
		d*=10;
		d+=b1[i]-'0';
	}
	if(a==b)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		f=false;
		f2=false;
	}
	if(c==d&&f2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		f=false;
		f1=false;
	}
	if(a1[2]-'A'<=2&&b1[2]-'A'<=2&&f1)
	{
		cout<<1;
	}
	else if(a1[2]-'A'>=3&&b1[2]-'A'>=3&&f1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		f=false;
	}
	if(f)
	{
		int t;
		t=abs((a1[2]-'A')-(b1[2]-'A'));
		if(t==1) cout<<1;
		else cout<<0;
	}
	else
	{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
