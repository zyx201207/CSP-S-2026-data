#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int Rtrack;
	string Rhere;
	int Xtrack;
	string Xhere;
	bool o=0;
	cin>>Rtrack;
	cin>>Rhere;
	cin>>Xtrack;
	cin>>Xhere;
	if(Rtrack==Xtrack)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(Rhere[1]==Xhere[1]&&Rhere[0]==Xhere[0])
	{
		cout<<1;
		if(Rhere[2]<='C'&&Xhere[2]<='C')
		{
			cout<<1;
			if(Rhere[2]==Xhere[2]+1||Rhere[2]==Xhere[2]-1)
			{
				cout<<1;
				return 0;
			}
			else
			{
				cout<<0;
				return 0;
			}
			o=1;
		}
		if(Rhere[2]>'C'&&Xhere[2]>'C')
		{
			cout<<1;
			if(Rhere[2]==Xhere[2]+1||Rhere[2]==Xhere[2]-1)
			{
				cout<<1;
				return 0;
			}
			else
			{
				cout<<0;
				return 0;
			}
			o=1;
		}
		if(!o)
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
	return 0;
}
