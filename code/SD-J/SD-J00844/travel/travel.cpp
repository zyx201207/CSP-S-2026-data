#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=0x3f3f3f3f;
string cx,cy,sx,sy,ans,x,y,dx,dy;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>sx>>cy>>sy;
	if(cx==cy)
	{
			ans+="1";
		x=sx[0]+sx[1];
		y=sy[0]+sy[1];
		if(x==y)
		{
			ans+="1";
			dx=sx[2];
			dy=sy[2];
			if(((dx=="A"||dx=="B"||dx=="C")&&(dy=="A"||dy=="B"||dy=="C"))||((dx=="F"||dx=="D")&&(dy=="F"||dy=="D")))
			{
				ans+="1";
			if((dx=="A"&&dy=="B")||(dx=="B"&&dy=="A"))
				ans+="1";
			else if((dx=="B"&&dy=="C")||(dy=="B"&&dx=="C"))
				ans+="1";
			else if((dx=="D"&&dy=="F")||(dy=="D"&&dx=="F"))
				ans+="1";
			else
				ans+="0";
			}
			else
				ans+="00";
		}
		else
			ans+="000";
	}
	else
		ans+="0000";
	cout<<ans;
	return 0;
}
