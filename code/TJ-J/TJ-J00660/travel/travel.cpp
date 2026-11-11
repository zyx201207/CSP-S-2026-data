#include<bits/stdc++.h>
using namespace std;
#define int long long
struct chezuo
{
	int cx;
	int line;
	char seat;
};
int s;
signed main()
{	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	chezuo r,x;
	cin>>r.cx>>r.line>>r.seat>>x.cx>>x.line>>x.seat;
	if(r.cx==x.cx)
	{
		cout<<"1";
		s++;
	}
	else{
		cout<<"0";
	}
	
	if(r.line==x.line)
	{
		cout<<"1";
		s++;
	}
	else{
		cout<<"0";
	}
	
	if(r.seat==x.seat) 
	{
		cout<<"1";
		s++;
	}
	else if(r.seat=='A'||r.seat=='B'||r.seat=='C')
	{
		if(x.seat=='A'||x.seat=='B'||x.seat=='C') 
		{
			cout<<"1";
			s++;
		}
		else cout<<"0";
	}
	else if(r.seat=='D'||r.seat=='E')
	{
		if(x.seat=='D'||x.seat=='E') 
		{
			cout<<"1";
			s++;
		}
		else cout<<"0";
	}
	
	if(s==3)
	{
		if(x.seat=='A'&&r.seat=='B') cout<<1;
		else if(x.seat=='B'&&r.seat=='A') cout<<1;
		else if(x.seat=='B'&&r.seat=='C') cout<<1;
		else if(x.seat=='C'&&r.seat=='B') cout<<1;
		else if(x.seat=='D'&&r.seat=='E') cout<<1;
		else if(x.seat=='E'&&r.seat=='D') cout<<1;
	}
	else{
		cout<<"0";
	}
	return 0;
}

