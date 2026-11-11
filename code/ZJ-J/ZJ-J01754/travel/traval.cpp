#include<bits/stdc++.h>
using namespace std;
long long rc,xc;
char rs[5],xs[5],ans[5];

void dy()
{
	for(int i=1;i<=4;i++)
	{
		ans[i]='0';
	}
}
void dia()
{
	ans[1]=1;
	for(int i=2;i<=4;i++)
	{
		ans[i]='0';
	}
}
void fin()
{
	for(int i=1;i<=4;i++)
	{
		ans[i]='1';
	}
}
void trid()
{
	for(int i=1;i<=3;i++)
	{
		ans[i]='1';
	}
	ans[4]='0';
}
int main()
{
	freopen("traval.in","r",stdin); 
	freopen("traval.out","w",stdout); 
	cin>>rc>>rs>>xc>>xs;
	if(rc!=xc) dy();
	else
	{
		if(rs[0]!=xs[0]||rs[1]!=xs[1])	dia();
		else
		{
			if(rs[2]>='D'&&xs[2]>='D')fin();
			if(rs[2]<'D'&&xs[2]<'D') 
			{
				if(rs[2]=='B'||xs[2]=='B')
				fin();
				else trid();
			}
			else
			{
				ans[1]='1';
				ans[2]='1';
				ans[3]='0';ans[4]='0';
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		cout<<ans[i];
	}
	return 0;
}
