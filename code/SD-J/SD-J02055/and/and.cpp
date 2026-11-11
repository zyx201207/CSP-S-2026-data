#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m;
int a[N];
bool d[N][31];
int vis[31]={};
int cnt=0;
void h(int a,int b)
{
	for(int i=0;a!=0;a/=2,i++)
	{
		d[b][i]=a%2;
	}
}
int ans()
{
	int c=0,j=1;
	for(int i=0;i<=30;i++,j*=2)
	{
		if(vis[i]==m)
		{
			c+=j;
		}
	}
	return c;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		h(a[i],i);
	}
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=30;j++)
		{
			vis[j]+=d[i][j];
		}
		cnt=ans();
	}
	int sum=1;
	for(int i=m+1;i<=n;i++)
	{
		for(int j=0;j<=30;j++)
		{
			vis[j]+=d[i][j];
		}
		for(int j=0;j<=30;j++)
		{
			vis[j]-=d[i-m][j];
		}
		cnt=max(cnt,ans());
	}
	cout<<cnt;
	return 0;
}









