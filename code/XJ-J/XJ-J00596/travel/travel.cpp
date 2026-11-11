#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c,s=1;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
	 cout<<"1";
	for(int i=0;i<=1;i++)
	{
		if(b[i]==d[i]);
		else
		{
			s=0;
			cout<<"000";
			break;
		}
	}
	if(s!=0)
	{
	 cout<<"1";
		if(('A'<=b[2]&&b[2]<='C')&&('A'<=d[2]&&d[2]<='C')) 
		{
			cout<<"1";
			if(b[2]==d[2]+1||b[2]==d[2]-1)cout<<"1";
			else cout<<"0";
		}
		else if(('D'==b[2]||b[2]=='F')&&('D'==d[2]||'F'==d[2])) cout<<"11";
		else cout<<"00";
	}
	}
	else 
	{
		cout<<"0000";
	}


	return 0;
}