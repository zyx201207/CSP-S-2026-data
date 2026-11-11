#include<bits/stdc++.h>
using namespace std;
int i,e,f;
string a,c;
char b[4],d[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	for(i=1;i<=3;i++)
	cin>>b[i];
	cin>>c;
	for(i=1;i<=3;i++)
	cin>>d[i];
	if(a==c)
	{
		cout<<1;
		if(a==c&&b[1]==d[1]&&b[2]==d[2])
		{
			cout<<1;
			if(b[3]=='A'||b[3]=='B'||b[3]=='C'&&d[3]=='A'||d[3]=='B'||d[3]=='C')
			{
				cout<<1;
				if(b[3]=='A'&&d[3]=='B'||b[3]=='B'&&d[3]=='C'||b[3]=='B'&&d[3]=='A'||b[3]=='B'&&d[3]=='C')
				{
					cout<<1;	
					return 0;			
				}	
			}
			else
			{
				cout<<0;	
				return 0;		
			}
			if(b[3]=='D'||b[3]=='F'&&d[3]=='D'||d[3]=='F')
			{
				cout<<1;
				if(b[3]=='D'&&d[3]=='F'||b[3]=='F'&&d[3]=='D')
				{
					cout<<1;
					return 0;					
				}
			}
			else
			{
				cout<<0;	
				return 0;		
			}
		}
		else
		cout<<0<<0<<0;
	}
	else
	cout<<0<<0<<0<<0;
}
