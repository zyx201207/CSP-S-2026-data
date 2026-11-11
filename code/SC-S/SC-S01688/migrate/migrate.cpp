#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n,d,x[2000006],ans,cnt,minn;

void dfs(int l,int r,int now,int z)
{
	if(now==r)
	{
		if(z==minn)cnt++;
		else if(z<=minn)
		{
			cnt=1;
			minn=z;
		}
	}
	int nx=now;
	while(nx+1<=r&&x[nx+1]-x[now]<=d)
	{
		nx++;
		dfs(l,r,nx,z+1);
	}
}

signed main(void)
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				minn=0x3f3f3f3f3f3f3f3f;
				cnt=0;
				dfs(i,j,i,0);
				if(cnt==2)ans++;
			}
		}cout<<ans<<endl;
	}
	return 0;
}