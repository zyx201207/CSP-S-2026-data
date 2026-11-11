#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		int y=0,r=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
				if(j==n||a[j]!=a[j+1])
					a[j]==1?y++:r++;
		}
		cout<<y<<' '<<r;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
			if(j==n||a[j]!=a[j+1])
				ans[j]++;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}
