#include<bits/stdc++.h>
#define ll long long
using namespace std;
string xc,xs,yc,ys;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>xc>>xs>>yc>>ys;
	if(xc!=yc)
	{
		cout<<"0000";
		return 0;
	}
	if(xs[0]!=ys[0] || xs[1]!=ys[1])
	{
		cout<<"1000";
		return 0;
	}
	if((xs[2]=='F' && ys[2]=='D') || (xs[2]=='D' && ys[2]=='F'))
	{
		cout<<"1111";
		return 0;
	}
	if(xs[2]-1<=66 && ys[2]-1<=66)
	{
		if(xs[2]-ys[2]-1+1>=-1 && xs[2]-ys[2]-1+1<=1)
		{
			cout<<"1111";
			return 0;
		}
		cout<<"1110";
		return 0;
	}
	cout<<"1100";
	return 0;
 } 
