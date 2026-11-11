#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

string s1,s2,c1,c2;
int main()
{
	freopen("travel.in","r",stdin),freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1!=s2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(c1[0]!=c2[0]||c1[1]!=c2[1])
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	char n=c1[2],m=c2[2];
	bool n1,m1;
	if(n>'C') n1=1;
	else n1=0;
	if(m>'C') m1=1;
	else m1=0;
	if(m1==n1)
	{
		cout<<1;
		if(c1[2]-c2[2]==1||c1[2]-c2[2]==-1) cout<<1;
		else cout<<0;
	}
	else
	{
		cout<<"00";
	}
	return 0;
}

