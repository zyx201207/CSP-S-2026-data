#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+10,MAXM=3e5+10;
int n,m,a[MAXN],ans[MAXM],vis[MAXM],flag=1;
vector<int> cnt[10010];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			flag=0;
		}
	}
	//cout<<flag<<endl;
	if(flag)
	{
		for(int i=1;i<=n;i++)
		{
			vis[a[i]]++;
		}
		int x=1;
		for(int i=1;i<=n;i++)
		{
			vis[a[i]]--;
			if(vis[a[i]]==0)
			{
				cout<<x<<' ';
			}
			x++;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		memset(cnt,0,sizeof(cnt));
		//memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			cnt[a[j]].push_back(j);
		}
		for(int j=i;j<=n;j++)
		{
			int k=cnt[a[j]].size()-1;
			j=cnt[a[j]][k];
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
/*
3
2 a
2 b
1 c
*/