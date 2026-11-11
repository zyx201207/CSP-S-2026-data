#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a1,a2,c1,c2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1;
	cin>>a2;
	cin>>c1;
	cin>>c2;
	if(a1==c1)
	{
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(a1[0]==c1[0]&&a1[1]==c1[1])
	{
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'))
	{
		cout<<"1";
	}else{
		if((a2[2]=='F'||a2[2]=='D')&&(c2[2]=='F'||c2[2]=='D'))
		{
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}
}
