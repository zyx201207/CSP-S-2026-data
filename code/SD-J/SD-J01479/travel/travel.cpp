#include<bits/stdc++.h>
using namespace std;
int sum=0;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0] && c1[1]==c2[1])
	{
		sum++;
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			sum++;
			int a=s1[2],b=s2[2];
			if(a<='C' && b<='C')
			{
				sum++;
				if(a-1==b || b-1==a)sum++;
				else cout<<"1110";
			}
			else if(a>'C' && a<='F' && b>'C' && b<='F')
			{
				sum++;
				if(a-1==b || b-1==a)sum++;
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	if(sum==4) cout<<"1111";
	return 0;
}
