#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,s="";
	cin>>a>>b>>c>>d;
	if(a==c) 
	{
		if(b[0]==d[0]&&b[1]==d[1])
		{
			if((int)b[2]<=67&&(int)d[2]<=67||(int)b[2]>=68&&(int)d[2]>=68) 
			{
				if(abs(b[3]-d[3])==1) s="1111";
				else s="1110";
			}
			else s="1100";
		}
		else s="1000";
	}
	else s="0000";
	cout<<s;
	return 0;
}
