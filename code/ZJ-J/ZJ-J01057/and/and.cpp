#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int s[n+5]={};
	for(int i=1;i<=n;i++) cin>>s[i];
	if(m==1)
	{
		sort(s+1,s+n+1);
		cout<<s[n];
		return 0;
	}
	if(m==n)
	{
		int ans=s[1];
		for(int i=2;i<=n+1;i++) ans&=s[i-1];
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		int ans=s[1];
		for(int i=1;i<=n;i++)
		{
			int now=s[1];
			for(int j=2;j<=+1;j++)
			{
				if(j==i+1) continue;
				now&=s[i-1];
			}
			ans=max(ans,now);
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{	
		sort(s+1,s+n+1);
		for(int i=n;i>=1;i--)
			if(s[i]==s[i-1])
			{
				cout<<s[i];
				return 0;
			}
		cout<<(s[n]&s[n-1]);
		return 0;
	}
	return 0;
}