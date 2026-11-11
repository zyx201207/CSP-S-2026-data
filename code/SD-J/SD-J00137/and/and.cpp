#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200005],b[200005];
bool vis[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	if(n==1)
		for(int i=1;i<=n;i++)
			ans=max(ans,a[i]);
	else if(n==2)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
	else if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
	}
	cout<<ans;
	return 0;
}
