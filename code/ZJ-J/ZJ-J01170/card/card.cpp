#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],next[n+1]={};
	int w[m+1]={},ans[m+1]={};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(w[a[i]]!=0)next[w[a[i]]]=i;
		w[a[i]]=i;
	}
	int pos;
	for(int i=1;i<=n;i++)
	{
		pos=i;
		while(pos<=n)
		{
			if(next[pos])pos=next[pos];
			else ans[a[pos++]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
