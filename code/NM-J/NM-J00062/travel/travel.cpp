#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)//同车厢 
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])//同排 
		{
			cout<<1;
			if((s1[2]>=65&&s1[2]<=67&&s2[2]>=65&&s2[2]<=67)||(s1[2]>=68&&s1[2]<=70&&s2[2]>=68&&s2[2]<=70))//同侧
			{
				cout<<1;
				if(s1[2]>=65&&s1[2]<=67&&s2[2]>=65&&s2[2]<=67)//位于过道左侧
				{
					if(s1[2]==s2[2]+1||s1[2]==s2[2]-1)//相邻
						cout<<1;	
					else
						cout<<0;
				}
				else
				{
					if(s1[2]==s2[2]+2||s1[2]==s2[2]-2)
						cout<<1;
					else
						cout<<0;
				}
			}
			else
				cout<<0<<0;
		}
		else
			cout<<0<<0<<0;
	}
	else 
		cout<<0<<0<<0<<0;
	return 0;
}
/*
A	B	C	D	E	F
65	66	67	68	69	70
*/
