#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool isc(char r,char x)
{
	if(r<='C' && 'A'<=r && 'A'<=x && x<='C') return 1;
	else if('D'<=r && r<='E' && 'D'<=x && x<='E') return 1;
	else return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,xc;
	char ra,rb,r,xa,xb,x;
	cin>>rc>>ra>>rb>>r;
	cin>>xc>>xa>>xb>>x;	
	if(rc==xc)
	{
		cout<<1;
		if(ra==xa && rb==xb) 
		{
			cout<<1;
			if(isc(r,x))
			{
				cout<<1;
				if(abs((r-'0')-(x-'0'))==1)
					cout<<1;
				else cout<<0;	  
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	} 
	else cout<<0<<0<<0<<0;
	return 0;
}
