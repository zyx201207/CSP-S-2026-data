#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],ans[N];
vector<int>g[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		int t=a[i],k=i,tot=0;
		while(k<=n)
		{
			int len=g[t].size()-1;
			int vv=g[t][len];
			if(vv>k)
			k=vv;
			b[++tot]=t;
			k++;
			t=a[k];
		}
		for(int j=1;j<=tot;j++)
		{
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	cout<<ans[i]<<' ';
	return 0;
}
