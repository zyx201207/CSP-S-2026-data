//long long
#include<bits/stdc++.h>
using namespace std;
const int K=2e5+10;
int n,m;
int a[K];
bool vis[K];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	for(int i=30;i>=0;i--)
	{
		int xx=(1<<i);
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]) continue;
			if(a[j]>=xx) cnt++;
		}
		if(cnt<m)
		{
			for(int j=1;j<=n;j++) if(!vis[j]&&a[j]>=xx) a[j]=a[j]-xx;
			continue;
		}
		ans=ans+xx;
		for(int j=1;j<=n;j++) if(!vis[j]&&a[j]<xx) vis[j]=1;
		for(int j=1;j<=n;j++) if(a[j]>=xx) a[j]=a[j]-xx;
//		cout<<i<<" "<<cnt<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}
