#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
string s1,s2;
string c1,c2;
int ans;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
	}
	for(int i=0;i<=1;i++)
	{
		if(s1[i]==s2[i])
		{
			ans++;
		}
	}
	if(ans==2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
	}
	bool cnt=0;
	if(ans==2)
	{
		if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))
		{
			cout<<"1";
			cnt=1;
			if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
	        {
		        cout<<"1";
		        return 0;
	        }
		}
		if(cnt==0)
		{
			cout<<"0";
		}
	}
	cout<<"0";
	return 0;
} 
