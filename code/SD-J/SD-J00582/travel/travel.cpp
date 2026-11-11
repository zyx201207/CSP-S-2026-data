#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	string s,t;	
} a,b;
void solve(char c1,char c2)
{
	
	if(c1>c2)swap(c1,c2);
	
	if(c1<='C'&&c2<='C')cout<<1;
	else if(c1>'C'&&c2>'C')cout<<1;
	else cout<<0;
	if((c1=='A'&&c2=='B')||(c1=='B'&&c2=='C')||(c1=='D'&&c2=='F'))cout<<1;
	else cout<<0;
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a.s>>a.t>>b.s>>b.t;
	if(a.s==b.s)cout<<1;
	else 
	{
		cout<<"0000";
		return 0;
	}
	string c1,c2;
	c1+=a.t[0];
	c1+=a.t[1];
	c2+=b.t[0];
	c2+=b.t[1];
	if(c1==c2)cout<<1;
	else 
	{
		cout<<"000";
		return 0;
	}
	solve(a.t[2],b.t[2]);
	return 0;
}
