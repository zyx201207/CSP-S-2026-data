#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128
#define F first
#define S second

string c1,c2,s1,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<"1";
			char x=s1[2];
			char y=s2[2];
			if(x>y)
			{
				swap(x,y);
			}
			if((x<='C'&&y<='C')||(x>'C'&&y>'C'))
			{
				cout<<"1";
				if(y-x==1)
				{
					cout<<"1";
				}else
				{
					cout<<"0";
				}
			}else
			{
				cout<<"00";
			}
		}else
		{
			cout<<"000";
		}
	}else
	{
		cout<<"0000";
	}
	return 0;
}
