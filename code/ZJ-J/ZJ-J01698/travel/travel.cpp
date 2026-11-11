#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else
	{
		string a=s1.substr(0,2),b=s2.substr(0,2);
		if(a!=b)cout<<"1000";
		else
		{
			char c=s1[2],d=s2[2];
			if((c=='A'||c=='B'||c=='C')&&(d=='D'||d=='E')||(c=='D'||c=='E')&&(d=='A'||d=='B'||d=='C'))cout<<"1100";
			else 
			{
				if(c=='A'&&d=='B'||c=='B'&&d=='C'||c=='D'&&d=='E')cout<<"1111";
				else cout<<"1110";
			}
		}
	}
	return 0;
}
