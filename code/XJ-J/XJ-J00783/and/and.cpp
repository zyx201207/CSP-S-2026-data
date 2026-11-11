#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt=0;
	string s,ans;
	ans='0';
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(m--)
	{
		int Max=0,t=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>Max)
			{
				Max=a[i];
				t=i;
			}
		}
		a[t]=0;
		while(Max!=0)
		{
			s+=Max%2+'0';
			Max=Max/2;
		}
		int l;
		l=max(ans.size(),s.size());
		for(int i=0;i<l;i++)
		{
			if(s[i]=='1' && ans[i]=='1')
			{
				ans[i]=='1';
			}
			else
			{
				ans[i]='0';
			}
		}
	}
	int sum=1;
	for(int i=ans.size()-1;i>=0;i--)
	{
		cnt+=(s[i]-'0')*sum;
		sum*=2;
	}
	cout<<cnt;
	return 0;
}