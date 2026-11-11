#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(s1[0]+s1[1]==s2[0]+s2[1])
		{
			cout<<"1";
			int cnt=int(s1[2]-'A');
			int ans=int(s2[2]-'A');
			if(ans==1 and cnt==0 or ans==1 and cnt==2 or ans==0 and cnt==1 or ans==0 and cnt==2 or ans==2 and cnt==0 or ans==2 and cnt==1)
			{
				cout<<"1";
				if(ans==0 and cnt==1 or ans==1 and cnt==0 or ans==2 and cnt==1 or ans==1 and cnt==2)
				{
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else
			if(ans==3 and cnt==4 or ans==4 and cnt==3)
			{
				cout<<"11";
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
