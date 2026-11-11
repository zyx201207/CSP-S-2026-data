#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string a,b,a1,b1;
	cin>>a>>b>>a1>>b1;
	if(b[2] == 'F')
	{
		b[2]-=1;
	} 
	if(b1[2] == 'F')
	{
		b[2]-=1;
	} 
	if(a == a1)
	{
		cout<<1;
		if(b[0] == b1[0]&&b[1]==b1[1])
		{
			cout<<1;
			if((b1[2]<='C'&&b[2]<='C')||(b[2]>'C'&&b1[2]>'C'))
			{
				cout<<"1";
				if(b1[2]-b[2]==1||b[2]-b1[2]==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
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
}
