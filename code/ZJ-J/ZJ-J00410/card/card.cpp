#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],cnt[1000001],ans[1000001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(cnt,0,sizeof(cnt));
		stack<int>s;
		for(int j=i;j<=n;j++)
		{
			if(cnt[a[j]]!=0)
			{
				while(s.top()!=a[j])cnt[s.top()]--,s.pop();
			}
			if(s.empty()||s.top()!=a[j])s.push(a[j]),cnt[a[j]]++;
		}
		for(int j=1;j<=m;j++)
		{
			ans[j]+=(cnt[j]!=0);
		}
	}
	for(int j=1;j<=m;j++)cout<<ans[j]<<" ";
	return 0;
}