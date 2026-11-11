#include<bits/stdc++.h>
using namespace std;
string s1,ss1,s2,ss2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>ss1>>s2>>ss2;
	if(s1!=s2) cout<<"0000";
	else
	{
		string x1=ss1.substr(0,2);
		string x2=ss2.substr(0,2);
		if(x1!=x2) cout<<"1000";
		else
		{
			int f1=ss1[2]-'A';
			int f2=ss2[2]-'A';
			if((f1<=2&&f2>=3)||(f1>=3&&f2<=2)) cout<<"1100";
			else
			{
				if(abs(f1-f2)==1) cout<<"1111";
				else cout<<"1110";
			}
		}
	}
	return 0;
}
