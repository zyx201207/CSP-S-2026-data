#include<bits/stdc++.h>
using namespace std;
int n,m,maxx=-1;
struct node
{
	int x;
	char s;
} a[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].s;
		maxx=max(a[i].x,maxx);
	}
	if(n==1) 
	{
		cout<<0;
	}
	else if(n==2)
	{
		if(a[1].s!=a[2].s) cout<<min(a[1].x,a[2].x);
		else cout<<0;
	}
	else if(n<11)
	{
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i].x;j++)
			{
				s+=a[i].s;
				ans++;
			}
		}
		for(int i=0;i<s.size()/2;i++)
		{
			if(s[i]!=s[s.size()-i-1]) cnt++;
		}
		cout<<cnt;
	}
	else if(maxx==1){
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].s!=a[n-i+1].s) cnt++;
		}
		cout<<cnt;
	}
	else if(n<200001&&maxx<=500)
	{
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i].x;j++)
			{
				s+=a[i].s;
			}
		}
		for(int i=0;i<=s.size()/2;i++)
		{
			if(s[i]!=s[s.size()-i-1]) cnt++;
		}
		cout<<cnt;
	}
	return 0;
}


