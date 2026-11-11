#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
string cr,sr,cx,sx,ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool f;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx)
		f=1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(sr[0]==sx[0]&&sr[1]==sx[1])
		f=1;
	else
	{
		cout<<"1000";
		return 0;
	}
	if(sr[2]<='C'&&sx[2]<='C' || sr[2]>'C'&&sx[2]>'C')
		f=1;
	else
	{
		cout<<"1100";
		return 0;
	}
	if(sr[2]<='C'&&sx[2]<='C'&&abs(sr[2]-sx[2])==1 || sr[2]>'C'&&sx[2]>'C')
		f=1;
	else
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}