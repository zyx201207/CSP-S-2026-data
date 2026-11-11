#include<bits/stdc++.h>
using namespace std;
string p1, p2;
string u1, u2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>u1>>p1>>u2>>p2;
	if(u1 == u2) 
	{
		cout<<1;
		if(p1[0] == p2[0] && p1[1] == p2[1])
		{
			cout<<1;
			if(((p1[2] == 'A' || p1[2] == 'B' || p1[2] == 'C') && (p2[2] == 'A' || p2[2] == 'B' || p2[2] == 'C')) || ((p1[2] == 'D' || p1[2] == 'F') && (p2[2] == 'D' || p2[2] == 'F')))
			{
				cout<<1;
				if(p1[2] == 'A' && p2[2] == 'B')
				{
					cout<<1;
					return 0;
				}
				else if(p1[2] == 'B' && (p2[2] == 'C' || p2[2] == 'A'))
				{
					cout<<1;
					return 0;
				}
				else if(p1[2] == 'C' && p2[2] == 'B')
				{
					cout<<1;
					return 0;
				}
				else 
				{
					cout<<0;
					return 0;
				}
			}
			else
			{
				cout<<00;
				return 0;
			} 
		} 
		else 
		{
			cout<<000;
			return 0;
		}
	}
	else 
	{
		cout<<0000;
		return 0;
	}
	return 0;
}
