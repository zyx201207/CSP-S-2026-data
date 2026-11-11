#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	string s,s1;
	cin>>n>>s>>m>>s1;
	if(n!=m)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	int a=int(s[0]-'0')*10+int(s[1]-'0');
	int b=int(s1[0]-'0')*10+int(s1[1]-'0');
	if(a!=b)
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	int c=s[2]-'A'+1;
	int d=s1[2]-'A'+1;
	if(c==6)c--;
	if(d==6)d--;
	if(c<=3&&d>3||c>3&&d<=3)
	{
		cout<<"00";
	}
	else if(abs(c-d)==1)
	{
		cout<<"11";
	}
	else
	{
		cout<<"10";
	}
	return 0;
}