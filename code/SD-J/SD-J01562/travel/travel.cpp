#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string sx,sy,cx,cy;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>sx>>sy>>cx>>cy;
	if(sx==cx)
	{
		if(sy[0]==cy[0]&&sy[1]==cy[1])
		{
			int a1,a2;
			if(sy[2]<='C') a1=0;
			else a1=1;
			if(cy[2]<='C') a2=0;
			else a2=1;
			if(a1==a2)
			{
				if(abs(int(sy[2]-cy[2]))==1)
					cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
 } 
