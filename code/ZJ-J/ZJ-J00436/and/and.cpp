#include<bits/stdc++.h>
using namespace std;
int a[200010];
string s[200010];
int jl[200010];
string zh(int x)
{
	string ans="";
	while(x>1)
	{
		int t=x%2+'0';
		ans=ans+char(t);
		x/=2;
	}
	ans=ans+char(x+'0');
	return ans;
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int mx=-2e9;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=zh(a[i]);
		int len=s[i].size();
		mx=max(mx,len);
	}
	bool flag=0;
	for(int i=mx-1;i>=0;i--)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(s[j][i]=='1')
			{
				jl[++cnt]=a[j];
			}
		}
		if(cnt==m)
		{
			int ans=jl[1];
			for(int i=2;i<=cnt;i++)
			{
				ans&=jl[i];
			}
			cout<<ans;
			flag=1;
			break;
		}
		if(cnt>m)break;
	}
	if(flag==0)
	{
		sort(a+1,a+n+1,cmp);
		int ans=a[1];
		for(int i=2;i<=m;i++)
		{
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}
