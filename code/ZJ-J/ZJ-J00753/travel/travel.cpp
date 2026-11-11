#include<bits/stdc++.h>
#define int long long
using namespace std;
bool ch(int a,int b)
{
	if(a+b==9)
		return 1;
	if(a+b<=4||(a==2&&b==3)||(a==3&&b==2))
		return 1;
	return 0;
}
signed main()
{
 	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	int x,y;
	x=(s1[0]-'0')*10+s1[1]-'0';
	y=(s3[0]-'0')*10+s3[1]-'0';
	if(x!=y)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	x=(s2[0]-'0')*10+s2[1]-'0';
	y=(s4[0]-'0')*10+s4[1]-'0';
	if(x!=y)
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	x=min(s2[2]-'A'+1,5);
	y=min(s4[2]-'A'+1,5);
	if(!ch(x,y))
	{
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs(x-y)==1)
		cout<<1;
	else
		cout<<0;
 	return 0;
}
