#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],ans;
long long cntt[200005];
void dfs(long long now,long long target,long long cnt)
{
	if(x[now] == x[target]) cntt[cnt]++;
	else
	{
		for(int i = now + 1;i <= target;i++)
		{
			if(x[i] - x[now] <= d) dfs(i,target,cnt + 1);
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans = 0;
		cin>>n>>d;
		if(n == 1) cout<<"0"<<endl;
		else
		{
			for(int i = 1;i <= n;i++) cin>>x[i];
			for(int i = 1;i <= n - 1;i++)
			{
				for(int j = i;j <= n;j++)
				{
					for(int k = 1;k <= j - i + 1;k++) cntt[k] = 0;
					dfs(i,j,0);
					bool flag = true;
					for(int k = 1;k <= j - i + 1 && flag;k++)
					{
						//cout<<cntt[k]<<endl;
						if(cntt[k] > 0) 
						{
							if(cntt[k] == 2) ans++;
							flag = false;
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

