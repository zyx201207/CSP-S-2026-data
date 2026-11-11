#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,k=0,t=0,l=0;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b)
	{
		t++;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((c[0]==d[0]&&c[1]==d[1])&&t)
	{
		k++;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((c[2]<'D'&&d[2]<'D'||c[2]>'C'&&d[2]>'C')&&k)
	{
		l++;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((c[2]-1==d[2]&&l||c[2]+1==d[2]&&l||c[2]=='D'&&d[2]=='F'||c[2]=='F'&&d[2]=='D')&&k)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
