#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	string ans="0000";
	if(a1==b1)
	{
		ans="1000";
		int x1=a2[2];
		int y1=b2[2];
		int x2=a2[0]*10+a2[1];
		int y2=b2[0]*10+b2[1];
		if(x2==y2)
		{
			ans="1100";
			if(x1<='C' && y1<='C')
			{
				ans="1110";
				if(x1+1==y1 || x1==y1+1)
				{
					ans="1111";
				}
				
			}
			else if(x1>'C'&& y1>'C')
			{
				ans="1110";
				if(x1+1==y1 || x1==y1+1)
				{
					ans="1111";	
				}
				
			}
			
		}
		
	}
	
	cout<<ans;
	return 0;
}