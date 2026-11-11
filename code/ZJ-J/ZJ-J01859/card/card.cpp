#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],lst[300005],ans[500005],s1[300005],s2[300005];
int l[300005];
bool vis[500005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],s1[a[i]]++;
	memset(vis,1,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		if(!vis[i-1]) ans[i]+=ans[i-1];
		ans[i]++;
		ans[i]+=lst[a[i]];
		lst[a[i]]=ans[i];
		s2[a[i]]++;
		if(s2[a[i]]==s1[a[i]]) vis[i]=0;
	}
	for(int i=1;i<=n;i++) l[a[i]]=i;
	for(int i=1;i<=m;i++) cout<<ans[l[i]]<<" ";
	cout<<"\n";
	return 0;
}