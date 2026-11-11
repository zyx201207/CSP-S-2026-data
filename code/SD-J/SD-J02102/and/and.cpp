#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,ans;
int a[N],maxx,maxx2,vis[100];
bool bo[N];
void dfs(int now)
{
	if(now==m){
		maxx2=vis[m];
		return ;
	}
	now++;
	for(int i=1;i<=n;i++)
	{
		if(!bo[i])
		{
			bo[i]=1;
			vis[now]=vis[now-1]&a[i];
			dfs(now);
			bo[i]=0;
			
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(a[i],maxx);
		ans&=a[i];
	}
	if(n<=20)
	{
		for(int i=1;i<=n;i++)
		{
			vis[1]=a[i];
			bo[i]=1;
			dfs(1);
			bo[i]=0;
		}
		cout<<maxx2;
	}
	else if(m==1)
	{
		cout<<maxx;
	}
	else if(m==2)
	{
		maxx=0;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			maxx=max(maxx,a[i]&a[j]);
		}
	}
	else if(m==n)
	{
		cout<<ans;
	}
	return 0;
}
/*
4
2
3
15
12
12
*/
