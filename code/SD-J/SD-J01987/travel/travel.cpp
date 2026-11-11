#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx)
		cout<<1;
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	bool f=0;
	for(int i=0;i<=1;i++)
	{
		if(sr[i]!=sx[i])
			f=1;
	}
	if(f==0)
		cout<<1;
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	if(sr[2]=='A')
	{
		if(sx[2]=='B') cout<<1<<1;
		else if(sx[2]=='C') cout<<1<<0;
		else cout<<0<<0;		
	}
	else if(sr[2]=='B')
	{
		if(sx[2]=='A'||sx[2]=='C') cout<<1<<1;
		else cout<<0<<0;	
	}
	else if(sr[2]=='C')
	{
		if(sx[2]=='B') cout<<1<<1;
		else if(sx[2]=='A') cout<<1<<0;
		else  cout<<0<<0;		
	}
	else if(sr[2]=='D')
	{
		if(sx[2]=='F') cout<<1<<1;
		else cout<<0<<0;	
	}
	else 
	{
		if(sx[2]=='D') cout<<1<<1;
		else cout<<0<<0;
	}		
	return 0;
}
