#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int b[200005];
int s[5];
int c[10];
int sum=0;
void dfs(int k)
{
	if(k==m+1)
	{
		int ans=c[1];
		for(int i=2;i<=m;i++)
		{
			ans&=c[i];
		} 
		sum=max(sum,ans);
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(b[i]==0)
			{
				b[i]=1;
				c[k]=a[i];
				dfs(k+1);
				b[i]=0;
				c[k]=0;
			}
		}
	}
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	bool b1=0,b2=0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(a[i]>=4) b1=1;
		if(a[i]!=i-1) b2=1;
	}
	if(m==1)
	{
		int ans=-1;
		for(int i=0;i<n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout << ans;
		return 0;
	}
	if(m==n)
	{
		int ans=a[0];
		for(int i=1;i<n;i++)
		{
			ans&=a[i];
		}
		cout << ans;
		return 0;
	}
	if(m<=20)
	{
		sum=0;
		dfs(1);
		cout << sum;
		return 0;
	}
	if(b1==0)
	{
		for(int i=0;i<n;i++)
		{
			s[a[i]]++;
		}
		if(m<=s[3])
		{
			cout << "3";
			return 0;
		}
		m-=s[3];
		if(m<=s[2])
		{
			cout << "2";
			return 0;
		}
		else if(m<=s[1])
		{
			cout << "1";
			return 0;
		}
		cout << "0";
		return 0;
	}
	if(b2==0)
	{
		int ans=n-1;
		for(int i=n-2;i>=n-m;i--)
		{
			ans&=i;
		}
		cout << ans;
		return 0;
	}
	sort(a,a+n,cmp);
	cout << a[m-1];
}