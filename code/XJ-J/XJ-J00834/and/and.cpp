#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],cur=INT_MAX,maxn2=-1,maxn,idx=INT_MAX,cnt;
void dfs(int i,int k,int sum)
{
	if(k>m) return;
	if(k==m) 
	{
		if(sum!=cur)
		{
			maxn=max(maxn,sum);
		}
	}
	if(i>n) return;
	dfs(i+1,k+1,sum&a[i]);
	dfs(i+1,k,sum);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i]; 
		maxn2=max(a[i],maxn);
		idx&=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int l=i,r=j;
			int c=(a[l]&a[r]);
			cnt=max(c,cnt);
		}
	}
	if(n<=20)
	{
		dfs(1,0,cur);
		cout<<maxn;
	}
	else if(m==1)
	{
		cout<<maxn2;
	}
	else if(m==n)
	{
		cout<<idx;
	}
	else if(m==2)
	{
		
		cout<<cnt;
	}
	return 0;
}
