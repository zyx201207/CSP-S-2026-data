#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	string a,b,aa,bb;
	int l=0;
	cin>>a>>b>>aa>>bb;
	if(a==aa)
	{
		cout<<'1';
		if(b[0]==bb[0]&&b[1]==bb[1])
		{
			cout<<'1';
			if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(bb[2]=='A'||bb[2]=='B'||bb[2]=='C'))
			{
				cout<<'1';
				if ((b[2]-bb[2]==1)||(b[2]-bb[2]==-1))
				{
					cout<<'1';	
				}
				else 
				{
					cout<<'0';
				}
			}
			else if((b[2]=='F'||b[2]=='D')&&(bb[2]=='F'||bb[2]=='D'))
			{
				cout<<"11";
			}
			else 
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
