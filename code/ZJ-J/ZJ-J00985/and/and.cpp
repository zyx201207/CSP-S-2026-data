#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn,minn,k;
void dfs(int h,int n,int m,int k)
{
	if(k==0||(h>n&&m))
	  return;
	if(m==0)
	{
	  maxn=max(maxn,k);
	  return;
	}
	dfs(h+1,n,m-1,k&a[h]);
	dfs(h+1,n,m,k);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=20)
	{
	  dfs(1,n,m,0xffffffff);
	  cout<<maxn;
	  return 0;
	}
	if(m==1)
	{
	  for(int i=1;i<=n;i++)
		  maxn=max(maxn,a[i]);
	  cout<<maxn<<" ";
	  return 0;
	}
	if(m==n)
	{
	  maxn=0xffffffff;
	  for(int i=1;i<=n;i++)
		  maxn=maxn&a[i];
	  cout<<maxn;
	  return 0;
	}
	if(m==n-1)
	{
	  maxn=0xffffffff;
	  minn=INT_MAX;
	  for(int i=1;i<=n;i++)
	  {
		  bitset<32>b(a[i]);
		  if(minn>b.count())
		  {
		  	minn=b.count();
		  	k=i;
		  }
	  }
	  for(int i=1;i<=n;i++)
		  if(i!=k)
		    maxn=maxn&a[i];
	  cout<<maxn;
	  return 0;
	}
	sort(a+1,a+n+1,greater<int>());
	cout<<a[m];
	return 0;
}