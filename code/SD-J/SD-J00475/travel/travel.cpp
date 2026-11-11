#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e1+10,M=1e1+10;
int c1,c2;
string s1,s2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1])
	{
		cout<<"1000";
		return 0;
	}
	if((s1[2]>='D'&&s2[2]<'D')||(s2[2]>='D'&&s1[2]<'D'))
	{
		cout<<"1100";
		return 0;
	}
	if(s1[2]>='D'&&s2[2]>='D')
	{
		cout<<"1111";
	}
	else if(abs(s1[2]-s2[2])==1)
	{
		cout<<"1111";
	}
	else
	{
		cout<<"1110";
	}
	return 0;
}

