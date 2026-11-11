#include<bits/stdc++.h>
using namespace std;
int last[500000+10];
int a[500000+10];
int ans[500000+10];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int l=last[a[i]]+1;
		int t=a[i];
		ans[t]++;
		while(l<=n)
		{
			l=last[t]+1;
			t=a[l];
			ans[t]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}
