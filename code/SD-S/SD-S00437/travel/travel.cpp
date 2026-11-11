#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve_problems()
{
	string c1,s1,c2,s2;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	int a=0,b=0,c=0,d=0;
	if(c1==c2)
	{
		a=1;
		if((s1[0]==s2[0])&&(s1[1]==s2[1]))
		{
			b=1;
			if(((('A'<=s1[2])&&(s1[2]<='C'))&&(('A'<=s2[2])&&(s2[2]<='C')))||((('D'<=s1[2])&&(s1[2]<='F'))&&(('D'<=s2[2])&&(s2[2]<='F'))))
			{
				c=1;
			}
			if((abs(s1[2]-s2[2])==1)&&(!((s1[2]=='C')&&(s2[2]=='D'))))
			{
				d=1;
			}
		}
	}
	cout<<a<<b<<c<<d;
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	for(int t=1;t<=T;t++)
	{
		solve_problems();
	}
	return 0;
}
