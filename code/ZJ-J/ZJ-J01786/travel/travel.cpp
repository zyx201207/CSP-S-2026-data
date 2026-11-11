#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool ck()
{
	char x=b[2],y=c[2];
	if(x=='A'&&y=='B')return 1;
	if(x=='B'&&(y=='A'||y=='C'))return 1;
	if(x=='C'&&y=='B')return 1;
	if(x=='D'&&y=='F')return 1;
	if(x=='F'&&y=='D')return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>d>>c;
	if(a==d)
	{
		int x=(b[0]-'0')*10+(b[1]-'0'),y=(c[0]-'0')*10+(c[1]-'0');
		if(x==y)
		{
			if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(c[2]=='A'||c[2]=='B'||c[2]=='C')||((b[2]=='D'||b[2]=='F')&&(c[2]=='D'||c[2]=='F')))
			{
				if(ck())cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else
		{
			cout<<"1000";
		}
	}
	else cout<<"0000";
	return 0;
}
