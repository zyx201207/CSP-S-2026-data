#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b,c,d,ans;
int main()
{
 	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		ans="1000";
		string tmp="",tmp2="";
		tmp=tmp+b[0]+b[1];
		tmp2=tmp2+d[0]+d[1];
//		cout<<tmp<<" "<<tmp2<<endl;
		if(tmp==tmp2)
		{
			ans="1100";
			if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))
			||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')))
			{
				ans="1110";
				if(b[2]=='D'||b[2]=='F')
				{
					cout<<"1111";
				}
				else if(abs(b[2]-d[2])==1)
				{
					cout<<"1111";
				}
				else
				{
					cout<<ans;
				}
			}
			else
			{
				cout<<ans;
			}
		}
		else
		{
			cout<<ans;
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}

