#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e5+5;
int n,m;
ll a[N],MAX;
ll s[N],d[N];

struct node
{
	ll calt;
	int count;
}b[N];
int cmp(node a,node b)
{
	return a.count<b.count;
}
void dfs(int k,int last,ll sum)
{
	if(k>m)
	{
		MAX=max(MAX,sum);
		return;
	}
	for(int i=last+1;i<=n;i++)
	{
		if(k==1) dfs(k+1,i,a[i]);
		else dfs(k+1,i,(sum&a[i]));
	}
}
int pd(ll nums)
{
	ll x=nums+1ll;
	int i=0;
	while((1<<i)<=x)
	{
		if((1<<i)==x) return 1;
		i++;
	}
	return 0;
}
int bloty(int nums)
{
	int x=nums,ans=0;
	while(x)
	{
		if(x%2) ans++;
		x/=2;
	}
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	int bo=1,cat=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		bo=min(bo,pd(a[i]));
		if(a[i]!=i-1) cat=0;
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n]<<"\n";
	}
	else if(cat)
	{
		sort(a+1,a+n+1);
		MAX=a[n];
		for(int i=n-1;i>=n-m+1;i--) MAX&=a[i];
		cout<<MAX<<"\n";
	}
	else if(bo)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1]<<"\n";
	}
	else if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		  if(i==1) s[i]=a[i];
		  else s[i]=s[i-1]&a[i];
		for(int i=n;i>=1;i--)
		  if(i==n) d[i]=a[i];
		  else d[i]=d[i+1]&a[i];
		MAX=max(s[n-1],d[2]);
		for(int i=2;i<n;i++) MAX=max(MAX,(s[i-1]&d[i+1]));
		cout<<MAX<<"\n";
	}
	else if(m==n)
	{
		MAX=a[1];
		for(int i=2;i<=n;i++) MAX&=a[i];
		cout<<MAX<<"\n";
	}
	else if(n<=20&&m<=20||n<=2000&&m==2)
	{
		MAX=0;
		dfs(1,0,0);
		cout<<MAX<<"\n";
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			b[i].calt=a[i];
			b[i].count=bloty(a[i]);
		}
		sort(b+1,b+n+1,cmp);
		MAX=b[n].calt;
		for(int i=n-1;i>=n-m+1;i--)
		{
			//cout<<a[i]<<"\n";
			MAX&=b[i].calt;
		}
		cout<<MAX<<"\n";
	}
	return 0;
}
/*
4 2
3 15 12 12
*/
