// 欧阳宁佑 SN-J00845 西安市铁一中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
bool vis[200010];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=30;i>=0;i--)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]) continue;
			if((a[j]>>i)&1) cnt++;
		}
		if(cnt>=m)
		{
			for(int j=1;j<=n;j++)
			{
				if(vis[j]) continue;
				if((a[j]>>i)&1); else vis[j]=1; 
			}
			ans|=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
