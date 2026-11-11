#include <bits/stdc++.h>
using namespace std;
#define N 4
char s1[N],s2[N];
string c1,c2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000"<<endl;
		return 0;
	}
	bool ok=1;
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i])
		{
			cout<<0;
			ok=false;
			break;
		}
	}
	if(ok)
		cout<<1;
	char ch1=s1[2],ch2=s2[2];
	if(((ch1<='C'&&ch2<='C')||(ch1>='D'&&ch2>='D'))&&ok)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((s1[0]!=s2[0])||(s1[1]!=s2[1]))
		cout<<0;
	else if((ch1=='D'&&ch1=='C')||(ch1=='C'&&ch2=='D'))
		cout<<0;
	else if(ch1>ch2)
	{
		if(ch1-1==ch2||(ch1-2==ch2&&ch1=='F'))
			cout<<1;
		else
			cout<<0;
	}
	else
	{
		if(ch1+1==ch2||(ch1+2==ch2&&ch1=='D'))
			cout<<1;
		else
			cout<<0;
	}
	cout<<endl;
	
	return 0;
}
