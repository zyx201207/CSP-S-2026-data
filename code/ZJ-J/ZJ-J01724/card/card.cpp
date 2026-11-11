#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
int n,m;
int a[N],ans[N],vis[N],cnt[N],last[N];
bool flag=true;
void solve1()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			vis[j]=0;
		for (int j=i;j<=n;j++)
		{
			if (vis[a[j]]!=0)
				for (int k=vis[a[j]];k<j;k++)
					vis[a[k]]=0;
			vis[a[j]]=j;
		}
		for (int j=1;j<=m;j++)
			if (vis[j]!=0)
				ans[j]++;
	}
}
void solve2()
{
	for (int i=1;i<=n;i++)
		if (cnt[i])
		{
			for (int j=1;j<=m;j++)
				vis[j]=0;
			for (int j=i;j<=n;j++)
			{
				if (cnt[j] and vis[a[j]]!=0)
					for (int k=vis[a[j]];k<j;k++)
						vis[a[k]]=0;
				vis[a[j]]=j;
			}
			for (int j=1;j<=m;j++)
				if (vis[j]!=0)
					ans[j]+=cnt[i];
		}
}
void solve3()
{
	for (int i=1;i<=n;i++)
		if (a[i]!=a[i+1])
			ans[a[i]]=i;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	int pos=0;
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==a[i-1])
			cnt[pos]++;
		else
		{
			cnt[i]++;
			pos=i;
			sum++;
		}
	}
	for (int i=1;i<=n;i++)
		if (a[i-1]>a[i])
		{
			flag=false;
			break;
		}
	if (n<=5000 and m<=3000)
		solve1();
	else if (flag)
		solve3();
	else
		solve2();
	for (int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
} 
