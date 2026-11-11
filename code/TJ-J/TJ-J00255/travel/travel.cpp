#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,t1,t2;
	cin>>s1>>s2>>t1>>t2;
	if(s1!=t1)cout<<"0000";
	else 
	{
		cout<<"1";
		if(s2[0]!=t2[0] or s2[1]!=t2[1])cout<<"000";
		else 
		{
			cout<<"1";
			if(!(s2[2]>='A' and t2[2]>='A' and s2[2]<='C' and t2[2]<='C') and !(s2[2]>='D' and t2[2]>='D'))cout<<"00";
			else
			{
				cout<<"1";
				if((s2[2]=='D' and t2[2]=='F') or (s2[2]=='F' and t2[2]=='D') or (abs(t2[2]-s2[2])==1 and t2[2]!='D' and s2[2]!='D'))cout<<"1";
				else cout<<"0";
			}
		}
	}
	return 0;
}
