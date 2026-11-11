#include<bits/stdc++.h>
using namespace std;
int n,m,use[200001];
bool used[200001][32];
long long maxx,a[200001];
long long ans,two[32];
void check(long long x,int y)
{
	for(int i=30;i>=0;i--)
	{
		if(x>=two[i])
		{
			x-=two[i];
			used[y][i]=1;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	two[0]=1;
	for(int i=1;i<=30;i++)
	{
		two[i]=two[i-1]*2;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		check(a[i],i);
	}
	for(int j=30;j>=0;j--)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(used[i][j]==1 && use[i]!=1)
			{
				cnt++;
			}
		}
		if(cnt>=m)
		{
			ans+=two[j];
			for(int i=1;i<=n;i++)
			{
				if(used[i][j]==0 && use[i]!=1)use[i]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}