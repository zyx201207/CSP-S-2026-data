#include<bits/stdc++.h>
#define int long long
using namespace std;
int k[200010];
bool sum[200010][31];
bool chk[200010];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		maxn=max(maxn,k[i]);
		int cnt=0;
		int x=k[i];
		while(x)
		{
			sum[i][++cnt]=(x%2==1);
			x/=2;
		}
	}
	int ans=0;
	int p=log2(maxn);
	for(int i=p+1;i>=1;i--)
	{
		int c=0;
		for(int j=1;j<=n;j++)
		{
			if(chk[j]==0)
			{
				if(sum[j][i]==1)
				{
					c++;
				}
			}
		}
		if(c>=m)
		{
			ans*=2;
			ans+=1;
			for(int j=1;j<=n;j++)
			{
				if(sum[j][i]==0)
				{
					chk[j]=1;
				}
			}
		}else{
			ans*=2;
		}
	}
	cout<<ans;
	return 0;
}

