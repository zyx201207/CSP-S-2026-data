//郭骐领 西安市益新中学 SN-J00682
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,b[200005];
void dfs(int x)
{
	if(x>m)
	{
		ans=max(ans,b[m]);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]&a[i];
		dfs(x+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(m==1)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			sum=max(sum,x);
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	b[0]=-1;
	dfs(1);
	cout<<ans;
	return 0;
}
