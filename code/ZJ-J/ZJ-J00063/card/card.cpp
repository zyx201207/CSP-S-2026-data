#include<bits/stdc++.h>
using namespace std;
const int N=5e5+15;
int n,m;
int a[N];
int lst[N],l[N],ans[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!lst[a[i]]) lst[a[i]]=i;
		else l[lst[a[i]]]=1,lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(l[j]==1) j=lst[a[j]];
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i];
		if(i!=m) cout<<" ";
	}
	return 0;
}