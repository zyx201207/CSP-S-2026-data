#include<bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
int s1;
string s2;
int s3;
string s4;
int bo=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
	{
		cout<<1;
		
	}
	else cout<<0;
	if(s1==s3&&s2[1]==s4[1]&&s2[0]==s4[0])
	{
		cout<<1;
	}
	else cout<<0;
	if(s1==s3&&s2[1]==s4[1]&&s2[0]==s4[0])
	{
		
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
		{
			if(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')
			{
				bo=1;
			}
		}
		if(s2[2]=='D'||s2[2]=='F')
		{
			if(s4[2]=='D'||s4[2]=='F')
			{
				bo=1;
			}
		}
	}	
	cout<<bo;
	
	if(s1==s3&&s2[1]==s4[1]&&s2[0]==s4[0]&&bo==1)
	{
		
		int a=(int)(s2[2]);
		int b=(int)(s4[2]);
		if(a==b+1||a==b-1)
		{
			cout<<1;
		}
		else cout<<0;
		
	}
	else cout<<0;
	return 0;
}


