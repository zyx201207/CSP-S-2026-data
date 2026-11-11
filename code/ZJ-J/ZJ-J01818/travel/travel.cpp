#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
ll f(char x,char y)
{
	if(x<='C')
	{
		if(y<='C') return 1;
		return 0;
	}
	else
	{
		if(y>'C') return 1;
		return 0;
	}
}
ll ff(string x,string y)
{
	ll a=(x[0]-'0')*10+(x[1]-'0');
	ll b=(y[0]-'0')*10+(y[1]-'0');
	if(a==b)
	{
		if(abs(x[2]-y[2])==1) return 1;
		return 0;
	}
	else
	{
		if(x[2]==y[2]) return 1;
		return 0;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	ll a=(s1[0]-'0')*10+(s1[1]-'0');
	ll b=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2) cout<<1;
	else cout<<0;
	if(c1==c2&&(a==b)) cout<<1;
	else cout<<0;
	if(c1==c2&&(a==b)&&f(s1[2],s2[2])) cout<<1;
	else cout<<0;
	if(c1==c2&&(a==b)&&f(s1[2],s2[2])&&ff(s1,s2)) cout<<1;
	else cout<<0;
	return 0;
}
/*
02 02B 02 01A
*/
