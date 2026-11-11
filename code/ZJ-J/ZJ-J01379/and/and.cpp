#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
set<int> s;
void fun()
{
	int sum=1;
	for(int i=1;i<=30;i++) 
	{
		s.insert(sum);
		sum*=2;
	}
}
int dfs(int x,int i)
{
	if(i>n) return 0;
	if(x==m) return a[i];
	int mx=0;
	for(int k=i;k<=n;k++)
	{
		int cnt=a[k]&dfs(x+1,k+1);
		mx=max(cnt,mx);
	}
	return mx;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	fun();
	cin>>n>>m;
	bool oka=true,okb=true;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(s.find(a[i])==s.end()) oka=false;
		if(a[i]!=i-1) okb=false;
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		int cnt=a[1];
		for(int i=2;i<=n;i++)
		{
			cnt=cnt&a[1];
		}
		cout<<cnt;
		return 0;
	}
	if(m==2)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cnt=max(cnt,a[i]&a[j]);
			}
		}
		cout<<cnt;
		return 0;
	}
	if(oka)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	if(okb)
	{
		int cnt=a[n-m+1];
		for(int i=n-m+2;i<=n;i++)
		{
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	cout<<dfs(0,1);
	return 0;
}
