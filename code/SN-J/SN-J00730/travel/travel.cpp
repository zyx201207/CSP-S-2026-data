//张宸铭 西安辅轮中学 SN-J00730 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen('travel.in','r' stdin)
    freopen('travel.out','w' stdout)
	string a,aa,b,bb;
	cin>>a>>aa>>b>>bb;
	if (a[0]!=b[0]||a[1]!=b[1])
	{
		cout<<"0000";
		return 0;
	}
	if (aa[0]!=bb[0]||aa[1]!=bb[1])
	{
		cout<<"1000";
		return 0;
	}
	if (aa[2]=='A'&&bb[2]=='D')
	{
		cout<<"1100";
		return 0;
	}
	if (aa[2]=='A'&&bb[2]=='D')
	{
		cout<<"1100";
		return 0;
	}
	if (aa[2]=='D'&&bb[2]=='A')
	{
		cout<<"1100";
		return 0;
	}
	if (aa[2]=='B'&&bb[2]=='D')
	{
		cout<<"1100";
		return 0;
	}
	if (aa[2]=='D'&&bb[2]=='B')
	{
		cout<<"1100";
		return 0;
	}
	if (aa[2]=='C'&&bb[2]=='D')
	{
		cout<<"1100";
		return 0;
	}
	if (aa[2]=='D'&&bb[2]=='C')
	{
		cout<<"1100";
		return 0;
	}
	if (aa[2]=='A'&&bb[2]=='E')
	{
		cout<<"1100";
		return 0;
	}
	if (aa[2]=='E'&&bb[2]=='A')
	{
		cout<<"1100";
		return 0;
	}
	if (aa[2]=='B'&&bb[2]=='E')
	{
		cout<<"1100";
		return 0;
	}
	if (aa[2]=='E'&&bb[2]=='B')
	{
		cout<<"1100";
		return 0;
	}
	if (aa[2]=='C'&&bb[2]=='E')
	{
		cout<<"1100";
		return 0;
	}
	if (aa[2]=='E'&&bb[2]=='C')
	{
		cout<<"1100";
		return 0;
	}
	if (aa[2]=='A'&&bb[2]=='C')
	{
		cout<<"1110";
		return 0;
	}
	if (aa[2]=='C'&&bb[2]=='A')
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
}
