#include<bits/stdc++.h>
using namespace std;
int a[200005][35];
int t[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		t[i]=1;
		int x;
		cin>>x;
		for(int j=0;j<=29;j++)
		{
			if((x>>j)&1)
			{
				a[i][j]=1;
			}
		}
	}
	int ans=0;
	for(int i=29;i>=0;i--)
	{
		int h=0;
		for(int j=1;j<=n;j++)
		{
			if(t[j]==1&&a[j][i]==1)
			{
				h++;
			}
		}
		if(h<m)
		{
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			if(t[j]==1&&a[j][i]==0)
			{
				t[j]=0;
			}
		}
		ans+=(1<<i);
	}
	cout<<ans;
	return 0;
}
