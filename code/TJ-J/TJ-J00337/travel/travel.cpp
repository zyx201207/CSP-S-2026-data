#include<bits/stdc++.h>
using namespace std;
struct node
{
	string c;
	string s;
};
node x,y;
int p;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x.c>>x.s>>y.c>>y.s;
	if(x.c==y.c)
	{
		cout<<1;
		p++;
	}
	else cout<<0;
	if(x.s[1]==y.s[1]&&x.s[0]==y.s[0]&&p==1)
	{
		cout<<1;
		p++;
	}
	else cout<<0;
	if(x.s[2]>=65&&x.s[2]<=67&&y.s[2]>=65&&y.s[2]<=67&&p==2)
	{
		cout<<1;
		p++;
	}
	else if(x.s[2]>=68&&x.s[2]<=69&&y.s[2]>=68&&y.s[2]<=69&&p==2)
	{
		cout<<1;
		p++;
	}
	else cout<<0;
	if(abs(x.s[2]-y.s[2])==1&&p==3) cout<<1;
	else cout<<0;
	return 0;
} 
