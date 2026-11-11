#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt,l,f;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll x;
		char c;
		cin>>x>>c;
		if(x>500)
		{
			f=1;
		}
		l+=x;
		if(f)
		{
			continue;
		}
		for(int i=1;i<=x;i++)
		{
			s+=c; 
		}
	}
	if(f)
	{
		cout<<l/2;
		return 0;
	}
	for(int i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-1-i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}