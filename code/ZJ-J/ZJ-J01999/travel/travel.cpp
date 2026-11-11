#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool x1=0,x2=0,x3=0,x4=0;
	if (c1==c2)
	{
		x1=1;
	}
	string p1="",p2="";
	for (int i=0;i<=1;i++)
	{
		p1+=s1[i];
		p2+=s2[i];
	}
	if (p1==p2 && x1==1)
	{
		x2=1;
	}
	if (((s1[2]=='F' || s1[2]=='D')&& (s2[2]=='D' || s2[2]=='F')) || ((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C'))&&x2==1)
	{
		x3=1;
	}
	if (x3==1 && ((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && (s2[2]=='C' || s2[2]=='A')) ||(s1[2]=='C' && s2[2]=='B')))
	{
		x4=1;
	}
	cout<<x1<<x2<<x3<<x4<<'\n';
	return 0;
}