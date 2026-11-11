#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string r,s;
	cin>>a>>r>>b>>s;
	if(a!=b)
	{
		cout<<"0000";
	}
	else
	{
		cout<<"1";
		int k,j;
		k=(r[0]-'0')*10+r[1]-'0';
		j=(s[0]-'0')*10+s[1]-'0';
		if(k!=j)
		{
			cout<<"000";
		}
		else
		{
			cout<<"1";
			if((r[2]=='D'&&s[2]=='F')||(r[2]=='F'&&s[2]=='D')||(r[2]=='A'&&s[2]=='B')||(r[2]=='A'&&s[2]=='C')||(r[2]=='B'&&s[2]=='A')||(r[2]=='B'&&s[2]=='C')||(r[2]=='C'&&s[2]=='A')||(r[2]=='C'&&s[2]=='B'))
			{
				cout<<"1";
				char p=r[2],o=s[2];
				if(p>o)
				{
					swap(p,o);
				}
					if(p+1==o)
					{
						cout<<"1";
					}
					else
					{
						cout<<"0";
					}
				
			}
			else
				cout<<"00";
		}
	}
}
