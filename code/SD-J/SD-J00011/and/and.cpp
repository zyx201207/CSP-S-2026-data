#include<iostream>
using namespace std;
const int N=2e5+5;
int n,m,a[N],vis[N],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int k=30;k>=0;k--)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
			if((a[i]>>k)&1 && !vis[i])
				cnt++;		
		if(cnt<=m-1) continue;
		ans+=(1<<k);
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			if(!((a[i]>>k)&1)) vis[i]=1;
		}
	}
	cout<<ans;
}
