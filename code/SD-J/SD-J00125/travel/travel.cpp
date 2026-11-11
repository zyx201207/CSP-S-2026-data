#include<bits/stdc++.h>
#define int long long
#define N 100010
using namespace std;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else
	{
		string s1n=s1.substr(0,2);
		string s2n=s2.substr(0,2);
		if(s1n!=s2n)cout<<"1000";
		else
		{
			char s1z=s1[2],s2z=s2[2];
			bool b1=(s1z=='A')||(s1z=='B')||(s1z=='C');
			bool b2=(s2z=='A')||(s2z=='B')||(s2z=='C');
			if((b1 xor b2)==1)cout<<"1100";
			else
			{
				if(!(s1z+1==s2z||s2z+1==s1z))cout<<"1110";
				else cout<<"1111";
			}
		}
	}
	return 0;
}

