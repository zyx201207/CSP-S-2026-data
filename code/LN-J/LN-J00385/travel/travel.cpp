#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int y=1,n=0;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<y;
		if(b[0]==d[0]&&b[1]==d[1])
		{
			cout<<y;
			if(b[2]=='a')
			{
				if(d[2]=='b') cout<<y<<y;
				else if(d[2]=='c')cout<<y<<n;
				else if(d[2]=='d')cout<<n<<n;
				else if(d[2]=='f')cout<<n<<n;
				}
			if(b[2]=='b')
			{
				if(d[2]=='a') cout<<y<<y;
				else if(d[2]=='c')cout<<y<<y;
				else if(d[2]=='d')cout<<n<<n;
				else if(d[2]=='f')cout<<n<<n;
				}
			if(b[2]=='c')
			{
				if(d[2]=='b') cout<<y<<y;
				else if(d[2]=='a')cout<<y<<n;
				else if(d[2]=='d')cout<<n<<n;
				else if(d[2]=='f')cout<<n<<n;
				}
			if(b[2]=='d')
			{
				if(d[2]=='f') cout<<y<<y;
				else if(d[2]=='c')cout<<n<<n;
				else if(d[2]=='a')cout<<n<<n;
				else if(d[2]=='b')cout<<n<<n;
				}
			if(b[2]=='f')
			{
				if(d[2]=='d') cout<<y<<y;
				else if(d[2]=='a')cout<<n<<n;
				else if(d[2]=='b')cout<<n<<n;
				else if(d[2]=='c')cout<<n<<n;
				}
			
			}
		else
		{
			cout<<n<<n<<n;
			}
		}
	else
	{
		cout<<n<<n<<n<<n;
		}
	
	return 0;
	}
