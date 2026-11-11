#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string ans;
	if(a==c) ans+='1';
	else 
	{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]) ans+='1';
	else 
	{
		cout<<"1000";
		return 0;
	}
	int c1=0,c2=0;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C')c1++;
	if(d[2]=='A'||d[2]=='B'||d[2]=='C')c1++;
	if(b[2]=='D'||b[2]=='F')c2++;
	if(d[2]=='D'||d[2]=='F')c2++;
	if(c2==2||c1==2)ans+='1';
	else
	{
		cout<<"1100";
		return 0;
	}
	if(b[2]<='C'&&d[2]<='C')
	{
		if(abs(int(b[2])-int(d[2]))==1) ans+='1';
		else
		{
			cout<<"1110";
			return 0;
		}
	}
	else
	{
		if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')) ans+='1';
		else 
		{
			cout<<"1110";
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
