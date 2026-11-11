#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m,a[maxn],ans=-1;
void dfs(int k,int v,int sum)
{
	if(k>n)
		return;
	if(v>=m)
	{
		ans=max(ans,sum);
		return;
	}
	int p=sum&a[k];
	dfs(k+1,v+1,p);
	dfs(k+1,v,sum);
}
bool cmp(int A,int B)
{
	return A>B;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	// for(int i=1;i<=n;i++)
	// 	cout<<a[i]<<' ';
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
			sum&=a[i];
		cout<<sum;
		return 0;
	}
	if(n<=20)
	{
		dfs(1,0,a[1]);
		cout<<ans;
	}
	return 0;
}