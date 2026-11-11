#include <bits/stdc++.h>
using namespace std;
int a,b;
string s,s1;
bool check(char a,char b)
{
	if((a=='D'&&b=='F')||(a=='F'&&b=='D')||(a<='C'&&b<='C'&&a!=b&&a>='A'&&b>='A'))
	{
		return true;
	}else{
		return false;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>s1;
	if(a==b)
	{
		cout<<1;
		if(s[0]==s1[0]&&s[1]==s1[1])
		{
			cout<<1;
			if(check(s[2],s1[2]))
			{
				cout<<1;
				if(abs(s[2]-s1[2])==1)
				{
					cout<<1;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
