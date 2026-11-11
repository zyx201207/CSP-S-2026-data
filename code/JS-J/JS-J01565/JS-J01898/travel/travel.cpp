#include<bits/stdc++.h>
using namespace std;
int q,w;
string s,ss;
int main()
{

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>q>>s>>w>>ss;
	if(q==w)
	{
		cout<<1;
		if(s[0]==ss[0]&&s[1]==ss[1])
		{
			cout<<1;
			if((s[2]<='C'&&ss[2]<='C')||(s[2]>'C'&&ss[2]>'C'))
			{
				cout<<1;
				if((s[2]=='A'&&ss[2]=='C')||(ss[2]=='A'&&s[2]=='C'))
					cout<<0;
				else
					cout<<1;
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	return 0;
}