#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);}
	return x*f;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
	cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1])
		{
			cout<<"1";
			if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A'))
			cout<<"10";
			else
			{
				if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='A'&&d[2]=='C')||(b[2]=='E'&&d[2]=='F')||(b[2]=='F'&&d[2]=='E'))
				cout<<"11";
				else
				cout<<"00";
			}
		}
		else
			cout<<"000";
	}
	else
	cout<<"0000";


	return 0;
}
