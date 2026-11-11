//郭骐领 西安市益新中学 SN-J00682
#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b,c,d,ans="";
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	if(b[0]+b[1]!=d[0]+d[1])
	{
		cout<<"1000";
		return 0;
	}
	if(b[2]=='A'&&d[2]=='D' || b[2]=='A'&&d[2]=='F' || b[2]=='B'&&d[2]=='D' || b[2]=='B'&&d[2]=='F' || b[2]=='C'&&d[2]=='D' || b[2]=='C'&&d[2]=='F' || b[2]=='D'&&d[2]=='A' || b[2]=='D'&&d[2]=='B' || b[2]=='D'&&d[2]=='C' || b[2]=='F'&&d[2]=='A' || b[2]=='F'&&d[2]=='B' || b[2]=='F'&&d[2]=='C')
	{
		cout<<"1100";
		return 0;
	}
	if(b[2]=='A'&&d[2]=='C' || b[2]=='C'&&d[2]=='A')
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
