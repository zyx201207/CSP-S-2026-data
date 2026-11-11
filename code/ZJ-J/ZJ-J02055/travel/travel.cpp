#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else
	{
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			char c1=s1[2],c2=s2[2];
			if(((c1=='A'||c1=='B'||c1=='C')&&(c2=='A'||c2=='B'||c2=='C'))||((c1=='D'||c1=='F')&&(c2=='D'||c2=='F')))
			{
				if(abs(c1-c2)==1)cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	return 0;
}

