#include<bits/stdc++.h>
using namespace std;
int my_abs(int x)
{
	return x>=0?x:-x;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)
	{
		cout<<"0000";
		return 0;
	}
	if(s2[0]!=s4[0]||s2[1]!=s4[1])
	{
		cout<<"1000";
		return 0;
	}
	if(s2[2]<'D'&&s4[2]>'C'||s2[2]>'C'&&s4[2]<'D')
	{
		cout<<"1100";
		return 0;
	}
	if(my_abs((int)s2[2]-(int)s4[2])!=1) cout<<"1110";
	else cout<<"1111";
	return 0;
}
