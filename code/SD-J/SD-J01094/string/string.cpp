#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//const int N=
string s;
string a;
LL cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++)
	{
		LL x;
		char y;
		cin>>x>>y;
		for(LL i=1;i<=x;i++)
		{
			s+=y;
		}
	}
	for(int i=0;i<s.size();i++)
		cout<<s[i];
	for(LL i=s.size()-1;i>=0;i--)
		a+=s[i];
	if(a==s)
		cout<<0;
	else
	{
		LL mid=s.size()/2;
		if(s.size()%2!=0)
		{
			for(LL i=mid+1;i<s.size();i++)
			{
				if(s[i]!=s[i-mid])
					cnt++;
			}
		}
		else
		{
			for(LL i=mid;i<s.size();i++)
			{
				if(s[i]!=s[i-mid])
					cnt++;
			}
		}	
	}
	cout<<cnt;
	return 0;
}
