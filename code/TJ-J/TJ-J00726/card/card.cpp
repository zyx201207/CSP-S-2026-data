#include <bits/stdc++.h>
using namespace std;
const int maxn=1001;
int n,m;
int a[maxn],vis[maxn];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		vis[i]=a[i];
		int v=vis[i];
		for(int j=i;j>0;j--)
		if(v!=vis[j])
		continue;
		int vis[i];
	}
	return 0;
}
