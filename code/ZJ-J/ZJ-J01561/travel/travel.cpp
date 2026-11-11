#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string ac,ap,bc,bp;
	cin>>ac>>ap>>bc>>bp;
	if(ac==bc)
	{
		cout<<'1';
		int a=0,b=0;
		for(int i=0;i<2;i++)
		{
			a=a*10+ap[i]-'0';
			b=b*10+bp[i]-'0';
		}
		if(a==b)
		{
			cout<<'1';
			char az=ap[2],bz=bp[2];
			if(az=='A')
			{
				if(bz=='B')
				{
					cout<<"11";
					return 0;
				}
				if(bz=='C')
				{
					cout<<"10";
					return 0;
				}
				cout<<"00";
				return 0;
			}
			if(az=='B')
			{
				if(bz=='A'||bz=='C')
				{
					cout<<"11";
					return 0;
				}
				cout<<"00";
				return 0;
			}
			if(az=='C')
			{
				if(bz=='B')
				{
					cout<<"11";
					return 0;
				}
				if(bz=='A')
				{
					cout<<"10";
					return 0;
				}
				cout<<"00";
				return 0;
			}
			if(az=='D')
			{
				if(bz=='F')
				{
					cout<<"11";
					return 0;
				}
				cout<<"00";
				return 0;
			}
			if(az=='D')
			{
				if(bz=='F')
				{
					cout<<"11";
					return 0;
				}
				cout<<"00";
				return 0;
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
		else 
		{
			cout<<"000";
			return 0;
		}
	}
	else cout<<"0000";
	return 0;
}
