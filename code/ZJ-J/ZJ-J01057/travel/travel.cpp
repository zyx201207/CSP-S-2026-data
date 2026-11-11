#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans="";
	if(c1==c2)
	{
		ans+="1";
		string p1,p2;
		p1=s1.substr(0,2);
		p2=s2.substr(0,2);
		if(p1==p2)
		{
			ans+="1";
			p1=s1.substr(2);
			p2=s2.substr(2);
			if(p1>="D"&&p2>="D"||p1<="C"&&p2<="C")
			{
				ans+="1";
				char pp1,pp2;
				pp1=p1[0];
				pp2=p2[0];
				if(abs(pp1-pp2)==1) ans+="1";
				else ans+="0";
			}
			else ans+="00";
		}
		else ans+="000";
	}
	else ans+="0000";
	cout<<ans;
	return 0;
}
 